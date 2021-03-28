// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(int n)
    {
        int left=1;
        int right=n;
        while(left<=right)
        {
            int middle=left+(right-left)/2;
            if(isBadVersion(middle))
            {
                if(middle==1) return middle;
                else if(!isBadVersion(middle-1)) return middle;
                else right=middle-1;
            }
            else
            {
                left=middle+1;
            }
        }
        return -1;
    }
    int firstBadVersion(int n) {
       return binarySearch(n);
    }
};