#include <iostream>
#include <time.h>
using namespace std;

void print(char* ttt){
    for(int i = 0; i < 9; i+=3){
        cout << ttt[i] << " | " << ttt[i+1] << " | " << ttt[i+2] << endl;
    }
}

int main(){
    char tictactoe[9]; bool end = false, rd; int i;
    tictactoe[0] = '1'; tictactoe[1] = '2'; tictactoe[2] = '3';
    tictactoe[3] = '4'; tictactoe[4] = '5'; tictactoe[5] = '6';
    tictactoe[6] = '7'; tictactoe[7] = '8'; tictactoe[8] = '9';
    cout << "There are two players that'll play the game." << endl << "The players will choose a number from 1 to 9 to play as you see below." << endl;
    print(tictactoe); cout << "1st player: 5" << endl; tictactoe[4] = 'X';
    print(tictactoe); cout << "2nd player: 6" << endl; tictactoe[5] = 'O';
    print(tictactoe);
    srand((unsigned) time(NULL)); rd = rand() % 2; cout << "The ";
    if(rd == 1){
        cout << "1st";
    }else{
        cout << "2nd";
    }
    cout << " player will start the game." << endl << "The game is starting..." << endl;
    tictactoe[4] = '5'; tictactoe[5] = '6'; print(tictactoe);
    do{
        if(rd == 1){
            do{
                cout << "1st player: "; cin >> i; 
            }while(i > 9 || i < 1 || tictactoe[i-1] == 'X' || tictactoe[i-1] == 'O');
            if((i <= 9) && (i >= 1) && (tictactoe[i-1] != 'X') && (tictactoe[i-1] != 'O')){
                tictactoe[i-1] = 'X';
            }
        }else if(rd == 0){
            do{
                cout << "2nd player: "; cin >> i;
            }while(i > 9 || i < 1 || tictactoe[i-1] == 'X' || tictactoe[i-1] == 'O');
            if((i <= 9) && (i >= 1) && (tictactoe[i-1] != 'X') && (tictactoe[i-1] != 'O')){
                tictactoe[i-1] = 'O';
            }
        }
        for(i = 0; i < 9; i+=3){
            if(tictactoe[i] == tictactoe[i+1] && tictactoe[i] == tictactoe[i+2]){
                end = true;
            }
        }
        for(i = 0; i < 3; i++){
            if(tictactoe[i] == tictactoe[i+3] && tictactoe[i] == tictactoe[i+6]){
                end = true;
            }
        }
        if((tictactoe[0] == tictactoe[4] && tictactoe[0] == tictactoe[8]) || (tictactoe[2] == tictactoe[4] && tictactoe[2] == tictactoe[6])){
            end = true;
        }
        print(tictactoe);
        if((rd == 0) && (end == 0)){
            rd = true;
        }else if((rd == 1) && (end == 0)){
            rd = false;
        }
        if(end == 1){
            if(rd == 1){
                cout << "The 1st player won the game." << endl;
            }else if(rd == 0){
                cout << "The 2nd player won the game." << endl;
            }
        }
        if(tictactoe[0] != '1' && tictactoe[1] != '2' && tictactoe[2] != '3' && tictactoe[3] != '4' && tictactoe[4] != '5' && tictactoe[5] != '6' && tictactoe[6] != '7' && tictactoe[7] != '8' && tictactoe[8] != '9'){
            end = true;
            cout << "Nobody won the game." << endl;
        }
    }while(end == 0);
    std::ios_base::sync_with_stdio(false);
    std::cout << "Press enter to exit the game.";
    std::cin.get();
    return 0;
}