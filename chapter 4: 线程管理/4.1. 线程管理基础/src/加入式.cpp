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
	
	for(int i=0;i<10;i++)
	{
		cout<<"Main Thread.\n";
	}
	
	corr.join();   // 设定父子线程终止关系为加入式，在join()方法被调用之前，子线程和父线程并发执行，父线程执行到join()时被阻塞，直到子线程执行结束后，父线程才继续执行join()之后的代码 
	
	for(int i=0;i<10;i++)
	{
		cout<<"Concurrent Thread is finished."<<endl; 
	}
} 
