
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void func(int n,int k,int i,vector<int> vec)
    {
        if(vec.size() == k)
        {
            ans.push_back(vec);
            return;
        } 
        for(int j=i;j<=n;j++)
        {
            vec.push_back(j);
            func(n,k,j+1,vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        func(n,k,1,vec);
        return ans;
    }
};


int main()
{
    Solution solution=Solution();
    vector<vector<int>> result =solution.combine(4,2);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i].at(j)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}