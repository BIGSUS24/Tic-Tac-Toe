#include<iostream>
#include <ctime>
using namespace std;

void Board(char *spaces);
void player(char *spaces, char Player);
void comp(char *spaces, char Comp);
bool Winner(char *spaces, char Player, char Comp);
bool tie(char *spaces);

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char Player = 'X';
    char Comp = 'O';
    bool run = true;
    Board(spaces);
    
    while (run) {
        player(spaces, Player);
        Board(spaces);
        
        if (Winner(spaces, Player, Comp)) {
            run = false;
            break;
        } else if (tie(spaces)) {
            run = false;
            break;
        }

        comp(spaces, Comp);
        Board(spaces);
        
        if (Winner(spaces, Player, Comp)) {
            run = false;
            break;
        } else if (tie(spaces)) {
            run = false;
            break;
        }
    }
    
    cout << "YOU ARE ASS\n";
}

void Board(char *spaces) {
    cout << '\n';
    cout << "       |       |       " << '\n';
    cout << "   " << spaces[0] << "   |   " << spaces[1] << "   |   " << spaces[2] << "   " << '\n';
    cout << "_______|_______|_______" << '\n';
    cout << "       |       |       " << '\n';
    cout << "   " << spaces[3] << "   |   " << spaces[4] << "   |   " << spaces[5] << "   " << '\n';
    cout << "_______|_______|_______" << '\n';
    cout << "       |       |       " << '\n';
    cout << "   " << spaces[6] << "   |   " << spaces[7] << "   |   " << spaces[8] << "   " << '\n';
    cout << "       |       |       " << '\n';
    cout << '\n';
}


void player(char *spaces, char Player) {
    int num;
    do {
        cout << "SELECT A PLACE TO MARK (1-9): ";
        cin >> num;
        num = num - 1;
        if (spaces[num] == ' ') {
            spaces[num] = Player;
            break;
        }
    } while (!(num >= 0 && num < 9));
}

void comp(char *spaces, char Comp) {
    int num;
    srand(time(NULL));
    while (true) {
        num = rand() % 9;
        if (spaces[num] == ' ') {
            spaces[num] = Comp;
            break;
        }
    }
}

bool Winner(char *spaces, char Player, char Comp) {
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
        spaces[0] == Player ? cout << "YOU WIN BRODIE\n" : cout << "YOU LOSE SPITS YOU YOU\n";
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
        spaces[3] == Player ? cout << "YOU WIN BRODIE\n" : cout << "YOU LOSE SPITS YOU YOU\n";
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
        spaces[6] == Player ? cout << "YOU WIN BRODIE\n" : cout << "YOU LOSE SPITS YOU YOU\n";
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
        spaces[0] == Player ? cout << "YOU WIN BRODIE\n" : cout << "YOU LOSE SPITS YOU YOU\n";
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
        spaces[1] == Player ? cout << "YOU WIN BRODIE\n" : cout << "YOU LOSE SPITS YOU YOU\n";
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
        spaces[2] == Player ? cout << "YOU WIN BRODIE\n" : cout << "YOU LOSE SPITS YOU YOU\n";
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
        spaces[0] == Player ? cout << "YOU WIN BRODIE\n" : cout << "YOU LOSE SPITS YOU YOU\n";
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
        spaces[2] == Player ? cout << "YOU WIN BRODIE\n" : cout << "YOU LOSE SPITS YOU YOU\n";
    else
        return false;
    
    return true;
}

bool tie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    cout << "ITS A TIE DUMBASS\n";
    return true;
}
