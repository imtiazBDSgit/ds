//https://leetcode.com/problems/restore-ip-addresses/
#include<bits/stdc++.h>
using namespace std;

bool valid(string line,string reference)
{
 stringstream check1(line); 
 string intermediate; 
 while(getline(check1, intermediate, '.')) 
    { 
     try
     {
       if(stoi(intermediate)>255 || stoi(intermediate)<0){
           return false;
     }
    }
     catch(exception e){
         return false;
     }
    }
  line.erase(std::remove(line.begin(), line.end(), '.'), line.end()); 
  if(line==reference)
    return true;
  else
      return false;  
}
string getValidIP(string str){
    
    stringstream check1(str); 
	string intermediate; 
	string result="";
	 while(getline(check1, intermediate, '.')) 
	    { 
	       result+=to_string(stoi(intermediate))+".";;
	    }
    result.pop_back();
    return result;
}
int getRemainingLength(string res){
    return 12-3*count(res.begin(), res.end(), '.');
}
void ip(string s,int slength,int remaininglength,
int current_index,vector<string>& result,const string& res)
{  
    if(res=="")
        remaininglength=getRemainingLength(res+".");
    else
        remaininglength=getRemainingLength(res);
    if(remaininglength==0) //&& res.length()==s.length()+5)
    {
        if(!valid(res,s))
            return;
        result.push_back(res);
        return;
    }
    if(remaininglength>=slength-1 && current_index<s.length())
    {  
        ip(s,slength-1,remaininglength,current_index+1,result,res+s[current_index]+".");
        
    }
    if(remaininglength>=slength-2 && current_index<s.length()-1)
    {
        ip(s,slength-2,remaininglength,current_index+2,result,res+s[current_index]+s[current_index+1]+".");
        
    }
   if(remaininglength>=slength-3 && current_index<s.length()-2)
    {
        ip(s,slength-3,remaininglength,current_index+3,result,res+s[current_index]+s[current_index+1]+s[current_index+2]+".");
        
    }
  
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
    vector<string> test;
    if(s=="")
        return test;
    int len=s.length();
    int remaininglength=9;
    string res="";
    int index=0;
    vector<string>result;
    set<string> strset;
    ip(s,len,remaininglength,0,result,res);
    for(int i=0;i<result.size();i++)
        {
        string value=getValidIP(result[i]);
        if(value.length()==len+3)
            strset.insert(value);
        }
    vector<string>finalresult;
    for (auto it = strset.begin(); it != strset.end(); ++it) {
    finalresult.push_back(*it);
    }
    return finalresult;
        
    }
};