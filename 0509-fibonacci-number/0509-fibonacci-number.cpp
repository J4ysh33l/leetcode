class Solution {
public:
    int solve(int num,int* arr){
        if(num==1||num==0){
            return arr[num];
        }
        if(arr[num]==-1){
            arr[num]=solve(num-1,arr)+solve(num-2,arr);
        }
        return arr[num];
    }
    int fib(int n) {
        int arr[n+1];
        fill(arr, arr + n + 1, -1); 
        arr[0]=0;
        arr[1]=1;
        int ans=solve(n,arr);
        return ans;
    }
};