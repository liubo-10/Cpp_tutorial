* 👋 Hi, I’m liubo
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...



# 观察者模式（Observer Pattern）



## 背景

设计模式并非是软件开发的专业术语，实际上，“模式”最早诞生于建筑学。

设计模式的定义是：在面向对象软件设计过程中针对特定问题的简洁而优雅的解决方案。通俗一点说，设计模式是在某种场合下对某个问题的一种解决方案。如果再通俗一点说，设计模式就是给面向对象软件开发中的一些好的设计取个名字。

这些“好的设计”并不是谁发明的，而是早已存在于软件开发中。一个稍有经验的程序员也许在不知不觉中数次使用过这些设计模式。GoF（Gang of Four–四人组，《设计模式》几位作者）最大的功绩是把这些“好的设计”从浩瀚的面向对象世界中挑选出来，并且给予它们一个好听又好记的名字。

设计模式并不直接用来完成代码的编写，而是描述在各种不同情况下，要怎么解决问题的一种方案，他不是一个死的机制，他是一种思想，一种写代码的形式。每种语言对于各种设计模式都有他们自己的实现方式，对于某些设计模式来说，可能在某些语言下并不适用，比如工厂方法模式对于javascript。模式应该用在正确的地方。而哪些才算正确的地方，只有在我们深刻理解了模式的意图之后，再结合项目的实际场景才会知道。

模式的社区一直在发展。GoF在1995年提出了23种设计模式，但模式不仅仅局限于这23种，后面增加到了24种。在这20多年的时间里，也许有更多的模式已经被人发现并总结了出来，比如一些JavaScript 图书中会提到模块模式、沙箱模式等。这些“模式”能否被世人公认并流传下来，还有待时间验证。



## 观察者模式（Observer Pattern）

观察者模式定义了对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都将得到通知，并自动更新。观察者模式属于行为型模式，行为型模式关注的是对象之间的通讯，观察者模式就是观察者和被观察者之间的通讯。

观察者模式有一个别名叫“发布-订阅模式”，或者说是“订阅-发布模式”，订阅者和订阅目标是联系在一起的，当订阅目标发生改变时，逐个通知订阅者。我们可以用报纸期刊的订阅来形象的说明，当你订阅了一份报纸，每天都会有一份最新的报纸送到你手上，有多少人订阅报纸，报社就会发多少份报纸，报社和订报纸的客户就是上面文章开头所说的“一对多”的依赖关系。



## 发布订阅模式（Pub-Sub Pattern）

其实24种基本的设计模式中并没有发布订阅模式，上面也说了，他只是观察者模式的一个别称。

但是经过时间的沉淀，似乎他已经强大了起来，已经独立于观察者模式，成为另外一种不同的设计模式。

在现在的发布订阅模式中，称为发布者的消息发送者不会将消息直接发送给订阅者，这意味着发布者和订阅者不知道彼此的存在。在发布者和订阅者之间存在第三个组件，称为消息代理或调度中心或中间件，它维持着发布者和订阅者之间的联系，过滤所有发布者传入的消息并相应地分发它们给订阅者。

举一个例子，你在微博上关注了A，同时其他很多人也关注了A，那么当A发布动态的时候，微博就会为你们推送这条动态。A就是发布者，你是订阅者，微博就是调度中心，你和A是没有直接的消息往来的，全是通过微博来协调的（你的关注，A的发布动态）。






## 观察者模式和发布订阅模式有什么区别？

我们先来看下这两个模式的实现结构：

<img src="/home/liubo/00-liubo/learning/Cpp_tutorial/picture/观察者模式和发布订阅模式.png" style="zoom:150%;" /> 



观察者模式： 观察者（Observer）直接订阅（Subscribe）主题（Subject），而当主题被激活的时候，会触发（Fire Event）观察者里的事件。

发布订阅模式： 订阅者（Subscriber）把自己想订阅的事件注册（Subscribe）到调度中心（Topic），当发布者（Publisher）发布该事件（Publish topic）到调度中心，也就是该事件触发时，由调度中心统一调度（Fire Event）订阅者注册到调度中心的处理代码。

我们再来看下这两个模式的代码案例：（猎人发布与订阅任务）


观察者模式：

观察者模式和发布订阅模式最大的区别就是发布订阅模式有个事件调度中心。

