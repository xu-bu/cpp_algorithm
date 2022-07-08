//
// Created by test on 2022/7/2.
//
#include <bits/stdc++.h>

using namespace std;

void test(string s){
    int n=s.size();
    double x= sqrt(n);
    if (floor(x)==x){
        int offset=x;
        for(int i=0;i<offset;i+=1){
            for(int j=0;j<n;j+=offset){
                cout<<s[j+i];
            }
        }
    }else{
        cout<<"ERROR";
    }
}

int main(){
    string s="es gf";
    char *c=const_cast<char *>(s.c_str());
    char *delimiter=" ";
    char *save=nullptr;
    char *token=nullptr;
    token= strtok_s(c,delimiter,&save);
    vector<string> items;
    while(token!= nullptr){
        items.emplace_back(string(token));
        token= strtok_s(nullptr,delimiter,&save);
    }
    for(auto &each:items){
        cout<<each<<endl;
    }
}