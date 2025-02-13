* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...
* 📇 sssssdsdsdsdsdsdasd
* 🎃 dsdsdsdsdsddfsgdgasd
* 🍺 jyukyuiyuiyuigkasd
* 🍥 fsdfgdsgsdgdgadsa
* ✨ xcvxcvxcvxcvdasdaasd
* 🍰 dazdsxasxsaxsaasdsa
* 🚨 gdfgdshdfhfhygjtyu



# 消息队列（MessageQueue）

消息队列，是一个由消息组成的队列数据结构，是一种常见的异步RPC手段，服务架构中常见的组件，常用于分布式系统之间互相信息的传递。存在的意义一般用于服务间解耦、最终一致性、事件广播、错峰流控、任务异步/延迟处理等



MQ一般都做为企业级IT应用的中间件存在，有很多企业是作为标准IT基础结构存在的。在市面上常见的MQ中间件有IBM websphere message queue service，Oracle Advanced Queuing，Microsoft Message Queue(MSMQ)，Apache ActiveMQ等，其中apache ActiveMQ是基于apache协议的，和tomcat一样，你可以在项目中免费使用，MSMQ是Windows的组件，默认是不被安装的，可以在“添加/删除组件”中安装MSMQ（不同版本的Windows对应的MSMQ版本是不同的，XP/2003是3.0，Vista是4.0）。



其他实现

JMS（Java Message Service）：JMS是Java平台上的一种消息传递规范，支持多种消息队列实现，如ActiveMQ、RabbitMQ等。
RabbitMQ：一个基于Erlang的开源消息队列系统，支持多种消息传递协议，如AMQP、STOMP等。
Kafka：一个分布式的流处理平台，可以用于构建消息队列系统，支持高吞吐量、可扩展性和容错性。
RocketMQ：一个基于Java的开源消息队列系统，支持多种消息传递协议，如OpenMessaging、Apache QPID等。


## 一、消息队列相关概念

1、生产者（Producer）：负责产生消息；

2、消费者（Consumer）：负责消费消息；

3、消息（Message）：在应用间传送的数据。消息可以非常简单，比如只包含文本字符串，也可以更复杂，可能包含嵌入对象；

4、消息队列（Message Queue）：一种应用间的通信方式，消息发送后可以立即返回，由消息系统来确保消息的可靠传递。消息发布者只管把消息发布到 MQ 中而不用管谁来取，消息使用者只管从 MQ 中取消息而不管是谁发布的。这样发布者和使用者都不用知道对方的存在。

5、消息代理（Message Broker）：负责存储/转发消息，转发分为推和拉两种。

拉是指Consumer主动从Message Broker获取消息；
推是指Message Broker主动将Consumer感兴趣的消息推送给Consumer。

6、RPC（Remote Procedure Call Protocol） 远程过程调用协议。RPC是一种通过网络从远程计算机程序上请求服务，不需要了解底层网络技术的协议。RPC主要作用就是不同的服务间方法调用就像本地调用一样便捷。





7、VM：虚拟机（Virtual Machine）4：是物理计算机的虚拟表示或仿真，使用软件而非硬件来运行程序和部署应用程序。它通过虚拟化技术，能在一台物理计算机上模拟出多个独立的虚拟计算机，每个虚拟机都可运行自己的操作系统和应用程序，可提高计算机资源利用率、带来灵活性和便捷性等，在灾难恢复和系统迁移等方面也有重要作用。







## 二、MQ一般都具有这几个属性

1. 异步处理；即接收和发送方可以在不同的线程、进程或机器上，发送成功的同时，也不需要接收方立即接收；
2.  按消息发送的顺序处理消息（因为本身就是Queue）
3. 事物性的处理发送和接收消息；多个消息的发送和接收可以做在一个事物中，保证同时成功或同时失败；你也可以将MQ操作和数据库操作做在一个事物中，来处理一些特定的场景；
4. 保证消息的传递；当消息发送成功时，你就可以确定接收方一定能接收到；MQ会使用某种技术（文件系统、数据库）将消息保存起来；
5. 消息的路由；可以按某种规则，将队列中的消息自动的发送到不同的其他队列中；
6. 安全；使用多种手段进行权限认证，即程序是否有权限将消息插入到特定的队列中；
7. 接收方离线，在使用MQ的集成项目中，允许消息的接收系统离线，MQ会保存接收系统离线时发送系统发送的消息，当接收系统上线时，再发送消息给接收系统进行处理。这样可以使多个系统互相隔离，避免了一个系统崩溃，就造成整个流程都崩溃的情况。当然，我们必须保证MQ服务是在线的，我们可以使用高可靠性应用和负载均衡等技术，缩短MQ服务的离线时间。
8. 异常处理的隔离，由于是异步处理，如果接收方发现发送方发送的消息是有错误的，就可以返回一个消息，交发送方处理，此时，发送方可以使用另一个服务来专门处理异常。
9. 消息可以是多种形式的；比如二进制，字符串，XML等等，发送时，我们需要将数据变成合适的形式；