观察者模式由具体目标调度，每个被订阅的目标里面都需要有对观察者的处理，这种处理方式比较直接粗暴，但是会造成代码的冗余。

而发布订阅模式中统一由调度中心进行处理，订阅者和发布者互不干扰，消除了发布者和订阅者之间的依赖。这样一方面实现了解耦，还有就是可以实现更细粒度的一些控制。比如发布者发布了很多消息，但是不想所有的订阅者都接收到，就可以在调度中心做一些处理，类似于权限控制之类的。还可以做一些节流操作。
观察者模式是不是发布订阅模式

网上关于这个问题的回答，出现了两极分化，有认为发布订阅模式就是观察者模式的，也有认为观察者模式和发布订阅模式是真不一样的。

其实我不知道发布订阅模式是不是观察者模式，就像我不知道辨别模式的关键是设计意图还是设计结构（理念），虽然《JavaScript设计模式与开发实践》一书中说了分辨模式的关键是意图而不是结构。

如果以结构来分辨模式，发布订阅模式相比观察者模式多了一个中间件订阅器，所以发布订阅模式是不同于观察者模式的；如果以意图来分辨模式，他们都是实现了对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都将得到通知，并自动更新，那么他们就是同一种模式，发布订阅模式是在观察者模式的基础上做的优化升级。

不过，不管他们是不是同一个设计模式，他们的实现方式确实有差别，我们在使用的时候应该根据场景来判断选择哪个。








#### **1、观察者模式**

观察者模式定义了对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都将得到通知，并自动更新。观察者模式属于行为型模式，行为型模式关注的是对象之间的通讯，观察者模式就是观察者和被观察者之间的通讯。

观察者模式有一个别名叫“发布-订阅模式”，或者说是“订阅-发布模式”，订阅者和订阅目标是联系在一起的，当订阅目标发生改变时，逐个通知订阅者。我们可以用报纸期刊的订阅来形象的说明，当你订阅了一份报纸，每天都会有一份最新的报纸送到你手上，有多少人订阅报纸，报社就会发多少份报纸，报社和订报纸的客户就是上面文章开头所说的“一对多”的依赖关系。







#### **2、订阅-发布模式**

其实24种基本的设计模式中并没有发布订阅模式，上面也说了，他只是观察者模式的一个别称。

但是经过时间的沉淀，似乎他已经强大了起来，已经独立于观察者模式，成为另外一种不同的设计模式。

在现在的发布订阅模式中，称为发布者的消息发送者不会将消息直接发送给订阅者，这意味着发布者和订阅者不知道彼此的存在。在发布者和订阅者之间存在第三个组件，称为调度中心或事件通道，它维持着发布者和订阅者之间的联系，过滤所有发布者传入的消息并相应地分发它们给订阅者。

举一个例子，你在微博上关注了A，同时其他很多人也关注了A，那么当A发布动态的时候，微博就会为你们推送这条动态。A就是发布者，你是订阅者，微博就是调度中心，你和A是没有直接的消息往来的，全是通过微博来协调的（你的关注，A的发布动态）。







#### **3、两种模式的区别**

我们先来看下这两个模式的实现结构：

<img src="https://img2018.cnblogs.com/blog/849589/201904/849589-20190424122505055-2083728728.png" alt="img" style="zoom:150%;" />

可以看出，发布订阅模式相比观察者模式多了个事件通道，事件通道作为调度中心，管理事件的订阅和发布工作，彻底隔绝了订阅者和发布者的依赖关系。即订阅者在订阅事件的时候，只关注事件本身，而不关心谁会发布这个事件；发布者在发布事件的时候，只关注事件本身，而不关心谁订阅了这个事件。

观察者模式有两个重要的角色，即目标和观察者。在目标和观察者之间是没有事件通道的。一方面，观察者要想订阅目标事件，由于没有事件通道，因此必须将自己添加到目标(Subject) 中进行管理；另一方面，目标在触发事件的时候，也无法将通知操作(notify) 委托给事件通道，因此只能亲自去通知所有的观察者。

我们再来看一下这两个模式的代码实现：

















观察者模式（Observer Pattern）和发布-订阅模式（Publish-Subscribe Pattern）都是用于处理对象之间的一对多依赖关系，但它们在实现方式和应用场景上有一些异同。

