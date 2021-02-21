#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  
vector< vector<int> > result;
int num;
void backtrack(vector<int> v,int start,int sum)
{
    if(v.size()==num)
    {
        if(sum==0)
            result.push_back(v);
        return;
    }
    for(int i=start;i<=9;i++)
    {
        if(sum-i>=0)
        {
            v.push_back(i);
            backtrack(v,i+1,sum-i);
            v.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
    num=k;
    vector<int> v;
    backtrack(v,1,n);
    return result;
}
};
int main(){
    Solution sol =Solution();
    vector<vector<int>> res=sol.combinationSum3(3,9);
    for(int p=0;p<res.size();p++)
        {
            for(int f=0;f<res[p].size();f++)
            {
                cout<<res[p].at(f)<<" ";
            }
            cout<<"\n";
        }
    return 0;
}