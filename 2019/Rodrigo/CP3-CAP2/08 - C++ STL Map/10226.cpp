#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string name;
	scanf("%d ", &n);

	for(int t=0; t<n; ++t)
	{
		if(t)
			printf("\n");

		int total = 0;
		map<string, int> m;
		while(getline(cin, name) && name.size()) {
			++m[name];
			++total;
		}

		for(auto &e : m)
			printf("%s %.4f\n", e.first.c_str(), (e.second * 100.00) / total);
	}	

	return 0;
}
