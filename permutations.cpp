/* 
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
void swapped(vector<int>& nums,int i,int j)
{
    int temp=nums.at(i);
    nums.at(i)=nums.at(j);
    nums.at(j)=temp;
}
void permuteHelper(vector<int> nums,int i)
{
    if(i==nums.size()-1)
    {
        result.push_back(nums);
        return;
    }
    for(int j=i;j<nums.size();j++)
    {
        swapped(nums,i,j);
        permuteHelper(nums,i+1);
        swapped(nums,i,j);
    }
}
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
    permuteHelper(nums,0);
    return result;
        
    }
};

int main()
{
    Solution sol=Solution();
    vector<int> input={1,2,3};
    int i=0;
    vector<vector<int>> output=sol.permute(input);
    return 0;
}