#include <bits/stdc++.h>
#include <cxxabi.h>

using namespace std;

int main(int argc, char **argv) {
    map<int,int> dic;
    dic[1]=1;
    const char*  mangling_name;
    for(auto &each:dic){
        mangling_name =typeid(each).name();
    }
    char *demangle_name = (char *) malloc(30);
    int status = 0;
    std::size_t len = 30;
    demangle_name = abi::__cxa_demangle(mangling_name, NULL, NULL, &status);
    std::cout << status << std::endl;
    if (demangle_name == NULL)
        std::cout << "demangle failued." << std::endl;
    std::cout << demangle_name << std::endl;
    free(demangle_name);
    return 0;
}