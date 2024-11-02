#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nascimento.h"

int dias_de_vida(data_t nasc) {    //funçao para calcular a idade :)
    time_t t = time(NULL);         //hora atual
    struct tm *dataAtual = localtime(&t);
    data_t atual;
    atual.dia = dataAtual->tm_mday;
    atual.mes = dataAtual->tm_mon + 1;
    atual.ano = dataAtual->tm_year + 1900;
    int idade = atual.ano - nasc.ano;
    if (atual.mes < nasc.mes || (atual.mes == nasc.mes && atual.dia < nasc.dia)) {  //verifica se ja fez aniversario baseado em mes e dia
        idade--;
    }
    return idade;
}
int main(){
	FILE *arq;
	arq = fopen("dados.txt","a");   //troque o "dados.txt" pelo arquivo aonde deseja armazena as informações
	if(arq == NULL){                // Verificação ;)
    printf("ERRO");
    return 1;
}
	data_t nasc[101];
	int i;
	int idade;
	char dec,dec2;
	for(i=0;i<101;i++){             //coleta de dados
		
	printf("Digite o nome:");
	fgets(nasc[i].nome,50,stdin);
	fprintf(arq,"Nome: %s",nasc[i].nome);
	
	printf("Digite o dia:");
	scanf("%d",&nasc[i].dia);
	fflush(stdin);
	fprintf(arq,"Dia:%d ",nasc[i].dia);
	
	printf("Digite o mes:");
	scanf("%d",&nasc[i].mes);
	fflush(stdin);
	fprintf(arq,"Mes:%d ",nasc[i].mes);
	
	printf("Digite o ano:");
	scanf("%d",&nasc[i].ano);
	fflush(stdin);
	fprintf(arq,"Ano:%d ",nasc[i].ano);	
	
	printf("CADASTRADO\n\n");
	
	 idade = dias_de_vida(nasc[i]);
	 fprintf(arq,"Idade:%d\n\n",idade);
	 
	 printf("Deseja Adicionar mais um cadastro?(S/N)\n"); //ponto de checagem
	 scanf("%c",&dec);
	 fflush(stdin);
	 
	 if(dec == 'n'|| dec== 'N'){
	 	printf("Usuarios Cadastrados!!\n");
	 	break;
}
}
fclose(arq);
printf("Deseja ver os usuarios Cadastrados?(S/N)\n"); //checagem de leitura
scanf("%c",&dec2);
fflush(stdin);

if(dec2 == 's' || dec2 == 'S'){
arq = fopen("dados.txt","r");      //troque o "dados.txt" pelo arquivo aonde deseja armazena as informações
if(arq == NULL){                   // Verificação ;)
    printf("ERRO");
    return 1;
}

char texto[256];
while (fgets(texto,sizeof(texto),arq)){  //leitura do arquivo
printf("%s",texto);
}
fclose(arq);
}
return 0;
}
