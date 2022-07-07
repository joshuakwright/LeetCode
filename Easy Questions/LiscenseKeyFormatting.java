//Fast Version

class Solution {
    public String licenseKeyFormatting(String s, int k) {
        char newstr[] = new char[s.length() + 1 + s.length() / k];
        int j = newstr.length - 1;
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == '-') continue;
            if (c >= 'a') c = (char)(c - 32);
            
            newstr[j--] = c;
            if (++count == k) {
                newstr[j--] = '-';
                count = 0;
            }
        }
        
        if (j + 1 < newstr.length && newstr[j + 1] == '-') j++;
        return new String(newstr, j+1, newstr.length-j-1);
    }        
}



//My slow version

class Solution {
    public String licenseKeyFormatting(String s, int k) {
        int group = 0;
        boolean initialized = false;
        StringBuilder sb = new StringBuilder();
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) != '-') {
                sb.insert(0, s.charAt(i));
                group++;
                if (group == k) {
                    if (initialized) sb.insert(k, '-');
                    initialized = true;
                    group = 0;
                }   
            }
            if (i == 0 && sb.length() > k && group > 0) {
                sb.insert(group, '-');
            }
        }
        return sb.toString().toUpperCase();
    }        
}