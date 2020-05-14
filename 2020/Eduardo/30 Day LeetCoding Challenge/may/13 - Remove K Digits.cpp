class Solution {
public:
    string removeKdigits(string num, int k) {
        int idx=0;
        string res="";
        int m=0;

        if(k == 0) return num;
        
        while(k>0 && idx < num.size()){
            m=idx;
            for(int i=m+1; i<=idx+k && i < num.size(); i++){
                //cout << i << endl;
                if(num[i] < num[m]) m=i;
            }
            
            //cout << idx << " " << m << endl;
            //cout << "K:" << k << endl;
            if(idx+k >= num.size()){
                //res += '0';
                m=num.size()-1;
                break;
            }
            else res += num[m];
            k-=(m-idx);
            idx=m+1;
        }
        
        
        if(res == "") res = '0';
        res += num.substr(m+1);
        
        
        int i=0;
        while(res[i] == '0' && i < res.size()-1) i++;
        
        return res.substr(i);
    }
};