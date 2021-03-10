class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        
        while(num >= 1000){
            res += 'M';
            num -= 1000;
        }
        
        if(num >= 900){
            res += "CM";
            num -= 900;
        }else if(num >= 500){
            res += "D";
            num -= 500;
        }else if(num >= 400){
            res += "CD";
            num -= 400;
        }
        
        while(num >= 100){
            res += "C";
            num -= 100;
        }
        
        if(num >= 90){
            res += "XC";
            num -= 90;
        }else if(num >= 50){
            res += "L";
            num -= 50;
        }else if(num >= 40){
            res += "XL";
            num -= 40;
        }
        
        while(num >= 10){
            res += "X";
            num -= 10;
        }
        
        if(num >= 9){
            res += "IX";
            num -= 9;
        }else if(num >= 5){
            res += "V";
            num -= 5;
        }else if(num >= 4){
            res += "IV";
            num -= 4;
        }
        
        while(num >= 1){
            res += "I";
            num -= 1;
        }
        
        return res;
    }
};