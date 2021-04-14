#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0;
        int h=citations.size()-1;
        int len=citations.size();
        int m;
        while(l<=h){
            m=(l+h)/2;
            if(citations[m]<len-m)
                l=m+1;
            if(citations[m]>=len-m)
                h=m-1;
        }
        return len-l;
        
    }
};

int main(){
    return 0;
}
//calculate hindex
