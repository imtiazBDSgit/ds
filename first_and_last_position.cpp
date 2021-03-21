class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        vector<int> result;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                if(m==0) {
                    result.push_back(m);
                    break;}
                if(nums[m-1]!=target) {
                    result.push_back(m);
                    break;}
                else r=m-1;
            }
         else if(nums[m]<target){
            l=m+1;
        
        }
        else{
            r=m-1;
        }
        }
        if(result.size()==0) result.push_back(-1);
        
        
        l=0;
        r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                if(m==nums.size()-1) {
                    result.push_back(m);
                    break;}
                if(nums[m+1]!=target) {
                    result.push_back(m);
                    break;}
                else l=m+1;
            }
         else if(nums[m]<target){
            l=m+1;
        
        }
        else{
            r=m-1;
        }
        }
        if(result.size()==1) result.push_back(-1);
        return result;
    }
};