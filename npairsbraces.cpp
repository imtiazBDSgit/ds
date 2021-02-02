//https://leetcode.com/problems/generate-parentheses/

#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;
class Solution {
public:
    void BP(int n,vector<string> &ans,string S="",int left=0,int right=0)
        {
            if(S.length()==2*n)
            {
                ans.push_back(S);
                return;
            }
            if(left<n)
            {
                BP(n,ans,S+'(',left+1,right);
            }
            if(right<left)
            {
                BP(n,ans,S+')',left,right+1);
            }
        }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        BP(n,ans);
        return ans;
    }
};

int main(){
    Solution s=Solution();
    vector<string>p;
    p=s.generateParenthesis(3);
    for(int i=0;i<p.size();i++){
        cout<<p.at(i)<<endl;
    }
    return 0;
}