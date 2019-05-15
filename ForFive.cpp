#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct endereco {
	char logradouro[80];
	char bairro[15];
	char CEP[10];
	char cidade[15];
	char estado[3];
	char fone[12];
	char email[40];
} endereco;

typedef struct infocarro {
	char sigla;
	int regcarro;
} infocarro;

typedef union dadoscarro {
	char sigla;
	struct infocarro reservado;
} dadoscarro;

typedef struct loja {
	int regloja; //gerar automático
	char nome[30];
	char CNPJ[19];
	struct endereco end;
	int sold;
	int reserved;
	union dadoscarro tabela[3];
} loja;


void aloca_loja(loja **ploja, int tam){
	if((*ploja = (loja*)realloc(*ploja, tam * sizeof(loja)))== NULL){
		exit(1);
	}
}
void aloca_endereco(endereco **pendereco, int tam){
	if((*pendereco = (endereco*)realloc(*pendereco, tam * sizeof(endereco)))== NULL){
		exit(1);
	}
}

/*void aloca_infocarro(infocarro **pinfocarros, int tam){
	if((*pinfocarros = (infocarro*)realloc(*pinfocarros, tam*tamsizeof(infocarro)))== NULL){
		exit(1);
	}
}


void aloca_infocarro(dadoscarro **pdadoscarro, int tam){
	if((*pdadoscarro = (dadoscarro*)realloc(*pdadoscarro, tam * sizeof(dadoscarro)))== NULL){
		exit(1);
}
*/

void cadastro_loja(loja *p_loja, endereco *p_endereco){
	
	int static cont = 1000;
	 
	int tam, i;
	char nome[30], cnpj[19], endereco[100];
	
	printf("Digite o nome da loja que vc deseja Cadastrar\n");
	gets(nome);
	fflush(stdin);
	
	printf("Digite o CNPJ da Empresa (19 caracteres)\n");
	gets(cnpj);
	fflush(stdin);

	printf("Digite o endereço\n");
	gets(endereco);
	fflush(stdin);
	
	tam = strlen(endereco);
	aloca_endereco(&p_endereco, tam);
	printf("Alocou");
	
}

int main(){
	loja *p_loja = NULL;
	endereco *p_endereco = NULL;
	
	int i, op;

	printf("Bem Vindo\n");
	
	printf("Escolha uma das Opcoes Abaixo\n\n");
	
	do{
		printf("[1] - Cadastro de Concessionárias \n[2] - Consulta da Situação\n[3] - Cadastro de Carros\n[4] - Consulta de Carros\n[5] - Sair\n\n");
		scanf("%i", &op);
		fflush(stdin);
		switch(op){
			case 1: { //Case 1 Cadastro Loja
				cadastro_loja(p_loja, p_endereco);
				
				break;
			}	
			
			case 2: {
				
				break;
			}
			
			case 3:{
				
				break;
			}
			
			case 4:{
				
				break;
			}
			
			case 5:{
				printf("Saindo...");
				break;
			}
		}
	}while(op != 5);
}
