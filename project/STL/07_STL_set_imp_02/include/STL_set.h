/***********************************************************
 * @file name: STL_set.h
 * @author: liubo
 * @date: 2024.02.02
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

const maxCard=16;
enum ErrCode{noErr,overflow};
enum Bool{False,True};


class Set {
  public:
    Set(int sz=maxCard) {
        card=0;
        size=sz;
        elems=new int[size];
    }
    ~Set() {
        delete []elems;
    }


    void EmptySet() {
        card=0;
    }

    Bool Member(int);
    ErrCode AddElem(int);
    void RmvElem(int);
    void Copy(Set *);
    Bool Equal(Set *);
    void Print();
    void Intersect(Set *,Set *);
    ErrCode Union(Set *,Set *);

  private:
    int size;
    int *elems;
    int card;
};



class Set1
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





class Set2
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










