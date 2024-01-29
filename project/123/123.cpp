

/* Note:Your choice is C IDE */
#include <iostream>
using namespace std;
float &fn2(float r)
{
   float t;
   t=3.14*r*r;
   return t;	
}
void main()
{
 fn2(5.0)=12.4;
 cout<<fn2(5.0)<<endl;   
}




/* Note:Your choice is C IDE */
#include <iostream>
#include <string>
using namespace std;
void main()
{
  string s,t; 
  cout<<"please input a zifuchuan:"<<endl;
  cin>>s;
  t="I like programming!"; 
  cout<<"zifuchuan output:"<<endl<<s<<endl<<t<<endl;
  cout<<s.append(" OK!")<<endl;
}




/* Note:Your choice is C IDE */
#include <iostream>
using namespace std;
inline double circumference(double radius);
void main()
{
  double r=3.0,s;
  s=circumference(r);
  cout<<"the circumference is "<<s<<"."<<endl;  
}
inline double circumference(double radius)
{
   return 2*3.1415926*radius;	
}



/* Note:Your choice is C IDE */
#include <iostream.h>
int add(int x,int y)
{
  int sum;
  sum=x+y;
  return sum;	
}
int add(int x,int y,int z)
{
  int sum;
  sum=x+y+z;
  return sum;	
}
void main()
{
  int a,b;
  a=add(5,10);
  b=add(5,10,20);
  cout<<"a="<<a<<endl;
   cout<<"b="<<b<<endl;
    
}




/* Note:Your choice is C IDE */
#include <iostream.h>
template<class T>
T min(T a[],int n)
  {
     int i;
     T minv=a[0];
       for(i=1;i<n;i++)
          if(minv>a[i])
              minv=a[i];
     return minv;	
  }
void main()
{
  int a[]={1,3,0,2,7,6,4,5,2};
  double b[]={1.2,-3.4,6.8,9.8};
  int c[]={1,9,5,-6,7,8};
  cout<<"a de shuzu zhong min zhi wei:"<<min(a,9)<<endl; 
  cout<<"b de shuzu zhong min zhi wei:"<<min(b,4)<<endl; 
  cout<<"c de shuzu zhong min zhi wei:"<<min(c,6)<<endl; 
}




/* Note:Your choice is C IDE */
#include <iostream.h>
#define PI 3.1415926535
#define CS Circle_Square
template<class T>
double Circle_Square(T x)
{
   return x*x*PI;	
}
double Circle_Square(long x)
{
   return x*x*PI;	
}
void main()
{
  int      r1=1;
  double   r2=2.0;
  long     r3=3;
  cout<<"The first cs is "<<CS(r1)<<endl; 
  cout<<"The second cs is "<<CS(r2)<<endl; 
  cout<<"The third cs is "<<CS(r3)<<endl; 
}






/* Note:Your choice is C IDE */
#include <iostream.h>
void main()
{
  int i=0,&l=i,&k=l;
  i=++l-k;
  cout<<"i="<<i<<endl;  
}



/* Note:Your choice is C IDE */
#include <iostream.h>
class Tdate
{
	public:
	void set(int,int,int);
	int isLeapYear();
	void print();
	private:
	int month;
	int day;
	int year;
};
void Tdate::set(int m,int d,int y)
{
   month=m;day=d;year=y;	
}
int Tdate::isLeapYear()
{
    return((year%4==0&&year%100!=0)||(year%400==0));
}
void Tdate::print()
{
   cout<<month<<"/"<<day<<"/"<<year<<endl;
   cout<<isLeapYear()<<endl;
}
void main()
{
 Tdate x;
 x.set(10,23,2000);
 x.isLeapYear();
 x.print();   
}


/* Note:Your choice is C IDE */
#include <iostream.h>
class Tdate
{
	public:
	void set(int,int,int);
	int isLeapYear();
	void print();
	private:
	int month;
	int day;
	int year;
	};
void Tdate::set(int m,int d,int y)
{
   month=m;day=d;year=y;	
}
int Tdate::isLeapYear()
{
    return((year%4==0&&year%100!=0)||(year%400==0));
}
void Tdate::print()
{
  cout<<year<<"/"<<month<<"/"<<day<<endl;
}
void someFunc(Tdate& refs)
{
   refs.print();
   if(refs.isLeapYear())
   	cout<<"error"<<endl;
   	else
   	 cout<<"right"<<endl;
}
void main()
{
  Tdate s,*pTdate=&s;
  s.set(2,15,1998);
  pTdate->print();
  if((*pTdate).isLeapYear())
  cout<<"error"<<endl;
  else

  cout<<"right"<<endl;
  someFunc(s); 
}



#include<iostream>
using namespace std;
void sphere();
int main()
{
  sphere();	
}
void sphere()
{
   double radius;
   cout<<"please input radius:";
   cin>>radius;
   if(radius<0) return;
   cout<<"the result is "<<radius*radius*3.14*4<<"\n";	
}





/* Note:Your choice is C IDE */
#include<iostream.h>
const int SIZE=10;
class Cstack
{
    private:
      char stk[SIZE];
      int position;
    public:
      void init()
       {
          position=0;	
       }
     char push(char ch);
     char pop();
};
char Cstack::push(char ch)
{
    if(position==SIZE)
      {
          cout<<"栈满"<<endl;
          return 0;	
      }	
      stk[position++]=ch;
      return ch;
}
char Cstack::pop()
{
    if(position==0)	
      {
      	  
          cout<<"\n栈空"<<endl;
          return 0;
      }
      return stk[--position];
}
void main()
{



   Cstack s;
   s.init();
   char ch;
   cout<<"please input some characters:"<<endl; 
   cin>>ch;
   while(ch!='#'&&s.push(ch))
    cin>>ch;
    cout<<endl;
    cout<<"now output the data:"<<endl;
    while(ch=s.pop())
    cout<<ch;
}





/* Note:Your choice is C IDE */
#include <iostream.h>
class Tdate
{
	public:
	void set(int m=5,int d=16,int y=1991)
	{
	   month=m;day=d;year=y;	
	}
	void print()
	{
	   cout<<month<<"/"<<day<<"/"<<year<<endl;	
	}
	private:
	int month;
	int day;
	int year;
};
void main()
{
   Tdate a,b,c;
   a.set(4,12,1996);
   b.set(3);
   c.set(8,10);
   a.print(); 
   b.print(); 
   c.print(); 
}



/* Note:Your choice is C IDE */
#include<iostream.h>
class cube
{
   public:
   int volume(int ht,int wd)
   {
       return ht*wd;	
   }
   int volume(int ht,int wd,int dp)
   {
       return ht*wd*dp;	
   }
   private:
   int ht,wd,dp;
};
void main()
{
   cube c;
   cout<<c.volume(10,20)<<endl;
   cout<<c.volume(10,20,30)<<endl; 
}



/* Note:Your choice is C IDE */
#include <iostream.h>
class queue
{/*默认私有*/
	int q[100];
	int sloc,rloc;
	public:
	queue();
	void qput(int i);
	int qget();
};
queue::queue()
{
 	sloc=rloc=0;
 	cout<<"queue initialized"<<endl;
}
void queue::qput(int i)
{
   if(sloc==100)
     {
        cout<<"queue is full"<<endl;
        return;	
     }	
     sloc++;
     q[sloc]=i;
}
int queue::qget()
{
   if(rloc==sloc)
     {
         cout<<"queue is empty"<<endl;
         return 0;	
     }
     rloc++;
     return q[rloc];


}
void main()
{
   queue a,b;
   a.qput(10);
   b.qput(20);
   a.qput(20);
   b.qput(19);
   cout<<a.qget()<<" ";
   cout<<b.qget()<<"\n";
   cout<<a.qget()<<" "; 
   cout<<b.qget()<<"\n";
}








/* Note:Your choice is C IDE */
#include <iostream.h>
class test
{
	private:
	int num;
	float f1;
	public:
	test();
	test(int n,float f);
	int getint()
	   {
	      return num;	
	   }
	float getfloat()
	   {
	       return f1;	
	   }
};
test::test()
{
   cout<<"Initializing default"<<endl;
   num=0;
   f1=0.0;	
}
test::test(int n,float f)
{
    cout<<"Initializing"<<n<<","<<f<<endl;
    num=n;
    f1=f;	
}
void main()
{
   test x;
   test y(10,21.5); 
   test *px=new test;
   test *py=new test(10,21.5);
}




/* Note:Your choice is C IDE */
#include <iostream.h>
class Tdate
{
	public:
	    Tdate(int m=5,int d=16,int y=1990)
	        {
	            month=m;day=d;year=y;
	            cout<<month<<"/"<<day<<"/"<<year<<endl;
	        }	
	private:
	   int month;
	   int day;
	   int year;
};
void main()
{
    Tdate aday;
    Tdate bday(2);
    Tdate cday(3,12);
    Tdate dday(1,22,1998);
}


/* Note:Your choice is C IDE */
#include <iostream>
#include <string>
using namespace std;
class Student
{
    public:
    Student(char *pName)
    {
        cout<<"call one parameter constructor"<<endl;
        strncpy(name,pName,sizeof(name));
        name[sizeof(name)-1]='\0';	
        cout<<"the name is "<<name<<endl;
    }	
    Student()
    {
        cout<<"call no parameter constructor"<<endl;	
    }
    protected:
    char name[20];
};
void main()
{
  Student noName;
  Student ss("Jenny");  
}



/* Note:Your choice is C IDE */
#include<iostream>
using namespace std;
class test
{
    private:
    int num;
    float f1;
    public:
    test();
    test(int n,float f);
    int getint()
    {
        return num;	
    }
    float getfloat()
    {
        return f1;	
    }
};
test::test()
{
    cout<<"Initializing default"<<endl;
    num=0;
    f1=0.0;	
}
test::test(int n,float f)
{
    cout<<"Initializing"<<n<<","<<f<<endl;
    num=n;
    f1=f;	
}
void main()
{
  cout<<"the main function:"<<endl;
  test array[5];
  cout<<"the second element of array is "<<array[1].getint()<<","<<array[1].getfloat()<<endl;  


}


/* Note:Your choice is C IDE */
#include<iostream>
using namespace std;
class test
{
    private:
    int num;
    float f1;
    public:
    test(int n);	
    test(int n,float f);
};
inline test::test(int n)
{
     cout<<"Initializing\t"<<n<<endl;
     num=n;	
}
test::test(int n,float f)
{
  cout<<"Initializing\t"<<n<<","<<f<<endl;
  num=n;
  f1=f;	
}
void main()
{
 test array1[3]={1,2,3};
 test array2[]={test(2,3.5),test(4)};
 test array3[]={test(5.5,6.5),test(7,8.5)}; 
 test array4[]={test(5.5,6.5),7.5,8.5}; 
}





/* Note:Your choice is C IDE */
#include<iostream>
using namespace std;
class test
{
    private:
    int num;
    float f1;
    public:
    test(int n);	
    test(int n,float f);
};
inline test::test(int n)
{
     cout<<"Initializing\t"<<n<<endl;
     num=n;	
}
test::test(int n,float f)
{
  cout<<"Initializing\t"<<n<<","<<f<<endl;
  num=n;
  f1=f;	
}
void main()
{
 test array1[3]={1,2,3};
 test array2[]={test(2,3.5),test(4)};
 test array3[]={test(5.5,6.5),test(7,8.5)}; 
 test array4[]={test(5.5,6.5),7.5,8.5}; 
}



#include<iostream>
using namespace std;
int main()
{
  for(int i=1;i<=10;i++)
    {
     for(int j=1;j<=i;++j)	
        cout<<"M";
        cout<<endl;
    }
}




#include<iostream.h>
class Tdate{
public:
	Tdate(int m=5,int d=16,int y=1990)
	{
		month=m;day=d;year=y;
		cout<<month<<"/"<<day<<"/"<<year<<endl;
	}
	private:
	 int month;
	 int day;
	 int year;
};
void main()
{
	Tdate aday;
	Tdate bday(2);
	Tdate cday(3,12);
	Tdate dday(1,21,1998);
}


