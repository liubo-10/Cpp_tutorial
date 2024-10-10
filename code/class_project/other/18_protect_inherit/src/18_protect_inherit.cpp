/***********************************************************
 * @file name: 18_protect_inherit.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>
#include<string.h>

using std::cin;
using std::cout;
using std::endl;

class ST_COM {
  public:
    ST_COM(char *na,unsigned int n,float ma,float en,float ph):
    num(n),mat(ma),eng(en),phy(ph) {
        strcpy(name,na);
    }
  protected:
    char name[10];
    unsigned int num;
    float mat,eng,phy;
};
class EL_DEP:public ST_COM {
  public:
    EL_DEP(char *na,unsigned int n,float ma,float en,float ph,float pe,float el,float d):
    ST_COM(na,n,ma,en,ph),pex(pe),elnet(el),dst(d)
    {}
    void operator!() {
        cout<<"Name:"<<name<<"      Number:"<<num<<endl;
        cout<<"Mathematics Scor:"<<mat<<endl;
        cout<<"English Scor:    "<<eng<<endl;
        cout<<"Physics Scor:    "<<phy<<endl;
        cout<<"Exchange Scor:   "<<pex<<endl;
        cout<<"Elec_net Scor:   "<<elnet<<endl;
        cout<<"Data_struct Scor:"<<dst<<endl;
    }
  private:
    float pex,elnet,dst;
};

int main() {
    cout << "----------------begain------------------" << endl;

    EL_DEP a((char*)"wang",1234,71,72,73,81,82,83);
    !a;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}



/**
 * @expected output:
----------------begain------------------
Name:wang      Number:1234
Mathematics Scor:71
English Scor:    72
Physics Scor:    73
Exchange Scor:   81
Elec_net Scor:   82
Data_struct Scor:83
----------------end------------------
 * 
 */
