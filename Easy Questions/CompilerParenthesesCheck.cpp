class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1) {
            return false;
        }
        
        stack<int> c;
        map<char, char> par;
        par['('] = ')';
        par['{'] = '}';
        par['['] = ']';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                c.push(s[i]);   
            }
            else {
                if (c.size() == 0) {
                    return false;
                }
                if (par[c.top()] == s[i]) {
                    c.pop();
                } 
                else {
                    return false;
                }
            }
        }
        return c.size() == 0;
    }
};