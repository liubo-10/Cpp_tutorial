# lambda note

* 👋 Hi, I’m bliu2-10
* 👀 I’m interested in harmony
* 🌱 I’m currently learning harmony
* 💞️ I’m looking to collaborate on ...
* 📫 How to reach me ...











# C++知识点总结

## c++中如何读入回车符

有如下两种方式可以使用：

1 用cin.get()

由于cin的>>重载会跳过空白字符，包括回车符，所以无法用>>直接读入回车符。

可以用cin.get()，该成员函数功能为，从cin中读入一个字符，并返回。于是char c = cin.get(); 就是读入一个任意字符，同样可以读入回车符。

2 用getchar()。

C++完美兼容了C中的所有库函数，所以在C语言中用来从输入缓冲中读入一个字符的函数getchar，在C++中也是可以使用的。形式为

char c = getchar();

要使用getchar函数，需要引用头文件stdio.h,不过在C++中，使用cstdio效率更高。
































































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