#include<exception>
#include<iostream>
using namespace std;
void main()
{
  try
  {
    exception theError;
    throw(theError);	
  }	
  catch(const exception &theError)
  {
      cout<<theError.what()<<endl;	
  }
  try
  {
     logic_error theLogicError("Logic Error!");	
     throw(theLogicError);
  }
  catch(const exception & theLogicError)
  {
     cout<<theLogicError.what()<<endl;	
  }
}


#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(char *na)
	{
	    cout<<"call constructor"<<endl;
	    name=new char[strlen(na)+1];
	    if(name!=0)
	    {strcpy(name,na);}
	}
	Person(Person&p)
	{
	cout<<"call copy constructor"<<endl;
	name=new char[strlen(p.name)+1];
	 if(name!=0)
	    {strcpy(name,p.name);}
	}
	void printname()
	{
	   cout<<name<<endl;
	}
	~Person(){delete name;}
private:
	char *name;
};
void main()
{
	Person wang("wang");
	Person li(wang);
	wang.printname();
	li.printname();
}



#include<iostream>
using namespace std;
class SillyClass
{
public:
	SillyClass(int&i):ten(10),refI(i)
	{}
protected:
	const int ten;
	int&refI;
};
void main()
{
   int i;
   SillyClass sc(i);
   cout<<i<<endl;
}


#include<iostream.h>
class RMB
{
public:
	RMB(double value=0.0);
	operator double()
	{return yuan+jf/100.0;}
	void display()
	{
		cout<<(yuan+jf/100.0)<<endl;
	}
protected:
	unsigned int yuan;
	unsigned int jf;
};
RMB::RMB(double value)
{
      yuan=value;
      jf=(value-yuan)*100+0.5;
}
void main()
{
	RMB d1(2.0),d2(1.5),d3;
	d3=RMB((double)d1+(double)d2);
	d3=d1+d2;
	d3.display();
}

#include<iostream.h>
#include<string.h>
class Student
{
public:
	Student(char *pName="no name",int ssId=0)
	{
		strncpy(name,pName,40);
		name[39]='\0';
		id=ssId;
		cout<<"Constructing new student"<<pName<<endl;
	}
	Student(Student&s)
	{
	    cout<<"Constructing copy of "<<s.name<<endl;
	    strcpy(name,"copy of");
	    strcat(name,s.name);
	    id=s.id;
	}
	~Student()
	{
	    cout<<"Destructing "<<name<<endl;
	}
protected:
	char name[40];
	int id;
};
void fn(Student s)
{
    cout<<"In function fn()\n"<<endl;
}
void main()
{
	Student randy("Randy",1234);
	Student wang("wang",5678);
	cout<<"Calling fn()\n"<<endl;
	fn(randy);
	cout<<"Returned from fn()\n"<<endl;
}



#include<exception>
#include<iostream>
using namespace std;
void main()
{
  try
  {
    exception theError;
    throw(theError);	
  }	
  catch(const exception &theError)
  {
      cout<<theError.what()<<endl;	
  }
  try
  {
     logic_error theLogicError("Logic Error!");	
     throw(theLogicError);
  }
  catch(const exception & theLogicError)
  {
     cout<<theLogicError.what()<<endl;	
  }
}



#include<iostream.h>
class Student
{
public:
	Student()
	{
	cout<<"constructing student.\n";
	semesHours=100;
	gpa=3.5;
	}
	~Student()
	{cout<<"destructing student.\n";}
protected:
	int semesHours;
	float gpa;
};
class Teacher
{
public:
	Teacher()
	{cout<<"constructing teacher.\n";}
	~Teacher()
	{cout<<"destructing teacher.\n";}
};
class Tutorpair
{
public:
	Tutorpair()
	{
	cout<<"constructing tutorpair.\n";
	nomeeting=0;
	}
	~Tutorpair()
	{
	cout<<"destructing tutorpair.\n";
	}
protected:
	Student student;



	Teacher teacher;
	int nomeeting;
};
void main()
{
Tutorpair tp;
cout<<"back main.\n";
}


#include<iostream.h>
class A
{
static int i;
public:
    A()
    {
       i++;	
    }
    int list()
    {return i;}
};
int A::i=0;
void main()
{
A a1,a2,a3;
cout<<a1.list()<<","<<a2.list()<<","<<a3.list();	
}



#include<iostream.h>
#include<string.h>
class Student
{
public:
	Student(char *pName="no name")
	{
	  cout<<"create one student\n";
	  strncpy(name,pName,40);
	  name[39]='\0';
	  noOfStudents++;
	  cout<<noOfStudents<<endl;
	}
	~Student()
	{
	 cout<<"destruct one student\n";
	 noOfStudents--;
	 cout<<noOfStudents<<endl;
	}
	static int number()
	{
	   return noOfStudents;
	}
protected:
	static int noOfStudents;
	char name[40];
};
int Student::noOfStudents=0;
void fn()
{
Student s1;
Student s2;
cout<<Student::number()<<endl;
}
void main()
{


  Student wang;
  fn();
  cout<<Student::number()<<endl;
}



#include<iostream>
using namespace std;
int main()
{
  for(int i=1;i<=10;++i)
  {
    for(int j=1;j<=i-1;++j)
    cout<<" ";
    for(int k=1;k<=21-2*i;++k)
    cout<<"M";
    cout<<endl;	
  }	
}


#include<iostream.h>
#include<string.h>
class Student
{
public:
	Student(char *pName);
	~Student();
protected:
	static Student *pFirst;
	Student *pNext;
	char name[40];
};
Student * Student::pFirst=0;
Student::Student(char *pName)
{
	strncpy(name,pName,sizeof(name));
	name[sizeof(name)-1]='\0';
	pNext=pFirst;
	pFirst=this;
}
Student::~Student()
{
cout<<this->name<<endl;
if(pFirst==this)
{
   pFirst=pNext;
   return;
}
for(Student *pS=pFirst;pS;pS=pS->pNext)
	if(pS->pNext==this)
{
   pS->pNext=pNext;
   return;
}



}
Student *fn()
{
	Student *pS=new Student("Jenny");
	Student sb("Jone");
	return pS;
}
void main()
{
	Student sa("Jamsa");
	Student *sb=fn();
	Student sc("Tracey");
	delete sb;
}


#include<iostream.h>
#include<string.h>
class string
{
static int total_length;
int length;
char * contents;
public:
string(char *s)
{
	length=strlen(s);
	contents=new char[length +1];
	strcpy(contents,s);
}
static int set_total_length(string&obj)
{
total_length+=obj.length;
return total_length;
}
~string()
{delete[]contents;}
};
int string::total_length=0;
void main()
{
	string obj1("the first object");
	cout<<string::set_total_length(obj1)<<endl;
	string obj2("the second object");
	cout<<string::set_total_length(obj2)<<endl;
}




#include<iostream.h>
class A
{
	public:
	int i,*p;
	A(){i=10;p=&i;}
};
int A::*p=&A::i;
void main()
{
A aa,bb;	
(bb.*p)++;
-- *aa.p;
cout<<"AA:"<<aa.*p<<"BB:"<<bb.*p<<"\n";
cout<<"AA:"<<*aa.p<<"BB:"<<*bb.p<<"\n";
}





#include<iostream.h>
class A
{
   int i;
   public:
   int set(int k)
   {
      i=++k;return i;	
   }	
};
void main()
{
   int(A::*f)(int)=&A::set;	
   A aa;
   cout<<(aa.*f)(10)<<endl;
}



#include<iostream.h>
class A
{
	static int i;
	friend class B;
	public:
	static void set(int k)
	{i=k;i++;}
};
class B
{
public:
static void ds(int l)
{
int *p=&A::i;
cout<<*p<<"\n";
*p=1;cout<<*p;	
}	
};
int A::i=0;
void(*f1)(int)=&A::set;
void(*f2)(int)=&B::ds;
void main()
{
f1(10);
f2(20);	
}




#include<iostream.h>
const maxCard=16;
enum ErrCode{noErr,overflow};
enum Bool{False,True};
class Set
{
	int elems[maxCard];
	int card;
public:
	void EmptySet(){card=0;}
	Bool Member(int);
	ErrCode AddElem(int);
	void RmvElem(int);
	void Copy(Set *);
	Bool Equal(Set *);
	void Print();
	void Intersect(Set *,Set *);
	ErrCode Union(Set *,Set *);
};
Bool Set::Member(int elem)
{
	for(int i=0;i<card;++i)
		if(elems[i]==elem)
			return True;
	return False;
}
ErrCode Set::AddElem(int elem)
{
	if(Member(elem))
		return noErr;
	if(card<maxCard)
	{
		elems[card++]=elem;
		return noErr;
	}
	return overflow;
}
void Set::RmvElem(int elem)
{
	for(int i=0;i<card;++i)
		if(elems[i]==elem)
	{
		for(;i<card-1;++i)
			elems[i]=elems[i+1];
		--card;
		return;
	}
}
void Set::Copy(Set *set)
{
	for(int i=0;i<card;++i)
		set->elems[i]=elems[i];
	set->card=card;
}
Bool Set::Equal(Set *set)
{
	if(card!=set->card)
		return False;
	for(int i=0;i<card;++i)
		if(!set->Member(elems[i]))
			return False;
	return True;
}
void Set::Print()
{
	cout<<"{";
	for(int i=0;i<card;++i)
		cout<<elems[i]<<";";
	cout<<"}\n";
}
void Set::Intersect(Set *set,Set *res)//*this Π *set->*res
{
res->card=0;
for(int i=0;i<card;++i)
	for(int j=0;j<set->card;++j)
		if(elems[i]==set->elems[j])
{
	res->elems[res->card++]=elems[i];
	break;
}
}
ErrCode Set::Union(Set *set,Set *res)
{
	set->Copy(res);
	for(int i=0;i<card;++i)
		if(res->AddElem(elems[i])==overflow)
			return overflow;
	return noErr;
}
void main()
{
Set s1,s2,s3;
s1.EmptySet();
s2.EmptySet();
s3.EmptySet();
s1.AddElem(10);
s1.AddElem(20);
s1.AddElem(30);
s1.AddElem(40);
s2.AddElem(30);
s2.AddElem(50);
s2.AddElem(10);
s2.AddElem(60);
cout<<"s1=";s1.Print();
cout<<"s2=";s2.Print();
s2.RmvElem(50);
cout<<"s2-{50}";s2.Print();
if(s1.Member(20))
	cout<<"20 is in s1\n";
s1.Intersect(&s2,&s3);
cout<<"s1 intsec s2=";s3.Print();
s1.Union(&s2,&s3);
cout<<"s1 union s2";s3.Print();
if(!s1.Equal(&s2))
	cout<<"s1!=s2\n";
}






