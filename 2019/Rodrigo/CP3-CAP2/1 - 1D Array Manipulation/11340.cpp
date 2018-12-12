// 11340 - Newspaper

#include <bits/stdc++.h>
using namespace std;

map<char, int> value;

int main()
{
	int n;
	scanf("%d", &n);

	while(n--) {
		int k;
		scanf("%d ", &k);

		while(k--) {
			char c;
			int v;
			scanf("%c %d ", &c, &v);
			value[c] = v;
		}

		int l;
		char str[10100];
		scanf("%d ", &l);
		int answer = 0;

		while(l--) {
			gets(str);
			for(int i=0; str[i]; ++i)
				answer += value[str[i]];
		}

		printf("%.2f$\n", answer/100.00);
		value.clear();
	}
	return 0;
}