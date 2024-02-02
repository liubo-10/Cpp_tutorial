/***********************************************************
 * @file name: 07_STL_set.cpp
 * @author: liubo
 * @date: 2024.02.01
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

const int maxCard = 16;
enum ErrCode{noErr,overflow};
enum Bool{False,True};




class Set
{
	int size;
	int *elems;
	int card;

	public:

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

class Set {
  public:
    Set(int sz=maxCard) {
        card=0;;
        size=sz;
        elems=new int[size];
    }
    void EmptySet(){card=0;}
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
    int elems[maxCard];
    int card;
};

Bool Set::Member(int elem) {
    for(int i=0;i<card;++i) {
        if(elems[i]==elem) {
            return True;
        }
    }
    return False;
}

ErrCode Set::AddElem(int elem) {
    if(Member(elem)) {
        return noErr;
    }
    if(card<maxCard) {
        elems[card++]=elem;
        return noErr;
    }
    return overflow;
}

void Set::RmvElem(int elem) {
    for(int i=0;i<card;++i) {
        if(elems[i]==elem) {
            for(;i<card-1;++i) {
                elems[i]=elems[i+1];
            }
            --card;
            return;
        }
    }
}

void Set::Copy(Set *set) {
    for(int i=0;i<card;++i) {
        set->elems[i]=elems[i];
    }
    set->card=card;
}

Bool Set::Equal(Set *set) {
    if(card!=set->card) {
        return False;
    }
    for(int i=0;i<card;++i) {
        if(!set->Member(elems[i])) {
            return False;
        }
    }
    return True;
}

void Set::Print() {
    cout<<"{";
    for(int i=0;i<card;++i) {
        cout<<elems[i]<<";";
    }
    cout<<"}\n";
}

void Set::Intersect(Set *set,Set *res) {//*this Π *set->*res
    res->card=0;
    for(int i=0;i<card;++i) {
        for(int j=0;j<set->card;++j) {
            if(elems[i]==set->elems[j]) {
                res->elems[res->card++]=elems[i];
                break;
            }
        }
    }
}

ErrCode Set::Union(Set *set,Set *res) {
    set->Copy(res); // set->res
    for(int i=0;i<card;++i) {
        if(res->AddElem(elems[i])==overflow) {
            return overflow;
        }
    }
    return noErr;
}

int main() {
    cout << "----------------begain------------------" << endl;

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

    if(s1.Member(20)) {
        cout<<"20 is in s1\n";
    }

    s1.Intersect(&s2,&s3);
    cout<<"s1 intsec s2=";s3.Print();

    s1.Union(&s2,&s3); // s1 s2 合并到s3
    cout<<"s1 union s2";s3.Print();

    if(!s1.Equal(&s2)) {
        cout<<"s1!=s2\n";
    }

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
----------------begain------------------
s1={10;20;30;40;}
s2={30;50;10;60;}
s2-{50}{30;10;60;}
20 is in s1
s1 intsec s2={10;30;}
s1 union s2{30;10;60;20;40;}
s1!=s2
----------------end------------------
 */
