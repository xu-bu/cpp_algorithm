//
// Created by test on 2022/7/8.
//

#include <bits/stdc++.h>

using namespace std;

class Base{
public:
    Base(int x):a(x){}
    void print(){cout<<"base"<<endl;}
private:
    int a;
};

class Derived:public Base{
public:
    Derived(int x):Base(x-1),b(x){}
    void print(){cout<<"Derived"<<endl;}
private:
    int b;
};

class C:public Derived{
public:
    C(int x): Derived(x){}
};

int main(){
    Base obj1(1);
    cout<<sizeof(obj1)<<endl;
    Derived obj2(2);
    cout<<sizeof(obj2)<<endl;
    C obj3(3);
    cout<<sizeof(obj3)<<endl;
}