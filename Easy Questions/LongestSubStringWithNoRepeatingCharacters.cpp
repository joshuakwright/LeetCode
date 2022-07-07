class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {return 0;}
        
        int n = s.length(), ans = 0;
        map<char,int> window;
        
        for (int j = 0, i = 0; j < n; j++) {
            if (window.find(s.at(j)) != window.end()) {
                i = max(window[s.at(j)], i);
            }
            ans = max(ans, j - i + 1);
            window[s.at(j)] = j + 1;
        }
        return ans;
    }
};