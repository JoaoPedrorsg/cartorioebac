#include <stdio.h>   // biblioteca de comunica��o com usu�rio
#include <stdlib.h>  // biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h>  // biblioteca de aloca��o de texto por regi�o
#include <string.h>  // biblioteca respons�vel por cuidar das strings


int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
    // in�cio cria��o de vari�veis/string
    printf("Voc� escolheu o registro de nomes\n");
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da cria��o das vari�veis/string

    printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings

    FILE *file; // criar o arquivo
    file = fopen(arquivo, "w"); // criar o arquivo, "w" significa escrever
    fprintf(file, cpf); // salvo o valor da vari�vel
    fclose(file); // fechar o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: "); // coletando informa��o do usu�rio.
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome); // Adiciona %s para formatar a string corretamente
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome); // Adiciona %s para formatar a string corretamente
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo); // Adiciona %s para formatar a string corretamente
    fclose(file);

    system("pause");

    // Sub-menu da tela registrar
    int opcao; // Declara��o da vari�vel opcao
    do {
        system("cls");
        printf("Deseja fazer um novo registro?\n\n");
        printf("1 - Fazer novo registro\n");
        printf("2 - Voltar ao menu principal\n\n");
        printf("Digite a op��o desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registro(); // Corrigi para chamar a fun��o `registro`
                break;
            case 2:
                return 0;
            default:
                printf("Esta op��o n�o est� dispon�vel!\n\n");
                system("pause");
                break;
        }
    } while (opcao != 2); // Finaliza o loop se a op��o for 2

    return 0;
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    printf("Voc� escolheu consultar os nomes!\n");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r"); 

    if (file == NULL)
    {
        printf("CPF n�o cadastrado. Por favor, verifique se est� correto.\n");
        system("pause");
        return 0; // Adiciona retorno para sair da fun��o em caso de erro
    }

    while (fgets(conteudo, sizeof(conteudo), file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio:\n");
        printf("%s", conteudo);
        printf("\n\n");
    }
    fclose(file); // Lembre-se de fechar o arquivo ap�s a leitura
    system("pause");
}

int deletar()
{
    printf("Voc� escolheu deletar um usu�rio!\n");
    char cpf[40];
    char confirmacao;

    // Solicita o CPF do usu�rio
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%39s", cpf); // Limita o input a 39 caracteres + null terminator

    // Solicita confirma��o
    printf("Voc� realmente deseja deletar o usu�rio com CPF %s? (s/n): ", cpf);
    scanf(" %c", &confirmacao); // O espa�o antes de %c � para ignorar qualquer caractere de nova linha

    if (confirmacao == 's' || confirmacao == 'S') {
        // Cria o nome do arquivo baseado no CPF
        char nome_arquivo[50];
        snprintf(nome_arquivo, sizeof(nome_arquivo), "%s.txt", cpf);

        // Tenta remover o arquivo
        if (remove(nome_arquivo) == 0) {
            printf("Usu�rio deletado com sucesso.\n");
        }
        else {
            printf("O usu�rio n�o se encontra no sistema ou ocorreu um erro ao tentar deletar o arquivo.\n");
        }
    } else {
        printf("Opera��o de dele��o cancelada.\n");
    }

    system("pause"); // Pausa o console para que o usu�rio veja a mensagem
    return 0;
}
int main()
{
    int opcao = 0; // Definindo vari�veis
    int laco = 1;
    char senhadigitada[]="a";
    int comparacao;
    
     printf("### Cart�rio da EBAC ###\n\n");
     printf("Login de adminstrador!\n\nDigite a sua senha:");
     scanf("%s", senhadigitada);
     
     comparacao = strcmp(senhadigitada, "admin");
                
     if(comparacao == 0)
     {
	 
	    while (laco == 1) // Corrigi a condi��o do loop
	    {
	        system("cls"); // respons�vel por limpar a tela.
	
	        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	        printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
	        printf("Escolha a op��o desejada do menu:\n\n");
	        printf("\t1 - Registrar nome\n");
	        printf("\t2 - Pesquisar nome\n");
	        printf("\t3 - Deletar nome\n\n");
	        printf("\t4 - Sair do programa\n\n");
	        printf("Op��o: "); // Fim do menu
	
	        scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	        system("cls");
	
	        switch (opcao) // In�cio da sele��o de menu.
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
	
	            case 4:
	                printf("Obrigado por utilizar o sistema!\n");
	                return 0;
	
	            default:
	                printf("Essa op��o n�o est� dispon�vel!\n Obrigado, tente de novo!\n");
	                system("pause");
	                break;
	        }
	    }
	}
	
	else
	printf("Senha incorreta!");
}
