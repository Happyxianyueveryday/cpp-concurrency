#include <iostream>
#include <thread>

using namespace std;

void func()
{
	for(int i=0;i<10;i++)
	{
		cout<<"Concurrent Thread\n";
	}
}

int main(void)
{
	thread corr(func);
	
	corr.detach();   // 设定结束模式为分离式，从detach()方法被调用之后，父线程和子线程之间分离，均并发执行直到两者分别自行结束，父线程不再能够控制子线程 
	
	for(int i=0;i<10;i++)
	{
		cout<<"Main Thread.\n";
		cout<<"Concurrent-Thread and Main-Thread are all running before Main-Thread finished."<<endl; 
	}
} 
