# include <iostream>
# include <conio.h>
#include <windows.h>

using namespace std;


 int soma_01();
 int soma_02();
 int num1, num2, num3,num4, soma, maior, menor;
 
 int maiorNumero() {
	    if (num1 >= num2 && num1 >= num3) {
	        maior = num1;
	    } else if (num2 >= num1 && num2 >= num3) {
	        maior = num2;
	    } else {
	        maior = num3;
	    }
	    cout << "Maior:" << maior << "\n";
	     return 0;
 	}
 
 int menorNumero() {
     
     	if (num1 <= num2 && num1 <= num3) {
	        menor = num1;
	    } else if (num2 <= num1 && num2 <= num3) {
	        menor = num2;
	    } else {
	        menor = num3;
	    }
     cout << "Menor: " << menor << "\n";
    return 0;
}

int somatoria(){
	soma = num1 + num2 + num3;
	cout << "\nSoma: " << soma << "\n";
}
 
 int main(){
       DWORD dwThreadld;
           
       cout << "\n Digite os Quatro Numeros:\n";
       cin >> num1 >> num2 >> num3;
       if (CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)&maiorNumero,NULL,0,&dwThreadld)==NULL)
          {
             cout << "Erro na Criação da THREAD=";
             return (1);
          }
        if (CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)&menorNumero,NULL,0,&dwThreadld)==NULL){
             cout << "Erro na Criação da THREAD=";
             return (1);
        }
        if(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)&somatoria,NULL,0,&dwThreadld)==NULL){
        	cout << "Erro na Criação da THREAD=";
		}
          
       Sleep (1000);      
		cout << "Fim do programa!";
       
       return 0;
       
 }
