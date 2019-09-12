## 6. 同步

cpp11中的同步机制通常使用条件变量condition_variable来实现，使用前需要添加头文件<condition_variable>。包含以下的关键方法：

### 1. 构造函数
条件变量的构造直接使用默认构造函数，无需提供参数。条件变量具体所需要的

### 2. wait()方法
condition_variable的wait()方法的原型如下：

```
condition_variable::wait(unique_lock<T> &lock, function condition);
```

其中第一个参数为一个unique_lock类型的互斥锁，该互斥锁用于实现阻塞；第二个参数则为一个函数（或者lambda表达式），该函数作为条件变量的条件进行判断。

wait()方法的执行如下所示：

+ wait()方法首先判断和检查条件函数condition的返回值，若返回值为true则不阻塞；若返回值为false，则通过调用互斥锁的lock()方法锁定参数互斥锁lock进行阻塞，并使当前线程进入睡眠状态，直到另一个线程调用了相同条件变量的notify()系列方法，或者检查到条件函数返回值为true时，释放互斥锁解除阻塞，继续执行wait()之后的语句。

### 3. notify()方法
notify()方法用于沉睡线程的唤醒，具体有两个方法：

+ notify_one: 选择一个在该条件变量上睡眠等候(wait)的线程进行唤醒，若wait方法中提供的是公平锁，则总会唤醒等待最长时间的线程；若wait方法中提供的是非公平锁，则随机地选择线程唤醒，被唤醒的线程未必是等待最长时间的线程。
+ notify_all: 唤醒在该条件变量上睡眠等候的所有线程。

### 4. 可重入锁



