#include <bits/stdc++.h>
#define MAXN 11
using namespace std;

map<string, int> valor = {
{"YYYYYYN" , 0},
{"NYYNNNN" , 1},
{"YYNYYNY" , 2},
{"YYYYNNY" , 3},
{"NYYNNYY" , 4},
{"YNYYNYY" , 5},
{"YNYYYYY" , 6},
{"YYYNNNN" , 7},
{"YYYYYYY" , 8},
{"YYYYNYY" , 9},
};

string led_code[10] = {"YYYYYYN" ,"NYYNNNN" ,"YYNYYNY" ,"YYYYNNY" ,"NYYNNYY" ,"YNYYNYY" ,"YNYYYYY" ,"YYYNNNN" ,"YYYYYYY" ,"YYYYNYY"};

string sequence[MAXN];
int n;

bool solve(int idx, int prev, int burn_mask){
	if(idx == n)
		return true;
	if(prev < 1)
		return false;
	
	string number = sequence[idx];
	string next_number = led_code[prev-1];

	for(int i=0; i<7; i++){
		if(number[i] == 'Y' and burn_mask & (1 << i))
			return false;
	}


	string seq = sequence[idx];
	bool res = false;



	for(int i=0; i<7; i++){
		if(seq[i] == next_number[i]) continue;
		if(seq[i] == 'Y') return false;
		else{
			burn_mask |= (1<<i);
		}
	}

	return solve(idx+1,prev-1,burn_mask);

}



int main(){

	while(scanf("%d",&n) && n){
		string s;
		for(int i=0; i<n; i++){
			cin>>sequence[i];
		}

		bool res = false;

		for(int i=10; i>=0; i--)
			res |= solve(0,i,0);

		printf("%s\n",res ? "MATCH":"MISMATCH");
	}

	return 0;
}
