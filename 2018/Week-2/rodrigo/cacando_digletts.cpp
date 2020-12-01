// https://www.urionlinejudge.com.br/judge/pt/problems/view/2063

#include <bits/stdc++.h>
#define ll long long

ll subset[105];

ll gcd(ll u, ll v) {
  if(u%v == 0)
    return v;
  return gcd(v, u%v);
}

ll find(ll u, ll v) {
  if(subset[u] != v)
    return 1 + find(subset[u], v);
  return 1;
}

int main()
{
  ll n;
  scanf("%lld", &n);

  for(ll i=1; i<=n; ++i)
    scanf("%lld", &subset[i]);

  ll answer = 1;
  for(ll i=1; i<=n; ++i) {
    ll u = find(i, i);
    answer = (answer*u)/gcd(answer, u);
  }

  printf("%lld\n", answer);
  return 0;
}
