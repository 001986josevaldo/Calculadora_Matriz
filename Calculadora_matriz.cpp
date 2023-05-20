#define linhas 2
#define colunas 2

#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, " ");

    int matriz1[linhas][colunas];
    int matriz2[linhas][colunas];
    int matrizMult[linhas][colunas];
    int matrizSoma[linhas][colunas];
    int matrizSub[linhas][colunas];
    int matrizTrans[linhas][colunas];

    int sel;
    int varloop = 1;

    // Preenchimento das matrizes

    printf("\n\nMATRIZ DE INTEIROS:  TAMANHO: %d x %d", linhas, colunas);

    printf("\nPeenchendo a Matriz 1: \n");
    for (int i = 0; i <linhas; i++){
        for(int j = 0; j < colunas; j ++){
            printf("Digite o número [%d, %d]: ", i+1, j+1);
            scanf("%d%*c", &matriz1[i][j]);
        }
    }
    printf("\nPreenchendo a Matriz 2: \n");
    for (int i = 0; i < linhas; i ++){
        for (int j = 0; j < colunas; j ++){
            printf("Digite o número [%d, %d]: ", i+1, j+1);
            scanf("%d%*c", &matriz2[i][j]);
        }
    }
    printf("\nA Matriz (1) é: \n");
    for (int i = 0; i < linhas; i ++){
        printf("| ");
        for (int j = 0; j< colunas; j ++){
            printf("%d |", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\nA Matriz (2) é: \n");
    for (int i = 0; i < linhas; i ++){
        printf("| ");
        for (int j = 0; j < colunas; j ++){
            printf("%d |", matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n\nPresione ENTER para entrar no while-loop.\n");
    getchar();


    while (varloop == 1){ // loop da calculadora

        int matrizAux = 0; // aux da multipliccação

        printf("\n >>>>>>>>>>>>>>>>>>>>CALCULADORA<<<<<<<<<<<<<<<<<<<<");
        printf("\nMenu de Operações:");
        printf("\n1 - Soma\n2 - subtração\n3 - multiplicação\n4 - transposta\n5 - sair\n\n");
        printf("Selecione a operação pelo número correspondente no menu: ");
        scanf("%d%*c",&sel);

        switch (sel){

            case 1:
                for (int i = 0; i < linhas; i ++){// controle das linhas 
                    for (int j = 0; j < colunas; j++){// controle das coluns
                        matrizSoma[i][j] = matriz1[i][j] + matriz2[i][j]; // operação..
                    }
                }
                printf("\nA Matriz Soma é: \n");
                for(int i = 0; i < linhas; i++){
                    printf("| ");
                    for (int j = 0; j < colunas; j ++){
                        printf("%d | ",matrizSoma[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 2:
                for(int i = 0; i < linhas; i ++){
                    for (int j = 0; j < colunas; j ++){
                        matrizSub[i][j] = matriz1[i][j] - matriz2[i][j]; 
                    }
                }
                printf("\nA Matriz subtração é: \n");
                for (int i = 0; i < linhas; i ++){
                    printf("| ");
                    for (int j = 0; j < colunas; j ++){
                        printf("%d | ",matrizSub[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3: //--------------------- MULTIPLICAÇÃO ----------------------
                    /*O terceiro for representa a composição do termo que é a  soma
                    das multiplicações de cada linha*coluna, o que depende dos numeros de
                    colunas da matriz1 e linhas da matriz2
                    */
                for (int i = 0; i < linhas; i ++){
                    for (int j = 0; j < colunas; j ++){
                        for (int k = 0; k < colunas; k ++){
                            matrizAux = matrizAux + (matriz1[i][k] * matriz2[k][j]);
                        }
                        matrizMult[i][j] = matrizAux;
                        matrizAux = 0;
                    }
                }
                printf("\nA Matriz Multiplicação é: \n");
                for (int i = 0; i < linhas; i ++){
                    printf("| ");
                    for (int j = 0; j < colunas; j ++){
                        printf("%d | ",matrizMult[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 4: // ------------------------TRANSPOSTA ------------------------
                for(int i = 0; i < linhas; i ++){
                    for( int j = 0; j < colunas; j ++ ){
                        matrizTrans[i][j] = matriz1[j][i];
                    }
                }
                printf("\nA Matriz TRANSPOSTA é: \n");
                for( int i = 0; i < linhas; i ++){
                    printf("| ");
                    for(int j = 0; j < colunas; j ++){
                        printf("%d |", matrizTrans[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 5: // ----------------------------- SAIR -----------------------
                varloop = 0;
                printf("\nA Calculadora será encerrada. \n");
                printf("\nFim do SWITCH pressione ENTER para sair. \n");
                break;
            default:       
                printf("\nNenhuma Operação foi Realizada. \n");


        }
        if(sel < 5){
            printf("\nFim do SWITCH pressione ENTER para retornar no loop.");
            getchar();
        }

    }
    printf("\nFim do WHILE pressione ENTER para sair. \n");
    getchar();
    return 0;
}
