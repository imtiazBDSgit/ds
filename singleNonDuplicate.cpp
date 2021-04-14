#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        int l=0;
        int n=nums.size()-1;
        int h=nums.size()-1;
        int m;
        while(l<=h)
        {
            m=(l+h)/2;
            if(m==0 && nums[1]!=nums[0])
                return nums[m];
            else if(m==n and nums[n-1]!=nums[n])
                return nums[m];
            else
            {
                if(nums[m]!=nums[m+1] && nums[m]!=nums[m-1])
                    return nums[m];
                else if(nums[m]==nums[m+1])
                {
                    if(m%2==0)
                    {
                        l=m+1;
                    }
                    else
                    {
                        h=m-1;
                    }
                }
                else if(nums[m-1]==nums[m])
                {
                    if((m-1)%2==0)
                    {
                        l=m+1;
                    }
                    else
                    {
                        h=m-1;
                    }
                }

            }
            
        }
        return -1;
       
    }
};