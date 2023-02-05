/*
 PIC 10B 1B, Homework 1
 Purpose: Tic-tac-toe game
 Author: Omar Afifi
 Date: 10/18/2021
 */
#include <iostream>
#include<vector>
#include<string>
#include "game.h" //including the game /person files
// using namespace std;




int main()
{

    //declaring strings for player names
    std :: string name_1;
    std :: string name_2;
    //asking user for names
    std :: cout << "Player 1 name = ";
    //cin the names
    std :: cin >> name_1;
    // std:: cout << std :: endl;
    std :: cout << "Player 2 name = ";
    std :: cin >> name_2;
    std :: cout << "    Tic-Tac-Toe    " <<  std :: endl;
    
    //decalring a first and second player
    Person Player1(name_1,0,'X');
    Person Player2(name_2,0,'O');
    
    // std :: cout << Player1.get_name() << "(" << Player1.get_mark() << ")" <<" - " << Player2.get_name() << "(" << Player2.get_mark() << ")\n";
    //declaring a new game object with our players
    Game new_game(&Player1, &Player2, 2) ;
    
    //playing the game
    new_game.play_game();
    
    
    
    
    return 0;
}








