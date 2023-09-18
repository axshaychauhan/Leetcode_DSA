class Solution {
public:
    int addDigits(int num) {
       
        if(num <= 9) {
            return num;
        }
        
        int digitSum = 0;
        
        while(num>0) {
            int digit = num%10;
            digitSum += digit;
            num = num/10;
        }
        
      return addDigits(digitSum);
    }
};