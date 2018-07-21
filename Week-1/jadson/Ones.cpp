#include <stdio.h>

int main(int argc, char *argv[]) {
       int num;
       int soma=1;
       int cont=1;
       int resto=1;
       while(scanf("%i",&num)!=EOF){
       	soma=1,cont=1,resto=1;
       while(soma%num!=0){
       	resto=(10%num)*resto;
       	if(resto>num){
       		resto=resto%num;
		   }
       	soma=soma+resto;
       	cont++;
	   }
	   printf("%i\n",cont);
}
}
