// https://br.spoj.com/problems/SENHA/
// TIME 0.00

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t = 0;
	char key1[7];
	char key2[7];
	char curr, buff;

	map<char, int> password[7];

	while(scanf("%d", &n) && n)
	{
		getchar();

		for(int k=0; k<n; ++k)
		{
			for(int i=0; i < 5; ++i) {
				curr = getchar(); buff = getchar(); // buff is trash
				key1[i] = curr;

				curr = getchar(); buff = getchar(); // buff is trash
				key2[i] = curr;
			}

			for(int i=0; i<6; ++i) {
				curr = getchar(); buff = getchar(); // buff is trash
				++password[i][key1[curr - 'A']];
				++password[i][key2[curr - 'A']];
			}
		}

		if(t)
			putchar('\n');
		printf("Teste %d\n", ++t);

		for(int i=0; i<6; ++i) {
			char ans = '0';

			for(auto &e : password[i]) {
				if(e.second > password[i][ans])
					ans = e.first;
			}

			if(i != 5)
				printf("%c ", ans);
			else
				printf("%c\n", ans);

			password[i].clear();
		}
	}
	return 0;
}