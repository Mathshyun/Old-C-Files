/*
	Omok
	by Mathshyun!
*/
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int board[15][15] = {};
int cx = 7, cy = 7;
int turn = 1;

void gotoxy(int x, int y) {
	COORD pos = {2 * x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void showBoard() {
	system("cls");
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			switch(board[j][i]) {
				case 0:
					printf("¦«");
					break;
				case 1:
					printf("¡Ü");
					break;
				case 2:
					printf("¡Û"); 
			}
		}
		printf("\n"); 
	}
}

int checkBoard() {
	int L_R_cnt = 1, U_D_cnt = 1, LU_RD_cnt = 1, LD_RU_cnt = 1;
	for (int a = cx - 1;; a--) {
		if (board[a][cy] == turn) L_R_cnt++;
		else break;
	}
	for (int a = cx + 1;; a++) {
		if (board[a][cy] == turn) L_R_cnt++;
		else break;
	}
	for (int a = cy + 1;; a++) {
		if (board[cx][a] == turn) U_D_cnt++;
		else break;
	}
	for (int a = cy - 1;; a--) {
		if (board[cx][a] == turn) U_D_cnt++;
		else break;
	}
	for (int a = cx - 1, b = cy + 1;; a--, b++) {
		if (board[a][b] == turn) LU_RD_cnt++;
		else break;
	}
	for (int a = cx + 1, b = cy - 1;; a++, b--) {
		if (board[a][b] == turn) LU_RD_cnt++;
		else break;
	}
	for (int a = cx - 1, b = cy - 1;; a--, b--) {
		if (board[a][b] == turn) LD_RU_cnt++;
		else break;
	}
	for (int a = cx + 1, b = cy + 1;; a++, b++) {
		if (board[a][b] == turn) LD_RU_cnt++;
		else break;
	}
	if (L_R_cnt >= 5 || U_D_cnt >= 5 || LU_RD_cnt >= 5 || LD_RU_cnt >= 5) return 1;
	return 0;
}

void moveCursor() {
	int x = getch();
	if (x == 224) {
		switch(x = getch()) {
			case 72:
				if (cy == 0) break;
				gotoxy(cx, --cy);
				break;
			case 75:
				if (cx == 0) break;
				gotoxy(--cx, cy);
				break;
			case 77:
				if (cx == 14) break;
				gotoxy(++cx, cy);
				break;
			case 80:
				if (cy == 14) break;
				gotoxy(cx, ++cy);
		}
	}
	if (x == 13 && !board[cx][cy]) return;
	moveCursor();
}

int main() {
	system("title ¿À¸ñ by Mathshyun!");
	showBoard();
	printf("Turn : 1P");
	gotoxy(cx, cy);
	while(1) {
		moveCursor();
		board[cx][cy] = turn;
		showBoard();
		if(checkBoard()) {
			gotoxy(0, 15);
			printf("%dP Win!\n", turn);
			return 0;
		}
		turn = (turn == 1) ? 2 : 1;
		printf("Turn : %dP", turn);
		gotoxy(cx, cy);
	}
	return 0;
}
