#include <cstdio>
#define MAXN 200010

long long array[MAXN];
long long binary[MAXN];
long long segtree[MAXN*2-1];

bool isSpecial(long long n){
    if(n < 0)
        return false;
    long long end = n%10;
    while(n/10){
        n/=10;
    }
    if(n==end)
        return true;
    return false;
}

void specialArray(long long len){
    for(int i = 1; i <= len; i++)
        if(isSpecial(array[i]))
            binary[i] = 1;
        else
            binary[i] = 0;
}

long long query(long long node, long long start, long long end, long long left, long long rigth){
    // Totally out
    if(rigth < start || left > end)
        return 0;
    // Totally in
    if(left <= start && end <= rigth)
        return segtree[node];

    // Partial in
    long long mid = (start+end)/2;
    long long q1 = query(2*node, start, mid, left, rigth);
    long long q2 = query(2*node+1, mid+1, end, left, rigth);

    return q1+q2;
}

void update(long long node, long long start, long long end, long long index, long long value){
    if(start==end){
        binary[index] = value;
        segtree[node] = value;
    } else{
        long long mid = (start+end)/2;
        if(start <= index && index <= mid){
            update(2*node,start, mid, index, value);
        } else{
            update(2*node+1,mid+1, end, index, value);
        }
        segtree[node] = segtree[2*node]+segtree[2*node+1];
    }
}

void buildSegTree(long long node, long long start, long long end){
    if(start == end)
        segtree[node] = binary[start];
    else{
        // middle
        long long mid = (start+end)/2;
        // left
        buildSegTree(2*node, start, mid);
        // rigth
        buildSegTree(2*node+1, mid+1, end);
        
        // the childs sum
        segtree[node] = segtree[2*node]+segtree[2*node+1];
    }
}

int main(){

    long long n, q, a, b, c, result;
    scanf("%lld %lld", &n, &q);

    for(int i = 1; i <= n; i++)
        scanf("%lld", &array[i]);

    specialArray(n);
    buildSegTree(1, 1, n);

    while(q--){
        scanf("%lld %lld %lld", &a, &b, &c);
        
        if(a == 1){
            result=query(1,1,n,b,c);
            printf("%lld\n", result);
        }else if(a == 2){
            if(isSpecial(c))
                c = 1;
            else
                c = 0;
            update(1, 1, n, b, c);
        }
    }

    return 0;
}