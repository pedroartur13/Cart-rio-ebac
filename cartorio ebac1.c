#include <stdio.h> //biblioteca de comunicação com o usuário

#include <stdlib.h> //biblioteca de alocação de espaço em memória

#include <locale.h> //biblioteca de texto

#include <string.h> // biblioteca de strings


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copia os valores da string
	
	FILE *file; // cria arquivo
	file = fopen(arquivo, "w");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");//biblioteca de texto
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser contultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n Arquivo não encontrado\n\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf ("\n Essas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
}

int excluir()
{	char cpf[40];
	 
	printf("Digite o cpf a ser excluido:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o cpf não se encontra mais no sistema! . \n");
		system ("pause");
	}
	
	
}

 int main()
 {
 	int opcao=0;
 	int x=1;
 	
 	for(x=1;x=1;)
 	{
	 
	 	system("cls");
	 	
		setlocale(LC_ALL, "portuguese");//biblioteca de texto
	 	
	 	printf("	Cartório da EBAC\n\n");
	 	printf("Escolha a opção desejada no menu:\n\n");
	 	printf("\t 1 - Registrar usuários\n");
	 	printf("\t 2 - Consultar usuários\n");
	 	printf("\t 3 - Excluir usuários\n");
	 	printf("Opção: ");
	 	
		scanf("%d", &opcao);
		
		system("cls");
			
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			excluir();
			break;
			
			
			default:
			printf("\t Opção indisponivel\n\n");
			system("pause");
			break;	
		}
	}
	
}

 

 
