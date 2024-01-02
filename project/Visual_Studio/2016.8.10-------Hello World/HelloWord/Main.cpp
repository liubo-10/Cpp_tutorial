/*这两个根本不是同一样东西比如你用了#include<iostream.h>，
后面代码直接可以用这个头文件里定义的东西了，例如 cout之类的
但是 using namespace std，表示使用 std 名字空间的东西，你如果加了 #include<iostream>，
才可以使用 cout,如果不用using namespace std的情况下用 #include<iostream>，
还是不能直接使用cout;而是要用std;cout才能使用
跟<iostream.h>跟<iostream>其实是对应的，
只不过<iostream>是把<iostream.h>里面的东西封装到std名字空间去了，
你应该去看一看为什么要有名字空间
#include<iostream.h>//C的头文件
#include<iostream>//C++的头文件
using namespace std;//使用命名空间*/

#include<iostream>
using namespace std;
#include<process.h>//引入头文件system("pause")


int main()
{
	cout<<"Hello World"<<endl;
	system("pause");//暂停往下执行 按下任意键继续
	return 0;
}