## 二、消息队列使用场景







### 1、异步处理

消息队列允许生产者发送消息后立即返回，而消费者可以异步地处理消息，从而提高了系统的响应速度和吞吐量。



长耗时的报表，这个在程序中经常遇见，处理海量数据时，可能生成一个报表需要5分中或是更长的时间，客户不能在线实时等待，报表处理比较耗费资源，不能同时处理很多请求，甚至同时只允许处理一个，这时就可以使用MQ。客户端将报表请求和一些必要的报表条件放到Queue中，报表由另一个服务一个一个的处理，处理好后再给用户发一个消息（MSN消息，或mail等）用户再在浏览器或其他报表浏览器中查看报表。



在线商店，在客户下订单的过程后，系统只需做减库存、记录收货人信息和必要的日志，其他的必须配送处理、交易统计等其他处理可以不同时完成，这时就可以将后续处理消息放入Queue中，让另一台（组）服务器去处理，这样可以加快下订单的过程，提高客户的体验；

应用集成，其实和在线商店的情形差不多，系统A处理完毕后，就发送消息给系统B，此时，系统A并不需要等到系统B的处理结果。比如一个货物可能由多个物流服务提供商合作送到客户那里（工厂到码头用一个物流提供商，海上运输用另一个，到另一个码头后由本地物流商送到客户手中），第一个物流商A发送信息给第二个物流商B，物流商A的系统只要确认物流商B的系统已经接收到消息就可以了，并不需要等待处理结果。

系统间的消息通知，系统A处理完成后，将处理后的数据放到某的地方（网络文件服务器、数据库或其他地方），然后发送一个消息通知系统B，系统B收到消息后开始后续的处理；此时系统B并不需要轮询文件系统或数据，可以提高系统的性能





### 2、业务解耦

生产者和消费者之间通过消息队列进行通信，使得两者之间不需要直接交互，从而提高了系统的可扩展性和容错能力。



语义的重点在于通知，而不是执行



举个例子, 用户购买机票, 支付之后, 系统有以下流程
1. 更改流水和订单状态
2. 通知代理商出票
3. 发送短信通知用户购买的行程

可想而知, 发送短信这个行为, 是典型的非核心, 并发能力低, 响应耗时长的服务.
用户支付完成之后, 需要保证快速, 并且一定为用户更新订单状态, 并开始出票. 但是短信不是, 用户晚个半分钟收到短信并不会造成什么影响, 但是订单状态晚半分钟才更新, 显然就会对用户造成很不好的影响.
这个时候, 我们如果使用消息队列来通知短信服务, 主流程就顺利进行下去, 就实现了完美的业务解耦.



### 2、一致性

所有跨VM的一致性问题，从技术角度来说，都只有强一致性（分布式事务）和最终一致性（记录、补偿）两种解决方案



比如经典的转账案例，就有可能有多种意外发生

1.A扣钱成功, B加钱失败
2.A扣钱成功, B加钱成功, 结果回传时网络异常
3.A扣钱成功, B加钱失败, A想回滚但是down机



##### 强一致性

分布式事务



##### 最终一致性

最终一致性的大多实现方式都属于 记录+补偿
在做不确定的事情之前，先记录下
不确定的事情成功完成之后，删除记录，否则由task补偿性地重新触发这件事，直到成功为止







比如转账的例子
1. A基于本地事务扣钱和记录“通知B”，失败就一起回滚，然后再RPC将这个通知落地到broker，成功才删除“通知B”这个记录，否则定时任务扫描重试
2. broker通知B(推送, 或者由B主动拉取)
3. consumer消费成功, 通知A才删除落地记录，否则重试



