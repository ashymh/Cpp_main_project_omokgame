#include <iostream>
#include <string>
using namespace std;

void printOmokArt() {
    cout << "          �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n";
    cout << "          ��                                                                                ��\n";
    cout << "          ��   OOOOO    M       M   OOOOO   K     K    GGGGG       A       M       M  EEEEE ��\n";
    cout << "          ��  O     O   MM     MM  O     O  K   K     G           A A      MM     MM  E     ��\n";
    cout << "          ��  O     O   M M   M M  O     O  K  K      G          AAAAA     M M   M M  EEEE  ��\n";
    cout << "          ��  O     O   M  M M  M  O     O  K   K     G   GGG   A     A    M  M M  M  E     ��\n";
    cout << "          ��   OOOOO    M   M   M   OOOOO   K    K     GGGGGG  A       A   M   M   M  EEEEE ��\n";
    cout << "          ��                                                                                ��\n";
    cout << "          �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�\n";
    cout << "\n\n\n                  ���� ���! \n\n";
    cout << "           �̵�Ű : ��, ��, ��, ��\n           ���� : SPACE BAR\n\n";
}

int main() {
    string player1Name, player2Name;

    printOmokArt();

    cout << "\n�÷��̾�1�� �̸��� �����ּ���: ";
    getline(cin, player1Name);

    cout << "�÷��̾�2�� �̸��� �����ּ���: ";
    getline(cin, player2Name);

    cout << "\nȯ���մϴ�, " << player1Name << "�԰� " << player2Name << "��!\n";
}
