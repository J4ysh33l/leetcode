class Solution {
public:
    string countOfAtoms(string formula) {
          int n = formula.size();
    stack<map<string, int>> stk;
    stk.push({});
    for (int i = 0; i < n; ) {
        if (formula[i] == '(') {
            stk.push({});
            i++;
        } else if (formula[i] == ')') {
            auto top = stk.top();
            stk.pop();
            int iStart = ++i;
            int multiplicity = 0;
            while (i < n && isdigit(formula[i])) i++;
            if (i > iStart) multiplicity = stoi(formula.substr(iStart, i - iStart));
            else multiplicity = 1;
            for (auto &p : top) {
                stk.top()[p.first] += p.second * multiplicity;
            }
        } else {
            int iStart = i++;
            while (i < n && islower(formula[i])) i++;
            string name = formula.substr(iStart, i - iStart);
            iStart = i;
            int multiplicity = 0;
            while (i < n && isdigit(formula[i])) i++;
            if (i > iStart) multiplicity = stoi(formula.substr(iStart, i - iStart));
            else multiplicity = 1;
            stk.top()[name] += multiplicity;
        }
    }
    map<string, int> counts = stk.top();
    string result;
    for (auto &p : counts) {
        result += p.first;
        if (p.second > 1) result += to_string(p.second);
    }
    return result;
}
};