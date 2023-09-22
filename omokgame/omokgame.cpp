#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

using namespace std;

void gotoxy(int x, int y);
void cursor(int n);
int win(string** arr2, string wb, int x, int y);

enum eKeyCode
{
	KEY_UP = 72,     // 방향키 ↑
	KEY_DOWN = 80,   // 방향키 ↓
	KEY_LEFT = 75,   // 방향키 ←
	KEY_RIGHT = 77,  // 방향키 →
	KEY_SPACE = 32,  // 스페이스바
	KEY_R = 114,     // R키
};

void printOmokArt() {
	cout << "           ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n";
	cout << "           ★                                                                                ☆\n";
	cout << "           ☆   OOOOO    M       M   OOOOO   K     K    GGGGG       A       M       M  EEEEE ★\n";
	cout << "           ★  O     O   MM     MM  O     O  K   K     G           A A      MM     MM  E     ☆\n";
	cout << "           ☆  O     O   M M   M M  O     O  K  K      G          AAAAA     M M   M M  EEEE  ★\n";
	cout << "           ★  0     0   M  M M  M  0     0  K   K     G   GGG   A     A    M  M M  M  E     ☆\n";
	cout << "           ☆   OOOOO    M   M   M   OOOOO   K     K    GGGGG   A       A   M   M   M  EEEEE ★\n";
	cout << "           ★                                                                                ☆\n";
	cout << "           ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n";
	cout << "\n\n\n                                               조작 방법! \n\n";
	cout << "                             이동키 : ↑, ↓, ←, →        착수 : SPACE BAR\n\n";
}

