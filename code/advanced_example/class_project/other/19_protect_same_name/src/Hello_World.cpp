/***********************************************************
 * @file name: Hello_World.cpp
 * @author: liubo
 * @date: 2024.01.05
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
        avg=(mat+eng+phy)/3;
    }
    void operator!() {
        cout<<"Name:"<<name<<"      Number:"<<num<<endl;
        cout<<"Mathematics Scor :"<<mat<<endl;
        cout<<"English Scor     :"<<eng<<endl;
        cout<<"Physics Scor     :"<<phy<<endl;
    }
  protected:
    char name[10];
    unsigned int num;
    float mat,eng,phy,avg;
};
class EL_DEP:public ST_COM {
  public:
    EL_DEP(char *na,unsigned int n,float ma,float en,float ph,float pe,float el,float d):
    ST_COM(na,n,ma,en,ph),pex(pe),elnet(el),dst(d) {
        avg=((pex+elnet+dst)/3+ST_COM::avg)/2;
    }
    void operator!() {
        ST_COM::operator !();
        cout<<"Exchange Scor    :"<<pex<<endl;
        cout<<"Elec_net Scor    :"<<elnet<<endl;
        cout<<"Data_struct Scor :"<<dst<<endl;
        cout<<"Average Scor     :"<<avg<<endl;
    }
  protected:
    float pex,elnet,dst,avg;
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
Mathematics Scor :71
English Scor     :72
Physics Scor     :73
Exchange Scor    :81
Elec_net Scor    :82
Data_struct Scor :83
Average Scor     :77
----------------end------------------

 */