#include<iostream.h>
const maxCard=16;
enum ErrCode{noErr,overflow};
enum Bool {False,True};
class Set
{
	int size;
	int *elems;
	int card;
	public:
	Set(int sz=maxCard)
	{card=0;size=sz;elems=new int[size];}
	~Set(){delete []elems;}
	Bool Member(int);
	ErrCode AddElem(int);
	void RmvElem(int);
	void Copy(Set *);
	Bool Equal(Set *);
	void Print();
	void Intersect(Set *,Set *);
	ErrCode Union(Set *,Set *);
};
Bool Set::Member(int elem)
{
   for(int i=0;i<card;++i)	
   if(elems[i]==elem)
   return True;
   return False;
}
ErrCode Set::AddElem(int elem)
{
   if(Member(elem))
   return noErr;
   if(card<size)
   {
     elems[card++]=elem;
     return noErr;	
   }
   return overflow;
}
void Set::RmvElem(int elem)
{
for(int i=0;i<card;++i)
if(elems[i]==elem)	
     {
	    for(;i<card-1;++i)
	    elems[i]=elems[i+1];
	    --card;
	    return;
     }
}
void Set::Copy(Set *set)
{
  if(set->size<size)
    {
      delete []set->elems;
      set->elems=new int[size];	
      set->size=size;
    }	
  for(int i=0;i<card;++i)
      set->elems[i]=elems[i];
      set->card=card; 
}
Bool Set::Equal(Set *set)
{
   if(card!=set->card)	
   return False;
   for(int i=0;i<card;++i)
     if(!set->Member(elems[i]))
     return False;
     return True;
}
void Set::Print()
{
   cout<<"{";
   for(int i=0;i<card-1;++i)
   cout<<elems[i]<<";";	
   if(card>0)
   cout<<elems[card-1];
   cout<<"}\n";
}
void Set::Intersect(Set *set,Set *res)
{
  if(res->size<size)
  {
    delete []res->elems;
    res->elems=new int[size];
    res->size=size;	
  }	
  res->card=0;
  for(int i=0;i<card;++i)
     for(int j=0;j<set->card;++j)
        if(elems[i]==set->elems[j])
          {
             res->elems[res->card++]=elems[i];
             break;	
          }
}
ErrCode Set::Union(Set *set,Set *res)
{
   if(res->size<size+set->size)	
   {
     delete []res->elems;
     res->elems=new int[size+set->size];
     res->size=size+set->size;	
   }
   set->Copy(res);
   for(int i=0;i<card;++i)
     if(res->AddElem(elems[i])==overflow)
     return overflow;
     return noErr;
}
void main()
{
  Set s1,s2,s3;
  s1.AddElem(10);	
  s1.AddElem(20);
  s1.AddElem(30);
  s1.AddElem(40);
  s2.AddElem(30);
  s2.AddElem(50);
  s2.AddElem(10);
  s2.AddElem(60);
  cout<<"s1=";s1.Print();
  cout<<"s2=";s2.Print();
  s2.RmvElem(50);
  cout<<"s2-{50}=";s2.Print();
  if(s1.Member(20))
     cout<<"20 is in s1\n";
     s1.Intersect(&s2,&s3);
     cout<<"s1 intsec s2=";s3.Print();
     s1.Union(&s2,&s3);
     cout<<"s1 union s2=";s3.Print();
     if(!s1.Equal(&s2))
     cout<<"s1!=s2\n";
}




#include<iostream.h>
class Tx
{
  public:
  Tx(int i,int j);
  ~Tx();
  void display();
  private:
  int num1,num2;	
};
Tx::Tx(int i,int j=10)
{
  num1=i;
  num2=j;
  cout<<"Constructing"<<num1<<" "<<num2<<endl;	
}
void Tx::display()
{
  cout<<"display:"<<num1<<" "<<num2<<endl;	
}
Tx::~Tx()
{
  cout<<"Destructing"<<num1<<" "<<num2<<endl;	
}
void main()
{
  Tx t1(22,11);
  Tx t2(20);
  t1.display();
  t2.display();	
}




#include<iostream.h>
#include<string.h>
class Student
{
	char name[10],num[10];
public:
	Student(char *s1,char *s2)
	{
		strcpy(name,s1);
		strcpy(num,s2);
	}
	void dsp()
	{
	  cout<<"Name:"<<name<<endl<<"Number:"<<num<<endl;
	}
};
class Score
{
  unsigned int mat,phy,eng;
 public:
  Score(unsigned int i1,unsigned int i2,unsigned int i3):mat(i1),phy(i2),eng(i3)
  {}
  void show()
  {
    cout<<"Mathematics:"<<mat<<"\nPhyics:"<<phy<<"\nEnglish:"<<eng<<endl;
  }
};
void main()
{
	Student a("Wang","123456789");
	Score a1(72,82,92);
	a.dsp();
	a1.show();
}



#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  cout<<"please input a number:\n";	
   int m;
   cin>>m;
   double sqrtm=sqrt(m*1.0);
   for(int i=2;i<=sqrtm;++i)
     if(m%i==0)
       {
       	  cout<<m<<" is not a prime\n";
       	  return 1;
       }
       cout<<m<<" is a prime";
}




#include<iostream.h>
#include<string.h>
class Student
{
private:
	char name[10],num[10];
	friend void show(Student&st)
	{
		cout<<"Name:"<<st.name<<endl<<"Number:"<<st.num<<endl;
	}
public:
	Student(char *s1,char *s2)
	{strcpy(name,s1);strcpy(num,s2);}
};
class Score
{
  unsigned int mat,phy,eng;
  friend void show_all(Student&,Score *);
 public:
  Score(unsigned int i1,unsigned int i2,unsigned int i3):mat(i1),phy(i2),eng(i3)
  {}
};
void show_all(Student&st,Score *sc)
{
	show(st);
	cout<<"Mathematics:"<<sc->mat<<"\nPhysics:"<<sc->phy<<"\nEnglish:"<<sc->eng<<endl;
}
void main()
{
	Student wang("Wang","9901");
	Score ss(72,82,92);
	show_all(wang,&ss);
}



#define strmax 32
#include<string.h>
#include<iostream.h>
class myclass
{
  int x,y;
  char *string;
 public:
  myclass(int vx,int vy,char *str);
  friend int sum(myclass c1);
  friend int strlength(myclass c1);
  friend void print(myclass c1);
};
myclass::myclass(int vx,int vy,char *str)
{
x=vx;
y=vy;
string=new char[strmax];
strcpy(string,str);
}
int sum(myclass c1)
{return c1.x+c1.y;}
int strlength(myclass c1)
{return strlen(c1.string);}
void print(myclass c1)
{
  cout<<"x="<<c1.x<<endl<<"y="<<c1.y<<endl;
  cout<<"string:"<<c1.string<<endl;
}
void main()
{
	myclass c1(10,10,"my myclass object!");
	cout<<"the sum is:"<<sum(c1)<<endl;
	cout<<"the string is:"<<strlength(c1)<<endl;
	print(c1);
}






#include<iostream>
using namespace std;
int main()
{
   for(int i=1;i<=10;++i)
   {
        for(int j=1;j<=10-i;++j)
        cout<<" ";	
        for(char ch='A';ch<'A'+2*i-1;++ch)
        cout<<ch;
        cout<<"\n";
   }	
}



#include<iostream>
using namespace std;
int main()
{
  cout<<"please input a number:\n";	
  int m;
  cin>>m;
  for(int i=2;i<m;++i)
  if(m%i==0)
  {cout<<m<<" is not a prime\n";
  	return 1;}
  cout<<m<<" is a prime";
}





#define strmax 32
#include<string.h>
#include<iostream.h>
class myclass
{
  int x,y;
  char *string;
 public:
  myclass(int vx,int vy,char *str);
  	friend int sum(myclass c1);
  friend int strlength(myclass c1);
  friend void print(myclass c1);
};
myclass::myclass(int vx,int vy,char *str)
{
    x=vx;
    y=vy;
    string=new char[strmax];
    strcpy(string,str);
}
int sum(myclass c1)
{
  return (c1.x+c1.y);
}
int strlength(myclass c1)
{
	return strlen(c1.string);
}
void print(myclass c1)
{
   cout<<"x="<<c1.x<<"   "<<"y="<<c1.y<<endl;
   cout<<"string:"<<c1.string<<endl;
}
void main()
{
	myclass c1(10,10,"my myclass is a object");
	cout<<"the sum is:"<<sum(c1)<<endl;
	cout<<"the string is:"<<strlength(c1)<<endl;
	print(c1);
}




#define maxcard 32
#include<iostream.h>
class realset;
enum errcode{noerr,overflow};
class intset
{
	int elem[maxcard];
	int card;
public:
	intset()
	{card=0;}
	errcode addelem(int);
	void print();
	void settoreal(realset *set);
};
class realset
{
	float elem[maxcard];
	int card;
public:
	realset()
	{card=0;}
	errcode addelem(float);
	void print();
};
errcode intset::addelem(int elem1)
{
	for(int i=0;i<card;i++)
		if(elem[i]==elem1)
			return noerr;
	if(card<maxcard)
	{
		elem[card++]=elem1;
		return noerr;
	}
	else return overflow;
}
void intset::print()
{
    cout<<"{";
    for(int i=0;i<card-1;++i)
    	cout<<elem[i]<<",";
    if(card>0)  cout<<elem[card-1];
    cout<<"}\n";
}
void intset::settoreal(realset *set)
{
	for(int i=0;i<card;i++)
		set->addelem((float)elem[i]);
}
errcode realset::addelem(float elem1)
{
	for(int i=0;i<card;i++)
		if(elem[i]==elem1)
			return noerr;
	if(card<maxcard)
	{
		elem[card++]=elem1;
		return noerr;
	}
	else return overflow;
}
void realset::print()
{
     cout<<"{";
     for(int i=0;i<card-1;++i)
     	cout<<elem[i]<<",";
     if(card>0)
     	cout<<elem[card-1];
     cout<<"}\n";
}
void main()
{
  intset set1;
  realset *set2;
  set2=new realset;
  set1.addelem(12);
  set1.addelem(278);
  set1.addelem(54);
  set1.addelem(459);
  set1.print();
  set1.settoreal(set2);
  set2->print();
  delete set2;	
}





#include<iostream.h>
#include<string.h>
class Student;
class Score
{
   unsigned int mat,phy,eng;
  public:
   Score(unsigned int i1,unsigned int i2,unsigned int i3):mat(i1),phy(i2),eng(i3){}
   void show()
   {
     cout<<"Mathematics:"<<mat
     	<<"\nPhysics:"<<phy
     	<<"\nEnglish:"<<eng<<endl;
   }
   void show(Student&);
};
class Student
{
	friend void Score::show(Student&);
	char name[10],num[10];
public:
	Student(char *s1,char *s2){strcpy(name,s1);strcpy(num,s2);}
};
void Score::show(Student& st)
{
   cout<<"Name:"<<st.name<<"\n";
   show();
}
void main()
{
	Student wang("wang","1990");
	Score ss(72,82,92);
	ss.show(wang);
}




#include<iostream.h>
#include<string.h>
class Student
{
    friend class Score;
    char name[10],num[10];
   public:
    Student(char *s1,char *s2)
    {strcpy(name,s1);strcpy(num,s2);}
};
class Score
{
   unsigned int mat,phy,eng;
  public:
   Score(unsigned int i1,unsigned int i2,unsigned int i3):mat(i1),phy(i2),eng(i3){}
   void show()
   {cout<<"Mathematics:"<<mat<<"\nPhysics:"<<phy<<"\nEnglish:"<<eng<<endl;}
   void show(Student&);
};
void Score::show(Student& st)
{
  cout<<"Name:"<<st.name<<"\n";
  show();
}
void main()
{
	Student wang("wang","1990");
	Score ss(72,82,92);
	ss.show(wang);
}





#include<iostream.h>
class stack;
class node
{
   int data;
   node *prev;
  public:
   node(int d,node *n)
   {
      data=d;
      prev=n;
   }
   friend class stack;
};
class stack
{
   node *top;
  public:
   stack()
   {
       top=0;
   }
   void push(int i);
   int pop();
};
void stack::push(int i)
{
	node *n=new node(i,top);
	top=n;
}
int stack::pop()
{
       node *t=top;
       if(top)
         {
               top=top->prev;
               int c=t->data;
               delete t;
               return c;
         }
       return 0;
}
void main()
{
int c;
stack s;
     for(int i=0;i<10;i++)
     {
         cin>>c;
         s.push(c);
     }
      for(i=0;i<10;i++)
      	cout<<s.pop()<<" ";
      cout<<"\n";
}





