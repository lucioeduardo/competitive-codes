#include <bits/stdc++.h>
using namespace std;

int price[10010];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i<n; ++i)
            scanf("%d", price + i);

        int money;
        int val1 = 0, val2 = 1000000;
        scanf("%d", &money);

        sort(price, price + n);

        for(int i=0; i<n && price[i] <= (money/2); ++i) {
            if(!binary_search(price + i + 1, price + n, money - price[i]))
                continue;

            if((val2 - val1) > fabs(money - 2 * price[i])) {
                val1 = min(money - price[i], price[i]);
                val2 = max(money - price[i], price[i]);
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", val1, val2);
    }
    return 0;
}