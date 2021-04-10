#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getPivot(vector<int>& nums)
    {
        int l=0;
        int h=nums.size()-1;
        int m;
        int n=nums.size();
        int pivot;
        while(l<=h)
        {
            m=(l+h)/2;
            if(nums[m]<=nums[n-1])
                h=m-1;
            else
            {
                if(nums[m]>nums[m+1])
                    return m;
                    
                else
                    l=m+1;
             
            } 
        }
        return -1; 
    }
    int binarysearch(vector<int>nums,int target,int l, int h){
        int m;
        while(l<=h){
            m=(l+h)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]>target){
                h=m-1;
            }
            else{
                l=m+1;

            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target)
    {
        int pivot=getPivot(nums);
        int index=binarysearch(nums,target,pivot+1,nums.size()-1);

        if(index!=-1)
            return index;
        else
        {
            return binarysearch(nums,target,0,pivot);
        }
    }
    
};