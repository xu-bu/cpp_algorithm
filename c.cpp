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
    char *p[6]={"ABCD","EFGH","IJKL","MNOP"};
	int i;
	for(i=0;i<4;i++)
		cout<<p[i]<<endl;  //输出每个字符串，实际上p[i]为第i个字符串的首地址
	for(i=0;i<4;i++)
		cout<<*p[i];  //输出每个字符串第一个字符AEIM
	cout<<endl;
	for(i=0;i<4;i++)
		cout<<*(p[i]+1); //输出每个字符串第二个字符BFJN
}

#include <stdlib.h>


int main()
{
    char *str[]={"Welcome","to","CascoSigLtd","Shanghai"};
    char **p=str+1;
    str[0]=(*p++)+2;
    str[1]=*(p+1);
    str[2]=p[1]+5;
    str[3]=p[0]+(str[2]-str[1])+2;
    printf("%s\n",str[0]);
    printf("%s\n",str[1]);
    printf("%s\n",str[2]);
    printf("%s\n",str[3]);
}