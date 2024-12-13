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



# 04_C++_unique_lock


## unique_lock介绍

unique_lock取代lock_guard，unique_lock更像lock_guard的升级版，也是mutex的管家！

unique_lock是个类模板，工作中一般使用lock_guard（推荐使用）

lock_guard取代了mutex的lock()和unlock()
unique_lock比lock_guard灵活很多，效率差一点，内存占用多一点

lock_guard额外参数只能传入std::adopt_lock
unique_lock额外参数可以传入std::adopt_lock、std::try_to_lock、std::defer_lock…
额外参数的解释

- std::adopt_lock：标记作用，通知lock_guard或unique_lock不需要再构造函数中lock()，标记的效果就是“假设调用方线程已经拥有了互斥的所有权（已经lock()成功了）”
- std::try_to_lock：尝试获取锁，如果获取失败将不会阻塞在锁头上，会继续向下执行
- std::defer_lock：初始化一个没有加锁的mutex








# 六、总结

以上就是今天要讲的内容，本文仅仅简单介绍了lwIP的官网主页，后续会有更多内容。



# 七、参考资料

版权声明：本文参考了其他资料和CSDN博主的文章，遵循CC 4.0 BY-SA版权协议，现附上原文出处链接及本声明。
一、 https://blog.csdn.net/weixin_43808717/article/details/137182111
二、 
三、 





^v100^pc_search_result_base4&utm_term=lock_guard&spm=1018.2226.3001.4187



版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
本文链接：https://blog.csdn.net/weixin_45030965/article/details/130762686
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/weixin_45030965/article/details/130762686













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
