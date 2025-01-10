/***********************************************************
 * @file name: 25_employee_class.cpp
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

class employee {
  public:
    void setinfo(char *empname,int empsex,char *empid) {
        strcpy(name,empname);
        sex = empsex;
        strcpy(emp_id,empid);
    }
    void getinfo(char *empname,char *empid) {
        strcpy(empname,name);
        strcpy(empid,emp_id);
    }
    double getsalary() {
        return salary;
    }
  protected:
    char name[10];
    int sex;
    char emp_id[8];
    double salary;
};

class hourlyworker:public employee {

  public:
    hourlyworker() {
        hours=0;
        perhourpay=15.6;
    }
    int gethours() {
        return hours;
    }
    void sethours(int h) {
        hours=h;
    }
    double getperhourpay() {
        return perhourpay;
    }
    void setperhourpay(double pay) {
        perhourpay=pay;
    }
    void computepay() {
        if(hours<=40) {
            salary=perhourpay*hours;
        } else {
            salary=perhourpay*40+(hours-40)*1.5*perhourpay;
        }
    }
  protected:
    int hours;
    double perhourpay;
};

class pieceworker:public employee {
  public:
    pieceworker() {
        pieces=0;
        perpiecepay=26.8;
    }
    int getpieces() {
        return pieces;
    }
    void setpieces(int p) {
        pieces=p;
    }
    double getperpiecepay() {
        return perpiecepay;
    }
    void setperpiecepay(double ppp) {
        perpiecepay=ppp;
    }
    void computepay() {
        salary=pieces*perpiecepay;
    }
  protected:
    int pieces;
    double perpiecepay;
};

class manager:public employee {
  public:
    void setsalary(double s) {
        salary=s;
    }
};

class commissionworker:public employee {
  public:
    commissionworker() {
        basesalary=500;
        total=0;
        percent=0.01;
    }
    double getbase() {
        return basesalary;
    }
    void setbase(double base) {
        basesalary=base;
    }
    double gettotal() {
        return total;
    }
    void settotal(double t) {
        total=t;
    }
    double getpercent() {
        return percent;
    }
    void setpercent(double p) {
        percent=p;
    }
    void computepay() {
        salary=basesalary+total*percent;
    }
  protected:
    double basesalary;
    double total;
    double percent;
};

int main() {
    cout << "----------------begain------------------" << endl;

    char name[10],emp_id[9];
    hourlyworker hworker;
    hworker.setinfo((char*)"John",0,(char*)"001");
    hworker.sethours(65);
    hworker.getinfo(name,emp_id);
    hworker.computepay();
    cout<<"hourlyworker "<<name<<"'s id is:"<<emp_id
        <<" and salary is:"<<hworker.getsalary()<<endl;
    pieceworker pworker;
    pworker.setinfo((char*)"Mark",0,(char*)"002");
    pworker.setpieces(100);
    pworker.computepay();
    pworker.getinfo(name,emp_id);
    cout<<"pieceworker "<<name<<"'s id is:"<<emp_id
        <<"and salary is:"<<pworker.getsalary()<<endl;
    commissionworker cworker;
    cworker.settotal(234.6);
    cworker.setinfo((char*)"Jane",0,(char*)"003");
    cworker.computepay();
    cworker.getinfo(name,emp_id);
    cout<<"commissionworker "<<name<<"'s id is:"<<emp_id
        <<"and salary is:"<<cworker.getsalary()<<endl;
    manager mana;
    mana.setinfo((char*)"Mike",1,(char*)"004");
    mana.setsalary(3500);
    mana.getinfo(name,emp_id);
    cout<<"manager "<<name<<"'s id is:"<<emp_id
        <<" and salary is:"<<mana.getsalary()<<endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}


/**
 * @expected output:
----------------begain------------------
hourlyworker John's id is:001 and salary is:1209
pieceworker Mark's id is:002and salary is:2680
commissionworker Jane's id is:003and salary is:502.346
manager Mike's id is:004 and salary is:3500
----------------end------------------

 */
