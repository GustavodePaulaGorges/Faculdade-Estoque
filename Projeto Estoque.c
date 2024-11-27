#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define TAM 2

int pos[TAM] = {-1, -1};
int qtdList[TAM];
char nmList[TAM][256];

void title() {
	// infelizmente para a arte ficar correta, as \ tem que ser duplicadas para não serem lidas como escape
	printf(" ________  _________  ________  ________  ___  __                            \n");
    printf("|\\   ____\\|\\___   ___\\\\   __  \\|\\   ____\\|\\  \\|\\  \\              \n");
    printf("\\ \\  \\___|\\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\___|\\ \\  \\/  /|         \n");
    printf(" \\ \\_____  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\  \\    \\ \\   ___  \\      \n");
    printf("  \\|____|\\  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\  \\____\\ \\  \\\\ \\  \\  \n");
    printf("    ____\\_\\  \\   \\ \\__\\ \\ \\_______\\ \\_______\\ \\__\\\\ \\__\\     \n");
    printf("   |\\_________\\   \\|__|  \\|_______|\\|_______|\\|__| \\|__|              \n");
    printf("   \\|_________|                                                             \n");
    printf("                                                                             \n");
    printf(" ________  ___       ___  ___  ________                                      \n");
    printf("|\\   __  \\|\\  \\     |\\  \\|\\  \\|\\   ____\\                           \n");
    printf("\\ \\  \\|\\  \\ \\  \\    \\ \\  \\\\\\  \\ \\  \\___|_                     \n");
    printf(" \\ \\   ____\\ \\  \\    \\ \\  \\\\\\  \\ \\_____  \\                      \n");
    printf("  \\ \\  \\___|\\ \\  \\____\\ \\  \\\\\\  \\|____|\\  \\                    \n");
    printf("    \\ \\__\\    \\ \\_______\\ \\_______\\____\\_\\  \\                     \n");
    printf("     \\|__|     \\|_______|\\|_______|\\_________\\                          \n");
    printf("                                  \\|_________|                              \n");
    printf("                                                                             \n");
    printf("by Gustavo de Paula Gorges & Davi Gabriel Tomaz                              \n");
    printf("                                                                             \n");
    
    sleep(2);
}

// Preciso descobrir como fazer com que eu não precise definir todo o array de posições na mão com -1, pois tá feio. 
// seria melhor só definir ele com 10 posições e checr a primeira que está vazia, mas como? 
// aparentemente NULL = 0 que trava o sistema salvando na primeira posição.
int addItem(void) {
	system("cls"); 	
	
	char nmItem[256];
	int qtdItem;
	char opt;
	
	for (int i; i <= TAM; i++) {
		if (pos[i] == -1) {
			printf("Informe o nome do item: \n");
			fgets(nmItem, sizeof(nmItem), stdin);
			fflush(stdin);
			
			printf("Informe a quantidade: \n");
			scanf("%i", &qtdItem);
			fflush(stdin);
			
			pos[i] = i;
			snprintf(nmList[i], sizeof(nmList[i]), nmItem);
			qtdList[i] = qtdItem;
			
			printf("contador = %i \n", i);
			printf("posicao = %i \n", pos[i]);
			printf("nome = %s \n", nmList[i]);
			sleep(2);
			
			return 0;
		}
	}
	
	printf("Infelizmente o estoque esta cheio...");
	sleep(3);
	return 0;
}



void menu() {
	system("cls"); 	
	char menuOption;
	
	printf("|---------------------------------------------------------------| \n \n");
	printf("Bem vindo ao Stock Plus ** \n");
	printf("O que deseja fazer? \n \n");
	printf("1) %c Adicionar um produto ao estoque \n", 26);
	printf("2) %c Remover um produto do estoque \n", 26);
	printf("3) %c Consultar a quantidade de um produto no estoque \n", 26);
	printf("4) %c Exibir todos os produtos e suas quantidades no estoque. \n", 26);
	printf("q) %c Sair do Sistema \n", 26);
	scanf("%c", &menuOption);
	fflush(stdin);
	menuOption = tolower(menuOption);
	
	switch (menuOption) {
		case '1' : {
			addItem();
			menu();
			break;
		}
		case '2' : {
			break;
		}
		case '3' : {
			break;
		}
		case '4' : {
			break;
		}
		case 'q' : {
			break;
		}
		default : {
			system("cls");
			menu();
			break;
		}
	}
}

int main (void) {
	
	title();
	menu();
	
	return 0;
}

//std::string greeting = "OLA";
//printf("%s\n", greeting.c_str());
	