// https://br.spoj.com/problems/BRACELMG/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string a, b, c;

	while(n--) {
		cin >> a >> b;
		c = a;
		b += b;

		reverse(a.begin(), a.end());

		if(b.find(a) != string::npos || b.find(c) != string::npos)
			cout << "S" << endl;
		else
			cout << "N" << endl;
	}
	return 0;
}