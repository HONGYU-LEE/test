#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<queue>

using namespace std;

const size_t MAX_SIZE = 5;

class BlockQueue
{
    public:
        BlockQueue(size_t capacity = MAX_SIZE) : _capacity(capacity)
        {
            pthread_mutex_init(&_mutex, NULL);
            pthread_cond_init(&_pro_cond, NULL);
            pthread_cond_init(&_cus_cond, NULL);
        }

        ~BlockQueue()
        {
            pthread_mutex_destroy(&_mutex);
            pthread_cond_destroy(&_pro_cond);
            pthread_cond_destroy(&_cus_cond);
        }

        void Push(int data)
        {
            //加锁保证线程安全
            pthread_mutex_lock(&_mutex);

            //队列已满，阻塞生产者生产
            while(_queue.size() == _capacity)
            {
                pthread_cond_wait(&_pro_cond, &_mutex);
            }

            //数据入队
            _queue.push(data);

            pthread_mutex_unlock(&_mutex);
            //生产完毕，唤醒消费者消费
            pthread_cond_signal(&_cus_cond);

        }

        void Pop(int& data)
        {
            pthread_mutex_lock(&_mutex);

            while(_queue.empty())
            {
                //队列空，阻塞消费者消费
                pthread_cond_wait(&_cus_cond, &_mutex);
            }

            //数据出队
            data = _queue.front();
            _queue.pop();
            
            pthread_mutex_unlock(&_mutex);

            //消费完毕，唤醒生产者生产
            pthread_cond_signal(&_pro_cond);
        }

    private:
        queue<int> _queue;
        size_t _capacity;

        pthread_mutex_t _mutex;
        pthread_cond_t _pro_cond;
        pthread_cond_t _cus_cond;
};

//因为入口函数的参数必须为void* ，所以要强转成BlockQueue类型
void *producter(void *arg)
{
    BlockQueue *queue = (BlockQueue*)arg;
    //生产者不断生产数据
    
    int data = 0;
    while(1)
    {
        //生产数据
        queue->Push(data);

        cout << "生产者放入数据：" << data++ << endl;
    }

    return NULL;
}

void *customer(void *arg)
{
    BlockQueue *queue = (BlockQueue*)arg;
    //消费者不断取出数据
    while(1)
    {
        //取出数据
        int data;
        queue->Pop(data);

        cout << "消费者取出数据：" << data << endl;
    }

    return NULL;
}

int main()
{
    BlockQueue queue;
    pthread_t pro_tid[5], cus_tid[5];
	
    //创建线程
    for(size_t i = 0; i < 5; i++)
    {
        int ret = pthread_create(&pro_tid[i], NULL, producter, (void*)&queue);

        if(ret)
        {
            cout << "生产者线程创建失败" << endl;
            return -1;
        }

        ret = pthread_create(&cus_tid[i], NULL, customer, (void*)&queue);
        if(ret)
        {
            cout << "消费者线程创建失败" << endl;
            return -1;
        }
    }   
    
    //等待线程退出
    for(size_t i = 0; i < 4; i++)
    {
        pthread_join(pro_tid[i], NULL);
        pthread_join(cus_tid[i], NULL);
    }

    return 0;
}
