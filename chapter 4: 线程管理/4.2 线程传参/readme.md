## 4.2 线程传参

### 1. std::thread的参数传递方式
std::thread的传参非常容易出现错误，std::thread的传参具体过程如下：

+ 将用户创建线程时传入的实参进行拷贝。
+ 使用拷贝的实参调用线程的入口函数。

换言之，std::thread的构造函数并不知道自身的入口函数的参数类型列表，因此只能全部使用按值传参，构造函数在内部使用实参调用入口函数时才可能发生其他形式的传参。因此如果需要传递引用，需要使用到std::ref()方法将变量转化为对应的引用。

下面举了一个简单的代码例子。

```
void func(int &a, int &b)
{
	int res=a+b;
	cout<<res;
}

int main(void)
{
	int a=5, b=3;
	thread th1=thread(func, a, b);   // 报错，thread的构造函数仅按值传参，这里参数展开后收到的实参仅仅是两个右值，用这两个值调用入口函数时错误，不能将左值引用绑定到右值上
	th1.join();
} 
```

```
void func(int &a, int &b)
{
	int res=a+b;
	cout<<res;
}

int main(void)
{
	int a=5, b=3;
	thread th1=thread(func, ref(a), ref(b));  // 正确运行，传入的是两个引用，构造函数按值传参后拷贝了一个引用，用这两个引用值调用入口函数时参数类型正确，可以正常运行
	th1.join();
} 
```
