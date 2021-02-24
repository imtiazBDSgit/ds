#include<bits/stdc++.h>
using namespace std;

//Input: low = 100, high = 300
//Output: [123,234]

//Input: low = 1000, high = 13000
//Output: [1234,2345,3456,4567,5678,6789,12345]

class Solution {
    void sequence(int low,int high,string str,int l,vector<int>& vec)
    {
        str+=to_string(l);
        int val=stoi(str);
        if(val<=high && val>=low)
        {
            vec.push_back(val);
        }
        if(val>high)
            return;
        if(l==9)
            return;

        sequence(low,high,str,l+1,vec);
    
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>result;
        
        for(int i=1;i<=9;i++)
        {
            string str;
        sequence(low,high,str,i,result);
        }
        sort(result.begin(),result.end());
        return result;
    }
};



int main()
{
    Solution sol=Solution();
    vector<int> output=sol.sequentialDigits(1000,13000);
    for(int k=0;k<output.size();k++)
    {
        cout<<output[k]<<endl;
    }
    return 0;
}