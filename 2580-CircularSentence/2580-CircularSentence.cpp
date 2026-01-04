// Last updated: 05/01/2026, 00:04:31
class Solution {
public:
    bool isCircularSentence(string sentence) {
       for(int i=0;i<sentence.length();i++){
        if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1]){
            return false;
        }
       } 
       if(sentence[0]!=sentence[sentence.length()-1]){
        return false;
       }
       return true;
    }
};