#include<stdio.h>
#include <string.h>
/*fscanf examble*/

int main(){
	FILE *pFile;
	char nome[50], nome2[50];
	char *aux_nome, *aux_nome2, *temp;
	
	
	pFile=fopen("nomeArquivo.txt", "w");
	
	if(pFile!=NULL){
		fprintf(pFile, "Registros\n");
		
		printf("Escreva um nome: ");
		scanf("%s", nome);
		
		printf("Escreva um nome: ");
		scanf("%s", nome2);
		
		int x = strlen(nome);
		int y = strlen(nome2);
		
		fprintf(pFile,"Registro 1, numero de caracteres: %d\n",x);
		fprintf(pFile,"Registro 2, numero de caracteres: %d\n",y);
		
		// Trocando em memoria
		fprintf(pFile, "\nTrocando em memoria\n");
		
		aux_nome = nome;
        aux_nome2 = nome2;
        
        temp = aux_nome;
        aux_nome = aux_nome2;
        aux_nome2 = temp;
        
        int z = strlen(aux_nome);
		int w = strlen(aux_nome2);
		
		fprintf(pFile, "\nRegistro 1: %d\n", z);
		fprintf(pFile, "\nRegistro 2: %d\n", w);
		
	}
	
	printf("teste\n");
	fclose(pFile);
//	pFile=fopen("nomeArquivo.txt", "r");
	
//	if(pFile != NULL){
//		fscanf(pFile, "Nota 1: %d", &nota1);
//        fscanf(pFile, "Nota 2: %d", &nota2);
//		media = (nota1+nota2)/2;
//		printf("Media: %f ", media);
		
//	}
	
//	fclose(pFile);
	return 0;
}