这个操作显然也可以由RPC来实现，但是如果将其抽象出来，就变成了Message Queue
通过消息的两次落地+补偿, 可以确保consumer一定收到消息. 当然, 这种方式不可避免需要提到去重的问题.







### 广播

从通知的语义来分析, 消息队列需要把消息通知到对应的目标, 常见的就是两种通知方式: 点对点, 广播.
点对点: 顾名思义, 只对目标推送消息, 这种应用场景极少, 就不细说了.
而广播则也是MQ的一大核心特点和优势，把消息队列中的所有消息推送给所有可接收消息的目标, 当新接入下游的时候，我们就只需要关注消息是否成功推送到了发送队列，而不用在乎哪些下游需要订阅
将对消息的依赖转移到了下游



我们还是用转账这个例子, 假设A扣钱之后, 原本只需要通知到转账业务, 为B加钱, 现在增加需求, 需要给A发送扣钱成功的短信. 那么我们只需要把这个短信业务注册为下游去消费消息就行了, 并不需要改动到上游或者消息队列.





但是广播也有一些问题, 现在大家的服务器都是集群了, 那么如何需要保证一个集群, 只有一个服务器收到消息并消费呢? 如何控制某台服务器一定要收到消息呢?
这一点, 在QMQ中, 通过Group的方式获得了解决.



1. Consumer以Group的方式注册
2. Broker向每个Group中选择一台服务器推送消息
3. Consumer希望保证收到消息, 可以在Group处留白, 默认注册为独一无二的group
   总结为一句话, 就是组内单播, 组间广播







### 错峰与流控

前端的最大QPS显然远远高于数据库的处理能力，MQ就可以扮演一个漏斗的角色
如果没有MQ，使用RPC来实现，就需要上游或者下游自己处理请求的存储、拥塞、定时等问题，而且每增加这么一组上下游处理能力有差距的服务，就需要单独开发一套逻辑, 而且上下游耦合太过严重
如果没有Broker, 转储和解耦更像是无稽之谈.

1. 我们需要broker来转储消息, 并在合适的时间, 投递给合适的Consumer
2. 我们需要把provider和consumer解耦, provider只需要把消息投递到消息队列, 完全不需要关注consumer的存在.




### 延时（缓冲处理）

当生产者发送消息的速度超过消费者处理消息的速度时，消息队列可以作为缓冲区，存储多余的消息，避免系统过载。

有些业务场景, 需要用到延时, 消息队列显然也是不错的选择
当然, 这也是Broker的一大作用.





## 消息队列的特点

#### 消息队列的本质

一次RPC变N次、 消息转储、 选择合适的时间投递

1. provider消息投递到broker
2. broker消息投递到consumer
3. consumer消费确认, 通知broker



#### 安全性

- 认证和授权：消息队列系统应该支持认证和授权机制，以防止未授权的访问和数据泄露。
- 消息加密：对于敏感数据，可以对消息进行加密，以保护数据的安全性。
- 消息审计：对消息的发送和接收进行审计，以追踪和监控消息传递的过程。











## 二、消息队列的消费场景

接下来对消息队列的实现如何满足几种消费场景进行简单阐述。



1、消息至多被消费一次
该场景是最容易满足的，特点是整个消息队列吞吐量大，实现简单。适合能容忍丢消息，消息重复消费的任务。

a）Producer发送消息到Message Broker阶段： Producer发消息给Message Broker，不要求Message Broker对接收到的消息响应确认，Producer也不用关心Message Broker是否收到消息了。
b）Message Broker存储/转发阶段： 对Message Broker的存储不要求持久性，转发消息时也不用关心Consumer是否真的收到了。
c）Consumer消费阶段： Consumer从Message Broker中获取到消息后，可以从Message Broker删除消息，或Message Broker在消息被Consumer拿去消费时删除消息，不用关心Consumer最后对消息的处理结果。

2、消息至少被消费一次
适合不能容忍丢消息，但允许重复消费的任务。

a）Producer发送消息到Message Broker阶段：
Producer发消息给Message Broker，Message Broker必须响应对消息的确认。
b）Message Broker存储/转发阶段：
Message Broker必须提供持久性保障，转发消息时，Message Broker需要Consumer通知删除消息，才能将消息删除。
c）Consumer消费阶段：
Consumer从Message Broker中获取到消息，必须在消费完成后，Message Broker上的消息才能被删除。

