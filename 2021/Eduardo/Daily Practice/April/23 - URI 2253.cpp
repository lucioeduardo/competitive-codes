/*
A senha deve conter, no mínimo, uma letra maiúscula, uma letra minúscula e um número;
A mesma não pode ter nenhum caractere de pontuação, acentuação ou espaço;
Além disso, a senha pode ter de 6 a 32 caracteres.
*/

#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

int main(){
  string s;

  while(getline(cin,s)){ 
    

    bool q1a=false, q1b=false, q2 = true, q3=(s.length() >= 6 && s.length() <= 32);

    for(char c: s){
      if(isalpha(c)){
        if(c == tolower(c)) q1a=true;
        else q1b=true;
      }else if(!isdigit(c)){
        q2=false;
      }
    }

    if(q1a && q1b && q2 && q3)
      cout << "Senha valida." << endl;
    else
      cout << "Senha invalida." << endl;
  }
  
  return 0;
}
