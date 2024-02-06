/***********************************************************
 * @file name: 21_inherit_function.cpp
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

class Bed {
  public:
    Bed():weight(){}
    void Sleep() {
        cout<<"Sleeping...\n";
        }
    void SetWeight(int i) {
        weight=i;
        cout<<"Set Bed Weight:"<<weight<<"..\n";

    }
  protected:
    int weight;
};
class Sofa {
  public:
    Sofa():weight(){}
    void WatchTV() {
        cout<<"Watching TV\n";
    }
    void SetWeight(int i) {
        weight=i+2;
        cout<<"Set Sofa Weight:"<<weight<<"..\n";

    }
  protected:
    int weight;
};
class SleeperSofa:public Bed,public Sofa {
  public:
    SleeperSofa(){}
    void FoldOut() {
        cout<<"Fold out the sofa.\n";
    }
};

int main() {
    cout << "----------------begain------------------" << endl;

    SleeperSofa ss;
    ss.WatchTV();
    ss.Sleep();
    ss.Bed::SetWeight(20);
    ss.Sofa::SetWeight(20);

    cout << "----------------end------------------" << endl;
    return EXIT_SUCCESS;
}

/**
 * @expected output:
----------------begain------------------
Watching TV
Sleeping...
Set Bed Weight:20..
Set Sofa Weight:22..
----------------end------------------

 */
