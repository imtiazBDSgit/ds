
//https://www.hackerrank.com/contests/gl-bajaj-self-evaluation-evening-batch/challenges/bracket-challenge-1/problem
#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;
class Solution {
public:
    void BP(int n,int m,vector<string> &ans,string S="",int left=0,int right=0,
    int leftb=0,int rightb=0)
        {
            if(S.length()==2*n+(2*m))
                {
                    if(checkValidParenthesis(S))
                        {
                        ans.push_back(S);
                        return;
                        }
                }
             if(right<left)
                {
                        BP(n,m,ans,S+')',left,right+1,leftb,rightb);
                } 
             if(left<n)
                {
                    BP(n,m,ans,S+'(',left+1,right,leftb,rightb);
                    
                }
                     
            if(rightb<leftb)
                {
                  
                        BP(n,m,ans,S+'}',left,right,leftb,rightb+1);
                    
                }

            if(leftb<m)
                        {
                            BP(n,m,ans,S+'{',left,right,leftb+1,rightb);
                        }    
 
        }
    vector<string> generateParenthesis(int n,int m) 
    {
        vector<string> ans;
        BP(n,m,ans);
        return ans;
    }
    bool checkValidParenthesis(string s){
    stack<char> st;
     int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]=='{' || s[i]=='(')
        {
           st.push(s[i]);
           continue;
        }
        else
        {
           if(st.top()=='(' && s[i]=='}')
           {
                return false;
           }
           else if(st.top()=='{' && s[i]==')')
           {
                return false;
           }
           else
           {
                st.pop();
           }
           
        }
        

    }
    if(st.empty())
        return true;
    else
        return false;
}
};


int main(){
    int n,m;
    cin>>n>>m;
    Solution s=Solution();
    vector<string>p;
    p=s.generateParenthesis(n,m);
    for(int i=0;i<p.size();i++){
        cout<<p.at(i)<<endl;
    }
    return 0;
}