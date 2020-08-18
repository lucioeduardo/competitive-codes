#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;

#define MAXN 100010

int l[MAXN], r[MAXN], d[MAXN], a[MAXN], inc_d[MAXN];
ll inc_a[MAXN];

int main(){
  int n,m,k;

  cin>>n>>m>>k;

  for(int i=1; i<=n; i++){
    cin>>a[i];
  }

  for(int i=1; i<=m; i++){
    cin>>l[i]>>r[i]>>d[i];
  }

  for(int i=1; i<=k; i++){
    int x,y;
    cin>>x>>y;

    inc_d[x]++;
    inc_d[y+1]--;
  }

  ll v=0;

  for(int i=1; i<=m; i++){
    v += inc_d[i];

    ll nD = v*d[i];

    inc_a[l[i]] += nD;
    inc_a[r[i]+1] -= nD;
  }

  v=0;

  for(int i=1; i<=n; i++){
    v += inc_a[i];
    if(i>1) cout << " ";
    cout << a[i] + v;
  }

  cout << endl;

  return 0;
}