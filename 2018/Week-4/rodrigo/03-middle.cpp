// http://poj.org/problem?id=2388

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, x;
	cin >> n;
	vector<int> v; 
	while(n--) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	cout << v[v.size() >> 1] << endl;
	return 0;
}