// Last updated: 05/01/2026, 00:03:33
class Solution {
public:
    long long minimumSteps(string s) {
     long long swap=0;
     long black=0;  
     for(auto x:s){
        if(x=='0'){
            swap+=black;
        }else{
            black++;
        }
     } 
     return swap;
    }
};