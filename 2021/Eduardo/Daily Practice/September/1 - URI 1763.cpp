#include <bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr, val) memset(arr, val, sizeof(arr))
#define ll long long
using namespace std;

map<string, string> trad = {{"brasil", "Feliz Natal!"}, {"alemanha", "Frohliche Weihnachten!"}, {"austria", "Frohe Weihnacht!"}, {"coreia", "Chuk Sung Tan!"}, {"espanha", "Feliz Navidad!"}, {"grecia", "Kala Christougena!"}, {"estados-unidos", "Merry Christmas!"}, {"inglaterra", "Merry Christmas!"}, {"australia", "Merry Christmas!"}, {"portugal", "Feliz Natal!"}, {"suecia", "God Jul!"}, {"turquia", "Mutlu Noeller"}, {"argentina", "Feliz Navidad!"}, {"chile", "Feliz Navidad!"}, {"mexico", "Feliz Navidad!"}, {"antardida", "Merry Christmas!"}, {"canada", "Merry Christmas!"}, {"irlanda", "Nollaig Shona Dhuit!"}, {"belgica", "Zalig Kerstfeest!"}, {"italia", "Buon Natale!"}, {"libia", "Buon Natale!"}, {"siria", "Milad Mubarak!"}, {"marrocos", "Milad Mubarak!"}, {"japao", "Merii Kurisumasu!"}};

int main(){
  string str;

  while (cin >> str){
    if(trad.find(str) == trad.end())
      cout << "--- NOT FOUND ---" << endl;
    else
      cout << trad[str] << endl;
  }

  return 0;
}
