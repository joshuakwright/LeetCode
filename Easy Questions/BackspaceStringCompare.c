//Working solution using same idea as original, but it works

bool backspaceCompare(char * s, char * t){
    int i = strlen(s) - 1, j = strlen(t) - 1;
    int skipS = 0, skipT = 0;
    
    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if(s[i] == '#') {
                skipS++; 
                i--;
            } 
            else if(skipS > 0) {
                skipS--; 
                i--;
            }
            else break;
        }
        while(j >= 0) {
            if(t[j] == '#') {
                skipT++; 
                j--;
            }
            else if(skipT > 0) {
                skipT--; 
                j--;
            }
            else break;
        }
        if(i >= 0 && j >= 0 && s[i] != t[j]) return false;
        if((i >= 0) != (j >= 0)) return false;
        i--; j--;
    }
    
    return true;
}

//My initial solution that doesn't really work

bool backspaceCompare(char * s, char * t){
    int i = strlen(s) - 1, j = strlen(t) - 1;
    while(i != 0 || j != 0) {
        if (s[i] == '#') {
            int k = 0, del = 1;
            while (k < del) {
                if(i == 0) {
                    s[i] = 'A';
                    break;
                }
                i--;
                if(i != 0) i--;
                if(s[i] == '#') del++;
                k++;
            }
        }
        if (t[j] == '#') {
            int k = 0, del = 1;
            while (k < del) {
                if(j == 0) {
                    t[j] = 'A';
                    break;
                }
                j--;
                if(j != 0) j--; 
                if(t[j] == '#') del++;
                k++;
            }
        }
        printf("%c, %c\n", s[i], t[j]);
        if(s[i] != t[j]) return false;
        if(i != 0) i--;
        if(j != 0) j--;
    }
    
    return true;
}