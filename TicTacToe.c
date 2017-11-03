/*
	   ______  ______  ______       ______  ______  ______       ______  ______  ______
	  /_  __/ /_  __/ / ____/      /_  __/ / __  / / ____/      /_  __/ / __  / / ____/
	   / /     / /   / /     ___    / /   / / / / / /     ___    / /   / / / / / /___
	  / /     / /   / /     /__/   / /   / /_/ / / /     /__/   / /   / / / / / ____/
	 / /   __/ /_  / /___         / /   / __  / / /___         / /   / /_/ / / /___
	/_/   /_____/ /_____/        /_/   /_/ /_/ /_____/        /_/   /_____/ /_____/

	by Mathshyun!
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#define PLAYER 0
#define AI 1
#define TEST 2

//3▼3蘊縑憮曖 謝ル蒂 釭顫頂朝 掘褻羹
struct point {
	int x, y;
};

//蝓, ぬ, 鼠蒂 盪濰й 掘褻羹
struct numbers {
	int Xwin, Owin, draw;
};

int title();																				//顫檜ぎ 詭衛雖蒂 轎溘ж朝 л熱
int decideOrder();																			//PvA縑憮 牖憮蒂 薑ж朝 л熱
int isGameEnd(int map[3][3], int x, int y);													//啪歜檜 部陬朝雖 �挫恉炴� л熱
int pauseScreen();																			//橾衛 薑雖 �飛橉� ル衛ж朝 л熱
int isFork(int map[3][3], int turn);														//ん觼 鼻鷓(虞擊 熱 橈朝 鼻鷓)檣雖 �挫恉炴� л熱
void startGame(int type);																	//啪歜擊 衛濛ж朝 л熱
void endGame(int map[3][3], int p[2], int wp, int type, int turn, struct point pointer);	//啪歜擊 部頂朝 л熱
void printScreen(int map[3][3], int p[2], int type, int turn, struct point pointer);		//啪歜 �飛橉� ル衛ж朝 л熱
struct point TTTAI(int map[3][3], int turn);												//AI曖 摹鷗擊 唸薑ж朝 л熱

int main() {
	system("mode con:cols=100 lines=30");	//璽 觼晦 褻瞰
	system("title TIC-TAC-TOE");			//璽 薯跡 撲薑
	srand(time(NULL));						//楠渾 滲熱曖 衛萄(seed) 撲薑
	while (1) {
		int x = title();					//顫檜ぎ 詭衛雖蒂 ル衛п 奩�秣社� x縑 盪濰
		switch (x) {
		case 2:
			return 0;						//啪歜 謙猿
		default:
			startGame(x);					//啪歜 衛濛
		}
	}
	return 0;
}

//顫檜ぎ 詭衛雖蒂 轎溘ж朝 л熱
int title() {
	int x, selected = 0;

	while (1) {
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛         ______  ______  ______       ______  ______  ______       ______  ______  ______       弛\n");
		printf("弛        /_  __/ /_  __/ / ____/      /_  __/ / __  / / ____/      /_  __/ / __  / / ____/       弛\n");
		printf("弛         / /     / /   / /     ___    / /   / / / / / /     ___    / /   / / / / / /___         弛\n");
		printf("弛        / /     / /   / /     /__/   / /   / /_/ / / /     /__/   / /   / / / / / ____/         弛\n");
		printf("弛       / /   __/ /_  / /___         / /   / __  / / /___         / /   / /_/ / / /___           弛\n");
		printf("弛      /_/   /_____/ /_____/        /_/   /_/ /_/ /_____/        /_/   /_____/ /_____/           弛\n");
		printf("弛                                                                                                弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                    %s Ы溯檜橫 vs. Ы溯檜橫 %s                                     \n", (selected == 0) ? "Ⅱ" : "  ", (selected == 0) ? "９" : "  ");
		printf("                                       %s Ы溯檜橫 vs. AI %s                                        \n", (selected == 1) ? "Ⅱ" : "  ", (selected == 1) ? "９" : "  ");
		printf("                                           %s 釭陛晦 %s                                             \n", (selected == 2) ? "Ⅱ" : "  ", (selected == 2) ? "９" : "  ");
		printf("                             寞щ酈煎 醴憮蒂 遺霜檜堅 縛攪煎 摹鷗ж撮蹂                             \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf(" by Mathshyun!                                                                                      \n");
		switch (x = getch()) {
		case 224:
			x = getch();
			printf("");
			if (x == 72) {
				if (selected == 0) selected = 2;
				else selected--;
			}
			else if (x == 80) {
				if (selected == 2) selected = 0;
				else selected++;
			}
			break;
		case 13:
			return selected;
		}
	}
}

//PvA縑憮 牖憮蒂 薑ж朝 л熱
int decideOrder() {
	int x, selected = 0;

	while (1) {
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛         ______  ______  ______       ______  ______  ______       ______  ______  ______       弛\n");
		printf("弛        /_  __/ /_  __/ / ____/      /_  __/ / __  / / ____/      /_  __/ / __  / / ____/       弛\n");
		printf("弛         / /     / /   / /     ___    / /   / / / / / /     ___    / /   / / / / / /___         弛\n");
		printf("弛        / /     / /   / /     /__/   / /   / /_/ / / /     /__/   / /   / / / / / ____/         弛\n");
		printf("弛       / /   __/ /_  / /___         / /   / __  / / /___         / /   / /_/ / / /___           弛\n");
		printf("弛      /_/   /_____/ /_____/        /_/   /_/ /_/ /_____/        /_/   /_____/ /_____/           弛\n");
		printf("弛                                                                                                弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                            %s 摹奢 %s                                              \n", (selected == 0) ? "Ⅱ" : "  ", (selected == 0) ? "９" : "  ");
		printf("                                            %s �襤� %s                                              \n", (selected == 1) ? "Ⅱ" : "  ", (selected == 1) ? "９" : "  ");
		printf("                                           %s 鼠濛嬪 %s                                             \n", (selected == 2) ? "Ⅱ" : "  ", (selected == 2) ? "９" : "  ");
		printf("                                            %s 鏃模 %s                                              \n", (selected == 3) ? "Ⅱ" : "  ", (selected == 3) ? "９" : "  ");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		printf("                                                                                                    \n");
		switch (x = getch()) {
		case 224:
			x = getch();
			printf("");
			if (x == 72 && selected != 0) selected--;
			else if (x == 80 && selected != 3) selected++;
			break;
		case 13:
			switch (selected) {
			case 0:					//Ы溯檜橫 摹奢
				return PLAYER;
			case 1:					//Ы溯檜橫 �襤�
				return AI;
			case 2:					//鼠濛嬪
				return rand() % 2;
			case 3:					//鏃模
				return -1;
			}
		}
	}
}

//啪歜檜 部陬朝雖 �挫恉炴� л熱
int isGameEnd(int map[3][3], int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (map[i][y] != map[x][y]) break;
		cnt++;
	}
	if (cnt == 3) return map[x][y];
	cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (map[x][i] != map[x][y]) break;
		cnt++;
	}
	if (cnt == 3) return map[x][y];
	cnt = 0;
	if ((x + y) % 2 == 0) {
		cnt = 0;
		if (x == y) {
			for (int i = 0; i < 3; i++) {
				if (map[i][i] != map[x][y]) break;
				cnt++;
			}
		}
		if (cnt == 3) return map[x][y];
		cnt = 0;
		if (x + y == 2) {
			for (int i = 0; i < 3; i++) {
				if (map[i][2 - i] != map[x][y]) break;
				cnt++;
			}
		}
		if (cnt == 3) return map[x][y];
	}
	return 0;
}

//啪歜擊 衛濛ж朝 л熱
void startGame(int type) {
	struct point pointer;			//⑷營 ル衛и 蘊
	int map[3][3] = { 0 };			//裘擊 盪濰ж朝 寡翮
	int cnt = 0, turn = 1, p[2];
	clock_t prevTime;				//薯и 衛除擊 釭顫頂晦 嬪п 餌辨

	switch (type) {
	case 0:							//PvP
		p[0] = p[1] = PLAYER;
		break;
	case 1:							//PvA
		p[0] = decideOrder();
		if (p[0] == -1) return;		//牖憮 摹鷗 璽縑憮 鏃模й 唳辦 顫檜ぎ煎
		p[1] = (p[0] + 1) % 2;
		break;
	}

	pointer.x = 1;
	pointer.y = 1;
	printScreen(map, p, type, turn - 1, pointer);
	prevTime = clock();
	while (1) {
		if (kbhit()) {															//酈爾萄 殮溘檜 氈朝雖 匐餌
			switch (getch()) {
			case 224:
				if (p[turn - 1] == PLAYER) {									//Ы溯檜橫曖 離滔檜賊
					switch (getch()) {
					case 72:													//∟
						if (pointer.y == 0) continue;
						pointer.y--;
						break;
					case 75:													//∠
						if (pointer.x == 0) continue;
						pointer.x--;
						break;
					case 77:													//⊥
						if (pointer.x == 2) continue;
						pointer.x++;
						break;
					case 80:													//⊿
						if (pointer.y == 2) continue;
						pointer.y++;
					}
				}
				printScreen(map, p, type, turn - 1, pointer);
				break;
			case 13:															//縛攪
				if (p[turn - 1] == PLAYER && map[pointer.x][pointer.y] == 0) {
					int x;
					map[pointer.x][pointer.y] = turn;
					if (p[turn % 2] == AI) prevTime = clock();
					turn = turn % 2 + 1;
					x = isGameEnd(map, pointer.x, pointer.y);
					if (x != 0) {
						endGame(map, p, x, type, turn, pointer);
						return;
					}
					cnt++;
					if (cnt == 9) {
						endGame(map, p, 0, type, turn, pointer);
						return;
					}
					printScreen(map, p, type, turn - 1, pointer);
				}
				break;
			case 27:															//ESC
				if (pauseScreen() == 0) {
					printScreen(map, p, type, turn - 1, pointer);
					break;
				}
				else return;
			}
		}
		else {																	//酈爾萄 殮溘檜 橈戲賊
			if (p[turn - 1] == AI) {
				if ((clock() - prevTime) / CLOCKS_PER_SEC >= 1) {
					int x;
					struct point pointAI;
					pointAI = TTTAI(map, turn);
					map[pointAI.x][pointAI.y] = turn;
					turn = turn % 2 + 1;
					x = isGameEnd(map, pointAI.x, pointAI.y);
					if (x != 0) {
						endGame(map, p, x, type, turn, pointer);
						return;
					}
					cnt++;
					if (cnt == 9) {
						endGame(map, p, 0, type, turn, pointer);
						return;
					}
					printScreen(map, p, type, turn - 1, pointer);
				}
			}
		}
	}
}

//啪歜擊 部頂朝 л熱
void endGame(int map[3][3], int p[2], int wp, int type, int turn, struct point pointer) {
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛忙式式式式式式式成式式式式式式式成式式式式式式式忖忙式式式式式式式式式式式式式式式式式式式式式忖弛\n");
	printf("弛弛      %s      弛      %s      弛      %s      弛弛                                          弛弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 0) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 0) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 0) ? "∪" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛弛 %s %s %s                            弛弛\n", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (turn == 0) ? "Ⅱ" : "  ", (p[0] == PLAYER) ? "Ы溯檜橫" : "   AI   ", (type == 1) ? " " : "1");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛弛 %s %s %s                            弛弛\n", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (turn == 1) ? "Ⅱ" : "  ", (p[1] == PLAYER) ? "Ы溯檜橫" : "   AI   ", (type == 1) ? " " : "2");
	printf("弛弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛弛                                          弛弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 0) ? "Ⅱ" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 0) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 0) ? "Ⅱ" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 0) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 0) ? "Ⅱ" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 0) ? "９" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛戌式式式式式式式式式式式式式式式式式式式式式戎弛\n", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 0) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 0) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 0) ? "～" : "  ");
	printf("弛戍式式式式式式式托式式式式式式式托式式式式式式式扣                                              弛\n");
	printf("弛弛      %s      弛      %s      弛  忙式式式式式扛式式式式忖                                    弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 1) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 1) ? "∪" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  弛                    弛                                    弛\n", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ");
	if (wp == 0)
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  弛       鼠蝓睡       弛                                    弛\n", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ");
	else if (p[0] == p[1])
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  弛   %s %d 蝓!   弛                                    弛\n", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (p[wp - 1] == PLAYER) ? "Ы溯檜橫" : "   AI   ", wp);
	else
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  弛    %s 蝓!    弛                                    弛\n", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (p[wp - 1] == PLAYER) ? "Ы溯檜橫" : "   AI   ");
	printf("弛弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛%s弛                    弛                                    弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 1) ? "Ⅱ" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 1) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 1) ? "Ⅱ" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 1) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 1) ? "Ⅱ" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  戌式式式式式成式式式式戎                                    弛\n", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 1) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 1) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 1) ? "～" : "  ");
	printf("弛戍式式式式式式式托式式式式式式式托式式式式式式式扣                                              弛\n");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 2) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 2) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 2) ? "∪" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛                                              弛\n", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ");
	printf("弛弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 2) ? "Ⅱ" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 2) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 2) ? "Ⅱ" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 2) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 2) ? "Ⅱ" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 2) ? "９" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛                                              弛\n", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 2) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 2) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 2) ? "～" : "  ");
	printf("弛戌式式式式式式式扛式式式式式式式扛式式式式式式式戎                                              弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛                                                                                                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	getch();
}

//橾衛 薑雖 �飛橉� ル衛ж朝 л熱
int pauseScreen() {
	int x, selected = 0;
	while (1) {
		system("cls");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛忙式式式式式式式成式式式式式式式成式式式式式式式忖忙式式式式式式式式式式式式式式式式式式式式式忖弛\n");
		printf("弛弛              弛              弛              弛弛                                          弛弛\n");
		printf("弛弛              弛              弛              弛弛                                          弛弛\n");
		printf("弛弛              弛              弛              弛弛                                          弛弛\n");
		printf("弛弛              弛              弛              弛弛                                          弛弛\n");
		printf("弛弛              弛              弛              弛戌式式式式式式式式式式式式式式式式式式式式式戎弛\n");
		printf("弛弛              弛              弛              弛                                              弛\n");
		printf("弛弛              弛              弛              弛                                              弛\n");
		printf("弛戍式式式式式式式托式式式式式式式托式式式式式式式扣                                              弛\n");
		printf("弛弛              弛              弛    忙式式式式扛式式式忖                                      弛\n");
		printf("弛弛              弛              弛    弛                弛                                      弛\n");
		printf("弛弛              弛              弛    弛    橾衛 薑雖   弛                                      弛\n");
		printf("弛弛              弛              弛    弛                弛                                      弛\n");
		printf("弛弛              弛              弛    弛                弛                                      弛\n");
		printf("弛弛              弛              弛    弛 %s 啗樓ж晦 %s 弛                                      弛\n", (selected == 0) ? "Ⅱ" : "  ", (selected == 0) ? "９" : "  ");
		printf("弛弛              弛              弛    弛  %s 釭陛晦 %s  弛                                      弛\n", (selected == 1) ? "Ⅱ" : "  ", (selected == 1) ? "９" : "  ");
		printf("弛戍式式式式式式式托式式式式式式式托式式扣                弛                                      弛\n");
		printf("弛弛              弛              弛    戌式式式式成式式式戎                                      弛\n");
		printf("弛弛              弛              弛              弛                                              弛\n");
		printf("弛弛              弛              弛              弛                                              弛\n");
		printf("弛弛              弛              弛              弛                                              弛\n");
		printf("弛弛              弛              弛              弛                                              弛\n");
		printf("弛弛              弛              弛              弛                                              弛\n");
		printf("弛弛              弛              弛              弛                                              弛\n");
		printf("弛戌式式式式式式式扛式式式式式式式扛式式式式式式式戎                                              弛\n");
		printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
		printf("弛                                                                                                弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		switch (x = getch()) {
		case 224:
			x = getch();
			if (x == 72 || x == 80) selected = (selected + 1) % 2;
			break;
		case 13:
			return selected;
		}
	}
}

//ん觼 鼻鷓(虞擊 熱 橈朝 鼻鷓)檣雖 �挫恉炴� л熱
int isFork(int map[3][3], int turn) {
	int attacks = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (map[i][j] == map[i][(j + 1) % 3] && map[i][j] == turn && map[i][(j + 2) % 3] == 0) attacks++;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (map[j][i] == map[(j + 1) % 3][i] && map[j][i] == turn && map[(j + 2) % 3][i] == 0) attacks++;
	for (int i = 0; i < 3; i++)
		if (map[i][i] == map[(i + 1) % 3][(i + 1) % 3] && map[i][i] == turn && map[(i + 2) % 3][(i + 2) % 3] == 0) attacks++;
	for (int i = 0; i < 3; i++)
		if (map[i][2 - i] == map[(i + 1) % 3][2 - (i + 1) % 3] && map[i][2 - i] == turn && map[(i + 2) % 3][2 - (i + 2) % 3] == 0) attacks++;
	return (attacks >= 2);
}

//啪歜 �飛橉� ル衛ж朝 л熱
void printScreen(int map[3][3], int p[2], int type, int turn, struct point pointer) {
	system("cls");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛忙式式式式式式式成式式式式式式式成式式式式式式式忖忙式式式式式式式式式式式式式式式式式式式式式忖弛\n");
	printf("弛弛      %s      弛      %s      弛      %s      弛弛                                          弛弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 0) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 0) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 0) ? "∪" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛弛 %s %s %s                            弛弛\n", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (turn == 0) ? "Ⅱ" : "  ", (p[0] == PLAYER) ? "Ы溯檜橫" : "   AI   ", (type == 1) ? " " : "1");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛弛 %s %s %s                            弛弛\n", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (turn == 1) ? "Ⅱ" : "  ", (p[1] == PLAYER) ? "Ы溯檜橫" : "   AI   ", (type == 1) ? " " : "2");
	printf("弛弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛弛                                          弛弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 0) ? "Ⅱ" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 0) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 0) ? "Ⅱ" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 0) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 0) ? "Ⅱ" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 0) ? "９" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛戌式式式式式式式式式式式式式式式式式式式式式戎弛\n", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][0] == 1) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 2) ? "﹥" : "  ", (map[0][0] == 1) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 2) ? "﹥" : "  ", (map[1][0] == 1) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 2) ? "﹥" : "  ", (map[2][0] == 1) ? "﹥" : "  ");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 0) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 0) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 0) ? "～" : "  ");
	printf("弛戍式式式式式式式托式式式式式式式托式式式式式式式扣                                              弛\n");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 1) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 1) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 1) ? "∪" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛                                              弛\n", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ");
	printf("弛弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 1) ? "Ⅱ" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 1) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 1) ? "Ⅱ" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 1) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 1) ? "Ⅱ" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 1) ? "９" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛                                              弛\n", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][1] == 1) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 2) ? "﹥" : "  ", (map[0][1] == 1) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 2) ? "﹥" : "  ", (map[1][1] == 1) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 2) ? "﹥" : "  ", (map[2][1] == 1) ? "﹥" : "  ");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 1) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 1) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 1) ? "～" : "  ");
	printf("弛戍式式式式式式式托式式式式式式式托式式式式式式式扣                                              弛\n");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 2) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 2) ? "∪" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 2) ? "∪" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛                                              弛\n", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ");
	printf("弛弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛%s%s  %s  %s%s弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 2) ? "Ⅱ" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 2) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 2) ? "Ⅱ" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 2) ? "９" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 2) ? "Ⅱ" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 2) ? "９" : "  ");
	printf("弛弛  %s%s  %s%s  弛  %s%s  %s%s  弛  %s%s  %s%s  弛                                              弛\n", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ");
	printf("弛弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛  %s%s%s%s%s  弛                                              弛\n", (map[0][2] == 1) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 2) ? "﹥" : "  ", (map[0][2] == 1) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 2) ? "﹥" : "  ", (map[1][2] == 1) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 2) ? "﹥" : "  ", (map[2][2] == 1) ? "﹥" : "  ");
	printf("弛弛      %s      弛      %s      弛      %s      弛                                              弛\n", (p[turn] == PLAYER && pointer.x == 0 && pointer.y == 2) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 1 && pointer.y == 2) ? "～" : "  ", (p[turn] == PLAYER && pointer.x == 2 && pointer.y == 2) ? "～" : "  ");
	printf("弛戌式式式式式式式扛式式式式式式式扛式式式式式式式戎                                              弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛                                                                                                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
}

//AI曖 摹鷗擊 唸薑ж朝 л熱
struct point TTTAI(int map[3][3], int turn) {
	struct point res;
	int temp = 0;
	//啪歜擊 夥煎 部鳥 熱 氈擊 陽 摹鷗и棻
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[i][j] == map[i][(j + 1) % 3] && map[i][j] == turn && map[i][(j + 2) % 3] == 0) {
				res.x = i;
				res.y = (j + 2) % 3;
				return res;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[j][i] == map[(j + 1) % 3][i] && map[j][i] == turn && map[(j + 2) % 3][i] == 0) {
				res.x = (j + 2) % 3;
				res.y = i;
				return res;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (map[i][i] == map[(i + 1) % 3][(i + 1) % 3] && map[i][i] == turn && map[(i + 2) % 3][(i + 2) % 3] == 0) {
			res.x = (i + 2) % 3;
			res.y = (i + 2) % 3;
			return res;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (map[i][2 - i] == map[(i + 1) % 3][2 - (i + 1) % 3] && map[i][2 - i] == turn && map[(i + 2) % 3][2 - (i + 2) % 3] == 0) {
			res.x = (i + 2) % 3;
			res.y = 2 - (i + 2) % 3;
			return res;
		}
	}
	//鼻渠寞曖 奢問擊 離欽и棻
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[i][j] == map[i][(j + 1) % 3] && map[i][j] == (turn % 2 + 1) && map[i][(j + 2) % 3] == 0) {
				res.x = i;
				res.y = (j + 2) % 3;
				return res;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[j][i] == map[(j + 1) % 3][i] && map[j][i] == (turn % 2 + 1) && map[(j + 2) % 3][i] == 0) {
				res.x = (j + 2) % 3;
				res.y = i;
				return res;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (map[i][i] == map[(i + 1) % 3][(i + 1) % 3] && map[i][i] == (turn % 2 + 1) && map[(i + 2) % 3][(i + 2) % 3] == 0) {
			res.x = (i + 2) % 3;
			res.y = (i + 2) % 3;
			return res;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (map[i][2 - i] == map[(i + 1) % 3][2 - (i + 1) % 3] && map[i][2 - i] == (turn % 2 + 1) && map[(i + 2) % 3][2 - (i + 2) % 3] == 0) {
			res.x = (i + 2) % 3;
			res.y = 2 - (i + 2) % 3;
			return res;
		}
	}
	//ん觼蒂 虜萇棻
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[i][j] == 0) {
				int tempmap[3][3];
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++)
						tempmap[l][k] = map[l][k];
				tempmap[i][j] = turn;
				if (isFork(tempmap, turn)) {
					res.x = i;
					res.y = j;
					return res;
				}
			}
		}
	}
	//ん觼蒂 虞朝棻
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[i][j] == 0) {
				int tempmap[3][3];
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++)
						tempmap[l][k] = map[l][k];
				tempmap[i][j] = turn % 2 + 1;
				if (isFork(tempmap, turn % 2 + 1)) temp++;
			}
		}
	}
	if (temp >= 1) {
		if (temp >= 2) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (map[i][j] == turn) {
						for (int k = -1; k < 2; k++) {
							for (int l = -1; l < 2; l++) {
								if (i + k < 0 || i + k > 2 || j + l < 0 || j + l > 2) continue;
								if (map[i + k][j + l] == 0) {
									int tempmap[3][3];
									for (int m = 0; m < 3; m++)
										for (int n = 0; n < 3; n++)
											tempmap[m][n] = map[m][n];
									tempmap[i + k][j + l] = turn % 2 + 1;
									if (map[i - k][j - l] == 0 && !isFork(tempmap, turn % 2 + 1)) {
										res.x = i - k;
										res.y = j - l;
										return res;
									}
								}
							}
						}
					}
				}
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (map[i][j] == 0) {
						int tempmap[3][3];
						for (int k = 0; k < 3; k++)
							for (int l = 0; l < 3; l++)
								tempmap[l][k] = map[l][k];
						tempmap[i][j] = turn % 2 + 1;
						if (isFork(tempmap, turn % 2 + 1)) {
							res.x = i;
							res.y = j;
							return res;
						}
					}
				}
			}
		}
	}
	//陛遴等陛 綠歷擊 唳辦 陛遴等蒂 摹鷗и棻
	if (map[1][1] == 0) {
		res.x = 1;
		res.y = 1;
		return res;
	}
	//鼻渠寞檜 囀傘蒂 摹鷗и 唳辦 薑奩渠薹曖 囀傘蒂 摹鷗и棻
	for (int i = 0; i <= 2; i += 2) {
		for (int j = 0; j <= 2; j += 2) {
			if (map[i][j] == turn % 2 + 1 && map[2 - i][2 - j] == 0) {
				res.x = 2 - i;
				res.y = 2 - j;
				return res;
			}
		}
	}
	//綴 囀傘蒂 摹鷗и棻
	for (int i = 0; i <= 2; i += 2) {
		for (int j = 0; j <= 2; j += 2) {
			if (map[i][j] == 0) {
				res.x = i;
				res.y = j;
				return res;
			}
		}
	}
	//綴 餌檜萄蒂 摹鷗и棻
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (map[i + j][i - j + 1] == 0) {
				res.x = i + j;
				res.y = i - j + 1;
				return res;
			}
		}
	}
}