//My shitty broken solution that doesn't work

char * multiply(char * num1, char * num2){
    int num1Size = 0, num2Size = 0;
    for(int i = 0; num1[i] != '\0'; i++) {
        num1Size++;
    }
    for(int i = 0; num2[i] != '\0'; i++) {
        num2Size++;
    }
    if((num1Size == 1 && num1[0] == '0') || (num2Size == 1 && num2[0] == '0')) return "0";
    
    double *addList;
    if(num1Size > num2Size) {
        addList = malloc(sizeof(double*) * num2Size);
        for(int i = num2Size - 1; i >= 0; i--) {
            double carry = 0;
            double num = 0;
            double temp = 0;
            int j;
            for(j = num1Size - 1; j >= 0; j--) {
                temp = (num2[i] - '0') * (num1[j] - '0');
                temp += carry;
                carry = temp / 10;
                num += fmod(temp, 10) * pow(10, num1Size - j - 1);
            }
            if(carry) num += carry * pow(10, num1Size - j - 1);
            addList[i] = i < num2Size - 1 ? num * pow(10, num2Size - i - 1) : num;
        }
        
        double finalNum = 0;
        for(int i = 0; i < num2Size; i++) {
            finalNum += addList[i];
        }
        free(addList);

        int len = 0;
        double tempFinal = finalNum;
        while (tempFinal != 0) {
            len++;
            tempFinal /= 10;
        }
        
        char *outStr = malloc(sizeof(char*) * (len + 1));
        for(int i = 0; i < len; i++) {
            char temp = (finalNum / pow(10, len - i - 1)) + '0';  
            finalNum = fmod(finalNum, pow(10, len - (i + 1)));
            outStr[i] = temp;
        }
        outStr[len] = '\0';
        
        return outStr;
    }
    else {
        addList = malloc(sizeof(double*) * num1Size);
        for(int i = num1Size - 1; i >= 0; i--) {
            double carry = 0;
            double num = 0;
            double temp = 0;
            int j;
            for(j = num2Size - 1; j >= 0; j--) {
                temp = (num1[i] - '0') * (num2[j] - '0');
                temp += carry;
                carry = temp / 10;
                num += fmod(temp, 10) * pow(10, num2Size - j - 1);
            }
            if(carry) num += carry * pow(10, num2Size - j - 1);
            printf("%f\n", num);
            addList[i] = i < num1Size - 1 ? num * pow(10, num1Size - i - 1) : num;
            printf("%f\n", addList[i]);
        }
        
        double finalNum = 0;
        for(int i = 0; i < num1Size; i++) {
            finalNum += addList[i];
        }
        free(addList);

        int len = 0;
        double tempFinal = finalNum;
        while (tempFinal != 0) {
            len++;
            tempFinal /= 10;
        }
        printf("%f\n", finalNum);
        char *outStr = malloc(sizeof(char*) * (len + 1));
        for(int i = 0; i < len; i++) {
            char temp = (finalNum / pow(10, len - i - 1)) + '0';  
            finalNum = fmod(finalNum, pow(10, len - (i + 1)));
            outStr[i] = temp;
        }
        outStr[len] = '\0';
        
        return outStr;
    }
    
    return 0;
}