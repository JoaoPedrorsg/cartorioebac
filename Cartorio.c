#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaços em memória
#include <locale.h> //bibliotece de alocação de texto por região
#include <string.h> //biblioteca resposável por cuidar das string

int registro() //função responsalvel por cadastrar os usuários no sistema
{
		//inicio criação de vatiaiveis/string
		printf("Você escolheu o registro de nomes\n");
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// final da criação das variaiveis/string
		
		printf("Digiteo CPF a ser cadastrado:"); //coletando informação do usuário
		scanf("%s", cpf); //%s referese-se a string
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
		
		FILE *file; //criar o arquivo
		file = fopen(arquivo, "w"); //criar o arquivo, "w" significa escrever
		fprintf(file,cpf); //salvo o valor da variavel
		fclose(file); //fechar o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrodo:"); // coletando informação do usuário.
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobreno a ser cadastrado:");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
	 	file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado:");
		scanf("%s",cargo);
		
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
	printf("Você escolheu consultar os nomes!\n");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF não cadastrado. Por favor, verifique se está correto.\n");	
	} 
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usúario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sitema!\n");
		system("pause");
	}
	
	system("pause");	
}





int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
		system("cls"); //responsavel por limpar a tela.
		
		setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
		
		
		
		printf("###Cartório da EBAC###\n\n"); //Inicio do menu
		printf("Escolha a opção deseja do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Pesquisar nome\n");
		printf("\t3 - Deletar nome\n\n");
		printf("Opção:"); //FIm do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usúario
		
		system("cls");
		
		switch(opcao) //inicio da seleção de menu.
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("essa opção não esta disponivel!\n Obrigado, tente de novo!\n");
			system("pause");
			break;		
				
		}
	
	}
}

