#include <bits/stdc++.h>
#define MAXN 1000005

using namespace std;

int main(){

    bool flag;
    char str[MAXN];
    list<char> result;

    while(scanf("%s", str) != EOF){
        flag = false;

        for(int i = 0; i < strlen(str); i++){
            if(str[i] == '[') flag = true;
            else if(str[i] == ']') flag = false;

            if(str[i] != '[' && str[i] != ']'){
                if(flag){
                    result.push_front(str[i]);
                } else {
                    result.push_back(str[i]);
                }
            }
        }

        list<char>::iterator it;
        for(it = result.begin(); it != result.end(); it++)
            printf("%c", *it);
        printf("\n");

        result.clear();
    }



    return 0;
}