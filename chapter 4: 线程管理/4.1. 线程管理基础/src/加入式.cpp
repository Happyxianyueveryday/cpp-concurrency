#include <iostream>
#include <thread>

using namespace std;

void func()
{
	for(int i=0;i<100;i++)
	{
		cout<<"Concurrent Thread"<<endl;
	}
}

int main(void)
{
	thread corr(func);    // 创建并启动线程
	corr.join();          // 设定父子线程终止关系，调用join()方法将父子线程终止关系设定为加入式，该线程执行完毕后就立刻销毁，返回主线程继续执行	
	
	for(int i=0;i<100;i++)
	{
		cout<<"Main Thread."<<endl;
	}
} 
