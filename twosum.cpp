#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binary_search(vector<int> nums,int tar,int l){
        int left=l;
        int right=nums.size()-1;
        while(left<=right){
            int middle=(left+right)/2;
            if(nums[middle]==tar) return middle;
            else if(nums[middle]<tar) left=middle+1;
            else right=middle-1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            int index=binary_search(numbers,target-numbers[i],i+1);
            if(index==-1) continue;
            else
            {
                vector<int> res;
                res.push_back(i+1); res.push_back(index+1);
                return res;

            }
        }  
        vector<int> res{-1,-1};
        return res;
    }
};

int main(){
    Solution sol=Solution();
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> out=sol.twoSum(nums,target);
    for(int j=0;j<out.size();j++){
        cout<<out[j]<<endl;
    }
}