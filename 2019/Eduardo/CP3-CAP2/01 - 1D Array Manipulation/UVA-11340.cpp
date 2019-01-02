#include <bits/stdc++.h>
using namespace std;

map<char,int> val;

int main(){
    int t;

    scanf("%d ",&t);

    for(int i=0;i<t;i++){
        int k,m;

        scanf("%d ",&k);
        
        for(int i=0; i<k; i++){
            unsigned char c;
            int v;
            cin>>c>>v;

            val[c]=v;
        }

        scanf("%d ",&m);
        int res=0;
        for(int i=0;i<m;i++){
            string s;
            getline(cin, s);

            for(size_t j=0; j<s.length(); j++){
				if(val.find(s[j]) != val.end())
					res += val[s[j]];
            }
        }
		
        printf("%d.%02d$\n",res/100, res%100);
        val.clear();
    }
}
