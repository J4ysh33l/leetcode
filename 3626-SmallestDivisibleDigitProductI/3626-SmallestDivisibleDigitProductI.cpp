// Last updated: 05/01/2026, 00:02:19
class Solution {
public:
    int digitProduct(int n){
        int ans=1;
        while(n>0){
            ans*=n%10;
            n/=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int i=0;
        while(true){
            int num= digitProduct(n+i);
            if(num%t==0){
                return n+i;
            }
            i++;
        }
    }
};