#include<iostream.h>
class Complex
{
   double real;
   double image;
  public:
   Complex(double r=0, double i=0)
   {
       real=r;
       image=i;

   }
   friend void inputcomplex(Complex &comp);
   friend Complex addcomplex(Complex &c1,Complex &c2);
   friend Complex subcomplex(Complex &c1,Complex &c2);
   friend Complex mulcomplex(Complex &c1,Complex &c2);
   friend void outputcomplex(Complex &comp);
};
void inputcomplex(Complex &comp)
{
    cin>>comp.real>>comp.image;
}
Complex addcomplex(Complex &c1,Complex &c2)
{
    Complex c;
    c.real=c1.real+c2.real;
    c.image=c1.image+c2.image;
    return c;
}
Complex subcomplex(Complex &c1,Complex &c2)
{
  Complex c;
  c.real=c1.real-c2.real;
  c.image=c1.image-c2.image;
  return c;
}
Complex mulcomplex(Complex &c1,Complex &c2)
{
    Complex c;
    c.real=c1.real*c2.real-c1.image*c2.image;
    c.image=c1.real*c2.image+c1.image*c2.real;
    return c;
}
void outputcomplex(Complex &comp)
{
	cout<<"("<<comp.real<<","<<comp.image<<")";
}
void main()
{
  Complex c1,c2,result;
  cout<<"please input the first number's shi and xu:"<<endl;
  inputcomplex(c1);
  cout<<"please input the second number's shi and xu:"<<endl;
  inputcomplex(c2);
  result=addcomplex(c1,c2);
  outputcomplex(c1);
  cout<<"+";
   outputcomplex(c2);
  cout<<"=";
   outputcomplex(result);
  cout<<"\n---------------------------"<<endl;
  result=subcomplex(c1,c2);
  outputcomplex(c1);
  cout<<"-";
   outputcomplex(c2);
  cout<<"=";
   outputcomplex(result);
  cout<<"\n---------------------------"<<endl;
  result=mulcomplex(c1,c2);
  outputcomplex(c1);
  cout<<"*";
   outputcomplex(c2);
  cout<<"=";
   outputcomplex(result);
  cout<<endl;
}






#include<iostream.h>
class vehicle
{
private:
	float weight;
	int wheels;
public:
	vehicle(int in_wheels,float in_weight)
	{
	    wheels=in_wheels;weight=in_weight;
	}
	int get_wheels(){return wheels;}
	float get_weight(){return weight;}
};
class car:public vehicle
{
private:
	int passenger_load;
public:
	car(int in_wheels,float in_weight,int people=5):vehicle(in_wheels,in_weight)
	{passenger_load=people;}
	int get_passengers(){return passenger_load;}
};
void main()
{
	car bm(4,1000);
	cout<<"The message of bm(wheels,weight,passenger):"<<endl;
	cout<<bm.get_wheels()<<",";
	cout<<bm.get_weight()<<",";
	cout<<bm.get_passengers()<<endl;
}
	



#include<iostream.h>
class vehicle
{
private:
	int wheels;
	float weight;
public:
	vehicle(int in_wheels,float in_weight)
	{wheels=in_wheels;weight=in_weight;}
	int get_wheels(){return wheels;}
	float get_weight(){return weight;}
};
class car:private vehicle
{
private:
	int passenger_load;
public:
	car(int in_wheels,float in_weight,int people=5):vehicle(in_wheels,in_weight){passenger_load=people;}
	int get_wheels(){return vehicle::get_wheels();}
	float get_weight(){return vehicle::get_weight();}
	int get_passengers(){return passenger_load;}
};
void main()
{
	car bm(4,1000);
	cout<<"The message of bm(wheels,weight,passengers):"<<endl;
	cout<<bm.get_wheels()<<","
		<<bm.get_weight()<<","
		<<bm.get_passengers()<<endl;
}





#include<iostream.h>
class vehicle
{
private:
	int wheels;
protected:
	float weight;
public:
	vehicle(int in_wheels,float in_weight)
	{wheels=in_wheels;weight=in_weight;}
	int get_wheels()
	{return wheels;}
	float get_weight()
	{return weight;}
};
class car:protected vehicle
{
private:
	int passenger_load;
public:
	car(int in_wheels,float in_weight,int people=5):vehicle(in_wheels,in_weight){passenger_load=people;}
	int get_wheels(){return vehicle::get_wheels();}
	float get_weight(){return weight;}
	int get_passengers(){return passenger_load;}
};
void main()
{
	car bm(4,1000);
	cout<<"The message of bm(wheels,weight,passengers):"<<endl;
	cout<<bm.get_wheels()<<","
		<<bm.get_weight()<<","
		<<bm.get_passengers()<<endl;
}



#include<iostream.h>
class data
{
   int x;
  public:
   data(int x)
   {
   data::x=x;
   cout<<"class data\n";
   }
};
class a
{
    data d1;
   public:
    a(int x):d1(x)
    {cout<<"class a\n";}
};
class b:public a
{
    data d2;
   public:
    b(int x):a(x),d2(x)
    {cout<<"class b\n";}
};
class c:public b
{
	public:
	c(int x):b(x)
	{cout<<"class c\n";}
};
void main()
{
	c object(5);
}




#include<iostream.h>
#include<string.h>
class ST_COM
{
protected:
	char name[10];
	unsigned int num;
	float mat,eng,phy;
public:
	ST_COM(char *na,unsigned int n,float ma,float en,float ph):num(n),mat(ma),eng(en),phy(ph)
	{strcpy(name,na);}
};
class EL_DEP:public ST_COM
{
  float pex,elnet,dst;
 public:
  EL_DEP(char *na,unsigned int n,float ma,float en,float ph,float pe,float el,float d):ST_COM(na,n,ma,en,ph),pex(pe),elnet(el),dst(d){}
  void operator!()
  {
         cout<<"Name:"<<name<<"      Number:"<<num<<endl;
         cout<<"Mathematics Scor:"<<mat<<endl;
         cout<<"English Scor:    "<<eng<<endl;
         cout<<"Physics Scor:    "<<phy<<endl;
         cout<<"Exchange Scor:   "<<pex<<endl;
         cout<<"Elec_net Scor:   "<<elnet<<endl;
         cout<<"Data_struct Scor:"<<dst<<endl;
  }
};
void main()
{
   EL_DEP a("wang",1234,71,72,73,81,82,83);	
   !a;
}





#include<iostream.h>
#include<string.h>
class ST_COM
{
protected:
	char name[10];
	unsigned int num;
	float mat,eng,phy,avg;
public:
	ST_COM(char *na,unsigned int n,float ma,float en,float ph):num(n),mat(ma),eng(en),phy(ph)
	{
		strcpy(name,na);
		avg=(mat+eng+phy)/3;
	}
	void operator!()
	{
	   cout<<"Name:"<<name<<"      Number:"<<num<<endl;
	   cout<<"Mathematics Scor :"<<mat<<endl;
	   cout<<"English Scor     :"<<eng<<endl;
	   cout<<"Physics Scor     :"<<phy<<endl;
	}
};
class EL_DEP:public ST_COM
{
   float pex,elnet,dst,avg;
  public:
   EL_DEP(char *na,unsigned int n,float ma,float en,float ph,float pe,float el,float d):ST_COM(na,n,ma,en,ph),pex(pe),elnet(el),dst(d)
   {avg=((pex+elnet+dst)/3+ST_COM::avg)/2;}
   void operator!()
   {
   	ST_COM::operator !();
   	cout<<"Exchange Scor    :"<<pex<<endl;
   	cout<<"Elec_net Scor    :"<<elnet<<endl;
   	cout<<"Data_struct Scor :"<<dst<<endl;
   	cout<<"Average Scor     :"<<avg<<endl;
   }
};
void main()
{
     EL_DEP a("wang",1234,71,72,73,81,82,83);	
     !a;
}






#include<iostream.h>
class person
{
  char *name;
  int age;
  char add;
 public:
  person()
  {cout<<"the constructor of class persons!\n";}
  ~person()
  {cout<<"the adestructor of class persons!\n";}
};
class student:public person
{
     char *department;
     int level;
    public:
     student()
     {cout<<"the constructor of class student!\n";}
     ~student()
     {cout<<"the adestructor of class student!\n";}
};
class teacher:public person
{
   char *major;
   float salary;
  public:
   teacher()
   {cout<<"the constructor of class teacher!\n";}
   ~teacher()
   {cout<<"the adestructor of class teacher!\n";}
};
void main()
{
     student d1;
     teacher d2;
}




#include<iostream.h>
class Bed
{
public:
	Bed():weight(){}
	void Sleep(){cout<<"Sleeping...\n";}
	void SetWeight(int i){weight=i;}
protected:
	int weight;
};
class Sofa
{
public:
	Sofa():weight(){}
	void WatchTV(){cout<<"Watching TV\n";}
	void SetWeight(int i){weight=i+2;}
protected:
	int weight;
};
class SleeperSofa:public Bed,public Sofa
{
public:
	SleeperSofa(){}
	void FoldOut(){cout<<"Fold out the sofa.\n";}
};
void main()
{
   SleeperSofa ss;
   ss.WatchTV();
   ss.Sleep();
   ss.Bed::SetWeight(20);
   ss.Sofa::SetWeight(20);
}




#include<iostream.h>
class Furniture
{
public:
	Furniture(){}
	void SetWeight(int i){weight=i;}
	  int GetWeight(){return weight;}
	 protected:
	  int weight;
};
class Bed:virtual public Furniture
{
public:
	Bed(){}
	void Sleep(){cout<<"Sleeping...\n";}
};
class Sofa:virtual public Furniture
{
public:
	Sofa(){}
	void WatchTV(){cout<<"Watching TV...\n";}
};
class SleeperSofa:public Bed,public Sofa
{
public:
	SleeperSofa():Sofa(),Bed(){}
	void FoldOut(){cout<<"Fold out the sofa.\n";}
};
void main()
{
   SleeperSofa ss;
   ss.SetWeight(20);
   cout<<ss.GetWeight()<<endl;
}







#include<iostream.h>
class base
{
public:
	base(){cout<<"this is base class!\n";}
};
class base2
{
public:
	base2(){cout<<"this is base2 class!\n";}
};
class level1:public base2,virtual public base
{
public:
	level1(){cout<<"this is level1 class!\n";}
};
class level2:public base2,virtual public base
{
public:
	level2(){cout<<"this is level2 class!\n";}
};
class toplevel:public level1,virtual public level2
{
public:
	toplevel(){cout<<"this is toplevel class!\n";}
};
void main()
{
   toplevel topobj;
}







#include<iostream.h>
class OBJ1
{
public:
	OBJ1(){cout<<"OBJ1\n";}
	~OBJ1(){cout<<"destructing OBJ1"<<endl;}
};
class OBJ2
{
public:
	OBJ2(){cout<<"OBJ2\n";}
	~OBJ2(){cout<<"destructing OBJ2"<<endl;}
};
class Base1
{
public:
	Base1(){cout<<"Base1\n";}
	~Base1(){cout<<"destructing Base1"<<endl;}
};
class Base2
{
public:
	Base2(){cout<<"Base2\n";}
	~Base2(){cout<<"destructing Base2"<<endl;}
};
class Base3
{
public:
	Base3(){cout<<"Base3\n";}
	~Base3(){cout<<"destructing Base3"<<endl;}
};
class Base4
{
public:
	Base4(){cout<<"Base4\n";}
	~Base4(){cout<<"destructing Base4"<<endl;}
};
class Derived:public Base1,virtual public Base2,public Base3,virtual public Base4
{
public:
	Derived():Base4(),Base3(),Base2(),Base1(),obj2(),obj1()
	{cout<<"Derived ok.\n";}
	~Derived(){cout<<"destructing Drived"<<endl;}
protected:
	OBJ1 obj1;
	OBJ2 obj2;
};
void main()
{
  Derived aa;
}





#include<iostream.h>
template<class T>
	class tem
{
	T *data;
	int size;
	public :
		tem(int);
	~tem() {delete[] data;}
	T& operator[](int i) {return data[i];}
};
template<class T>
	tem<T>::tem(int n)
{
	data=new T[n];
	size=n;
}
void main()
{
	tem<int> x(5);
	int i;
	for(i=0;i<5;i++)
		x[i]=i;
	for(i=0;i<5;i++)
		cout<<x[i]<<' ';
	cout<<"\n";
}
	




