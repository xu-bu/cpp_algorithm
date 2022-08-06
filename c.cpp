#include <bits/stdc++.h>

using namespace std;

class Test{
private:
    int val;
public:
    explicit Test (int x):val(x){};
    int getVal(){return val;};
};

void doBar(Test t){
    int i=t.getVal();
}

int main() {
    doBar(42);
}