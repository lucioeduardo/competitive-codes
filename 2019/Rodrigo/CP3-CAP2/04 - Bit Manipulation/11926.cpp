// 11926 - Multitasking

#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

bitset<MAXN> task;

int main() {
  int n, m, x, y, z;

  while((cin >> n >> m) && (n + m))
  {
    string answer = "NO CONFLICT";
    task.reset();

    while(n--) {
      cin >> x >> y;

      while(x < y) {
        if(task[x])
          answer = "CONFLICT";
        task.set(x++, 1);
      }
    }

    while(m--) {
      cin >> x >> y >> z;
      int k=0;
      
      while(k < MAXN) {
        for(int i=x; i<y && (k+i) < 1000001; ++i) {
          if(task[k+i])
            answer = "CONFLICT";
          task.set(k+i,1);
        }
        k += z;
      }
    }

    cout << answer << endl;
  }
  return 0;
}