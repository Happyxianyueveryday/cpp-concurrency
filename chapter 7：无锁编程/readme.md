## 7. 无锁编程

### 1. atomic模板
在无锁编程中，临界变量必须使用atomic模板创建对应的类，因为只有atomic模板类具有CAS接口，而CAS技术是无锁编程的核心。

例如，如果字符串a是一个临界变量，则创建一个对应的atomic对象的语句为：


```
atomic<string> str(a);
```


### 2. 无锁编程的核心——CAS技术
无锁的核心技术是CAS(compare-and-swap)，cpp11中提供了两个CAS的方法：compare_exchange_weak和compare_exchange_strong。

#### 2.1 compare_exchange_weak方法
compare_exchange_weak方法是一个CAS成员操作，原型如下所示。

```
// atomic类成员方法
bool compare_exchange_weak (T& expected, T val,
           memory_order sync = memory_order_seq_cst) volatile noexcept;
bool compare_exchange_weak (T& expected, T val,
           memory_order sync = memory_order_seq_cst) noexcept;
```

该方法比较当前atomic对象的值是否和用户输入的期待值expected相等：
1. 若相等，则将atomic对象的值设置成用户给定的新值val，并返回true；
2. 若不相等，则将expect参数修改成当前atomic的值，通过引用参数返回给用户；同时维持atomic对象的原值不变，最后返回false。

compare_exchange_weak方法是原子级的原语，某个线程执行该方法时不会被其他线程打断。


#### 2.2 compare_exchange_strong方法
compare_exchange_strong同样是一个

