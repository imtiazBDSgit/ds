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
                ans.push_back(S);
                return;
            }
            if(left<n)
                {
                    BP(n,m,ans,S+'(',left+1,right,leftb,rightb);
                    
                }
            if(right<left && S[S.length()-1]!='{')
            {
                
                BP(n,m,ans,S+')',left,right+1,leftb,rightb);
            }  
           if(leftb<m)
                {
                    BP(n,m,ans,S+'{',left,right,leftb+1,rightb);
                }
            if(rightb<leftb && S[S.length()-1]!='(')
            {
                BP(n,m,ans,S+'}',left,right,leftb,rightb+1);
                
            }
           
               
             
            
                  
        }
    vector<string> generateParenthesis(int n,int m) 
    {
        vector<string> ans;
        BP(n,m,ans);
        return ans;
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