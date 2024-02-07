


























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
