#include <iostream>
#include <string>
using namespace std;

void printOmokArt() {
    cout << "          ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n";
    cout << "          ★                                                                                ☆\n";
    cout << "          ☆   OOOOO    M       M   OOOOO   K     K    GGGGG       A       M       M  EEEEE ★\n";
    cout << "          ★  O     O   MM     MM  O     O  K   K     G           A A      MM     MM  E     ☆\n";
    cout << "          ☆  O     O   M M   M M  O     O  K  K      G          AAAAA     M M   M M  EEEE  ★\n";
    cout << "          ★  O     O   M  M M  M  O     O  K   K     G   GGG   A     A    M  M M  M  E     ☆\n";
    cout << "          ☆   OOOOO    M   M   M   OOOOO   K    K     GGGGGG  A       A   M   M   M  EEEEE ★\n";
    cout << "          ★                                                                                ☆\n";
    cout << "          ☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★\n";
    cout << "\n\n\n                  조작 방법! \n\n";
    cout << "           이동키 : →, ←, ↑, ↓\n           착수 : SPACE BAR\n\n";
}

int main() {
    string player1Name, player2Name;

    printOmokArt();

    cout << "\n플레이어1의 이름을 적어주세요: ";
    getline(cin, player1Name);

    cout << "플레이어2의 이름을 적어주세요: ";
    getline(cin, player2Name);

    cout << "\n환영합니다, " << player1Name << "님과 " << player2Name << "님!\n";
}
