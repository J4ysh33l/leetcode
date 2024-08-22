class Solution {
public:
    string reverseVowels(string s) {
        int left=0;
        int right=s.length()-1;
        bool lvowel=false;
        bool rvowel=false;
        while(left<right){
            if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u' ||
                s[left] == 'A' || s[left] == 'E' || s[left] == 'I' || s[left] == 'O' || s[left] == 'U') {
                lvowel = true;
            }

            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u' ||
                s[right] == 'A' || s[right] == 'E' || s[right] == 'I' || s[right] == 'O' || s[right] == 'U') {
                rvowel = true;
            }
            if(!rvowel){
                right--;
            }
            if(!lvowel){
                left++;
            }
            if(rvowel && lvowel){
                swap(s[left],s[right]);
                lvowel=false;
                rvowel=false;
                left++;
                right--;
            }
        }
        return s;
    }
};