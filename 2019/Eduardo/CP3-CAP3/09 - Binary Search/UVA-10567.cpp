#include <bits/stdc++.h>
#define MAXC 260
using namespace std;

vector<int> idx[MAXC];

int main(){
	string s;
	

	cin>>s;

	for(int i=0; i<s.length(); i++)
		idx[s[i]].push_back(i);


	int n;
	scanf("%d",&n);

	while(n--){
		string cand;
		cin >> cand;

		int first=0;

		bool match=true;
		int act_idx=-1;

		for(int i=0; i<cand.length(); i++){
			char c = cand[i];

			vector<int>::iterator it = upper_bound(idx[c].begin(),idx[c].end(), act_idx);
			if(it == idx[c].end()){
				match = false;
				break;
			}

			act_idx = *it;
			if(i == 0) first=*it;
		}


		if(match) printf("Matched %d %d\n",first,act_idx);
		else printf("Not matched\n");
	}

	return 0;
}
