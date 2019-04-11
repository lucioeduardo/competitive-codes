#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int n, c, q, t;
char l;
pii score[105];

bool comp(int a, int b){
    if(score[a].first > score[b].first) return true;
    else if(score[a].first == score[b].first)
        if(score[a].second < score[b].second) return true;
        else if(score[a].second == score[b].second){
            return a < b;
        }
    return false;
}

int main(){

    scanf("%d ", &n);

    for(int i = 0; i < n; i++){  

        vector<int> ct;
        int penalties[105][10];
        for(int i = 0; i < 105; i++) score[i] = make_pair(0,0);
        memset(penalties, 0, sizeof(penalties));      

        string s;
        while(getline(cin, s)){
            if(s.empty()) break;

            sscanf(s.c_str(), "%d %d %d %c", &c, &q, &t, &l);
            if(find(ct.begin(), ct.end(), c) == ct.end()) ct.push_back(c);
            if(l == 'C' && penalties[c][q] != -1){
                score[c].second += (t+penalties[c][q]);
                score[c].first++;
                penalties[c][q]=-1;
            } else if(l == 'I' && penalties[c][q] != -1){
                penalties[c][q] += 20;
            }
        }

        sort(ct.begin(), ct.end(), comp);

        for(vector<int>::iterator it = ct.begin(); it != ct.end(); it++){
            printf("%d %d %d\n", *it, score[*it].first, score[*it].second);
        }
        printf("\n");

    }


    return 0;
}
