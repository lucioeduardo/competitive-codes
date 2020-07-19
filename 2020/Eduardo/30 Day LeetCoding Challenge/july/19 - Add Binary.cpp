class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        
        int i = a.length()-1;
        int j = b.length()-1;
        
        bool r=false;
        
        while(i>=0 || j>=0){
            int sum;
            
            if(i < 0) sum = (b[j--] - '0');
            else if(j < 0) sum = (a[i--] - '0');
            else{
                sum = (a[i] - '0') + (b[j] - '0');
                i--;j--;
            }
            
            if(r)
                sum++;

            if(sum < 2){
                res += '0'+sum;
                r=false;
            }else{
                r=true;
                res += '0'+(sum-2);
            }
        }
        
        if(r)
            res += '1';
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};