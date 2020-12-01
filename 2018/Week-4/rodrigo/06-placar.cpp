// https://br.spoj.com/problems/PLACAR/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, point;
	int test = 0;
	string name;

	while(cin >> n) {
		vector<pair<int, string> > students;

		while(n--) {
			cin >> name >> point;
			students.push_back(make_pair(point, name));
		}

		sort(students.begin(), students.end());

		int ind = 0;
		while(students[ind].first == students[0].first)
			++ind;

		cout << "Instancia " << ++test << endl << students[ind-1].second << endl;
	}
	return 0;
}