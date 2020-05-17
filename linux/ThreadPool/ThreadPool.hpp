#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<queue>

//类型重命名,将处理的方法定义为一个函数指针
typedef void (*handler_t)(int);

const size_t MAX_SIZE = 10;

class ThreadTask
{
    public:
        //设置需要处理的数据与对应的处理方法
        void SetTask(int data, handler_t handler)
        {
            _data = data;
            _handler = handler;
        }

        //处理数据
        void Run()
        {
           _handler(_data);
        }

    private:
        int _data;
        handler_t _handler;
};

class ThreadPool
{
    public:
        ThreadPool(size_t capacity = MAX_SIZE) : _capacity(capacity)
        {
            pthread_cond_init(&_cond, NULL);
            pthread_mutex_init(&_mutex, NULL);
            
            for(size_t i = 0; i < _capacity; i++)
            {
                pthread_t pid;
                int ret = pthread_create(&pid, NULL, start_routine, this);
                
                if(ret)
                {
                    std::cout << "线程创建失败" << std::endl;
                    exit(-1);
                }
            }
        }
        
        ~ThreadPool()
        {
            pthread_cond_destroy(&_cond);
            pthread_mutex_destroy(&_mutex);
        }

        void Push(ThreadTask& Task)
        {
            //互斥锁保证线程安全
            pthread_mutex_lock(&_mutex);
            //将任务放入队列中
            _queue.push(Task);

            //唤醒线程池全部线程，谁抢到谁就来处理这个任务
            pthread_cond_broadcast(&_cond);
            pthread_mutex_unlock(&_mutex);
        }

        //入口函数的参数只能有一个void*,所以需要写为static函数来去掉隐含的this指针
        static void* start_routine(void *arg)
        {
            //将void*强转为需要的类型
            ThreadPool* pool = (ThreadPool*)arg;
            
            while(1)
            {
                pthread_mutex_lock(&pool->_mutex);   

                while(pool->_queue.empty())
                {
                    pthread_cond_wait(&pool->_cond, &pool->_mutex);
                }

                ThreadTask Task;

                //将任务出队进行处理
                Task = pool->_queue.front();
                pool->_queue.pop();

                pthread_mutex_unlock(&pool->_mutex);

                //解锁后再处理，因为加锁只是保证队列操作的安全性
                Task.Run();
            }

            
            return NULL;
        }

    private:
        pthread_cond_t _cond;
        pthread_mutex_t _mutex;
        size_t _capacity;
        std::queue<ThreadTask> _queue;

};
