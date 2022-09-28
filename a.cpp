#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    ListNode *next;
    int val;

    ListNode() : val(0), next(nullptr) {};

    ListNode(int x) : val(x), next{nullptr} {};
};

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    map<int,vector<int>> dic;
    vector<string> wordList;
    vector<vector<bool>> isLink;
    int end=-1;
    int n;

    bool canLink(string s1,string s2){
        int num=0;
        for (int i = 0; i < s1.size(); ++i) {
            if(s1.at(i)!=s2.at(i)){
                num++;
            }
            if(num>1){
                return false;
            }
        }
        return true;
    }

    int dfs(int cur,vector<int> &visit){
        visit[cur]=true;
        if (isLink[cur][end]){
            return 1;
        }
        int ret=0x7fffe;
        for(int i=0;i<n;++i){
            if (isLink[i][cur] and i!=cur and !visit[i]){
                ret= min(ret,dfs(i,visit)+1);
            }
        }
        visit[cur]=false;
        return ret;
    }

    int ladderLength(string beginWord,string endWord,vector<string>& wordList) {
        this->wordList=wordList;
        n=wordList.size();
        isLink=vector<vector<bool>> (n,vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            if (wordList[i]==endWord){
                end=i;
            }
        }
        if (end==-1){
            return 0;
        }
        map<int,vector<int>> dic;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (canLink(wordList[i],wordList[j])){
                    dic[i].emplace_back(j);
                    dic[j].emplace_back(i);
                    isLink[i][j]=true;
                    isLink[j][i]=true;
                }
            }
        }
        int ans=0x7fffe;

        for(int i=0;i<n;i++){
            if(canLink(wordList[i],beginWord)){
                if(i==end){
                    return 2;
                }
                vector<int> visit(n);
                int tmp=dfs(i,visit);
                if(tmp!=0){
                    ans=min(tmp,ans);
                }
            }
        }
        if(ans>=0x7fffe){
            return 0;
        }
        return ans+2;
    }
};


int main() {
    vector<int> nums = {0,1,2,0,0,0,2,4,4,1};
    vector<int> pop = {1, 2, 3, 4, 5};
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    Solution solution = Solution();
    cout << solution.ladderLength(beginWord,endWord,wordList);
}
