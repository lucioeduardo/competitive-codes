class Solution {
public:
    int freq[26];
    string numbers[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    string originalDigits(string s) {
        memset(freq,0,sizeof(freq));
        
        int count[10];
        memset(count,0,sizeof(count));
        
        for(char c: s){
            if(c == 'z') count[0]++;
            if(c == 'g') count[8]++;
            if(c == 'w') count[2]++;
            if(c == 'h') count[3]++;
            if(c == 'x') count[6]++;
            if(c == 's') count[7]++;
            if(c == 'v') count[5]++;
            if(c == 'u') count[4]++;
            if(c == 'i') count[9]++;
            if(c == 'o') count[1]++;
        }
        
        count[3] -= count[8];
        count[7] -= count[6];
        count[5] -= count[7];
        count[9] -= (count[6] + count[8] + count[5]);
        count[1] -= (count[0] + count[2] + count[4]);
        
        string res="";
        
        for(int i=0; i<10; i++){
            for(int j=0; j< count[i]; j++)
                res += ('0'+i);
        }
        
        return res;
    }
};