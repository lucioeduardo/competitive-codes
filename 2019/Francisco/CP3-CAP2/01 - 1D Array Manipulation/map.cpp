#include <bits/stdc++.h>

using namespace std;

int main(){

    map<char, int> charPrice;
    charPrice.insert(make_pair('a', 100));
    charPrice['b'] = 2;

    for(map<char, int>::iterator it = charPrice.begin(); it != charPrice.end(); it++){
        printf("%c : %d\n", it->first, it->second);
    }

    if(charPrice.find('b') != charPrice.end()){
        printf("have 'b'\n");
    }
    

    printf("%d\n", charPrice['a']);

    return 0;
}