int main() {
	srand(time(NULL));
	string player1Name, player2Name;

	printOmokArt();
	 
	cout << "\n                                  플레이어1의 이름을 적어주세요: ";
	getline(cin, player1Name);

	cout << "\n                                  플레이어2의 이름을 적어주세요: ";
	getline(cin, player2Name);

	cout << "\n                                     환영합니다, " << player1Name << "님! " << player2Name << "님!\n\n";
	cout << "                                           게임을 시작합니다!";
	_getch();
	system("cls");

	bool turn = true;

	string** arr2 = new string * [21];
	for (int i = 0; i < 21; i++) {
		arr2[i] = new string[21];
	}
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++) {
			arr2[i][j] = "┼ "; // 동적 배열 사용
		}
	}
	for (int j = 0; j < 21; j++) {
		arr2[0][j] = "▩"; // 동적 배열 사용
	}
	for (int j = 0; j < 21; j++) {
		arr2[j][0] = "▩"; // 동적 배열 사용
	}
	for (int j = 0; j < 21; j++) {
		arr2[j][20] = "▩"; // 동적 배열 사용
	}
	for (int j = 0; j < 21; j++) {
		arr2[20][j] = "▩"; // 동적 배열 사용
	}

	int x = 10;
	int y = 10;// array[y][x/2]
	int cnt = 0;
	int flag = 0;
	char input;

	while (1) {
		if (flag == 1 && turn) {
				system("cls");
				PlaySound(TEXT("winning.wav"), NULL, SND_FILENAME | SND_ASYNC);

				cout << "★WINNER!★ ☆WINNER!☆ ★WINNER!★ ☆WINNER!☆ ★WINNER!★ ☆WINNER!☆\n\n"; 

				for (int i = 0; i < 28; i++) cout << " ";
				cout << player2Name << " 님 승리!";

				cout << "\n\n★WINNER!★ ☆WINNER!☆ ★WINNER!★ ☆WINNER!☆ ★WINNER!★ ☆WINNER!☆\n\n";


				cout << "다시하기: 1     종료: 2";
				input = _getch();
				if (input == '2') {
					break;
				}
			
		system("cls");
		flag = 0;
		for (int i = 0; i < 21; i++) {
			arr2[i] = new string[21];
		}
		for (int i = 1; i < 21; i++) {
			for (int j = 1; j < 21; j++) {
				arr2[i][j] = "┼ "; // 동적 배열 사용
			}
		}
		for (int j = 0; j < 21; j++) {
			arr2[0][j] = "▩"; // 동적 배열 사용
		}
		for (int j = 0; j < 21; j++) {
			arr2[j][0] = "▩"; // 동적 배열 사용
		}
		for (int j = 0; j < 21; j++) {
			arr2[j][20] = "▩"; // 동적 배열 사용
		}
		for (int j = 0; j < 21; j++) {
			arr2[20][j] = "▩"; // 동적 배열 사용
		}
	
		}
		else if (flag == 1 && turn != true) {
			system("cls");
			PlaySound(TEXT("winning.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << "★WINNER!★ ☆WINNER!☆ ★WINNER!★ ☆WINNER!☆ ★WINNER!★ ☆WINNER!☆\n\n";

			for (int i = 0; i < 28; i++) cout << " ";
			cout << player1Name << " 님 승리!";

			cout << "\n\n★WINNER!★ ☆WINNER!☆ ★WINNER!★ ☆WINNER!☆ ★WINNER!★ ☆WINNER!☆\n\n";

			cout << "다시하기: 1     종료: 2";
			input = _getch();
			if (input == '2') {
				break;
			}
			system("cls");
			flag = 0;
			for (int i = 0; i < 21; i++) {
				arr2[i] = new string[21];
			}
			for (int i = 1; i < 21; i++) {
				for (int j = 1; j < 21; j++) {
					arr2[i][j] = "┼ "; // 동적 배열 사용
				}
			}
			for (int j = 0; j < 21; j++) {
				arr2[0][j] = "▩"; // 동적 배열 사용
			}
			for (int j = 0; j < 21; j++) {
				arr2[j][0] = "▩"; // 동적 배열 사용
			}
			for (int j = 0; j < 21; j++) {
				arr2[j][20] = "▩"; // 동적 배열 사용
			}
			for (int j = 0; j < 21; j++) {
				arr2[20][j] = "▩"; // 동적 배열 사용
			}
		}
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				cout << arr2[i][j];
			}
			cout << endl;
		}
		if (turn) {
			gotoxy(9, 22);
			cout << player1Name <<" 님 ● 차례";
			if (flag == 1) {
				break;
			}
		}
		else {
			gotoxy(9, 22);
			cout << player2Name << " 님 ○ 차례";
			if (flag == 1) {
				break;
			}
		}
		char c = 'c';
		cursor(0);
		int i = 1;
		while (i) {
			if (arr2[y][x / 2] != "┼ " && c == KEY_SPACE) {
				;
			}
			else if (arr2[y][x / 2] != "┼ " && c == LEFT) {
				x--;
				x--;
			}
			else if (arr2[y][x / 2] != "┼ " && c == RIGHT) {
				x++;
			}
			else if (arr2[y][x / 2] != "┼ " && c == UP) {
				y--;
			}
			else if (arr2[y][x / 2] != "┼ " && c == DOWN) {
				y++;
			}
			else if (arr2[y][x / 2] == "┼ ") {
				printf("■");
			}
			if (y < 1) {
				y++;
				gotoxy(x, y);
				y = 1;
			}
			if (y > 19) {
				y--;
				gotoxy(x, y);
				y = 19;
			}
			if (x < 2) {
				x++;
				gotoxy(x, y);
				x = 2;
			}
			if (x > 38) {
				x--;
				gotoxy(x, y);
				x = 38;
			}
			gotoxy(x, y);
			if (_kbhit()) {   //키보드 입력 확인 (true / false)
				c = _getch();      // 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
				// 입력된 키를 받아온다.

				switch (c) {
				case eKeyCode::KEY_UP:    // 방향키 위를 눌렀을 때
				{
					cout << arr2[y][x / 2];
					--y;
					gotoxy(x, y);
					break;
				}
				case eKeyCode::KEY_DOWN:  // 방향키 아래를 눌렀을 때
				{

					cout << arr2[y][x / 2];
					++y;
					gotoxy(x, y);
					break;
				}
				case eKeyCode::KEY_LEFT:  // 방향키 왼쪽을 눌렀을 때
				{

					cout << arr2[y][x / 2];
					--x;
					--x;
					if (x < 0) {
						x = 40;
					}
					gotoxy(x, y);
					break;
				}
				case eKeyCode::KEY_RIGHT: // 방향키 오른쪽을 눌렀을 때
				{
					cout << arr2[y][x / 2];
					++x;
					++x;
					if (x > 40) {
						x = 0;
					}
					gotoxy(x, y);
					break;
				}
				case eKeyCode::KEY_SPACE: // 스페이스바를 눌렀을 때
				{
					PlaySound(TEXT("Blop-Sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
					cnt = 1;
					if (turn && arr2[y][x / 2] == "┼ ") {
						arr2[y][x / 2] = "●";
						cout << "●";
						i = 0;
						turn = false;
						flag = win(arr2, "●", x, y);
					}
					else if (!turn && arr2[y][x / 2] == "┼ ") {
						arr2[y][x / 2] = "○";
						cout << "○";
						i = 0;
						turn = true;
						flag = win(arr2, "○", x, y);
					}

					//arr2[y][x / 2];
					break;
				}
				}
			}
		}
		system("cls");
	}
}

int win(string** arr2, string wb, int x, int y) {
	int cnt = 1;
	int flag = 0;

	for (int i = 1; i < 6; i++) {
		if (arr2[y - i][x / 2] == wb) {//착수위치 위 확인
			cnt++;
			if (cnt == 5) {
				flag = 1;
			}
			else if (cnt > 5) {
				flag = 0;
			}
		}
		else break;
	}
	for (int i = 1; i < 6; i++) {
		if (arr2[y + i][x / 2] == wb) {
			cnt++;
			if (cnt == 5) {
				flag = 1;
			}
			else if (cnt > 5) {
				flag = 0;
			}
		}
		else break;
	}
	cnt = 1;
	//=================================================================================위아래 판별
	for (int i = 1; i < 6; i++) {
		if (arr2[y][x / 2 - i] == wb) {//착수위치 좌 확인
			cnt++;
			if (cnt == 5) {
				flag = 1;
			}
			else if (cnt > 5) {
				flag = 0;
			}
		}
		else break;
	}
	for (int i = 1; i < 6; i++) {
		if (arr2[y][x / 2 + i] == wb) {//우 확인
			cnt++;
			if (cnt == 5) {
				flag = 1;
			}
			else if (cnt > 5) {
				flag = 0;
			}
		}
		else break;
	}
	cnt = 1;
	//===================================================================================좌우 판별
	for (int i = 1; i < 6; i++) {
		if (arr2[y - i][x / 2 + i] == wb) {//오른쪽 위 2시방향 확인
			cnt++;
			if (cnt == 5) {
				flag = 1;
			}
			else if (cnt > 5) {
				flag = 0;
			}
		}
		else break;
	}
	for (int i = 1; i < 6; i++) {
		if (arr2[y + i][x / 2 - i] == wb) {//7시 방향 확인
			cnt++;
			if (cnt == 5) {
				flag = 1;
			}
			else if (cnt > 5) {
				flag = 0;
			}
		}
		else break;
	}
	cnt = 1;
	//=================================================================================== 2~7 대각선 판별
	for (int i = 1; i < 6; i++) {
		if (arr2[y + i][x / 2 + i] == wb) {//4시방향 확인
			cnt++;
			if (cnt == 5) {
				flag = 1;
			}
			else if (cnt > 5) {
				flag = 0;
			}
		}
		else break;
	}
	for (int i = 1; i < 6; i++) {
		if (arr2[y - i][x / 2 - i] == wb) {//10시방향 확인
			cnt++;
			if (cnt == 5) {
				flag = 1;
			}
			else if (cnt > 5) {
				flag = 0;
			}
		}
		else break;
	}
	cnt = 1;
	return flag;

}





void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursor(int n)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}