#include <stdio.h>
#include <stdlib.h>

const int N_MAX=100;

int mdc(int a,int b){
	/* calcula o mdc dos numeros a e b */
	if(b>a){
		return mdc(b,a);
	}
	
	if(a%b==0){
		return b;
	}	
	return mdc(a,b);
}

int subset_exist(int *array,int size){
	/*	Verifica se existe um subset B de dois elementos do array, tal que:
	1.B não é um subset vazio.
	2.Não existe inteiro x tal que x>1 divida os dois elementos.
	3.Os dois elementos são diferentes. */
	
	int cont=0;
	int cont2=0;
	
	for(cont;cont<size;cont++){
		for(cont2=cont;cont2<size;cont2++){
			if(mdc(array[cont],array[cont2])==1){
				return 1;
			}
		}
	}
	
	return 0;
}

int main(){
	int test_cases;
	int array[N_MAX];
	int size;
	
	int cont=0;
	int cont2;
	
	scanf("%i",&test_cases);
	for(cont;cont<test_cases;cont++){
		scanf("%i",&size);
		for(cont2=0;cont2<size;cont2++){
			scanf("%i",&array[cont2]);
		}
		
		if(subset_exist(array,size)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
	}
}