#include<iostream.h>
#include<string.h>
class Person
{
protected:
	char m_strName[10];
	int m_nSex;
	int m_nAge;
public:
	Person(char *name,int age,char sex)
	{
		strcpy(m_strName,name);
		m_nSex=(sex=='m'?0:1);
		m_nAge=age;
	}
	void ShowMe()
	{
	    cout<<"姓名："<<m_strName<<endl;
	    cout<<"性别："<<(m_nSex==0?"男":"女")<<endl;
	    cout<<"年龄："<<m_nAge<<endl;
	}
};
class Teacher:public Person
{
	char m_strDept[20];
	int m_fSalary;
public:
	Teacher(char *name,int age,char sex,char *dept,int salary):Person(name,age,sex)
	{
		strcpy(m_strDept,dept);
		m_fSalary=salary;
	}
	void ShowMe()
	{
		Person::ShowMe();
		cout<<"工作单位："<<m_strDept<<endl;
		cout<<"月    薪："<<m_fSalary<<endl;
	}
};
class Student:public Person
{
	char m_strID[12];
	char m_strClass[12];
public:
	Student(char *name,int age,char sex,char *ID,char *Class):Person(name,age,sex)
	{
		strcpy(m_strID,ID);
		strcpy(m_strClass,Class);
	}
	void ShowMe()
	{
	    cout<<"学号："<<m_strID<<endl;
	    Person::ShowMe();
	    cout<<"班级："<<m_strClass<<"\n";
	}
};
void main()
{
	Teacher teacher("刘馨",38,'m',"计算机系",3800);
	Student student("王丽",20,'v',"03214521","计算机03班");
	teacher.ShowMe();
	cout<<"-------------------------"<<endl;
	student.ShowMe();
}




#include<iostream.h>
#include<string.h>
template<class T>
	class List
{
public:
	List();
	void Add(T&);
	void Remove(T&);
	T *Find(T&);
	void PrintList();
	~List();
protected:
	struct Node
	{
		Node *pNext;
		T *Pt;
	};
	Node *pFirst;
};
template<class T>
	List<T>::List()
{
	pFirst=0;
}
template<class T>
	void List<T>::Add(T& t)
{
	Node *temp=new Node;
	temp->Pt=&t;
	temp->pNext=pFirst;
	pFirst=temp;
}
template<class T>
	void List<T>::Remove(T& t)
{
	Node *q=0;
	if(*pFirst->Pt==t)
	{
		q=pFirst;
		pFirst=pFirst->pNext;
	}
	else
	{
		for(Node *p=pFirst;p->pNext;p=p->pNext)
			if(*(p->pNext->Pt)==t)
		{
			q=p->pNext;
			p->pNext=q->pNext;
			break;
		}
	}
	if(q)
	{
		delete q->Pt;
		delete q;
	}
	else
		cout<<"No such node!"<<endl;
}
template<class T>
	T* List<T>::Find(T& t)
{
	for(Node *p=pFirst;p;p=p->pNext)
	{
		if(*(p->Pt)==t)
			return p->Pt;
	}
	return 0;
}
template<class T>
	void List<T>::PrintList()
{
	for(Node *p=pFirst;p;p=p->pNext)
	{
		cout<<*(p->Pt)<<"|";
	}
	cout<<endl;
}
template<class T>
	List<T>::~List()
{
	Node *p=pFirst;
	while(!p)
	{
		pFirst=pFirst->pNext;
		delete p->Pt;
		delete p;
		p=pFirst;
	}
}
void main()
{
	List<float> floatList;
	for(int i=1;i<7;i++)
	{
		floatList.Add(* new float((float)(i+0.3)));
	}
	floatList.PrintList();
	float b=(float)3.3;
	float *pa=floatList.Find(b);
	if(pa)
		floatList.Remove(*pa);
	floatList.Remove(*new float((float)0.3));
	floatList.PrintList();
}




#include<iostream.h>
#include<string.h>
class employee
{
protected:
	char name[10];
	char emp_id[8];
	double salary;
public:
	void setinfo(char *empname,int empsex,char *empid)
	{
		strcpy(name,empname);
		strcpy(emp_id,empid);
	}
	void getinfo(char *empname,char *empid)
	{
		strcpy(empname,name);
		strcpy(empid,emp_id);
	}
	double getsalary()
	{
		return salary;
	}
};
class hourlyworker:public employee
{
protected:
	int hours;
	double perhourpay;
public:
	hourlyworker()
	{
		hours=0;
		perhourpay=15.6;
	}
	int gethours()
	{
		return hours;
	}
	void sethours(int h)
	{
		hours=h;
	}
	double getperhourpay()
	{
		return perhourpay;
	}
	void setperhourpay(double pay)
	{
		perhourpay=pay;
	}
	void computepay()
	{
		if(hours<=40)
			salary=perhourpay*hours;
		else
			salary=perhourpay*40+(hours-40)*1.5*perhourpay;
	}
};
class pieceworker:public employee
{
protected:
	int pieces;
	double perpiecepay;
public:
	pieceworker()
	{
		pieces=0;
		perpiecepay=26.8;
	}
	int getpieces()
	{
		return pieces;
	}
	void setpieces(int p)
	{
		pieces=p;
	}
	double getperpiecepay()
	{
		return perpiecepay;
	}
	void setperpiecepay(double ppp)
	{
		perpiecepay=ppp;
	}
	void computepay()
	{
		salary=pieces*perpiecepay;
	}
};
class manager:public employee
{
public:
	void setsalary(double s)
	{
		salary=s;
	}
};
class commissionworker:public employee
{
protected:
	double basesalary;
	double total;
	double percent;
public:
	commissionworker()
	{
		basesalary=500;
		total=0;
		percent=0.01;
	}
	double getbase()
	{
		return basesalary;
	}
	void setbase(double base)
	{
		basesalary=base;
	}
	double gettotal()
	{
		return total;
	}
	void settotal(double t)
	{
		total=t;
	}
	double getpercent()
	{
	   return percent;
	}
	double setpercent(double p)
	{
	    percent=p;
	}
	void computepay()
	{
	    salary=basesalary+total*percent;
	}
};
void main()
{
	char name[10],emp_id[9];
	hourlyworker hworker;
	hworker.setinfo("John",0,"001");
	hworker.sethours(65);
	hworker.getinfo(name,emp_id);
	hworker.computepay();
	cout<<"hourlyworker "<<name<<"'s id is:"<<emp_id
		<<" and salary is:"<<hworker.getsalary()<<endl;
	pieceworker pworker;
	pworker.setinfo("Mark",0,"002");
	pworker.setpieces(100);
	pworker.computepay();
	pworker.getinfo(name,emp_id);
	cout<<"pieceworker "<<name<<"'s id is:"<<emp_id
		<<"and salary is:"<<pworker.getsalary()<<endl;
	commissionworker cworker;
	cworker.settotal(234.6);
	cworker.setinfo("Jane",0,"003");
	cworker.computepay();
	cworker.getinfo(name,emp_id);
	cout<<"commissionworker "<<name<<"'s id is:"<<emp_id
		<<"and salary is:"<<cworker.getsalary()<<endl;
	manager mana;
	mana.setinfo("Mike",1,"004");
	mana.setsalary(3500);
	mana.getinfo(name,emp_id);
	cout<<"manager "<<name<<"'s id is:"<<emp_id
		<<" and salary is:"<<mana.getsalary()<<endl;
}




#include<iostream.h>
#include<stdlib.h>
template<typename T>
	class BinaryTree;
template<typename T>
	class Node
{
	Node<T> *lchild,*rchild;
	T info;
public:
	Node()
	{
		lchild=NULL;
		rchild=NULL;
	}
	Node(T data,Node<T> *left=NULL,Node<T> *right=NULL)
	{
		info=data;
		lchild=left;
		rchild=right;
	}
	friend class BinaryTree<T>;
};
template<typename T>
	class BinaryTree
{
	Node<T> *root;
	void InOrder(Node<T> *Current);
	void Insert(const T &data,Node<T> * &b);
	void Remove(const T &data,Node<T> * &a,Node<T> * &b);
	void Destory(Node<T> *Current);
public:
	BinaryTree()
	{
		root=NULL;
	}
	~BinaryTree()
	{
		Destory(root);
	}
	void Creat(T *data,int n);
	void InOrder()
	{
		InOrder(root);
	}
	void Remove(const T &data)
	{
		Remove(data,root,root);
	}
};
template<typename T>
	void BinaryTree<T>::Destory(Node<T> *Current)
{
	if(Current!=NULL)
	{
		Destory(Current->lchild);
		Destory(Current->rchild);
		delete Current;
	}
}
template<typename T>
	void BinaryTree<T>::Insert(const T &data,Node<T> * &b)
{
	if(b==NULL)
	{
		b=new Node<T>(data);
		if(b==NULL)
		{
			cout<<"空间不足"<<endl;
			exit(1);
		}
	}
	else if(data<b->info)
		Insert(data,b->lchild);
	else
		Insert(data,b->rchild);
}
template<typename T>
	void BinaryTree<T>::Creat(T *data,int n)
{
	for(int i=0;i<n;i++)
		Insert(data[i],root);
}
template<typename T>
	void BinaryTree<T>::InOrder(Node<T> *Current)
{
	if(Current!=NULL)
	{
		InOrder(Current->lchild);
		cout<<Current->info<<"  ";
		InOrder(Current->rchild);
	}
}
template<typename T>
	void BinaryTree<T>::Remove(const T &data,Node<T> * &a,Node<T> * &b)
{
	Node<T> *temp1,*temp2;
	if(b!=NULL)
		if(data<b->info)    Remove(data,b,b->lchild);
	else if(data>b->info)    Remove(data,b,b->rchild);
	else if(b->lchild!=NULL&&b->rchild!=NULL)
	{
		temp2=b;
		temp1=b->rchild;
		if(temp1->lchild!=NULL)
		{
			while(temp1->lchild!=NULL)
			{
				temp2=temp1;
				temp1=temp1->lchild;
			}
			temp2->lchild=temp1->rchild;
		}
		else temp2->rchild=temp1->rchild;
		b->info=temp1->info;
		delete temp1;
	}
		else
		{
			temp1=b;
			if(b->rchild!=NULL)
			{
				temp1=b->rchild;
				b->info=temp1->info;
				b->rchild=temp1->rchild;
				b->lchild=temp1->lchild;
			}
			else if(b->lchild!=NULL)
			{
			       temp1=b->lchild;
				b->info=temp1->info;
				b->rchild=temp1->rchild;
				b->lchild=temp1->lchild;
			}
			else if(b==root)    root=NULL;
			else if(a->rchild==temp1)  a->rchild=NULL;
			else a->lchild=NULL;
			delete temp1;
		
	}
}
void main()
{
   const int n=15;
   int i,a[n]={10,5,15,8,3,18,13,12,14,16,20,1,4,6,9};
   BinaryTree<int> btree;
   btree.Creat(a,n);
   cout<<"输入数据："<<endl;
   for(i=0;i<n;i++)
   	cout<<a[i]<<" ";
   cout<<endl<<"中序："<<endl;
   btree.InOrder();
   btree.Remove(a[13]);
   cout<<endl<<"中序："<<endl;
   btree.InOrder();
  btree.Remove(a[3]);
  cout<<endl<<"中序："<<endl;
   btree.InOrder();
  btree.Remove(a[9]);
  cout<<endl<<"中序："<<endl;
  btree.InOrder();
  btree.Remove(a[2]);
   cout<<endl<<"中序："<<endl;
  btree.InOrder();
  btree.Remove(a[0]);
   cout<<endl<<"中序："<<endl;
  btree.InOrder();
  int a1[1]={10};
  BinaryTree<int> btree1;
  btree1.Creat(a1,1);
  cout<<"输入数据："<<"\t"<<a1[0]<<"\t";
  cout<<endl<<"中序："<<"\t";
  btree1.InOrder();
  btree1.Remove(a[0]);
  cout<<endl<<"中序："<<endl;
  btree1.InOrder();
}







  #include<iostream.h>
  class RMB
  {
  public:
  	RMB(unsigned int d,unsigned int c);
  	RMB operator +(RMB&);
  	RMB& operator ++();
  	void display()
  	{
  		cout<<(yuan+jf/100.0)<<endl;
  	}
  protected:
  	unsigned int yuan;
  	unsigned int jf;
  };
  RMB::RMB(unsigned int d,unsigned int c)
  {
       yuan=d;
       jf=c;
       while(jf>=100)
       {
            yuan++;
            jf-=100;
       }
  }
  RMB RMB::operator +(RMB& s)
  {
        unsigned int c=jf+s.jf;
        unsigned int d=yuan+s.yuan;
        RMB result(d,c);
        return result;
  }
  RMB& RMB::operator ++()
  {
        jf++;
        if(jf>=100)
        {
           jf-=100;
           yuan++;
        }
        return *this;
  }
  void main()
  {
  	RMB d1(1,60);
  	RMB d2(2,50);
  	RMB d3(0,0);
  	d3=d1+d2;
  	++d3;
  	d3.display();
  }







