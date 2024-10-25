class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()){
            return false;
        }
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for(int i=0;i<word1.length();i++){
            map1[word1[i]]++;
            map2[word2[i]]++;
        }
        for(char x: word1){
            if(map2.find(x)==map2.end()){
                return false;
            }
        }
        for(char x: word2){
            if(map1.find(x)==map1.end()){
                return false;
            }
        }
        vector<int> freq1,freq2;
        for(auto x: map1) {
            freq1.push_back(x.second);
        }
        for(auto x: map2){
            freq2.push_back(x.second);
        } 
            
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1==freq2;
    }
};