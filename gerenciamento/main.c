#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100

typedef struct{
    char nome[MAX];
    int qtdProduct;
    float preco;
}product;
///funcoes
void cadastrarProduto(const char *produtosMerc);
void listarProduto(const char *produtosMerc);
void buscarProduto(const char *produtosMerc);

int main(){
    setlocale(LC_ALL,"Portuguese");
    int flag;
    const char *produtosMerc = "produtos.csv";
    
    do{ 
        printf("\n::::Bem vindo::::\nEscolha uma opção\n1-Cadastrar Produto\n2-Listar Produtos\n3-Buscar Produto\n4-Sair\n >>");
        scanf("%d",&flag); 
        getchar();
        switch(flag){
            case 1:
                printf(">>Cadastrar Produto<<\n");
                cadastrarProduto(produtosMerc);
            break;
            case 2:
                printf(">>Listar Produtos<<\n");
                listarProduto(produtosMerc);
            break;
            case 3:
                printf(">>Buscar Produto<<");
                buscarProduto(produtosMerc);
            break;
            case 4:
                printf("Saindo...");
            break;
            default:
                printf("Opção inválida");
        }

    }while (flag!=4);
    
     
    

    return 0;
    }
    void cadastrarProduto( const char *produtosMerc){
        FILE *arquivo = fopen(produtosMerc, "a");
        if(arquivo==NULL){
            printf("Erro ao abrir o arquivo");
            return;
        }
        product p;
        printf("Informe o nome do produto: ");
        fgets(p.nome,MAX,stdin);
        setbuf(stdin,NULL);
        printf("Informe a quantidade: ");
        scanf("%d",&p.qtdProduct);
        printf("Qual o preço? ");
        scanf("%f",&p.preco);
        fprintf(arquivo, "%s,%d,%.2f\n", p.nome, p.qtdProduct, p.preco); // Salva no arquivo em formato CSV
        fclose(arquivo);
        printf("Produto Cadastrado com sucesso!!");
    }
    void listarProduto(const char *produtosMerc){
        FILE *arquivo = fopen(produtosMerc, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }
    char linha[MAX];
    printf("Produtos cadastrados:\n");
    printf("Nome\t\tQuantidade\tPreço\n");
    printf("-----------------------------------------\n");
    while (fgets(linha, MAX, arquivo) != NULL) {
        product p;
        sscanf(linha, "%[^,],%d,%f", p.nome, &p.qtdProduct, &p.preco); // Lê dados do CSV
        printf("%-15s\t%-10d\tR$ %.2f\n", p.nome, p.qtdProduct, p.preco);
    }
    fclose(arquivo);
    }
    void buscarProduto(const char *produtosMerc) {
         FILE *arquivo = fopen(produtosMerc, "r");
         if (arquivo == NULL) {
         printf("Erro ao abrir o arquivo");
        return;
    }
    char nomeBusca[MAX], linha[MAX];
    printf("Informe o nome do produto a ser buscado: ");
    fgets(nomeBusca, MAX, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // Remove o '\n' do nome buscado
    int encontrado = 0;

    while (fgets(linha, MAX, arquivo) != NULL) {
        product p;
        sscanf(linha, "%[^,],%d,%f", p.nome, &p.qtdProduct, &p.preco); // Lê dados do CSV
        if (strcmp(p.nome, nomeBusca) == 0) { // Compara os nomes
            printf("Produto encontrado:\n");
            printf("Nome: %s\nQuantidade: %d\nPreço: R$ %.2f\n", p.nome, p.qtdProduct, p.preco);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado!\n");
    }

    fclose(arquivo);
}