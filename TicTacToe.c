#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid = 0;

int draw(int ***mat) {
	int aux= 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(mat[0][i][j] == 0) {
				aux++;
			}
		}
	}
	return aux;
}

int winP1(int ***mat, int *p1) {
	int cond = 0;

	while (cond == 0) {
		int aux1 = 0;

		// linhas p1
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mat[0][i][j] == 1)
					aux1++;
			}
			if (aux1 >= 3) {
				(*p1)++;
				break;
			}
			aux1 = 0;
		}
		if (*p1 > 0) {
			cond = 1;
			return 1;
			break;
		}

		// colunas p1
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mat[0][j][i] == 1)
					aux1++;
			}
			if (aux1 >= 3) {
				(*p1)++;
				break;
			}
			aux1 = 0;
		}
		if (*p1 > 0) {
			cond = 1;
			return 1;
			break;
		}

		// diagonal principal
		for (int i = 0; i < 3; i++) {
			if (mat[0][i][i] == 1)
				aux1++;
		}
		if (aux1 >= 3)
			(*p1)++;
		aux1 = 0;

		if (*p1 > 0) {
			cond = 1;
			return 1;
			break;
		}

		// diagonal secundC!ria
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				if (mat[0][i][i] == 1)
					aux1++;
			}
			if (i == 2) {
				if (mat[0][0][i] == 1)
					aux1++;
				if (mat[0][i][0] == 1)
					aux1++;
			}
		}
		if (aux1 >= 3)
			(*p1)++;

		if (*p1 > 0) {
			cond = 1;
			return 1;
			break;
		}

		// fim do loop
		break;
	}

}

int winP2(int ***mat, int *p2) {
	int cond = 0;

	while (cond == 0) {
		int aux1 = 0;

		// linhas p1
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mat[0][i][j] == 2)
					aux1++;
			}
			if (aux1 >= 3) {
				(*p2)++;
				break;
			}
			aux1 = 0;
		}
		if (*p2 > 0) {
			cond = 1;
			return 1;
			break;
		}

		// colunas p1
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mat[0][j][i] == 2)
					aux1++;
			}
			if (aux1 >= 3) {
				(*p2)++;
				break;
			}
			aux1 = 0;
		}
		if (*p2 > 0) {
			cond = 1;
			return 1;
			break;
		}

		// diagonal principal
		for (int i = 0; i < 3; i++) {
			if (mat[0][i][i] == 2)
				aux1++;
		}
		if (aux1 >= 3)
			(*p2)++;
		aux1 = 0;

		if (*p2 > 0) {
			cond = 1;
			return 1;
			break;
		}

		// diagonal secundC!ria
		for (int i = 0; i < 3; i++) {
			if (i == 1) {
				if (mat[0][i][i] == 2)
					aux1++;
			}
			if (i == 2) {
				if (mat[0][0][i] == 2)
					aux1++;
				if (mat[0][i][0] == 2)
					aux1++;
			}
		}
		if (aux1 >= 3)
			(*p2)++;

		if (*p2 > 0) {
			cond = 1;
			return 1;
			break;
		}

		// fim do loop
		break;
	}
}
void show(int ***mat) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			printf("%d ", mat[0][i][j]);
		printf("\n");
	}
}
int main() {
	int **game;
	int p1 = 0, p2 = 0, ind1 = 0, ind2 = 0, over = 0, aux = 0, draww = 0, gamecond = 0,p1aux = 0, p2aux = 0;
	game = malloc(sizeof(int*) * 3);
	for(int i = 0; i < 3; i++)
		game[i] = malloc(sizeof(int) * 3);
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
			game[i][j] = 0;
	}
	printf("===========Tic tac toe in C===========\n");
	printf("Rules: You must write two indices in int value, considering how an array works in C\n");
	printf("Good Luck!\n");
	do {
		do {
			do {
				valid = 0;
				printf("Player 1 turn: ");
				scanf("%d %d", &ind1, &ind2);
				if (ind1 < 3 && ind1 >= 0 && ind2 < 3 && ind2 >= 0) {
					if (game[ind1][ind2] != 0) {
						printf("invalid place\n");
						valid = 0;
					} else {
						valid = 1;
						break;
					}
				}  else
					printf("invalid indices\n");
			} while(valid == 0);
			game[ind1][ind2] = 1;
			if( over == 0) {
				over = winP1(&game, &p1);
			}
			if(over == 0)
				over = winP2(&game, &p2);
			show(&game);
			if (p1 > 0) {
				printf("Player 1 wins!\n");
			}
			if(p1 == 0 && p2 == 0)
				if(draw(&game) == 0) {
					draww++;
					printf("Draw!\n");
					over++;
				}
			if(over > 0) {
				gamecond = 1;
				break;
			}
			do {
				valid = 0;
				printf("Player 2 turn: ");
				scanf("%d %d", &ind1, &ind2);
				if (ind1 < 3 && ind1 >= 0 && ind2 < 3 && ind2 >= 0) {
					if (game[ind1][ind2] != 0) {
						printf("invalid place\n");
						valid = 0;
					} else {
						valid = 1;
						break;
					}
				}  else
					printf("invalid indices\n");
			} while(valid == 0);
			game[ind1][ind2] = 2;
			if( over == 0) {
				over = winP1(&game, &p1);
			}
			if(over == 0)
				over = winP2(&game, &p2);
			show(&game);
			if (p2 > 0) {
				printf("Player 2 wins!\n");
			}
			if(p1 == 0 && p2 == 0)
				if(draw(&game) == 0) {
					draww++;
					printf("Draw!\n");
					over++;
				}

			if(over > 0) {
				gamecond = 1;
				break;
			}
		} while (gamecond == 0);
		int choose = 0;
		p1aux+=p1;
		p2aux+=p2;
		printf("Leaderboard, Player 1: %d \n Player 2: %d \n Draw: %d\n", p1aux, p2aux, draww);
		printf("Wanna still playing?, 1 = yes, 0 = no: ");
		scanf(" %d", &choose);
		if(choose <= 0) {
			over = 2;
			break;
		} else if (choose >= 1) {
			gamecond = 0;
			over = 0;
			p1 = 0;
			p2 = 0;
			for (int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++) {
					game[i][j] = 0;
				}
		}
	} while(over < 2);

}