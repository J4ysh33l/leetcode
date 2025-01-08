class Solution {
public:
    void isValid(string word, vector<string>& words, int& count, int index) {
        int n = word.size();
        for (int i = index + 1; i < words.size(); i++) {
            // Check if `word` is a prefix or suffix of `words[i]`
            if (words[i].substr(0, n) == word && words[i].substr(words[i].size() - n, n) == word) {
                count++;
            }
        }
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            isValid(words[i], words, count, i);
        }
        return count;
    }
};
