// https://www.urionlinejudge.com.br/judge/pt/problems/view/1260
// TIME 0.384

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string name;
	map<string, int> esp;

	scanf("%d", &n);
	getchar(); getchar();

	for(int t=0; t<n; ++t) {
		if(t){
			putchar('\n');
		}

		int cont = 0;
		while((getline(cin, name)) && name[0]) {
			++esp[name];
			++cont;
		}

		for(auto &e : esp) {
			printf("%s %.4f\n", e.first.c_str(), (e.second * 100.00) / cont);
		}
		esp.clear();
	}
	return 0;
}