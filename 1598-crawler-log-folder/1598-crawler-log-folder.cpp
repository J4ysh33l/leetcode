class Solution {
public:
    int minOperations(vector<string>& logs) {
        // stack<int> dir;
        int count=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                if(count!=0){
                    // stack.pop();
                    count--;
                }
            }else if(logs[i]=="./"){
                continue;
            }else{
                // dir.push(count);
                count++;
            }
        }
        return count;
    }
};