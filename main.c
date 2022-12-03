#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[])
{
    struct lista_cfg lista;


    int choice;
    int n;
    int maior_valor_na_lista;
    int pos;

    
    while (1)
    {
        printf( "                               \n"
        "           ***************	     		\n"
        "           *   M E N U   *				\n"
        "           ***************				\n"
        "										\n"
        "1.  Inicializar a lista				\n"
        "2.  Verificar se lista eh vazia		\n"
        "3.  Verificar se lista eh cheia. 		\n"
        "4.  Inserir elemento. 					\n"
        "5.  Remover elemento. 					\n"
        "6.  Mostrar tamanho da lista. 			\n"
        "7.  Mostrar maior valor na lista. 		\n"
        "8.  Remover elemento na posicao P.		\n"
        "9.  Imprimir a lista. 					\n"
        "10. Sair 								\n"
        ">>> Digite a opcao desejada: ")        ;   scanf("%d", &choice);



        switch (choice){

            case 1:

                lista_inicializar(&lista);
                printf("\n Lista inicializada!\n");
                break;

            case 2:

                if (lista_esta_vazia(&lista))
                    printf("\n A lista eh vazia!\n");
                else
                    printf("\n A lista nao eh vazia.\n");
                break;

            case 3:

                if (lista_esta_cheia(&lista))
                    printf("\n A lista eh cheia!\n");
                else
                    printf("\n A lista nao eh cheia.\n");
                break;

            case 4:

                printf("\n Digite o numero que voce deseja inserir na lista: ");
                scanf("%d", &n);

                if (lista_insere_elemento(&lista, n))
                    printf("\n Elemento inserido com sucesso!\n");
                else
                    printf("\n Nao foi possivel inserir o elemento.\n");
                break;

            case 5:

                printf("\n Digite o numero que voce deseja remover da lista: "),
                scanf("%d", &n);

                if (lista_remover_elemento(&lista, n))
                    printf("\n Elemento removido com sucesso!\n");
                else
                    printf("\n Nao foi possivel remover o elemento.\n");
                break;


            case 6:

                printf("\nTamanho da lista: %d\n" , lista_tamanho(&lista));
                break;

            case 7:

                if(lista_encontrar_maior_elemento(&lista , &maior_valor_na_lista))
                    printf("\nMaior elemento na lista: %d\n" , maior_valor_na_lista);
                else
                    printf("\nN existe maior elemento na lista, ela esta vazia\n");
                
                break;

            case 8:


                printf("\nDigite a posicao para remover o elemento: ");
                scanf("%d" , &pos);

                if(lista_remover_elemento_por_indice(&lista, pos))
                    printf("\n Elemento removido com sucesso!\n");
                else
                    printf("\n Nao foi possivel remover o elemento.\n");


                break;
                
            case 9:

                lista_print(lista);
                break;

            case 10:
                printf("\n \t TCHAU! \n \n ");
                exit(0);
                break;

            default:
                printf("\n Opcao inexistente\n");
        }
    }
}