








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

}
