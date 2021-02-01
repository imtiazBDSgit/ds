//https://leetcode.com/problems/powx-n/

#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) 
    {
       if(n==0)
           return 1;
    
       if(n==1)
        return x;
       else if(x==1)
        return x;
       else
        {
           long sign=n<0?-1:1;
            double result=myPow(x,sign*n/2);
            result*=result;
            if(n&1==1)
                result=result*x;
            if (sign<0){
                return 1/result;
            }
            else{
                return result;
            }
        }
       
        
    }
};

int main()
{
Solution s=Solution();
cout<<s.myPow(2,-2)<<endl;
}