#include<iostream.h>
#include<string.h>
class String
{
	char name[256];
public:
	String(char *str)
	{
		strcpy(name,str);
	}
	String() {}
	String operator +(const String&);
	void display()
	{
	     cout<<"The string is:"<<name<<endl;
	}
};
static char *str;
String String::operator +(const String& a)
{
	strcpy(str,name);
	strcat(str,a.name);
	return String(str);
}
void main()
{
	str=new char[256];
	String demo1("Visual C++　");
	String demo2("6.0　");
	demo1.display();
	demo2.display();
	String demo3=demo1+demo2;
	demo3.display();
	String demo4=demo3+"Programming.";
	demo4.display();
	delete str;
}







#include<iostream.h>
#include<string.h>
class String
{
	char name[256];
public:
	String(char *str)
	{
		cout<<"constructor,char *---->String\n";
		strcpy(name,str);
	}
	String(String &s)
	{
		cout<<"copy constructor\n";
		strcpy(name,s.name);
	}
	String() {cout<<"default constructor\n";}
	~String() {}
	String operator +(const String&);
	void operator =(const String& s)
	{
		strcpy(name,s.name);
		cout<<"operator ="<<endl;
	}
	void display()
	{
		cout<<"The string is:"<<name<<endl;
	}
};
static char * str;
String String::operator +(const String& a)
{
	String s;
	cout<<"operator +"<<endl;
	strcpy(s.name,name);
	strcat(s.name,a.name);
	return s;
}
void main()
{
	str=new char[256];
	String demo1("Visual c++");
	String demo2("6.0");
	demo1.display();
	demo2.display();
	String demo3;
	demo3=demo1+demo2;
	cout<<"----------------------------\n";
	demo3.display();
	String demo4;
	demo4=demo3+"Programming!";
	demo4.display();
	delete str;
	cout<<"----------------------------\n";
	String demo5=demo4;
	demo5.display();
}







#include<iostream.h>
class RMB
{
public:
	RMB(unsigned int d,unsigned int c);
	friend RMB operator +(RMB&,RMB&);
	friend RMB& operator ++(RMB&);
	void display()
	{
		cout<<(yuan+jf/100.0)<<endl;
	}
protected:
	unsigned int yuan;
	unsigned int jf;
};
RMB::RMB(unsigned int d,unsigned int c)
{
   yuan=d;
   jf=c;
   while(jf>=100)
   {
        yuan++;
        jf-=100;
   }
}
RMB operator +(RMB& s1,RMB& s2)
{
     unsigned int jf=s1.jf+s2.jf;
     unsigned int yuan=s1.yuan+s2.yuan;
     RMB result(yuan,jf);
     return result;
}
RMB& operator ++(RMB& s)
{
    s.jf++;
    if(s.jf>=100)
    {
         s.jf-=100;
         s.yuan++;
    }
    return s;
}
void main()
{
	RMB d1(1,60);
	RMB d2(2,50);
	RMB d3(0,0);
	d3=d1+d2;
	++d3;
	d3.display();
}





#include<iostream.h>
#include<string.h>
class String
{
	char name[256];
public:
	String(char *str)
	{
		strcpy(name,str);
	}
	String() {}
	~String() {}
	friend String operator +(const String&,const String&);
	void display()
	{
	    cout<<"The string is:"<<name<<endl;
	}
};
static char *str;
String operator +(const String& a,const String& b)
{
	strcpy(str,a.name);
	strcat(str,b.name);
	return String(str);
}
void main()
{
	str=new char[256];
	String demo1("Visual C++");
	String demo2("6.0");
	demo1.display();
	demo2.display();
	String demo3=demo1+demo2;
	demo3.display();
	String demo4=demo3+"Programming.";
	demo4.display();
	String demo5="Programming "+demo4;
	demo5.display();
	delete str;
}









#include<iostream.h>
class complex
{
	float real,imag;
public:
	complex(float r=0,float i=0)
	{
		real=r;
		imag=i;
	}
	void print();
	friend complex operator +(complex a,complex b);
	friend complex operator -(complex a,complex b);
	friend complex operator *(complex a,complex b);
	friend complex operator /(complex a,complex b);
};
void complex::print()
{
	cout<<real;
	if(imag>0)   cout<<"+";
	if(imag!=0)  cout<<imag<<"i\n";
}
complex operator +(complex a,complex b)
{
	complex temp;
	temp.real=a.real+b.real;
	temp.imag=a.imag+b.imag;
	return temp;
}
complex operator -(complex a,complex b)
{
	complex temp;
	temp.real=a.real-b.real;
	temp.imag=a.imag-b.imag;
	return temp;
}
complex operator *(complex a,complex b)
{
      complex temp;
      temp.real=a.real*b.real-a.imag*b.imag;
      temp.real=a.real*b.imag+a.imag*b.real;
      return temp;
}
complex operator /(complex a,complex b)
{
      complex temp;
      float tt;
      tt=1/(b.real*b.real+b.imag*b.imag);
      temp.real=(a.real*b.real+a.imag*b.imag)*tt;
      temp.imag=(b.real*a.imag-a.real*b.imag)*tt;
      return temp;
}
void main()
{
	complex c1(2.3,4.6),c2(3.6,2.8),c3;
	c1.print();
	c2.print();
	c3=c1+c2;
	c3.print();
	c3=c1-c2;
	c3.print();
	c3=c1*c2;
	c3.print();
	c3=c1/c2;
	c3.print();
}



#include<iostream.h>
#include<string.h>
class Student
{
	char name[10];
	float score[3];
	static unsigned int sum;
public:
	void operator [](Student&);
		Student(char *na,float ma=0,float en=0,float ph=0)
	{
		score[0]=ma;score[1]=en;score[2]=ph;strcpy(name,na);
	}
	void operator !()
	{
		if(sum>0)
			cout<<"Mat:"<<score[0]/sum
				<<"  Eng:"<<score[1]/sum
				<<"  Phy"<<score[2]/sum<<endl;
	}
};
void Student::operator [](Student& s)
{
	unsigned int i;
	float nt=0.;
	for(i=0;i<3;i++)
	{
		score[i]+=s.score[i];
		nt+=s.score[i];
	}
	cout<<s.name<<"     :"<<nt/3<<endl;
	sum++;
}
unsigned int Student::sum=0;
void main()
{
	int i;
	Student sa[]={Student("wang ",60,70,80),Student("li   ",70,80,90),Student("zhang",50,60,70)},total("Total");
	for(i=0;i<3;i++)
		total[sa[i]];
	!total;
}




#include<iostream.h>
class Increase
{
public:
	Increase(int x):value(x){}
	Increase & operator ++();
	Increase operator ++(int);
	void display()
	{
		cout<<"the value is:"<<value<<endl;
	}
private:
	int value;
};
Increase & Increase::operator ++()
{
	value++;
	return *this;
}
Increase Increase::operator ++(int)
{
	Increase temp(* this);
	value++;
	return temp;
}
void main()
{
	Increase n(20);
	n.display();
	(n++).display();
	n.display();
	++n;
	n.display();
	++(++n);
	n.display();
	(n++)++;
	n.display();
}



#include<iostream.h>
class Increase
{
public:
	Increase(int x):value(x){}
	friend Increase & operator ++(Increase&);
	friend Increase operator ++(Increase&,int);
	void display()
	{
	     cout<<"the value is:"<<value<<endl;
	}
private:
	int value;
};
Increase & operator ++(Increase& a)
{
     a.value++;
     return a;
}
Increase operator ++(Increase& a,int)
{
	Increase temp(a);
	a.value++;
	return temp;
}
void main()
{
	Increase n(20);
	n.display();
	(n++).display();
	n.display();
	++n;
	n.display();
	++(++n);
	n.display();
	(n++)++;
	n.display();
}





#include<iostream.h>
class pp
{
public:
	int n;
	float m;
	pp * operator->()
	{
	   return this;
	}
};
void main()
{
   pp t1;
   t1->m=10;
   cout<<"t1. m is:"<<t1.m<<endl;
   cout<<"t1->m is:"<<t1->m<<endl;
}





#include<iostream.h>
class Sample
{
	int n;
public:
	Sample() {}
	Sample(int i)
	{
		n=i;
	}
	Sample & operator =(Sample);
		void disp()
	{
		cout<<"n="<<n<<endl;
	}
};
Sample & Sample::operator =(Sample s)
{
	Sample::n=s.n;
	return *this;
}
void main()
{
	Sample s1(10),s2;
	s2=s1;
	s2.disp();
}




#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(char *na)
	{
		cout<<"call constructor"<<endl;
		name=new char[strlen(na)+1];
		if(name!=0)
		{
			strcpy(name,na);
		}
	}
	Person(Person& p)
	{
	cout<<"call copy constructor"<<endl;
	name=new char[strlen(p.name)+1];
	}
	void printname()
	{
	 cout<<name<<endl;
	}
	~Person()
	{
	    delete name;
	}
	operator =(Person& p)
	{
	     cout<<"call operator override"<<endl;
	     name=new char[strlen(p.name)+1];
	     if(name!=0)
	     	strcpy(name,p.name);
	}
private:
	char *name;
};
void main()
{
	Person wang("wang");
	Person li(wang);
	li=wang;
	li.printname();
}




#include<iostream.h>
#include<string.h>
class Name
{
public:
	Name() {pName=0;}
	Name(char *pn) {copyName(pn);}
	~Name() {deleteName();}
	Name & operator =(Name& s)
	{
		deleteName();
		copyName(s.pName);
		return *this;
	}
	void display() {cout<<pName<<endl;}
protected:
	void copyName(char *pN);
	void deleteName();
	char *pName;
};
void Name::copyName(char *pN)
{
	pName=new char[strlen(pN)+1];
	if(pName)
		strcpy(pName,pN);
}
void Name::deleteName()
{
	if(pName)
	{
		delete pName;
		pName=0;
	}
}
void main()
{
	Name s("Jone");
	Name t("temporary");
	t.display();
	t=s;
	t.display();
}




#include<iostream.h>
#include<malloc.h>
class Point
{
    int x,y;
   public:
    Point() {}
    Point(int l,int w)
    {
        x=l;
        y=w;
    }
    void disp()
    {
         cout<<"面积："<<x*y<<endl;
    }
    Point operator ,(Point r)
    {
         Point temp;
         temp.x=r.x;
         temp.y=r.y;
         return temp;
    }
    Point operator +(Point r)
    {
         Point temp;
         temp.x=r.x+x;
         temp.y=r.y+y;
         return temp;
    }
};
void main()
{
	Point r1(1,2),r2(3,4),r3(5,6);
	r1.disp();
	r2.disp();
	r3.disp();
	r1=(r1,r2+r3,r3);
	r1.disp();
}




#include<iostream.h>
class base
{
public:
	void who()
	{
		cout<<"this is the class of base !"<<endl;
	}
};
class derive1:public base
{
public:
	void who()
	{
		cout<<"this is the class of derive1!"<<endl;
	}
};
class derive2:public base
{
public:
	void who()
	{
		cout<<"this is the class of derive2!"<<endl;
	}
};
void main()
{
    base obj1,*p;
    derive1 obj2;
    derive2 obj3;
    p=&obj1;
    p->who();
    p=&obj2;
    p->who();
    ((derive2 *)p)->who();
    obj2.who();
    obj3.who();
}






