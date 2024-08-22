class Solution {
public:
    int findComplement(int num) {
        int n=num;
        vector<int> bit;
        while(n>0){
            if(n%2){
                bit.push_back(1);
            }else{
                bit.push_back(0);
            }
            cout<<n%2<<endl;
            n/=2;
        }
        int digit=0;
        for(int i=0;i<bit.size();i++){
            (bit[i]) ? digit+=0: digit+=1*pow(2,i);
        }
        return digit;
    }
};