3、消息仅被消费一次
适合对消息消费情况要求非常高的任务，实现较为复杂，这里的“仅被消费一次”包含如下两种场景：

1）Message Broker上存储的消息被Consumer仅消费一次，场景要求：
a）Producer发送消息到Message Broker阶段： Producer发消息给Message Broker，不要求Message Broker对接收到的消息响应确认，Producer也不用关心Message Broker是否收到消息了。
b）Message Broker存储/转发阶段： Message Broker必须提供持久性保障，并且每条消息在其消费队列里有唯一标识（这个唯一标识可以由Producer产生，也可以由Message Broker产生）。
c）Consumer消费阶段： Consumer从Message Broker中获取到消息后，需要记录下消费的消息标识，以便在后续消费中防止对某个消息重复消费。比如Consumer获取到消息，消费完后，还没来得及从Message Broker删除消息，就挂了，这样Message Broker如果把消息重新加入待消费队列的话，那么这条消息就会被重复消费了。

2）Producer上产生的消息被Consumer仅消费一次，场景要求：
a）Producer发送消息到Message Broker阶段： Producer发消息给Message Broker，Message Broker必须响应对消息的确认，并且Producer负责为该消息产生唯一标识，以防止Consumer重复消费（因为Producer发消息给Message Broker后，由于网络问题没收到Message Broker的响应，可能会重发消息给到Message Broker）。
b）Message Broker存储/转发阶段： Message Broker必须提供持久性保障，并且每条消息在其消费队列里有唯一标识（这个唯一标识需要由Producer产生）。
c）Consumer消费阶段： Consumer从Message Broker中获取到消息后，需要记录下消费的消息标识，以便在后续消费中防止对某个消息重复消费。比如Consumer获取到消息，消费完后，还没来得及从Message Broker删除消息，就挂了，这样Message Broker如果把消息重新加入待消费队列的话，那么这条消息就会被重复消费了。

















## MessageQueue C++实现

以下是一个简单的 C++ 实现的消息队列（`MessageQueue`）示例。消息队列通常用于在多线程环境中实现线程间的通信，允许一个线程将消息放入队列，另一个线程从队列中取出消息进行处理。



收起



cpp









```cpp
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

// 定义消息类型
using Message = int;

// 消息队列类
class MessageQueue {
public:
    // 向队列中添加消息
    void enqueue(const Message& message) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(message);
        // 通知等待的线程有新消息可用
        cv_.notify_one();
    }

    // 从队列中取出消息
    Message dequeue() {
        std::unique_lock<std::mutex> lock(mutex_);
        // 等待直到队列中有消息
        cv_.wait(lock, [this] { return !queue_.empty(); });
        Message message = queue_.front();
        queue_.pop();
        return message;
    }

private:
    std::queue<Message> queue_;
    mutable std::mutex mutex_;
    std::condition_variable cv_;
};

// 生产者线程函数
void producer(MessageQueue& queue) {
    for (int i = 0; i < 5; ++i) {
        queue.enqueue(i);
        std::cout << "Produced: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

// 消费者线程函数
void consumer(MessageQueue& queue) {
    for (int i = 0; i < 5; ++i) {
        Message message = queue.dequeue();
        std::cout << "Consumed: " << message << std::endl;
    }
}

int main() {
    MessageQueue queue;

    // 创建生产者和消费者线程
    std::thread producerThread(producer, std::ref(queue));
    std::thread consumerThread(consumer, std::ref(queue));

    // 等待线程完成
    producerThread.join();
    consumerThread.join();

    return 0;
}
```

### 代码说明：



1. **`Message` 类型**：定义了消息的类型，这里使用 `int` 作为示例。

2. `MessageQueue` 类

   ：

   - `enqueue` 方法：用于向队列中添加消息。使用互斥锁 `std::mutex` 来保证线程安全，添加消息后使用 `std::condition_variable` 通知等待的线程。
   - `dequeue` 方法：用于从队列中取出消息。使用 `std::condition_variable` 的 `wait` 方法等待队列中有消息可用，避免忙等待。

3. **`producer` 函数**：模拟生产者线程，向消息队列中添加 5 条消息，并在每次添加后打印消息。

