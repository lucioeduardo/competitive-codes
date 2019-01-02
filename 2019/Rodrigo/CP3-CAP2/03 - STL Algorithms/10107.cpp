#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int index = 0;
	vector<int> v(10001);

	while(cin >> v[index++]) {
		sort(v.begin(), v.begin() + index);

		cout << (index&1 ? v[index/2] : (v[index/2 - 1] + v[index/2]) / 2) << endl;
	}

	return 0;
}
