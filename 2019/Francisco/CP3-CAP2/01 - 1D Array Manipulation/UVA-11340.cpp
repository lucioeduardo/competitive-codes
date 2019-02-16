#include <bits/stdc++.h>
#define LINE_SIZE 10010

using namespace std;

int n, k, m;
char text[LINE_SIZE];
map<char, int> charPrice;

int main(){
	
    scanf("%d", &n);

    char c;
    int p;
    double result;

    for(int i = 0; i < n; i++){
      
	    result = 0;
        scanf("%d", &k);

	    for(int j = 0; j < k; j++){
	        scanf(" %c %d", &c, &p);
	        charPrice[c] = p;
	        //charPrice.insert(make_pair(c, p))
	    }

	    scanf("%d", &m);
	
	    for(int j = 0; j <= m; j++){
	        
            fgets(text, LINE_SIZE, stdin);

	        for(int k = 0; k < strlen(text); k++){
	            if(charPrice.find(text[k]) != charPrice.end()){
		            result += charPrice[text[k]] / 100.0; 
		        }
	        }
	    }

	    printf("%.2f$\n", result);
        charPrice.clear();
    }

    return 0;
}