4. **`consumer` 函数**：模拟消费者线程，从消息队列中取出 5 条消息，并在每次取出后打印消息。

5. **`main` 函数**：创建 `MessageQueue` 对象，启动生产者和消费者线程，并等待它们完成。

### 编译和运行：



将上述代码保存为 `message_queue.cpp`，然后使用以下命令编译和运行：



收起



sh









```sh
g++ -std=c++11 -pthread message_queue.cpp -o message_queue
./message_queue
```



这样就可以看到生产者和消费者线程之间的消息传递过程。

在多线程环境中，使用消息队列有哪些注意事项？

在多线程环境中使用消息队列时，需要考虑以下几个重要的注意事项：

### 线程安全



- 互斥访问

  ：

  - 消息队列通常会被多个线程同时访问，一个线程可能在添加消息（入队操作），而另一个线程可能在取出消息（出队操作）。因此，必须使用同步机制（如互斥锁 `std::mutex`）来保护对队列的访问，防止多个线程同时修改队列结构导致数据不一致或竞态条件。
  - 例如，在 C++ 中实现的消息队列，入队和出队操作都需要加锁，以确保同一时间只有一个线程可以对队列进行操作。



收起



cpp









```cpp
#include <queue>
#include <mutex>

template<typename T>
class MessageQueue {
private:
    std::queue<T> queue_;
    std::mutex mutex_;
public:
    void enqueue(const T& item) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(item);
    }

    T dequeue() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T item = queue_.front();
        queue_.pop();
        return item;
    }
};
```



- 死锁避免

  ：

  - 在使用多个锁时，要注意避免死锁的发生。死锁通常是由于线程以不同的顺序获取锁导致的。例如，如果一个线程先获取锁 A 再获取锁 B，而另一个线程先获取锁 B 再获取锁 A，就可能发生死锁。
  - 可以通过规定锁的获取顺序、使用锁的超时机制等方法来避免死锁。

### 等待和通知机制



- 条件变量的使用

  ：

  - 当队列为空时，消费者线程需要等待新消息的到来；当队列满时，生产者线程需要等待队列有空间。可以使用条件变量（如 `std::condition_variable`）来实现线程的等待和通知机制。
  - 条件变量可以避免线程的忙等待，提高效率。例如，消费者线程在队列为空时调用 `wait` 方法进入等待状态，当生产者线程添加新消息后，调用 `notify_one` 或 `notify_all` 方法唤醒等待的消费者线程。



收起



cpp









```cpp
#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class MessageQueue {
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
public:
    void enqueue(const T& item) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.push(item);
        }
        cv_.notify_one();
    }

    T dequeue() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return !queue_.empty(); });
        T item = queue_.front();
        queue_.pop();
        return item;
    }
};
```

### 队列容量限制



- 避免无限增长

  ：

  - 如果消息队列没有容量限制，可能会导致内存使用无限增长，最终耗尽系统资源。因此，在设计消息队列时，需要考虑设置队列的最大容量。
  - 当队列达到最大容量时，生产者线程需要等待队列有空间才能继续添加消息。可以在消息队列类中添加一个容量限制的成员变量，并在入队操作时进行检查。



收起



cpp









```cpp
#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class MessageQueue {
private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cv_;
    size_t max_size_;
public:
    MessageQueue(size_t max_size) : max_size_(max_size) {}

    void enqueue(const T& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return queue_.size() < max_size_; });
        queue_.push(item);
        cv_.notify_one();
    }

    T dequeue() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return !queue_.empty(); });
        T item = queue_.front();
        queue_.pop();
        cv_.notify_one();
        return item;
    }
};
```

### 消息处理和异常处理



- 消息处理逻辑

  ：

  - 消费者线程在处理消息时，要确保消息处理逻辑的正确性和稳定性。如果消息处理过程中出现异常，要进行适当的异常处理，避免线程崩溃导致整个系统出现问题。
  - 可以使用 `try-catch` 块来捕获和处理异常，并记录错误信息。

- 资源管理

  ：

  - 如果消息包含动态分配的资源（如内存、文件句柄等），要确保在消息处理完成后正确释放这些资源，避免内存泄漏或资源泄漏。

### 线程退出和清理



- 优雅退出

  ：

  - 在程序结束或线程需要退出时，要确保消息队列能够优雅地关闭。可以使用特殊的消息（如退出信号）来通知消费者线程停止工作。
  - 同时，要确保所有等待的线程能够被正确唤醒，避免出现线程一直等待的情况。