观察者模式：

观察者模式定义了一种一对多的依赖关系，使得当一个对象的状态发生变化时，其所有依赖对象都会得到通知并自动更新。在观察者模式中，有以下角色：

    主题（Subject）： 也称为被观察者，负责维护一组观察者对象并通知它们状态的变化。
    观察者（Observer）： 定义一个更新接口，用于接收主题通知的变化。
    具体主题（Concrete Subject）： 实现主题接口，维护观察者列表并通知它们状态的变化。
    具体观察者（Concrete Observer）： 实现观察者接口，具体的观察者对象，接收主题的通知并进行相应的更新。






发布-订阅模式：

发布-订阅模式也是一种一对多的依赖关系，但是它通过一个消息通道来实现，消息的发布者将消息发布到通道中，订阅者从通道中订阅消息。在发布-订阅模式中，有以下角色：

    消息通道（Message Channel）： 用于发布者发布消息和订阅者订阅消息的中介。
    发布者（Publisher）： 负责发布消息到消息通道。
    订阅者（Subscriber）： 订阅感兴趣的消息类型，并从消息通道中接收相应的消息。

异同点：

    实现方式： 观察者模式通常是面向对象的，主题和观察者之间直接交互。而发布-订阅模式使用中介（消息通道）来进行消息的发布和订阅，发布者和订阅者之间没有直接的耦合关系。
    通信方式： 观察者模式中主题主动通知观察者，而发布-订阅模式中发布者和订阅者之间通过消息通道进行通信。
    灵活性： 发布-订阅模式更具有灵活性，可以支持多对多的关系，而观察者模式通常是一对多的关系。






使用情况：

    观察者模式： 当一个对象的状态变化需要通知多个依赖对象，并且对象之间有一定的关联时，可以使用观察者模式。例如，GUI界面组件的事件处理、数据模型和视图之间的同步等情况。
    发布-订阅模式： 当存在一个复杂的消息通信网络，多个发布者和多个订阅者之间需要进行灵活的消息交互时，可以使用发布-订阅模式。例如，分布式系统中的事件通知、消息队列等情况。

总之，观察者模式和发布-订阅模式都用于处理对象之间的一对多依赖关系，但它们在通信方式、实现方式和适用场景上有所不同。选择合适的模式取决于系统的需求和结构。






Observer 模式(观察者模式)

Observer 模式要解决的问题为：建立一个一（Subject）对多（Observer）的依赖关系，并且做到当“一”变化的时候，依赖这个“一”的多也能够同步改变。最常见的一个例子就是：对同一组数据进行统计分析时候，我们希望能够提供多种形式的表示（例如以表格进行统计显示、柱状图统计显示、百分比统计显示等）。指多个对象间存在一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。

举例：
Subject 提供依赖于它的观察者 Observer 的注册（registerObserver）和注销（remove）操作，并且提供了使得依赖于它的所有观察者同步的操作（notifyObserver），观察者 Observer 则提供一个 Update 操作，注意这里的 Observer 的 Update 操作并不在 Observer 改变了 Subject 目标状态的时候就对自己进行更新，这个更新操作要延迟到 Subject 对象发出 Notify 通知所有Observer 进行修改（调用 Update）。





