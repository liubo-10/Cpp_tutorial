/***********************************************************
 * @file name: 21_set_exchange.cpp
 * @author: liubo
 * @date: 2024.01.05
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#define maxcard 32

using std::cin;
using std::cout;
using std::endl;

class realset;
enum errcode{noerr, overflow};
class intset {
  public:
    intset() {
        card=0;
    }
    errcode addelem(int);
    void print();
    void settoreal(realset *set);
  private:
    int elem[maxcard];
    int card;
};

class realset {
  public:
    realset() {
        card=0;
    }
    errcode addelem(float);
    void print();
  private:
    float elem[maxcard];
    int card;
};

errcode intset::addelem(int elem1) {
    for(int i=0; i<card; i++) {
        if(elem[i]==elem1) {
            return noerr;
        }
    }
    if(card<maxcard) {
        elem[card++]=elem1;
        return noerr;
    } else {
        return overflow;
    }
}

void intset::print() {
    cout<<"{";
    for(int i=0;i<card-1;++i) {
        cout<<elem[i]<<",";
    }
    if(card>0) {
        cout<<elem[card-1];
    }
    cout<<"}\n";
}

void intset::settoreal(realset *set) {
    for(int i=0;i<card;i++) {
        set->addelem((float)elem[i]);
    }
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

int main() {
    cout << "----------------begain------------------" << endl;

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

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
{12,278,54,459}
{12,278,54,459}
----------------end------------------
 * 
 */
