#include <stdio.h>   // biblioteca de comunicação com usuário
#include <stdlib.h>  // biblioteca de alocação de espaços em memória
#include <locale.h>  // biblioteca de alocação de texto por região
#include <string.h>  // biblioteca responsável por cuidar das strings

int registrar(); // Prototipando a função registrar

int registro() // função responsável por cadastrar os usuários no sistema
{
    // início criação de variáveis/string
    printf("Você escolheu o registro de nomes\n");
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criação das variáveis/string

    printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings

    FILE *file; // criar o arquivo
    file = fopen(arquivo, "w"); // criar o arquivo, "w" significa escrever
    fprintf(file, cpf); // salvo o valor da variável
    fclose(file); // fechar o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: "); // coletando informação do usuário.
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
    int opcao; // Declaração da variável opcao
    do {
        system("cls");
        printf("Deseja fazer um novo registro?\n\n");
        printf("1 - Fazer novo registro\n");
        printf("2 - Voltar ao menu principal\n\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registro(); // Corrigi para chamar a função `registro`
                break;
            case 2:
                return 0;
            default:
                printf("Esta opção não está disponível!\n\n");
                system("pause");
                break;
        }
    } while (opcao != 2); // Finaliza o loop se a opção for 2

    return 0;
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    printf("Você escolheu consultar os nomes!\n");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("CPF não cadastrado. Por favor, verifique se está correto.\n");
        system("pause");
        return 0; // Adiciona retorno para sair da função em caso de erro
    }

    while (fgets(conteudo, sizeof(conteudo), file) != NULL)
    {
        printf("\nEssas são as informações do usuário:\n");
        printf("%s", conteudo);
        printf("\n\n");
    }
    fclose(file); // Lembre-se de fechar o arquivo após a leitura
    system("pause");
}

int deletar()
{
    printf("Você escolheu deletar nomes!\n");
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) // Verifica se a remoção foi bem-sucedida
    {
        printf("Usuário deletado com sucesso.\n");
    }
    else
    {
        printf("O usuário não se encontra no sistema!\n");
    }

    system("pause");
}

int main()
{
    int opcao = 0; // Definindo variáveis
    int laco = 1;

    while (laco == 1) // Corrigi a condição do loop
    {
        system("cls"); // responsável por limpar a tela.

        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

        printf("### Cartório da EBAC ###\n\n"); // Início do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nome\n");
        printf("\t2 - Pesquisar nome\n");
        printf("\t3 - Deletar nome\n\n");
        printf("\t4 - Sair do programa\n\n");
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando a escolha do usuário

        system("cls");

        switch (opcao) // Início da seleção de menu.
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
                printf("Essa opção não está disponível!\n Obrigado, tente de novo!\n");
                system("pause");
                break;
        }
    }
}
