//My original slow version
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {return "";}
        if (strs.size() == 1) {return strs[0];}
        string common = strs[0];
        string comp;
        int min = common.length();
        for (int i = 1; i < strs.size(); i++) {
            comp = strs[i]; 
            if (common[0] != comp[0]) {return "";}
            if (comp.length() < min) {
                min = comp.length();
                common.erase(min);
            }
            for (int j = 0; j < min; j++) {
                if ((common[j] != comp[j]) && (j <= common.length())) {
                    common.erase(j);
                    min = common.length();
                }
            }
        }
        return common;
    }
};

//Slightly faster version using vertical scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {return "";}
        if (strs.size() == 1) {return strs[0];}
        int min = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < min) {
                min = strs[i].length();
            }
        }
        string common = strs[0];
        common.erase(min);
        for (int j = 0; j < min; j++) {
            for (int k = 0; k < strs.size(); k++) {
                if(common[j] != strs[k][j]) {
                    common.erase(j);
                    min = common.length();
                }
            }
        }
        return common;
    }
};

//Divide and conqure with recursion method

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {return "";}
        if (strs.size() == 1) {return strs[0];}
        return shortestCommonPrefix(strs, 0, strs.size() - 1);
    }
    
private:
    string shortestCommonPrefix(vector<string> strs, int l, int r) {
        if (l == r) {
            return strs[l];
        }
        else {
            int mid = (l + r)/2;
            string lcpLeft = shortestCommonPrefix(strs, l , mid);
            string lcpRight = shortestCommonPrefix(strs, mid + 1,r);
            cout << lcpLeft << " " << lcpRight << "\n";
            return commonPrefix(lcpLeft, lcpRight);
        }
    }

    string commonPrefix(string sleft, string sright) {
        int min = sleft.length();
        if (sright.length() < min) {min = sright.length();}
        for (int i = 0; i < min; i++) {
            if (sleft[i] != sright[i]) {
                return sleft.erase(i);
            }
        }
        return sleft.erase(min);
    }
};


//Broke shit
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {return "";}
        if (strs.size() == 1) {return strs[1];}
        return shortestCommonPrefix(strs);
    }
    
private:
    string shortestCommonPrefix(vector<string> strs) {
        int min = strs[0].length();
        int index = 0;
        string sleft = strs[0];
        string sright;
        for (int i = 1; i < strs.size() / 2; i++) {
            if (strs[i].length() < min) {
                min = strs[i].length();
                index = i;
                sleft = strs[i];
            }
        }
        
        
        min = strs[(strs.size() / 2)].length();
        index = (strs.size() / 2);
        sright = strs[(strs.size() / 2)];
        for (int j = (strs.size() / 2) + 1; j < strs.size(); j++) {
            if (strs[j].length() < min) {
                min = strs[j].length();
                index = j;
                sright = strs[j];
            }  
        }
        cout << sleft << " " << sright;
        return commonPrefix(sleft, sright);
        
    }

    string commonPrefix(string sleft, string sright) {
        int min = sleft.length();
        if (sright.length() < min) {min = sright.length();}
        for (int i = 0; i < min; i++) {
            if (sleft[i] != sright[i]) {
                sleft.erase(i);
            }
        }
        return sleft;
    }
};

        