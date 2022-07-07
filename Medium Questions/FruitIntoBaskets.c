int totalFruit(int* fruits, int fruitsSize){
    if (fruitsSize == 1) return 1;
    
    int num1[2] = {fruits[0], 0};
    int num2[2] = {-1, -1};
    int count = 1;
    
    int i = 1;
    while (true) {
        if(i == fruitsSize - 1) return ++count;
        if (fruits[i] != fruits[0]) {
            num2[0] = fruits[i];
            num2[1] = i;
            count++;
            i++;
            break;
        }   
        count++;
        i++;
    }
    
    int maxCount = count;
    int tracked = num2[0];
    for (; i <= fruitsSize - 1; i++) {
        if (fruits[i] != num1[0] && fruits[i] != num2[0]) {
            if (count > maxCount) maxCount = count;
            if(num1[1] > num2[1]) {
                num2[0] = fruits[i];
                num2[1] = i;
                count = i - num1[1] + 1;
            }
            else {
                num1[0] = fruits[i];
                num1[1] = i;
                count = i - num2[1] + 1;
            }
            tracked = fruits[i];
        }
        else {
            if (tracked != fruits[i]) {
                if(tracked == num1[0]) {
                    num2[1] = i;
                    tracked = num2[0];
                }
                else {
                    num1[1] = i;
                    tracked = num1[0];
                }
            }
            count++;
        }
    }
    if(count > maxCount) maxCount = count;
    
    return maxCount;
}