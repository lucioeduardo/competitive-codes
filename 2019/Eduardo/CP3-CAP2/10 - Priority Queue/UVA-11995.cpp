#include <bits/stdc++.h>
using namespace std;

bool flag_q, flag_s, flag_p;

int main(){
	int n;
	
	while(scanf("%d",&n) != EOF){
		flag_q = flag_p = flag_s = true;
		
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		
		for(int i=0; i<n; i++){
			int a,b;
			
			scanf("%d %d",&a,&b);
			if(a == 1){
				s.push(b);
				q.push(b);
				p.push(b);
			}else{
				if(s.empty()){
					flag_s = flag_q = flag_p = false;
					continue;
				}
				if(s.top() != b) flag_s = false;
				if(q.front() != b) flag_q = false;
				if(p.top() != b) flag_p = false;
				
				s.pop();q.pop();p.pop();
			}
		}
				
		if(!(flag_q || flag_s || flag_p)) printf("impossible\n");
		else if((flag_q + flag_s + flag_p) > 1) printf("not sure\n");
		else if(flag_p) printf("priority queue\n");
		else if(flag_q) printf("queue\n");
		else printf("stack\n");
	}


	return 0;
}
