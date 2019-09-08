## 5. 互斥

### 1. 互斥信号量——std::mutex

cpp在mutex头文件中提供了最基本的互斥信号量，即std::mutex。std::mutex提供两个方法，lock()方法给互斥量加锁，相当于PV操作中的P操作，unlock()方法给互斥量解锁，相当于PV操作的V操作。

互斥信号量std::mutex的使用方法为：

+ 将需要访问临界资源的临界区代码夹在lock()方法(P操作)和unlock()方法(V操作)之间

在直接使用裸信号量std::mutex时，必须谨慎处理，在临界区代码结束后必须记得使用unlock()方法解除互斥锁（尤其是分支代码很多且可能抛出异常的情况）。这也是推荐使用RAII的互斥信号量——lock_guard的原因。


### 2. RAII互斥信号量——lock_guard




