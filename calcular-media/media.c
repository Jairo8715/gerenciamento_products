#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
void soma();
void multiplicacao();
void divisao();
void subtracao();
int main(){
    setlocale(LC_ALL,"Portuguese");
    int resp;
    
    do{
         printf(":::Calculadora:::\n");
         printf("Escolha uma das operações: \n1-SOMA\n2-MULTIPLICAÇÃO\n3-DIVISÃO\n4-SUBTRAÇÃO\n5-SAIR>>");
         scanf("%d",&resp);
        switch (resp){
            case 1:
             printf(">>1-SOMA<<\n");
             soma();
             break;
             case 2:
                 printf(">>2-MULTIPLICAÇÃO<<\n");
                 multiplicacao();
             break;
             case 3:
                 printf(">>3-DIVISÃO<<");
                  divisao();
                break;
              case 4:
                printf("4-SUBTRAÇÃO\n");
                subtracao();
            break;
            case 5:
                 printf("Saindo...\n");
             break;
                default:
                 printf("Escolha uma opção válida!");
        }
    }while(resp!=5);

    return 0;
}
void soma(){
    int n1,n2,result;
    printf("Informe um número: ");
    scanf("%d",&n1);
    printf("Informe outro número:");
    scanf("%d",&n2);
    result=n1+n2;
    printf("A soma entre %d e %d é %d\n",n1,n2,result);
}
void multiplicacao(){
    int n1,n2,result;
    printf("Informe um número: ");
    scanf("%d",&n1);
    printf("Informe outro número:");
    scanf("%d",&n2);
    result=n1*n2;
    printf("A multiplicação entre %d e %d é %d\n",n1,n2,result);
}
void divisao(){
    int n1,n2,result;
    printf("Informe um número: ");
    scanf("%d",&n1);
    printf("Informe outro número:");
    scanf("%d",&n2);
    if (n2 == 0) {
        printf("Erro: Divisão por zero não é permitida!\n");
    } else {
        result = (float)n1 / n2; // Conversão explícita para float
        printf("A divisão entre %d e %d é %.2f\n", n1, n2, result);
    }
}
void subtracao(){
    int n1,n2,result;
    printf("Informe um número: ");
    scanf("%d",&n1);
    printf("Informe outro número:");
    scanf("%d",&n2);
    result=n1-n2;
    printf("A subtração entre %d e %d é %d\n",n1,n2,result);
}