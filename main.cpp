#include <iostream>
#include "ttt_functions.h"
using namespace std;

int main()
{
    introduction();

    while(!full() && !player1_won() && !player2_won()){

        set_choice();
        board_update();
        player_change();
        board_out();
    }

    end_game();


}