- 资源清理

  ：

  - 在消息队列不再使用时，要清理队列中的所有消息，并释放相关的资源（如锁、条件变量等）。



分享



入队和出队操作的加锁顺序是否有要求？

除了互斥锁，还有哪些同步机制可以用于消息队列？

在多线程环境中使用消息队列时，如何避免死锁？





AI 编程



粘贴代码或描述你的问题﻿

代码文件

GitHub 仓库





![img](https://lf-flow-web-cdn.doubao.com/obj/flow-doubao/samantha/logo-icon-white-bg.png)

豆包





新对话



[AI 搜索](https://www.doubao.com/chat/search)

[帮我写作](https://www.doubao.com/chat/write)

[图像生成](https://www.doubao.com/chat/create-image)

[AI 阅读](https://www.doubao.com/chat/chat-with-doc)

[AI 编程](https://www.doubao.com/chat/coding)



语音通话

新

[AI 看网站有更新](https://www.doubao.com/chat/pc-ai-guidance)

[AI 智能体](https://www.doubao.com/chat/bot/discover)



书签





![img](https://www.doubao.com/client-local-file/process_icon/294946f4f91baccaecf91d6e3876e487.png)

Marscode

![img](https://www.doubao.com/client-local-file/process_icon/294946f4f91baccaecf91d6e3876e487.png)

知乎

![img](https://www.doubao.com/client-local-file/process_icon/294946f4f91baccaecf91d6e3876e487.png)

抖音

![img](https://www.doubao.com/client-local-file/process_icon/294946f4f91baccaecf91d6e3876e487.png)

番茄小说

![img](https://www.doubao.com/client-local-file/process_icon/294946f4f91baccaecf91d6e3876e487.png)

即梦 AI绘画

![img](https://www.doubao.com/client-local-file/process_icon/294946f4f91baccaecf91d6e3876e487.png)

BiliBili

![img](https://www.doubao.com/client-local-file/process_icon/294946f4f91baccaecf91d6e3876e487.png)

今日头条

[AI 云盘](https://www.doubao.com/chat/drive/)

历史对话

[![豆包](https://lf-flow-web-cdn.doubao.com/obj/flow-doubao/doubao/web/static/image/overall-thread.f8994bd4.png)C++实现消息队列](https://www.doubao.com/chat/1339977683723010)

[![豆包](https://lf-flow-web-cdn.doubao.com/obj/flow-doubao/doubao/web/static/image/overall-thread.f8994bd4.png)解释 VM 的含义](https://www.doubao.com/chat/1320636021385474)

[![豆包](https://lf-flow-web-cdn.doubao.com/obj/flow-doubao/doubao/web/static/image/overall-thread.f8994bd4.png)C++ 内存释放](https://www.doubao.com/chat/1320397584133890)

[![豆包](https://lf-flow-web-cdn.doubao.com/obj/flow-doubao/doubao/web/static/image/overall-thread.f8994bd4.png)Windows 下 SSH 连接 GitHub 失败](https://www.doubao.com/chat/1273558473838594)

[![豆包](https://lf-flow-web-cdn.doubao.com/obj/flow-doubao/doubao/web/static/image/overall-mobile.04d64249.png)手机版对话](https://www.doubao.com/chat/1012605143433218)

[查看全部](https://www.doubao.com/chat/thread/list)



































































# 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
一、https://blog.csdn.net/dingguohang/article/details/54862134

二、https://blog.csdn.net/qq_29229567/article/details/86490519

https://blog.csdn.net/weixin_63490470/article/details/141157896



https://blog.csdn.net/qq_43513394/article/details/132378013



https://blog.csdn.net/D1842501760/article/details/123142298



https://mp.weixin.qq.com/s/dyliEQffLQthWt1cJFLT3Q



https://mp.weixin.qq.com/s/tbJ2lCDYLMzh00fffcTQyg







https://mp.weixin.qq.com/s/6_IW6twz2RWNjvnP81y0rQ



https://mp.weixin.qq.com/s/qEd7DBDqi2pYeL-OG3U7Rw



https://mp.weixin.qq.com/s/og53vJtj400GM8rATPrMaw



https://blog.csdn.net/suixin______/article/details/117785821













---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
---
