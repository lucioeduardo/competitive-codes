#include <bits/stdc++.h>
#define MAXN 220
using namespace std;

char tab_b[MAXN][MAXN];
string tab_d;
int l,c,idx=-1;


string solve_b(int line_i, int line_f, int col_i, int col_f){
	string res = "";

	if(line_i > line_f || col_i > col_f)
		return "";

	if(line_i == line_f and (col_i == col_f)){
		res = tab_b[line_i][col_i];
	}else{
		int line_m = (line_i + line_f)/2;
		int col_m = (col_i + col_f)/2;

		string quad[4];

		quad[0] = solve_b(line_i, line_m, col_i, col_m);
		quad[1] = solve_b(line_i, line_m, col_m+1, col_f);
		
		quad[2] = solve_b(line_m+1, line_f, col_i, col_m);
		quad[3] = solve_b(line_m+1, line_f, col_m+1, col_f);

		bool flag = true;
		string comp = "x";

		for(int i=0;i<4;i++){
			if(quad[i].length() > 1)
				flag = false;

			if(comp == "x" and quad[i].length()>0)
				comp = quad[i];
			
			else if(quad[i].length() > 0 and quad[i] != comp)
				flag = false;
		}

		if(flag)
			res = quad[0];
		else
			res = "D" + quad[0] + quad[1] + quad[2] + quad[3];
	}

	return res;
}

void solve_d(int line_i, int line_f, int col_i, int col_f){

	if(line_i > line_f || col_i > col_f)
		return;

	char c = tab_d[++idx];


	if(tab_d[idx] == 'D'){
		int line_m = (line_i + line_f)/2;
		int col_m = (col_i + col_f)/2;

		string quad[4];

		solve_d(line_i, line_m, col_i, col_m);
		solve_d(line_i, line_m, col_m+1, col_f);
		
		solve_d(line_m+1, line_f, col_i, col_m);
		solve_d(line_m+1, line_f, col_m+1, col_f);

	}else{
		for(int i=line_i; i <= line_f; i++){
			for(int j=col_i; j<= col_f; j++){
				tab_b[i][j] = tab_d[idx];
			}
		}
	}
}

int main(){
	char type;

	while(scanf("%c ",&type) && type != '#'){
		scanf("%d %d ",&l,&c);

		int count=0;

		if(type == 'B'){
			printf("D%4d%4d",l,c);
			for(int i=0; i<l; i++){
				for(int j=0;j<c;j++){
					if(count == 50){
						//printf("aaaa\n");
						count=0;
						getchar();
					}
					scanf("%c", &tab_b[i][j]);
					count++;
				}
			}

			string res = solve_b(0,l-1,0,c-1);

			for(int i=0; i<res.length(); i++){
				if(i%50 == 0) printf("\n");
				printf("%c",res[i]);
			}

			cout << endl;
		}else{
			cin>>tab_d;
			
			idx=-1;
			solve_d(0,l-1,0,c-1);

			printf("B%4d%4d\n",l,c);

			count=0;

			for(int i=0; i<l; i++){
				for(int j=0;j<c;j++){
					if(count == 50){
						count=0;
						printf("\n");
					}
					printf("%c", tab_b[i][j]);
					count++;
					
				}
			}

			printf("\n");
		}
		getchar();
	}

	return 0;
}
