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

+ wait()方法首先判断和检查条件函数condition的返回值。
+ 若返回值为true则锁定互斥锁，然后即可互斥执行wait之后的代码。
+ 若返回值为false，则释放互斥锁，并使当前线程进入睡眠状态以让其他线程执行，直到另一个线程调用了相同条件变量的notify()系列方法，或者检查到条件函数返回值为true时，释放互斥锁解除阻塞，继续执行wait()之后的语句。

### 3. notify()方法
notify()方法用于沉睡线程的唤醒，具体有两个方法：

+ notify_one: 选择一个在该条件变量上睡眠等候(wait)的线程进行唤醒，若wait方法中提供的是公平锁，则总会唤醒等待最长时间的线程；若wait方法中提供的是非公平锁，则随机地选择线程唤醒，被唤醒的线程未必是等待最长时间的线程。
+ notify_all: 唤醒在该条件变量上睡眠等候的所有线程。

### 4. unique_lock和wait()方法详细解析

unique_lock是一个RAII的互斥锁，但是本身也提供了lock()和unlock()，unique_lock本身是cpp11为了补充自身没有finally语句而产生的，unique_lock提供lock()和unlock()方法供用户进行加锁和解锁的同时，

下面以一个例子来解析unique_lock互斥锁和wait()方法的配合使用。这是阻塞队列的出队操作代码。

```
```

unique_lock本身是一个类似于lock_guard的RAII自动锁，但是除了构造时加锁，析构时解锁外，它还提供了和裸互斥锁一致的lock()加锁和unlock()解锁方法，从而能够适应wait()方法本身的需要。

在上述代码中，wait()方法首先检查条件函数。若条件函数返回false，即栈为空，这时无法进行出栈操作，则wait方法调用unique_lock的unlock()方法解锁互斥量，让权等待，让其他线程执行；若条件函数返回true，则调用lock()方法加锁互斥量，然后继续执行下面的临界区代码。






