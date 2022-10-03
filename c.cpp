#include <bits/stdc++.h>
#include <string_view>

using namespace std;

template <typename T> std::string type_name();

class Test{
private:
    int val;
public:
    explicit Test (int x):val(x){};
    int getVal(){return val;};
};



int main() {
    int i=5;
    cout<<(char)(97+i);
}
