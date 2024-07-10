class Solution {
    
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        if(n%2!=0 || n<=0){
            return false;
        }
        n/=2;
        return isPowerOfTwo(n);
    }
};