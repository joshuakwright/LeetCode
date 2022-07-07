//My first super slow solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {return 0;}
        
        int min = 0;
        int tempLen = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i - 1; j >= min; j--) {
                if (s[i] == s[j]) {
                    if (tempLen > maxLen) {
                        maxLen = tempLen;
                    }
                    tempLen = 0;
                    min = j + 1;
                    i = j + 1;
                }
            }
            tempLen++;
        }
        if(tempLen > maxLen) {
            maxLen = tempLen;
        }
        return maxLen;
    }
};

//My even slower version using a map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {return 0;}
        
        int tempLen = 0;
        int maxLen = 0;
        map<char,int> storage;
        map<char,int>::iterator it;
        for (int i = 0; i < s.length(); i++) {
            it = storage.find(s[i]);
            if (storage.end() != it) {
                maxLen = max(maxLen, tempLen);
                tempLen = 0;
                i = it->second++;
                storage.clear();
            }
            else {
                storage.insert(pair<char,int>(s[i], i));
                tempLen++;
            }
        }
        maxLen = max(maxLen, tempLen);
        return maxLen;
    }
};

//Faster version using a map
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