#include<iostream.h>
class base
{
public:
	virtual void f1()
	{
	   cout<<"f1 function of base"<<endl;
	}
	virtual void f2()
	{
	   cout<<"f2 function of base"<<endl;
	}
	virtual void f3()
	{
	   cout<<"f3 function of base"<<endl;
	}
	virtual void f4()
	{
	   cout<<"f4 function of base"<<endl;
	}
};
class derive:public base
{
	void f1()
	{
	   cout<<"f1 function of derive!"<<endl;
	}
	void f2(int x)
	{
	   cout<<"f2 function of derive!"<<endl;
	}
	void f3()
	{
	   cout<<"f3 function of derive!"<<endl;
	}
	void f4()
	{
	   cout<<"f4 function of derive!"<<endl;
	}
};
void main()
{
    base obj1,*ptr;
    derive obj2;
    ptr=&obj1;
    ptr->f1();
    ptr->f2();
    ptr->f3();
    ptr=&obj2;
    ptr->f1();
    ptr->f2();
    ptr->f3();
}





#include<iostream.h>
class A
{
public:
	A()
	{
	    cout<<"the constructor of class is A"<<endl;
	    f();
	}
	virtual void f()
	{
	   cout<<"A::f()"<<endl;
	}
	void g()
	{
	     cout<<"A::g()"<<endl;
	}
	void h()
	{
	    cout<<"A::h()"<<endl;
	    f();g();
	}
};
class B:public A
{
public:
	void f()
	{
	    cout<<"B::f()"<<endl;
	}
	void g()
	{
	  cout<<"B::g()"<<endl;
	}
};
void main()
{
   A a;
   B b;
   A *p=&b;
   p->f();
   p->g();
   p->h();
   a.f();
   a.g();
   a.h();
   b.f();
   b.g();
   b.h();
}




#include<iostream.h>
class base
{
public:
	base(){}
	virtual void vf()
	{
		cout<<"base::vf() called"<<endl;
	}
};
class son:public base
{
public:
	son(){vf();}
	void g(){vf();}
};
class grandson:public son
{
public:
	grandson(){}
	void vf()
	{
	    cout<<"grandson::vf() called\n";
	}
};
void main()
{
    grandson gs;
    gs.g();
}




#include<iostream.h>
class base
{
public:
	virtual void print()
	{
	   cout<<"class base\n";
	}
};
class son:public base
{
public:
	virtual void print(){}
};
class grandson:public son
{
public:
	virtual void print()
	{
	    cout<<"class grandson!\n";
	}
};
void show(base *p)
{
	p->print();
}
void main()
{
   base *pbase=new base;
   son *pson=new son;
   grandson *pgrandson=new grandson;
   show(pbase);
   show(pson);
   show(pgrandson);
}




#include<iostream.h>
class shape
{
public:
	virtual float area()=0;
};
class triangle:public shape
{
protected:
	float h,w;
public:
	triangle(float hh,float ww)
	{
		h=hh;
		w=ww;
	}
	float area() {return float(h*w*0.5);}
};
class rectangle:public triangle
{
public:
	rectangle(float h,float w):triangle(h,w){}
	float area() {return h*w;}
};
class circle:public shape
{
private:
	float radius;
public:
	circle(float r)
	{radius=r;}
	float area()
	{
	   return float(radius*radius*3.14);
	}
};
float total(shape *s[],int n)
{
    float sum=0;
    for(int j=0;j<n;j++)
    	sum+=s[j]->area();
    return sum;
}
void main()
{
	shape *s[4];
	s[0]=new triangle(3,4);
	s[1]=new rectangle(2,4);
	s[2]=new circle(5);
	s[3]=new circle(8);
	float sum=total(s,4);
	cout<<sum<<endl;
}




#include<iostream.h>
#include<string.h>
#include<conio.h>
class person
{
	friend class list;
protected:
	char name[20];
	int age;
	char add[40];
	char tele[15];
	static person *ptr;
	person *next;
public:
	person(char *,int,char *,char *);
	virtual void print();
	virtual void insert()=0;
};
class student:public person
{
	friend class list;
	int level;
	float grade_point_average;
public:
	student(char *,int,char *,char *,int,float );
	void print();
	void insert();
};
class teacher:public person
{
	friend class list;
	float salary;
public:
	teacher(char *,int,char *,char *,float );
	void print();
	void insert();
};
class staff:public person
{
	friend class list;
	float hourly_wages;
public:
	staff(char *,int,char *,char *,float );
	void print();
	void insert();
};
class list
{
	person *root;
public:
	list() {root=0;}
	void insert_person(person *node);
	void remove(char *name);
	void print_list();
};
person::person(char *name,int age,char *add,char *tele)
{
	strcpy(person::name,name);
	strcpy(person::add,add);
	strcpy(person::tele,tele);
	person::age=age;
	next=0;
}
void person::print()
{
	cout<<"\nname:"<<name<<"\n";
	cout<<"age:"<<age<<"\n";
	cout<<"address:"<<add<<"\n";
	cout<<"telephone number:"<<tele<<"\n";
}
student::student(char *name,int age,char *add,char *tele,int level,float grade_point_average):person(name,age,add,tele)
{
	student::level=level;
	student::grade_point_average=grade_point_average;
}
void student::print()
{
	person::print();
	cout<<"grade_point_average:"<<grade_point_average<<endl;
	cout<<"level:"<<level<<endl;
}
void student::insert()
{
	ptr=new student(name,age,add,tele,level,grade_point_average);
}
teacher::teacher(char *name,int age,char *add,char *tele,float salary):person(name,age,add,tele)
{
	teacher::salary=salary;
}
void teacher::print()
{
	person::print();
	cout<<"salary:"<<salary<<"\n";
}
void teacher::insert()
{
	ptr=new teacher(name,age,add,tele,salary);
}
staff::staff(char *name,int age,char *add,char *tele,float hourly_wages):person(name,age,add,tele)
{
	staff::hourly_wages=hourly_wages;
}
void staff::print()
{
	person::print();
	cout<<"hourly_wages:"<<hourly_wages<<"\n";
}
void staff::insert()
{
	ptr=new staff(name,age,add,tele,hourly_wages);
}
void list::insert_person(person *node)
{
	char key[20];
	strcpy(key,node->name);
	person *curr_node=root;
	person *previous=0;
	while(curr_node!=0&&strcmp(curr_node->name,key)<0)
	{
	    previous=curr_node;
	    curr_node=curr_node->next;
	}
	node->insert();
	node->ptr->next=curr_node;
	if(previous==0)
		root=node->ptr;
	else previous->next=node->ptr;
}
void list::remove(char *name)
{
     person *curr_node=root;
     person *previous=0;
     while(curr_node!=0&&strcmp(curr_node->name,name)!=0)
     {
         previous=curr_node;
         curr_node=curr_node->next;
     }
     if(curr_node!=0&&previous==0)
     {
          root=curr_node->next;
          delete curr_node;
     }
     else if(curr_node!=0&&previous!=0)
     {
         previous->next=curr_node->next;
         delete curr_node;
     }
}
void list::print_list()
{
      person *cur=root;
      while(cur!=0)
      {
      	cur->print();
      	cur=cur->next;
      }
}
person *person::ptr=0;
void main()
{
   list people;
   student stu("wangchong",20,"shanghai","024578414",3,54);
   teacher tea("lining",43,"beijing","011645274",564);
   staff sta("chenling",42,"qingdao","213456715",20);                                                                 
   people.insert_person(&stu);
   people.insert_person(&tea);
   people.insert_person(&sta);
   people.print_list();
   cout<<endl<<"删除："<<endl;
   people.remove("chenling");
   people.remove("lining");
   people.remove("wangchong");
   people.print_list();
}




#include<iostream.h>
#include<string.h>
class base
{
	char *p;
public:
	base(int sz,char *bptr)
	{
		p=new char [sz];
		strcpy(p,bptr);
		cout<<"constructor base"<<endl;
	}
	virtual ~base()
	{
		delete []p;
		cout<<"destructor base\n";
	}
};
class derive:public base
{
	char *pp;
public:
	derive(int sz1,int sz2,char *bp,char *dptr):base(sz1,bp)
	{
		pp=new char [sz2];
		strcpy(pp,dptr);
		cout<<"constructor derive"<<endl;
	}
	~derive()
	{
		delete []pp;
		cout<<"destructor derive\n";
	}
};
void main()
{
	base *px=new derive(5,7,"base","derive");
	delete px;
}







#include<iostream.h>
#include<conio.h>
class fairy_tale
{
public:
	virtual void act1()
	{
		cout<<"princess meets frog\n";
		act2();
	}
	void act2()
	{
		cout<<"princess kisses frog\n";
		act3();
	}
	virtual void act3()
	{
		cout<<"frog turns into prince\n";
		act4();
	}
	virtual void act4()
	{
		cout<<"they live happy ever after\n";
		act5();
	}
	virtual void act5()
	{
		cout<<"the end\n";
	}
};
class unhappy_tale:public fairy_tale
{
	void act3()
	{
	   cout<<"frog stays another frog\n";
	   act4();
	}
	void act4()
	{
	   cout<<"princess runs away in disgust\n";
	   act5();
	}
	void act5()
	{
	   cout<<"the not-so-happy end\n";
	}
};
void main()
{
   char ch;
   fairy_tale *tale;
   cout<<"which tale would you like to hear(f/u)?\n";
   cin>>ch;
   if(ch=='f')
   	tale=new fairy_tale;
   else
   	tale=new unhappy_tale;
   tale->act1();
   delete tale;
}



#include<iostream.h>
#include<iomanip.h>
void main()
{
	int x=30,y=300,z=1024;
	cout<<"Decimal:"<<x<<''<<y<<''<<z<<endl;
	cout<<"Octal:"<<oct<<x<<''<<y<<''<<z<<endl;
	cout<<"Hexadecimal:"<<hex<<x<<''<<y<<''<<z<<endl;
	cout<<setiosflags(ios:uppercase);
	cout<<"Hexadecimal:"<<hex<<x<<''<<y<<''<<z<<endl;
	cout<<resetiosflags(ios:uppercase);
	cout<<"Hexadecimal:"<<hex<<x<<''<<y<<''<<z<<endl;
	cout<<"Decimal:"<<dec<<x<<''<<y<<''<<z<<endl;
}





#include<iostream.h>
#include<iomanip.h>
void main()
{
	int x=30,y=300,z=1024;
cout<<"Decimal:"<<x<<' '<<y<<' '<<z<<endl;
	cout<<"Octal:"<<oct<<x<<' '<<y<<' '<<z<<endl;
	cout<<"Hexadecimal:"<<hex<<x<<' '<<y<<' '<<z<<endl;
	cout<<setiosflags(ios::uppercase);
	cout<<"Hexadecimal:"<<hex<<x<<' '<<y<<' '<<z<<endl;
	cout<<resetiosflags(ios::uppercase);
	cout<<"Hexadecimal:"<<hex<<x<<' '<<y<<' '<<z<<endl;
	cout<<"Decimal:"<<dec<<x<<' '<<y<<' '<<z<<endl;
}






#include<iostream.h>
#include<iomanip.h>
void main()
{
   int a=10;
   int b=1000;
   cout<<setw(15)<<a<<"\n";
   cout<<setw(2)<<b;	
}






#include<iostream.h>
#include<iomanip.h>
void main()
{
    /*cout<<setfill('*')	
        <<setw(2)<<"OK"<<endl
        <<setw(3)<<"OK"<<endl
        <<setw(4)<<"OK"<<endl
        <<setw(5)<<"OK"<<endl;
        cout<<setfill(' ');*/
        int i;
        for(i=2;i<=5;i++)
        {
           	cout<<setfill('*')
           	    <<setw(i)<<"OK"<<endl;
           	    /*cout<<setfill(' ');*/
        }
         cout<<setfill(' ');
}






