#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;

	while((cin >> str) && str != "#")
		printf("%s\n", next_permutation(str.begin(), str.end()) ? str.c_str() : "No Successor");
	return 0;
}
