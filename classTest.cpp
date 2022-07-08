//
// Created by test on 2022/7/8.
//

#include <bits/stdc++.h>

using namespace std;

class LogSystem{
public:
    map<int,int> dic;
    LogSystem(){

    }

    void Add(int id,int timeStamp){
        this->dic[id]=timeStamp;
    }

    int Delete(int id){
        int ret=this->dic.erase(id);
        return ret;
    }

    int Query(int startTime,int endTime){
        int ret=0;
        for(auto it:this->dic){
            if(it.second<=endTime&&it.second>=startTime){
                ret++;
            }
        }
        return ret;
    }
};

int main(){
    LogSystem obj=LogSystem();
    obj.Add(1,5);
    obj.Add(2,5);
    obj.Add(3,6);
    cout<<obj.Delete(2)<<endl;
    cout<<obj.Delete(4)<<endl;
    cout<<obj.Query(5,6)<<endl;
}