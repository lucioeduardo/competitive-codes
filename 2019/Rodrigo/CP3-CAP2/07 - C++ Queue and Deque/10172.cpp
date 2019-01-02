#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int N, S, Q, x, e;
        int total = 0;
        
        cin >> N >> S >> Q;

        queue<int> q[110];
        stack<int> carrier;

        for(int i=0; i<N; ++i) {
            cin >> x;
            total += x;

            while(x--) {
                cin >> e;
                q[i].push(e - 1);
            }
        }

        int answer = 0;

        for(int station = 0;; (station = (station + 1) % N))
        {

            while(!carrier.empty() && (carrier.top() == station || q[station].size() < Q)) {
                if(carrier.top() != station)
                    q[station].push(carrier.top());
                else
                    --total;

                carrier.pop();
                ++answer;
            }

            while(carrier.size() < S && !q[station].empty()) {
                carrier.push(q[station].front());
                q[station].pop();
                ++answer;
            }

            if(carrier.empty() && !total)
                break;
            answer += 2;
        }
        cout << answer << endl;

    }

    return 0;
}