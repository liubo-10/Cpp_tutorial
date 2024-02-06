/***********************************************************
 * @file name: 16_protected.cpp
 * @author: liubo
 * @date: 2024.02.06
 * @describe: template
 *   使用protected关键字时，父类的成员函数和数据成员可以被其子类继承并使用。
 *   在子类中，protected成员可以被访问和使用，但在其他类中，无法直接访问protected成员。
 * 
 **********************************************************/
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class vehicle {
  private:
    int wheels;
  protected:
    float weight;
  public:
    vehicle(int in_wheels,float in_weight) {
        wheels=in_wheels;
        weight=in_weight;
    }
    int get_wheels() {
        return wheels;
    }
    float get_weight() {
        return weight;
    }
};
class car:protected vehicle {
  private:
    int passenger_load;
  public:
    car(int in_wheels,float in_weight,int people=5):
    vehicle(in_wheels,in_weight) {
        passenger_load=people;
    }
    int get_wheels() {
        return vehicle::get_wheels();
    }
    float get_weight() {
        return weight;
    }
    int get_passengers() {
        return passenger_load;
    }
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
 * 
 * 
 */
