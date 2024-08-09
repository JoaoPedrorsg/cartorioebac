#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> //bibliotece de aloca��o de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar das string

int registro() //fun��o responsalvel por cadastrar os usu�rios no sistema
{
		//inicio cria��o de vatiaiveis/string
		printf("Voc� escolheu o registro de nomes\n");
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// final da cria��o das variaiveis/string
		
		printf("Digiteo CPF a ser cadastrado:"); //coletando informa��o do usu�rio
		scanf("%s", cpf); //%s referese-se a string
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
		
		FILE *file; //criar o arquivo
		file = fopen(arquivo, "w"); //criar o arquivo, "w" significa escrever
		fprintf(file,cpf); //salvo o valor da variavel
		fclose(file); //fechar o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrodo:"); // coletando informa��o do usu�rio.
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
	
	printf("Voc� escolheu consultar os nomes!\n");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o cadastrado. Por favor, verifique se est� correto.\n");	
	} 
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do us�ario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sitema!\n");
		system("pause");
	}
	
	system("pause");	
}





int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
		system("cls"); //responsavel por limpar a tela.
		
		setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
		
		
		
		printf("###Cart�rio da EBAC###\n\n"); //Inicio do menu
		printf("Escolha a op��o deseja do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Pesquisar nome\n");
		printf("\t3 - Deletar nome\n\n");
		printf("Op��o:"); //FIm do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do us�ario
		
		system("cls");
		
		switch(opcao) //inicio da sele��o de menu.
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
			printf("essa op��o n�o esta disponivel!\n Obrigado, tente de novo!\n");
			system("pause");
			break;		
				
		}
	
	}
}

