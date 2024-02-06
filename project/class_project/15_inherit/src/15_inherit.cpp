/***********************************************************
 * @file name: 15_inherit.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 * 
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class vehicle {
  public:
    vehicle(int in_wheels,float in_weight) {
        wheels=in_wheels;
        weight=in_weight;
    }
    int get_wheels() {
        return wheels;
        // return vehicle::get_wheels();
    }
    float get_weight() {
        return weight;
        // return vehicle::get_weight();
    }
  private:
    float weight;
    int wheels;
};
class car:public vehicle {
  public:
    car(int in_wheels,float in_weight,int people=5):
    vehicle(in_wheels,in_weight) {
        passenger_load=people;
    }
    int get_passengers() {
        return passenger_load;
    }
  private:
    int passenger_load;
};
int main() {
    cout << "----------------begain------------------" << endl;

    car bm(4,1000);
    cout<<"The message of bm(wheels,weight,passenger):"<<endl;
    cout<<bm.get_wheels()<<",";
    cout<<bm.get_weight()<<",";
    cout<<bm.get_passengers()<<endl;

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
The message of bm(wheels,weight,passenger):
4,1000,5
----------------end------------------
 * 
 */
