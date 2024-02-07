







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