```C++


#include <iostream>
#include <list>
using namespace std;

//抽象的英雄 抽象的观察者  Observer
class AbstractHero {
public:
    virtual void Update() = 0;
};

//具体的英雄 具体的观察者 
class HeroA :public AbstractHero {
public:
    HeroA() {
        cout << "英雄A正在鲁BOSS" << endl;
    }
    virtual void Update() {
        cout << "英雄A停止撸，待机状态" << endl;
    }
};

class HeroB :public AbstractHero {
public:
    HeroB() {
        cout << "英雄B正在鲁BOSS" << endl;
    }
    virtual void Update() {
        cout << "英雄B停止撸，待机状态" << endl;
    }

};

class HeroC :public AbstractHero {
public:
    HeroC() {
        cout << "英雄C正在鲁BOSS" << endl;
    }
    virtual void Update() {
        cout << "英雄C停止撸，待机状态" << endl;
    }
};

class HeroD :public AbstractHero {
public:
    HeroD() {
        cout << "英雄D正在鲁BOSS" << endl;
    }
    virtual void Update() {
        cout << "英雄D停止撸，待机状态" << endl;
    }
};

class HeroE :public AbstractHero {
public:
    HeroE() {
        cout << "英雄E正在鲁BOSS" << endl;
    }
    virtual void Update() {
        cout << "英雄E停止撸，待机状态" << endl;
    }
};

//定义抽象的观察目标  Subject
class AbstractBoss {
public:
    //    添加观察者
    virtual void addHero(AbstractHero* hero) = 0;
    //    删除观察者
    virtual void deleteHero(AbstractHero* hero) = 0;
    //    通知所有观察者
    virtual void notifv() = 0;
};

//相对于 concreteSubject
class BOSSA :public AbstractBoss {
public:
    //    添加观察者
    virtual void addHero(AbstractHero* hero) {
        pHeroList.push_back(hero);
    }
    //    删除观察者
    virtual void deleteHero(AbstractHero* hero) {
        pHeroList.remove(hero);
    }
    //    通知所有观察者
    virtual void notifv() {
        for (list<AbstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end(); it++) {
            (*it)->Update();
        }
    }





    list<AbstractHero*> pHeroList;

};

void test01() {
    //    创建观察者
    AbstractHero* heroA = new HeroA;
    AbstractHero* heroB = new HeroB;
    AbstractHero* heroC = new HeroC;
    AbstractHero* heroD = new HeroD;
    AbstractHero* heroE = new HeroE;

    //    创建观察目标
    AbstractBoss* bossA = new BOSSA;
    bossA->addHero(heroA);
    bossA->addHero(heroB);
    bossA->addHero(heroC);
    bossA->addHero(heroD);
    bossA->addHero(heroE);
    
    cout << "heroC阵亡" << endl;
    bossA->deleteHero(heroC);
    
    cout << "Boss死了，通知其他英雄停止攻击。。。" << endl;
    bossA->notifv();

}

int main() {

    test01();
    return 0;

}


```

















八、观察者模式

行为型模式：主要关注的是对象之间的通信

观察者-监听者模式（发布-订阅模式）设计模式：主要关注的是对象的一对多的关系，也就是多个对象都依赖一个对象，当该对象的状态发生改变是，其他对象都能够接收到相应通知。

比如有一组数据，生成一个数据对象，通过这一组数据可以生成曲线图（对象1）/柱状图（对象2）/圆饼图（对象3），当数据对象发生改变时，对象1、对象2、对象3应该及时的收到相应的通知！

三个观察者








```c++



#include<iostream>
#include<string>
#include<unordered_map>
#include<list>
using namespace std;

/*
Observer1、Observer2、Observer3
Subject（主题)主题有更改，应该及时通知相应的观察者，去处理相应的事件
*/

//观察者抽象类
class Observer
{
public:
	//处理消息的接口
	virtual void handle(int msgid) = 0;
};

//第一个观察者实例
class Observer1 :public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid)
		{
		case 1:
			cout << "Observer1 recv 1 msg!" << endl;
			break;
		case 2:
			cout << "Observer1 recv 2 msg!" << endl;
			break;
		default:
			cout << "Observer1 recv unknow msg!" << endl;
			break;
		}
	}
};
//第二个观察者实例
class Observer2 :public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid)
		{
		case 2:
			cout << "Observer2 recv 2 msg!" << endl;
			break;
		default:
			cout << "Observer2 recv unknow msg!" << endl;
			break;
		}
	}
};
//第三个观察者实例
class Observer3 :public Observer
{
public:
	void handle(int msgid)
	{
		switch (msgid)
		{
		case 1:
			cout << "Observer3 recv 1 msg!" << endl;
			break;
		case 3:
			cout << "Observer3 recv 3 msg!" << endl;
			break;
		default:
			cout << "Observer3 recv unknow msg!" << endl;
			break;
		}
	}
};



```

















