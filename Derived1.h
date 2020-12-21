#include <iostream>
#include "Base.h"

using namespace std;

class Derived1: public Base{
public:
    void print(){ cout << "Derived1" <<endl;}
};