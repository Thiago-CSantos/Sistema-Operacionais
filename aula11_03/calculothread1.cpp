/* Programa que vai solicitar para digitar 4 números.
   Mostre a multiplicação =(num1+num2)*(num3+num4).
   Faça uma thread para calcular num1 + num2 e outra para calcular num3 + num4*/

# include <iostream>
# include <conio.h>
#include <windows.h>

using namespace std;


 int soma_01();
 int soma_02();
 int num1, num2, num3, num4, soma1, soma2;
 
 int soma_01()
 {
     soma1 = num1 + num2;
     return 0;
 }
 
 int soma_02()
 {
     soma2 = num3 + num4;
     return 0;
 }
 
 int main(){
       int multi;
       DWORD dwThreadld;
           
       cout << "\n Digite os Quatro Numeros:\n";
       cin >> num1 >> num2 >> num3 >> num4;
       if (CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)&soma_01,(LPVOID)&multi,3,&dwThreadld)==NULL)
          {
             cout <<"Erro na Criação da THREAD=" <<multi;
             return (1);
          }
          else if (CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)&soma_02,(LPVOID)&multi,3,&dwThreadld)==NULL)
          {
             cout <<"Erro na Criação da THREAD=" <<multi;
             return (1);
          }
       Sleep (1000);      
       multi = soma1*soma2;
       
       cout << "\n\n\nMultiplicacao =  " << multi << "\n\n";
       
       system ("pause");
       
       return 0;
       
 }
 
 
