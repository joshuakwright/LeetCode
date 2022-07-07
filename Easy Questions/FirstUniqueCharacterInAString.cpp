class Solution {
public
    int firstUniqChar(string s) {
        int hash[26]={0};
        for(int i=0;is.size();i++)
            hash[s[i]-'a']++;
        for(int i=0;is.size();i++){
            if(hash[s[i]-'a']==1)return i;
        }
        return -1;
    }
};