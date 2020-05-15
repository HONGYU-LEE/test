#include<iostream>
#include<pthread.h>
#include<vector>
#include<semaphore.h>
using namespace std;

const size_t MAX_SIZE = 5;

class CircularQueue
{
    public:
        CircularQueue(int capacity = MAX_SIZE) 
            : _queue(capacity) 
            , _capacity(capacity)
            , _front(0)
            , _rear(0)
        {
            sem_init(&_mutex, 0, 1);
            sem_init(&_full, 0, 0);
            sem_init(&_empty, 0, _capacity);
        }
        
        ~CircularQueue()
        {
            sem_destroy(&_mutex);
            sem_destroy(&_full);
            sem_destroy(&_empty);
        }
        
        //入队
        void Push(int data)
        {
            //入队前先减少一个空闲资源，防止其他进程争抢资源，如果资源不够则阻塞
            sem_wait(&_empty);
            sem_wait(&_mutex);
            
            _queue[_rear++] = data;
            _rear %= _capacity;
           
            sem_post(&_mutex);
            sem_post(&_full);
            //入队完成，使用资源+1，同时唤醒消费者使用资源
        }

        //出队
        void Pop(int& data)
        {
            //出队前减少当前使用的资源数
            sem_wait(&_full);
            sem_wait(&_mutex);
            
            data = _queue[_front++];
            _front %= _capacity;
           
            sem_post(&_mutex);
            sem_post(&_empty);
            //出队完成，唤醒生产者生产资源
        }

    private:
        vector<int> _queue;
        size_t _capacity;
        size_t _front;
        size_t _rear;

        //需要三个信号量，一个互斥信号量，一个信号量表示空闲资源，一个信号量正在使用资源
        sem_t _mutex;
        sem_t _full;
        sem_t _empty;
        
};

void* productor(void* arg)
{
    //因为入口函数的参数为void*，所以需要强转回对应类型
    CircularQueue* queue = (CircularQueue*)arg;
    int data = 0;

    while(1)
    {
        queue->Push(data);
        cout << "生产者存入数据：" << data++ << endl;
    }

    return NULL;
}

void* customer(void* arg)
{
    CircularQueue* queue = (CircularQueue*)arg;
    int data;

    while(1)
    {
        queue->Pop(data);
        cout << "消费者取出数据：" << data << endl;
    }

    return NULL;
}

int main()
{
    CircularQueue queue;
    pthread_t pro_pid[5], cus_pid[5];
    
    //创建线程
    for(int i = 0; i < 5; i++)
    {
        int ret = pthread_create(&pro_pid[i], NULL, productor, (void*)&queue);
        if(ret)
        {
            cout << "生产者进程创建失败" << endl;
            return -1;
        }
        
        ret = pthread_create(&cus_pid[i], NULL, customer, (void*)&queue);

        if(ret)
        {
            cout << "消费者进程创建失败" << endl;
            return -1;
        }
    }

    //线程等待
    for(int i = 0; i < 5; i++)
    {
        pthread_join(pro_pid[i], NULL);
        pthread_join(cus_pid[i], NULL);
    }

    return 0;
}

