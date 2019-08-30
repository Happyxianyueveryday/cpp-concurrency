#include <thread>
#include <iostream>

using namespace std;

/**
 * thread_callback: 线程对象的执行函数 
 */ 
void thread_callback()
{
	for(int i=0;i<3;i++)
	{
		cout<<"Hello world from concurrent thread."<<endl;
	}
}

int main(void)
{
	thread corr(thread_callback);    // 使用执行函数初始化和启动线程对象 
	cout<<"Hello world from main thread."<<endl;
	corr.join();    // 调用join方法，决定结束线程对象的方式
}
