#include <iostream>
#include <string>

using namespace std;

string lower(string s){
    for(int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}

int main(){

    int p;
    cin >> p;

    int i;
    string word;
    string lowerWord;

    while(p--){
        int v = 0;

        cin >> word;

        lowerWord = lower(word);

        for(i = 0; i < lowerWord.size()-1; i++)
            if(lowerWord[i] >= lowerWord[i+1]){
                v = 1;
                break;
            }

        if(!v)
            cout << word << ":" << " O" << endl;
        else
            cout << word << ":" << " N" << endl;
    }


    return 0;
}