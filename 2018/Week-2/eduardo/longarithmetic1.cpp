#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string long_mult(string str1, string str2){
	int len1 = str1.length();
	int len2 = str2.length();
	
	int max_len = len1+len2-1;
	int num1[len1], num2[len2], mult[max_len+1];
	
	memset(mult, 0, sizeof(mult));
	
	for(int i=0; i<len1; i++){
		num1[i] = str1[len1-i-1] - '0';
	}
	
	for(int i=0; i<len2; i++){
		num2[i] = str2[len2-i-1] - '0';
	} 
	
	for(int i=0; i<len1; i++){
		for(int j=0; j<len2; j++){
			mult[j+i] += num1[i]*num2[j];
		}
	}
	
	for(int i=0; i<max_len; i++){		
		mult[i+1] += mult[i]/10;
		mult[i]%=10;
	}
	
	string res="";
	
	if(mult[max_len] != 0)
		res += ('0' + mult[max_len]);
	for(int i=max_len-1; i>=0; i--){
		res += ('0' + mult[i]);
	}
	
	return res;
}

string to_str(int num){
	string res = "";
	while(num > 0){
		int x = num % 10;
		num/=10;
		
		res += ('0' + x);
	}
	reverse(res.begin(), res.end());
	return res;
}

string long_factorial(int n){
	if(n == 0) return "1"; 
	return long_mult(to_str(n), long_factorial(n-1));
}

int main(){
	
	int n;
	cin>>n;
	cout<<long_factorial(n)<<endl;
	return 0;
}

