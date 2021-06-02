#include <iostream>
#include <vector>
#include "ttt_functions.h"

using namespace std;
vector<string> board{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
int player_choice = 0;
int player = 1;

void introduction(){
    cout << "=========================================\n";
    cout << "Welcome to Tic Tac Toe!\n";
    cout << "=========================================\n";

    cout << "Player 1's symbol = X\n";
    cout << "Player 2's symbol = O\n";
    cout << "This is your grid: \n";

    std::cout << "     |     |      \n";
    std::cout << "  1  |  2  |  3   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  4  |  5  |  6   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  7  |  8  |  9   \n";
    std::cout << "     |     |      \n\n";
}


void board_out(){
    cout << "\n";
    cout << "         |     |\n";
    cout << "      " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    cout << "    _____|_____|_____\n";
    cout << "         |     |\n";
    cout << "      " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    cout << "    _____|_____|_____\n";
    cout << "         |     |\n";
    cout << "      " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "         |     |\n";
}



void set_choice(){
    cout << "Player " << player << "'s turn. Please enter a number between 1 to 9.\n";
    while(!(cin >> player_choice)){
          cin.clear();
          cin.ignore();

          cout << "\n";
    }
    while(board[player_choice - 1] != "1" && board[player_choice - 1] != "2" && board[player_choice - 1] != "3" && board[player_choice - 1] != "4" && board[player_choice - 1] != "5" && board[player_choice - 1] != "6" && board[player_choice - 1] != "7" && board[player_choice - 1] != "8" && board[player_choice - 1] != "9" && board[player_choice - 1] != "X" && board[player_choice - 1] != "O"){
        cout << "Invalid input, try again.\n";
        cin >> player_choice;

        cout << "n";
    }
}


void player_change(){
    if(player == 1){
        player++;
    } else{
        player--;
    }
}


void board_update(){
    if(player == 1){
        board[player_choice - 1] = "X";
    } else{
        board[player_choice - 1] = "O";
    }
}


bool full(){
    bool taken = true;
    for(int i = 0; i < 9; i++){
        if(board[i] != "X" && board[i] != "O"){
            taken = false;

    }
    }
    return taken;
}


bool player1_won(){
    if(board[0] == "X" && board[1] == "X" && board[2] == "X"){
        return true;
    } else if(board[3] == "X" && board[4] == "X" && board[5] == "X"){
        return true;
    } else if(board[6] == "X" && board[7] == "X" && board[8] == "X"){
        return true;
    }
   else if(board[0] == "X" && board[3] == "X" && board[6] == "X"){
        return true;
    } else if(board[1] == "X" && board[4] == "X" && board[7] == "X"){
        return true;
    } else if(board[2] == "X" && board[5] == "X" && board[8] == "X"){
        return true;
    }
   else if(board[0] == "X" && board[4] == "X" && board[8] == "X"){
        return true;
    } else if(board[2] == "X" && board[4] == "X" && board[6] == "X"){
        return true;
    } else{
        return false;
    }
}


bool player2_won(){
    if(board[0] == "O" && board[1] == "O" && board[2] == "O"){
        return true;
    } else if(board[3] == "O" && board[4] == "O" && board[5] == "O"){
        return true;
    } else if(board[6] == "O" && board[7] == "O" && board[8] == "O"){
        return true;
    }
   else if(board[0] == "O" && board[3] == "O" && board[6] == "O"){
        return true;
    } else if(board[1] == "O" && board[4] == "O" && board[7] == "O"){
        return true;
    } else if(board[2] == "X" && board[5] == "X" && board[8] == "X"){
        return true;
    }
   else if(board[0] == "O" && board[4] == "O" && board[8] == "O"){
        return true;
    } else if(board[2] == "O" && board[4] == "O" && board[6] == "O"){
        return true;
    } else{
        return false;
    }
}


void end_game(){
    if(full() && !player1_won() && !player2_won()){
        cout << "Game Over! It's a tie.";
    } else if(player1_won()){
        cout << "Game Over. Player 1 (X) is the winner!";
    } else if(player2_won()){
        cout << "Game Over. Player 2 (O) is the winner!";
    }
}





