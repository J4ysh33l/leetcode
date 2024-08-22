class Solution {
    bool isVowel(char s){
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ||
                s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') {
                return true;
        }
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int count=0;
        int maxCount=0;
        for(int i=0;i<k;i++){
            count+=isVowel(s[i]);
        }
        maxCount=count;
        for(int i=k;i<s.length();i++){
            count+=isVowel(s[i])-isVowel(s[i-k]);
            maxCount=max(count,maxCount);
        }
        return maxCount;
    }
};