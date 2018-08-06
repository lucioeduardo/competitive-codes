// https://br.spoj.com/problems/PALAVRMG/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string a;

	cin >> n;

	while(n--) {
		cin >> a;
		bool flag = true;

		for(int i=0; i<a.size()-1; ++i)
			if(tolower(a[i]) >= tolower(a[i+1]))
				flag = false;

		if(flag) cout << a << ": " << "O" << endl;
		else cout << a << ": " << "N" << endl;
	}
	return 0;
}