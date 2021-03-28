#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums)
    {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int middle=left+(right-left)/2;
            if(nums[middle]==0)
            {
               if(middle==0) return middle;
               else if(nums[middle-1]==1) return middle;
               else right=middle-1;
            }
            else
            {
                left=middle+1;
            }
        }
        return nums.size();
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
       vector<pair<int,int>> result;
       for(int i=0;i<mat.size();i++)
       {
           result.push_back(make_pair(binarySearch(mat[i]),i));
       }
        sort(result.begin(), result.end());
    
    vector<int> kresult;
    for(int j=0;j<k;j++){
        kresult.push_back(result[j].second);
    }
    return kresult;
    }
};