#include<iostream.h>
#include<iomanip.h>
void main()
{
    double test=22.0/7;
    cout<<test<<endl;	
    cout<<setprecision(0)<<test<<endl
        <<setprecision(1)<<test<<endl
        <<setprecision(2)<<test<<endl
        <<setprecision(3)<<test<<endl
        <<setprecision(4)<<test<<endl;
        cout<<setiosflags(ios::fixed);
        cout<<setprecision(8)<<test<<endl;
        cout<<setprecision(6);
}





#include<iostream.h>
#include<iomanip.h>
void main()
{
  cout<<setiosflags(ios::right)	
      <<setw(5)<<1
      <<setw(5)<<2
      <<setw(5)<<3<<endl;
      cout<<setiosflags(ios::left)	
      <<setw(5)<<1
      <<setw(5)<<2
      <<setw(5)<<3<<endl;
}





#include<iostream.h>
#include<iomanip.h>
void main()
{
   double x=66,y=-8.246;
   cout<<x<<" "<<y<<endl;
   cout<<setiosflags(ios::showpoint);	
   cout<<x<<" "<<y<<endl;
}








#include<iostream.h>
#include<iomanip.h>
void main()
{
   double x=66,y=-8.246;
   cout<<x<<" "<<y<<endl;
   cout<<setiosflags(ios::showpos);	
   cout<<x<<" "<<y<<endl;
}






#include<iostream.h>
void main()
{
  char str[250];
  cout<<"请输入一个字符串：\n";
  cin.getline(str,sizeof(str),',');
  cout<<"输入的字符串为："<<str<<endl;
}






#include<iostream.h>
void main()
{
  int x=123;
  double y=-33.1415926;
  cout<<"x=";
  cout.width(10);
  cout<<x;
  cout<<"y=";
  cout.width(10);
  cout<<y<<endl;
  cout.setf(ios::left);
  cout<<"x=";
  cout.width(10);
  cout<<x;
  cout<<"y=";
  cout.width(10);
  cout<<y<<endl;
  cout.fill('*');
  cout.precision(3);
  cout.setf(ios::showpos);
  cout<<"x=";
  cout.width(10);
  cout<<x;
  cout<<"y=";
  cout.width(10);
  cout<<y<<endl;
  cout.setf(ios::scientific);
  cout<<x<<' '<<y<<endl;
  cout.setf(ios::fixed);
   cout<<x<<' '<<y<<endl;
}





#include<iomanip.h>
class RMB
{
public:
	RMB(double v=0.0)
	{
		yuan=unsigned(v);
		jf=unsigned((v-yuan)*100.0+0.5);
	}
	operator double()
	{
	    return yuan+jf/100.0;
	}
	void display(ostream& out)
	{
		out<<yuan<<'.'<<setfill('0')
			<<setw(2)<<jf<<setfill(' ');
	}
protected:
	unsigned int yuan;
	unsigned int jf;
};
ostream& operator <<(ostream& ot,RMB& d)
{
	d.display(ot);
	return ot;
}
void main()
{
	RMB rmb(2.3);
	cout<<"Initially rmb="<<rmb<<"\n";
	rmb=2.0*rmb;
	cout<<"then rmb="<<rmb<<"\n";
}





#include<iostream.h>
class complex
{
	float real,image;
public:
	complex(float r=0,float i=0)
	{
		real=r;
		image=i;
	}
	friend ostream & operator <<(ostream &,complex &);
	friend istream & operator >>(istream &,complex &);
};
ostream & operator <<(ostream &output,complex &obj)
{
	output<<obj.real;
	if(obj.image>0) output<<"+";
	if(obj.image!=0) output<<obj.image<<"i";
	return output;
}
istream & operator >>(istream &input,complex &obj)
{
	cout<<"Input the real,image of the complex\n";
	input>>obj.real;
	input>>obj.image;
	return input;
}
void main()
{
	complex c1(2.3,4.6),c2(3.6,2.8),c3;
	cout<<"the value of c1 is:"<<c1<<"\n";
	cout<<"the value of c2 is:"<<c2<<"\n";
	cin>>c3;
	cout<<"the value of c3 is:"<<c3<<"\n";
}





#include<iostream.h>
#include<fstream.h>
#include<string.h>
void main()
{
   ofstream myf("e:\\myabc.txt");	
   char txt[255];
   while(1)
   {
   	  cin.getline(txt,255);
   	  if(strlen(txt)==0)
   	    break;
   	    myf<<txt<<endl;
   	}
}

#include<iostream.h>
#include<fstream.h>
class student
{
public:
	char name[10];
	int num;
	int age;
	char addr[15];
	friend ostream & operator <<(ostream &out,student &s);
	friend istream & operator <<(istream &in,student &s);
};
ostream & operator <<(ostream &out,student &s)
{
    out<<s.name<<" "<<s.num<<" "<<s.age<<" "
    	<<s.addr<<"\n";
    return out;
}
istream & operator >>(istream &in,student &s)
{
    in>>s.name>>s.num>>s.age>>s.addr;
    return in;
}
void main()
{
       ofstream ofile;
       ifstream ifile;
       ofile.open("e:\\s.txt");
       student s;
       for(int i=1;i<=3;i++)
       {
           cout<<"请输入第"<<i<<"个学生的姓名 学号 年龄 住址"<<endl;
           cin>>s;
           ofile<<s;
       }
       ofile.close();
       cout<<"\n读出文件内容"<<endl;
       ifile.open("e:\\s.txt");
       ifile>>s;
       while(!ifile.eof())
       {
           cout<<s;
           ifile>>s;
       }
       ifile.close();
}

#include<iostream.h>
#include<math.h>
void main()
{
   int n,i,flag,count=0;
   for(n=2;n<=100;n++)
   {
       flag=1;
       for(i=2;i<=sqrt(n);i++)	
          if(n%i==0)
          {
                flag=0;
                break;	
          }
        if(flag==1)
        {
            cout<<n<<"\t";
            count++;
            if(count%10==0)	 cout<<endl; 
        }
   }
      	
}

#include<iostream.h>
#include<math.h>
void main()
{
      int n,i,count=0;
      for(n=2;n<=100;n++) 
        {
           for(i=2;i<=sqrt(n);i++)	
              if(n%i==0)
                {
                 break;
                }
                else
                {
                      cout<<n<<endl;
                      	
                }
        } 	
}

#include<iostream.h>

int fact(int n)
{
	long int f;
	if(n==0||n==1)  f=1;
       else
    	 f=fact(n-1)*n;
    	return f;
}
void main()
{   long int t=0;
    for(int i=1;i<=20;i++)
     t+= fact(i);
    cout<<t;
}

#include<iostream.h>
void main()
{
   double sum=0,t=1,i,j;
   for(i=1;i<=20;i++)	 
      {
           /*for(j=1;j<=i;j++)	*/
           
                t=t*j;
          
            sum+=t;
      }
     
      cout<<sum;
}

#include<iostream.h>
void main()
{
   int sum=0,t=1,i,j;
   for(i=1;i<=5;i++)	 
   {
	     t*=i;
		                
           sum+=t; 
   }   
      cout<<sum;
}

#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
void sort(int [],int);
void main()
{
    fstream dat,out;
    int i,a[20],b[20];
    dat.open("E:\\file.dat",ios::binary|ios::out|ios::in);
    if(!dat)
    {
    	cout<<"can't open file\n";
    	exit(0);
    }
    for(i=0;i<20;i++)
    {
    	a[i]=rand();
    	dat.write((char *)&a[i],sizeof(int));
    }
    dat.seekg(0);
    for(i=0;i<20;i++)
    {
       dat.read((char *)&b[i],sizeof(int));
    }
    sort(b,20);
    out.open("E:\\file.out",ios::out);
    if(!out)
    {
        cout<<"cannot open file\n";
        exit(0);
    }
    for(i=0;i<20;i++)
    {
    	out<<b[i]<<' ';
    }
    out<<'\n';
    for(i=0;i<20;i++)
    {
    	cout<<setw(10)<<b[i];
    	if((i+1)%5==0) cout<<endl;
    }
    out.close();
    dat.close();
}
void sort(int x[],int m)
{
   int i,j,k,t;
   for(i=0;i<m-1;i++)
   {
        k=i;
        for(j=i+1;j<m;j++)
        	if(x[j]<x[k])  k=j;
        if(k!=i)
        {
        	t=x[i];x[i]=x[k];x[k]=t;
        }
   }
}


#include<fstream.h>
#include<iostream.h>
void main()
{
	fstream f("e:\\filein.txt",ios::in|ios::out|ios::binary);
	int i;
	for(i=0;i<20;i++)
		f.write((char *)&i,sizeof(int));
	streampos pos=f.tellp();
	for(i=20;i<40;i++)
	f.write((char *)&i,sizeof(int));
	f.seekg(pos);
	f.read((char *)&i,sizeof(int));
	cout<<"the data stored is:"<<i<<endl;
	f.seekp(0,ios::beg);
	for(i=100;i<140;i++)
		f.write((char *)&i,sizeof(int));
	f.seekg(pos);
	f.read((char *)&i,sizeof(int));
	cout<<"the data stored is "<<i<<endl;
}


#include<iostream.h>
double divide(double,double);
void main()
{
	double f1=0.0,f2=0.0;
	try
	{
		cout<<"f1/f2="<<divide(f1,f2)<<"\n";
	}
	catch(double)
	{
		cout<<"被0除"<<"\n";
	}
}
double divide(double x,double y)
{
	if(y==0)  throw 0.0;
	return x/y;
}


#include<iostream>
using namespace std;
void detail(int k)
{
   cout<<"start of detail function.\n";
   if(k==0) throw 123;
   cout<<"end of detail function.\n";

}
void compute(int i)
{
   cout<<"start of compute function.\n";
   detail(i);
  cout<<"end of compute function.\n";
}
int main()
{
    int x;
    cout<<"Enter x(0 will throw an exception):";
    cin>>x;
    try
    {
    	compute(x);
    }
    catch(int i)
    {
       cout<<"exception:"<<i<<endl;
    }
    cout<<"the end.\n";
    return 0;
}

#include<iostream>
using namespace std;
void main()
{
	 int i;
	 char ch;
 	 cout<<"请输入一个整数和一个字符";
 	 try
 	 {
 	    cin>>i>>ch;
 	    if(i==0)  throw 0;
 	    if(ch=='!')  throw '!';	
 	 }
 	 catch(int)
 	 {
 	     cout<<"输入为0\n";	
 	 }
 	 catch(char)
 	 {
 	   cout<<"输入字符！";	
 	 }
 	 cout<<"程序结束";
}


#include<iostream>
using namespace std;
class OutOfBounds
{
	 public:
	   OutOfBounds(int a)
	   { i=a;}
	   int indexValue()
	   {return i;}
	   private:
	   int i;
 
};
class Array
{
    public:
     int &operator[](int i)	
     {
          if(i<0||i>=10)	
          throw OutOfBounds(i);
          return a[i];
     }
     private:
     int a[10];
};
void main()
{
   Array a;
   try
   {
      a[3]=30;	
      cout<<"a[3]"<<a[3]<<endl;
      a[100]=1000;
      cout<<"a[100]"<<a[100]<<endl;
   }	
   catch(OutOfBounds error)
   {
   	  cout<<"subscript value"<<error.indexValue()<<"out of bounds.\n";
   }
   return;
}


#include<iostream>
using namespace std;
void h()
{ throw 0;}
void g()
{try{h();}
   catch(int)
   {
   	  cout<<"Catch in g\n";
   	  throw;
   	}
}
int main()
{
    try{g();}	
    catch(int)
    {
         cout<<"Catch in main\n";	
    }
    return 0;
}


#include<exception>
#include<iostream>
using namespace std;
void main()
{
  try
  {
    exception theError;
    throw(theError);	
  }	
  catch(const exception &theError)
  {
      cout<<theError.what()<<endl;	
  }
  try
  {
     logic_error theLogicError("Logic Error!");	
     throw(theLogicError);
  }
  catch(const exception & theLogicError)
  {
     cout<<theLogicError.what()<<endl;	
  }
}