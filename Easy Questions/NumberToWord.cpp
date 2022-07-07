class Solution {
public:
string Ones(int num) {
        switch(num) {
            case 1: return " One";
            case 2: return " Two";
            case 3: return " Three";
            case 4: return " Four";
            case 5: return " Five";
            case 6: return " Six";
            case 7: return " Seven";
            case 8: return " Eight";
            case 9: return " Nine";
        }
        return "";
    }
    string Teens(int num) {
        switch(num) {
            case 1: return " Eleven";
            case 2: return " Twelve";
            case 3: return " Thirteen";
            case 4: return " Fourteen";
            case 5: return " Fifteen";
            case 6: return " Sixteen";
            case 7: return " Seventeen";
            case 8: return " Eighteen";
            case 9: return " Nineteen";
        }
        return "";
    }
    string Tens(int num) {
        switch(num) {
            case 1: return " Ten";
            case 2: return " Twenty";
            case 3: return " Thirty";
            case 4: return " Forty";
            case 5: return " Fifty";
            case 6: return " Sixty";
            case 7: return " Seventy";
            case 8: return " Eighty";
            case 9: return " Ninety";
        }
        return "";
    }
    
    string HundredsToWords(int num) {
        string temp;
        if(num / 100 > 0) {
            temp.append(Ones(num / 100));
            temp.append(" Hundred");
            num %= 100;
        }
        if (num / 10 > 0) {
            if (num / 10 == 1 && num % 10 != 0) {
                return temp.append(Teens(num % 10));
            }
            else {
                temp.append(Tens(num / 10));
            }
            num %=10;
        }
        return temp.append(Ones(num));
    }
    
    string numberToWords(int num) {
        string ans;
        if (num == 0) return "Zero";
        if (num / 1000000000 > 0) {
            ans.append(HundredsToWords(num/1000000000));
            ans.append(" Billion");
            num %= 1000000000;
        }
        if (num / 1000000 > 0) {
            ans.append(HundredsToWords(num/1000000));
            ans.append(" Million");
            num %= 1000000;
        }
        if (num / 1000 > 0) {
            ans.append(HundredsToWords(num/1000));
            ans.append(" Thousand");
            num %= 1000;
        }
        ans.append(HundredsToWords(num));
        
        ans.erase(ans.begin());
        return ans;
    }
};
            