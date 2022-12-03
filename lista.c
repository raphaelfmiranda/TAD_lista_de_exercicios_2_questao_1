#include "lista.h"
#include <string.h>
#include <stdio.h>


void lista_inicializar(struct lista_cfg *lista) //inicializa comprimento da lista como 0(zero)
{	
	lista -> cur_len_data = 0;	
}
bool lista_esta_cheia(struct lista_cfg *lista) //retorna verdadeiro se a lista estiver cheia, caso contrário retornar falso
{	
	if(lista -> cur_len_data == MAX)
		return true;	
	return false;
}
bool lista_esta_vazia(struct lista_cfg *lista) //retorna verdadeiro se a lista estiver vazia, caso contrário retornar falso
{
	int len_lista = lista -> cur_len_data;
	
	if(len_lista == 0)
		return true;
	
	return false;	
}
int lista_insere_elemento(struct lista_cfg *lista , int elem_to_add) //insere elemento na lista, retornar 1 se conseguiu inserir elemento, caso contrário retorna 0
{
	if(lista_esta_cheia(lista))
		return 0;
		
	lista -> data[lista -> cur_len_data] = elem_to_add;
	lista -> cur_len_data += 1;
	
	return 1;
}
int lista_remover_elemento(struct lista_cfg *lista , int elem_to_remove) //remove elemento na lista, retornar 1 se conseguiu remover, caso contrário retorna 0
{
	if(lista_esta_vazia(lista))
		return 0;
	
	
	int i;
	int qtd_elem_to_move;
	for(i = 0 ; i < lista -> cur_len_data ; i++){

		if (lista -> data[i] == elem_to_remove){
		
			qtd_elem_to_move = sizeof(int) * (lista -> cur_len_data - i - 1);
			memmove(lista -> data + i , lista -> data + i + 1 , qtd_elem_to_move); //mover elementos que estão na FRENTE do elemento que vai ser REMOVIDO, "1 casa" para trás
			lista -> cur_len_data -= 1;
            break;
		}
	}
	
	
	return 1;
}
int lista_tamanho(struct lista_cfg *lista) //retornar a quantidade de elementos presentes da lista
{
	return lista -> cur_len_data;
}
int lista_encontrar_maior_elemento(struct  lista_cfg *lista , int *maior_valor_na_lista) //armazena através do ponteiro(int *maior_valor_na_lista) o maior elemento da lista, se a lista estiver vazia retorna 0, caso contrário retorna 1
{
	
	if(lista_esta_vazia(lista)){
		return 0;
	}

	int i;
	*maior_valor_na_lista = lista -> data[0]; //maior elemento inicial sempre vai ser o primeiro presente na lista
	for(i = 1 ; i < lista -> cur_len_data ; i++){

		if(lista -> data[i] > *maior_valor_na_lista)
			*maior_valor_na_lista = lista -> data[i];
			
	}


	return 1;
}
int lista_remover_elemento_por_indice(struct lista_cfg *lista , int posicao) //remove o elemento específicado presente na posição especifica, retornar 0 se a posição estiver fora dos limites da lista, caso contrário retorna 1
{
	int indice = posicao - 1; //índice do elemento para ser removido

	if(indice < 0 || indice >= lista -> cur_len_data) //verifica se o usuário digitou uma posição válida para remover o elemento
		return 0;

	int qtd_elem_to_move = sizeof(int) * (lista -> cur_len_data - indice - 1);
	memmove(lista -> data + indice , lista -> data + indice + 1 , qtd_elem_to_move);
	lista -> cur_len_data -= 1;


	return 1;
}
void lista_print(struct lista_cfg lista) //imprime lista no terminal
{
	int i;
//	printf("# Lista: ");
	for(i = 0 ; i < lista.cur_len_data ; i++)
	{
		printf("# Lista[%d]: %d\n" , i , lista.data[i]);
	}	
}