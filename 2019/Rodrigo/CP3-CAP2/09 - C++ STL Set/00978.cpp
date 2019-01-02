#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;

	for(int test=0; test<t; ++test)
	{
		if(test) printf("\n");

		int battle, g, b;
		cin >> battle >> g >> b;

		multiset<int, greater<int> > green, blue;

		for(int i=0; i<g; ++i){
			int e; cin >> e;
			green.insert(e);
		}
		for(int i=0; i<b; ++i){
			int e; cin >> e;
			blue.insert(e);
		}


		while(green.size() && blue.size())
		{
			vector<int> x, y;
			int time = battle;

			while(time-- && green.size() && blue.size())
			{
				int sg = *green.begin(), sb = *blue.begin();

				if(sg < sb) x.push_back(sb - sg);
				if(sg > sb) y.push_back(sg - sb);
				
				green.erase(green.begin());
				blue.erase(blue.begin());
			}

			for(auto &e : x) blue.insert(e);
			for(auto &e : y) green.insert(e);
		}

		if(green.size() < blue.size()) {
			cout << "blue wins" << endl;
			for(auto &e : blue)
				cout << e << endl;

		} else if(green.size() > blue.size()) {
			cout << "green wins" << endl;
			for(auto &e : green)
				cout << e << endl;

		} else {
			cout << "green and blue died" << endl;
		}

	}

	return 0;
}
