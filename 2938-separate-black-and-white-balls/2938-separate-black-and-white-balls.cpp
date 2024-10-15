class Solution {
public:
    long long minimumSteps(string s) {
     int swap=0;
     int black=0;  
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