// https://br.spoj.com/problems/JASPION/
// TIME 0.00

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	int n, m;
	string jp, pt;

	scanf("%d", &t);
	map<string, string> dic;

	while(t--)
	{
		scanf("%d %d", &n, &m);
		getchar();

		while(n--) {
			getline(cin, jp);
			getline(cin, pt);
			dic[jp] = pt;
		}

		while(m)
		{
			cin >> jp;
			char c = getchar();

			if(dic.count(jp)) { // caso tenha no dicionario
				if(m)
					printf("%s ", dic[jp].c_str());
				else
					printf("%s\n", dic[jp].c_str());
			} else {  // caso nao tenha no dicionario
				if(m)
					printf("%s ", jp.c_str());
				else
					printf("%s\n", jp.c_str());
			}

			if(c != ' ') { // caso for o final de uma frase
				putchar(c);
				--m;
			} 
		}
		dic.clear();
	}
	return 0;
}