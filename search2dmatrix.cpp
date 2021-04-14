#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int> array,int target){
        int l=0;
        int r=array.size()-1;
        int m;
        while(l<=r){
            m=(l+r)/2;
            if(array[m]==target)
                return m;
            if(array[m]>target)
                r=m-1;
            else
                l=m+1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int res=search(matrix[i],target);
            if(res==-1)
                continue;
            else
                return true;

        }
        return false;
        
    }
};