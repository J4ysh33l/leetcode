// Last updated: 05/01/2026, 00:04:22
class Solution {
public:
    int passThePillow(int n, int time) {
        time = time%(2*(n-1));
        if(time<n){
            return 1+time;
        }else{
            return (2*n)-(time+1);
        }
    }
};