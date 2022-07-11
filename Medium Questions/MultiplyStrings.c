// Final Super fast solution

char * 
multiply(char * num1, char * num2){
    int num1Size = strlen(num1), num2Size = strlen(num2);
    if(*num1 == '0' || *num2 == '0') return "0";
    int maxLen = num1Size + num2Size;
    
    int *numAns = malloc(sizeof(int) * (maxLen));
    memset(numAns, 0, sizeof(int)*maxLen);
    
    for (int i = num1Size - 1; i >= 0; i--) {
        for(int j = num2Size - 1; j >= 0; j--) {
            numAns[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    
    for(int i = maxLen - 1; i > 0; i--) {
        numAns[i - 1] += numAns[i] / 10;
        numAns[i] %= 10;
    }
    
    char *finalAns = (char*)malloc(sizeof(char) * (maxLen + 1));
    int index = 0;
    int i = numAns[i] == 0 ? 1 : 0;
    
    while (i < maxLen) {
        finalAns[index++] = numAns[i++] + '0';
    }
    finalAns[index] = '\0';
    free(numAns);
    
    return finalAns; //finalAns will need to be freed in calling function
}

// Working solution but slow 

char * 
multiply(char * num1, char * num2){
    int num1Size = 0, num2Size = 0;
    for(int i = 0; num1[i] != '\0'; i++) num1Size++;
    for(int i = 0; num2[i] != '\0'; i++) num2Size++;
    if((num1Size == 1 && num1[0] == '0') || (num2Size == 1 && num2[0] == '0')) return "0";
    
    int **multList = malloc(sizeof(int**) * num2Size);
    for(int i = 0; i < num2Size; i++) multList[i] = malloc(sizeof(int*) * (num1Size + num2Size));
    
    for (int i = num2Size - 1; i >= 0; i--) {
        int carry = 0;
        int j;
        for (j = num1Size + num2Size - 1; j > num1Size + i; j--) multList[i][j] = 0;
        for (int k = num1Size - 1; k >= 0; k--, j--) {
            int mult = (num1[k] - '0') * (num2[i] - '0') + carry;
            carry = mult / 10;
            multList[i][j] = mult % 10; 
        }
        
        if(carry) {
            multList[i][j] = carry;
        }
        else {
            multList[i][j] = 0;
        }
        
        while (--j >= 0) {
            multList[i][j] = 0;
        }
    }
    
    char *finalAns = malloc(sizeof(char *) * (num1Size + num2Size + 1));
    finalAns[num1Size + num2Size] = '\0';
    int j;
    int carry = 0;
    for(j = num1Size + num2Size - 1; j >= 0; j--) {
        int columnSum = 0;
        for(int i = 0; i < num2Size; i++) columnSum += multList[i][j];
        columnSum += carry;
        carry = columnSum / 10;
        finalAns[j] = (columnSum % 10) + '0';
    }
    for(int i = 0; i < num2Size; i++) free(multList[i]);
    free(multList);
    
    char *altAns;
    if(finalAns[0] == '0') {
        altAns = malloc(sizeof(char *) * (num1Size + num2Size));
        strcpy(altAns, (finalAns + 1));
        free(finalAns);
        return altAns;
    }
    
    return finalAns;
}

//My shitty initial broken solution that doesn't work

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