class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int h=x;
        long m;
        while(l<=h){
            m=(l+h)/2;
            if(m*m==x)
                return m;
            else if(m*m<x){
                if((m+1)*(m+1)>x)
                    return m;
                else
                    l=m+1;          
            }
            else
                h=m-1;
        }
        return -1;
    }
};