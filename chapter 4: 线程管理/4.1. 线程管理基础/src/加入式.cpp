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
	thread corr(func);
	corr.join();     // 使用加入式启动线程 
	
	for(int i=0;i<100;i++)
	{
		cout<<"Main Thread."<<endl;
	}
} 
