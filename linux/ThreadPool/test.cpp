#include "ThreadPool.hpp"
#include<unistd.h>

void handler1(int data)
{
    std::cout << "线程ID:"<< pthread_self() <<" 处理奇数数据:" << data << std::endl;

    sleep(1);
}



void handler2(int data)
{
    std::cout << "线程ID:"<< pthread_self() <<" 处理偶数数据:" << data << std::endl;

    sleep(1);
}

int main()
{
    ThreadPool pool;

    for(int i = 0; i < 10; i++)
    {
        ThreadTask task;
        
        //分别处理奇数和偶数
        if(i & 1)
        {
            task.SetTask(i, handler1);
        }
        else
        {
            task.SetTask(i, handler2);    
        }

        //任务放入队列中
        pool.Push(task);
    }
    
    //休眠一段时间防止结束后主线程退出
    sleep(100);
    return 0;
}
