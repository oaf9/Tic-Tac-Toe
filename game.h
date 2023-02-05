
#ifndef game_h
#define game_h
#include<vector>
#include <stdio.h>
#include "person.h"



class Game
{
   
private:
    
    std :: vector <int> occupied {}; // if the user chooses a spot on the grid (say i j), this vector stores the number 10*i + j, this allows us to keep track of which spots on the grid are already used.
    Person *player1; //pointers to our players
    Person *player2;
    
    int number_of_games;  //numebr of games desired
    char player1_mark = 'X'; //marks for players
    char player2_mark = 'O';
    
    //the grid basically represents the entire matrix, and it is initialized to store spaces.
                          //  0   1   2   3   4   5   6   7   8
    std :: vector<char> grid{' ',' ',' ',' ',' ',' ',' ',' ',' '};
                           // 11   12   13   21   22   23   31   32   33
    
public:
    
    Game(Person *x, Person *y, int num): player1(x), player2(y), number_of_games(num){};
    //only one constructor, since the user can't declare the game in the program, we don't need to worry about default constructors.
    
    //function descriptions in game.cpp :)
    void move(int x, int y, const Person& player);
    void play_game();
    void get_grid() const;
    void clear_grid();
    void clear_occupied();
};






#endif /* game_hpp */
