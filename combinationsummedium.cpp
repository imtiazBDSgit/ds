#include <bits/stdc++.h>
using namespace std;
void Print_Vector(vector<int> Vec) 
{ 
    for (int i = 0; i < Vec.size(); i++) { 
        cout << Vec[i] << " "; 
    } 
    cout << endl; 
    return; 
} 
class Solution{
    void combutil(vector<int> &candidates,int target,int l,vector<int>& v,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(v);
        }
        for(int i=l;i<candidates.size();i++)
        {

            if(candidates[i]<=target){
            v.push_back(candidates[i]);
            combutil(candidates,target-candidates[i],i,v,ans);
            v.pop_back();
            }
        }
    }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates,int target){
            vector<int>vec;
            vector<vector<int>> ans;
            combutil(candidates,target,0,vec,ans);
            return ans;
        }
};
int main(){
    Solution sol=Solution();
    vector<int> candidates={2,3,5};
    int t=8;
    vector<vector<int>>finalresult=sol.combinationSum(candidates,t);
    cout << "The elements in set are: ";
    for (int i=0;i<finalresult.size();i++)
    {
        Print_Vector(finalresult[i]);
    }
    return 0;
}