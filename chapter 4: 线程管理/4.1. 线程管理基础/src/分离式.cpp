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
	thread corr(func);   // 初始化线程并执行
	corr.detach();       // 设定父子线程关系模式，采用分离式，线程将一直独立执行下去，直到主线程终止
	
	for(int i=0;i<100;i++)
	{
		cout<<"Main Thread."<<endl;
	}
} 
