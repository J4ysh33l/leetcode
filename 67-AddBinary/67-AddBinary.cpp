// Last updated: 15/02/2026, 23:09:02
1class Solution {
2public:
3    string addBinary(string a, string b) {
4        int carry=0;
5        string c;
6        reverse(a.begin(),a.end());
7        reverse(b.begin(),b.end());
8        int maxLength = max(a.length(), b.length());
9        for (int i = 0; i < maxLength; i++) {
10            int bitA = i < a.length() ? a[i] - '0' : 0;
11            int bitB = i < b.length() ? b[i] - '0' : 0;
12            int sum = bitA + bitB + carry;
13            carry = sum / 2;
14            c.push_back((sum % 2) + '0');
15        }
16        
17        if (carry != 0) {
18            c.push_back('1');
19        }
20        reverse(c.begin(),c.end());
21        return c;
22    }
23};