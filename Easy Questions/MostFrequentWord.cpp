class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> count;
        set<string> bannedSet;
        set<char> symbols {' ', '!', '?', '\'', ',', ';', '.'};
        string word;
        int parLen = paragraph.length();
        
        for (int i = 0; i < banned.size(); i++) {
            bannedSet.insert(banned[i]);
        }
        
        for (int i = 0 ; i < parLen; i++) {
            char place = tolower(paragraph.at(i));
            if ((symbols.find(place) != symbols.end() || i + 1 == parLen) && !word.empty()) {
                if (i + 1 == parLen && symbols.find(place) == symbols.end()) {
                    word.push_back(place);
                }
                if (bannedSet.find(word) != bannedSet.end()) {
                    word.clear();
                    continue;
                }
                if (count.find(word) != count.end())  {
                    count[word]++;
                }
                else {
                    count[word] = 1;
                }
                word.clear();
                continue;
            }
            if (symbols.find(place) == symbols.end()) {
                word.push_back(place);
            }
        }
        
        map<string, int>::iterator mapIt;
        int max = 0;
        string sMax = "";
        for (mapIt = count.begin(); mapIt != count.end(); mapIt++) {
            if (mapIt->second > max) {
                max = mapIt->second;
                sMax = mapIt->first;
            }
        }
        
        return sMax;
    }
};