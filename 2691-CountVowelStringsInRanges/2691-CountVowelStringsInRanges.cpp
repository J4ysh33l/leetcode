// Last updated: 05/01/2026, 00:04:11
class Solution {
public:

    bool isVowel(char chr){
        if(chr == 'a' ||chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u'){
            return true;
        }else{
            return false;
        }
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // first initialize a vector dp
        // traverse the vector words and increment dp if words[i] starts and ends with vowel
        // for queries dp[r]-dp[l-1] if (l-1)<0 then return dp[r];
        // add these results in ans
        vector<int> ans;
        vector<int> dp(words.size()+1);
        dp[0]=0;
        for(int i=0;i<words.size();i++){
            string word= words[i];
            if(isVowel(word[0]) && isVowel(word[word.size()-1])){
                dp[i+1]=dp[i]+1;
            }else{
                dp[i+1]=dp[i];
            }
        }
        for(auto x: queries){
            ans.push_back(dp[x[1]+1]-dp[x[0]]);
        }

        return ans;
    }
};