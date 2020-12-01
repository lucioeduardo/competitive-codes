// SPOJ - https://br.spoj.com/problems/PLACAR/
#include <iostream>
#include <vector>
#include <algorithm>
#define all(c) c.begin(), c.end()
using namespace std;

typedef pair<int, string> pis;
vector<pis> placar;

bool compare(pis a, pis b){
	if(a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main(){
	int n, nota, t=1;
	string nome;
	
	while(cin>>n){
		placar.clear();
		for(int i=0; i<n; i++){
			cin>>nome>>nota;
			placar.push_back(pis(nota,nome));
		}
		
		sort(all(placar), compare);
		
		cout << "Instancia " << t++ << endl;
		cout << placar[0].second << endl;
		cout << endl;
	}
	

	
	return 0;
}
