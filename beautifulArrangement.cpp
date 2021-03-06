#include<bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    vector<vector<int>> result;
    bool checkBeautiful(vector<int> arrange)
    {  int count{0};
       for(int j=0;j<arrange.size();j++)
       {
           if(arrange[j]%(j+1)==0)
           {
               count++;
           }
           else if((j+1)%arrange[j]==0)
                   count++;
       }
       if(count==arrange.size())
            return true;
       else
           return false;
       
    }
    void swap(vector<int>& arr,int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    void permutations(vector<int>& arr,int i,int n)
    {
        if(i>=n-1)
        {
            result.push_back(arr);
            return;
        }
        for(int j=i;j<arr.size();j++)
        {
            swap(arr,i,j);
            if(arr[i]%(i+1)==0 || (i+1)%arr[i]==0)
                permutations(arr,i+1,n);
            swap(arr,i,j);
        }

    }
    int countArrangement(int n) 
    {
        vector<int>p;
        for(int i=1;i<=n;i++)
            p.push_back(i);
        permutations(p,0,n);
        int count{0};
        for(int j=0;j<result.size();j++)
        {
            if(checkBeautiful(result[j])){
                count=count+1;
            }
        }
        return count;
    }


};



int main()
{
    Solution sol=Solution();
    cout<<sol.countArrangement(2)<<endl;
    return 0;
}