// 11933 - Splitting Numbers

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while((cin >> n) && n)
    {
      int a = 0;
      int b = 0;
      int counter = 0;]

    for(int i=0; i<31; ++i) {
         if(n & (1 << i)) {
             if(counter&1) b |= (1 << i);
             else a |= (1 << i);

       ++counter;
     }
    }

    cout << a << " " << b << endl;
  }
  return 0;
}