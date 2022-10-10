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
    list<int> l={1,3};
    list<int> element={2};
    l.splice(l.begin()+1,element);
    for (auto &each:l) {
        cout<<each;
    }
}
