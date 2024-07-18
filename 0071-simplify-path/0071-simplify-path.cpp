#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> sta;
        string str;
        
        for (int i = 0; i < path.length(); i++) {
            // Skip multiple slashes
            if (path[i] == '/') {
                if (!str.empty() && str != ".") {
                    if (str == "..") {
                        if (!sta.empty()) {
                            sta.pop();
                        }
                    } else {
                        sta.push(str);
                    }
                }
                str = "";  // Reset for the next component
            } else {
                str.push_back(path[i]);
            }
        }
        
        // Handle the last component
        if (!str.empty() && str != ".") {
            if (str == "..") {
                if (!sta.empty()) {
                    sta.pop();
                }
            } else {
                sta.push(str);
            }
        }
        
        // Construct the simplified path
        str = "";
        stack<string> tempSta;
        
        while (!sta.empty()) {
            tempSta.push(sta.top());
            sta.pop();
        }
        
        while (!tempSta.empty()) {
            str += "/" + tempSta.top();
            tempSta.pop();
        }
        
        // Handle the case for root directory
        if (str.empty()) {
            str = "/";
        }
        
        return str;
    }
};