```c++
//主题类
class Subject
{
public:
	void addObserver(Observer* obser, int msgid)
	{
		_subMap[msgid].push_back(obser);
		/*
		auto it = _subMap.find(msgid);
		if (it != _subMap.end())
		{
			it->second.push_back(obser);
		}
		else
		{
			list<Observer*> lis;
			lis.push_back(obser);
			_subMap.insert({ msgid,lis });
		}
		*/
	}
	//主题检测发生改变，通知相应的观察者对象处理事件
	void dispatch(int msgid)
	{
		auto it = _subMap.find(msgid);
		if (it != _subMap.end())
		{
			for (Observer* pObser : it->second)
			{
				pObser->handle(msgid);
			}
		}
	}
private:
	unordered_map<int, list<Observer*>> _subMap;
};

```









```c++
int main()
{
	Subject subject;
	Observer* p1 = new Observer1();
	Observer* p2 = new Observer2();
	Observer* p3 = new Observer3();

	subject.addObserver(p1, 1);
	subject.addObserver(p1, 2);
	subject.addObserver(p2, 2);
	subject.addObserver(p3, 1);
	subject.addObserver(p3, 3);

	int msgid = 0;
	for (;;)
	{
		cout << "输入消息id:";
		cin >> msgid;
		if (msgid == -1)
			break;
		subject.dispatch(msgid);
	}


	return 0;
}

```













```c++
/*
订阅:
on(type,handler)：监听event事件，事件触发时调用fn函数；
发布:
emit(type,arg1,arg2,arg3...)：触发event事件，并把参数arg1,arg2,arg3....传给事件处理函数；

once(type,handler)：为指定事件注册一个单次监听器，单次监听器最多只触发一次，触发后立即解除监听器；
off(type,handler)：停止监听某个事件。
*/
class EventEmitter {
  constructor() {
    // 用来存放 订阅 和 发布的关系的
    this.eventMap = {};
  }

  // type 这里就代表事件的名称
  on(type, handler) {
    // 判断 handler 的实例 是不是一个函数
    if (!(handler instanceof Function)) {
      throw new Error("请传入一个函数");
    }
    // 判断 eventMap 中是否有这个类型
    if (!this.eventMap[type]) {
      // 若不存在，新建该队列
      this.eventMap[type] = [];
    }
    // 若存在，直接往队列里推入 handler
    this.eventMap[type].push(handler);
  }

  //向上派发 消息出去
  emit(type, ...params) {
    // 假设该事件是有订阅的（对应的事件队列存在）
    if (this.eventMap[type]) {
      // 将事件队列里的 handler 依次执行出队
      this.eventMap[type].forEach((handler, index) => {
        // 这里携带参数, 触发on方法的handler 回调
        handler(...params);
      });
    }
  }

  // 用来 卸载掉 不用监听的方法
  off(type, handler) {
    if (this.eventMap[type]) {
      this.eventMap[type].splice(this.eventMap[type].findIndex(handler), 1);
    }
  }

  once(type, handler) {
    let wrapFunc = (...args) => {
      handler.apply(this, args);
      this.off(type, wrapFunc);
    }
    this.on(type, wrapFunc);
    // return this;
  }
}

const event1 = new EventEmitter();
// 编写一个简单的 handler
const testHandler = function (params1, params2) {
  console.log(`test被触发了，参数值1是${params1},参数2是${params2}`);
};

const onceHandler = function(params) {
  console.log(`Once的参数是:${params}`);
}

// 监听事件
event1.on("test", testHandler);
event1.once("once1", onceHandler);

// 在触发事件的同时，传入希望 testHandler 感知的参数
event1.emit("test", "小红", "小黑");
event1.emit("once1","xiaoming");

```















https://blog.csdn.net/weixin_68266812/article/details/136182188?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EYuanLiJiHua%7EPosition-2-136182188-blog-128379200.235%5Ev43%5Econtrol&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EYuanLiJiHua%7EPosition-2-136182188-blog-128379200.235%5Ev43%5Econtrol&utm_relevant_index=5





















——————————————————

版权声明：

本文引用了博主原创文章，著作权归作者所有。遵循 CC 4.0 BY-SA 版权协议，商业转载请联系作者获得授权，非商业转载请附上原文出处链接和本声明。

本文是学习笔记，如有侵权，请联系删除。

参考：

链接：https://blog.csdn.net/hf872914334/article/details/88899326

链接：https://blog.csdn.net/weixin_43310500/article/details/135966999

链接：https://blog.csdn.net/weixin_45712636/article/details/124328504

链接：https://blog.csdn.net/qq_41721746/article/details/120448698












































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













  