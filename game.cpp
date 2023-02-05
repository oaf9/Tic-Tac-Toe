

#include "game.h"
#include <iostream>


/**
 this is a helper function: it takes a vector of ints, and an int, and tells you if the int is in the vector
 @param1 vec  our vector
 @param2 y   our int
 @return return_bool, true if the y was in vec,  false otherwise.
 */
bool is_in(const std :: vector<int>& vec, int y)
{
    bool return_bool = false;
    for(int i = 0; i < vec.size(); ++i)
        if(y == vec[i])
        {
            return_bool = true;
        }
    return return_bool;
}


/**
 Basically we want to alternate who goes first, so we essentially switch who player 1 and 2 are. but leave their marks
 @param1 first_player our first player
 @param2 second_player  our second player
 */
void player_swap(Person& first_player, Person& second_player)
{
    std :: string dum_string = first_player.get_name(); // create a dummy variable and swap names
    first_player.change_name(second_player.get_name());
    second_player.change_name(dum_string);
    
    int dum_score = first_player.get_score();           // create a dummy variable and swap scores
    first_player.change_score(second_player.get_score());
    second_player.change_score(dum_score);
}





/**
 move is a void  that takes a player, and two ints, and assigns the player a spot on the tic tac toe grid.
 @param1 x  the row number
 @param2 y   the culomn number.
 @param3  player the player who we are assigning to the point in the grid.
 */
void Game :: move(int x, int y, const Person& player)
{
    // basically we just check the x value, and then assign the appropriate spot based on the y value in our 1 dimensional grid vector.
    if(x == 1)
    {
        grid[y-1] = player.get_mark(); // enter the mark
    }
    if(x == 2)
    {
        grid[2 + y] = player.get_mark();
    }
    if(x == 3)
    {
        grid[5 + y] = player.get_mark();
    }
    
}



/**
 game is a pretty wild procedure : it bascally does 90% of the wor in this program and runs the games.
 */
void Game :: play_game()
{
    // explain how to move
    std :: cout << "When it is your turn, enter a row number followed by a space and a column number. \n";
    std :: cout << std :: endl; // looks neater
    
    
    for(int k = 0; k < number_of_games; ++k) //basically we're gonna repeat our game process how ever many times the user specified
    {
        std:: cout << "round  :" << k+1  << std:: endl;
        std:: cout << std:: endl;
        std :: cout << "     " << player1->get_name() << "(" << player1->get_mark() << ")" <<" - " << player2->get_name() << "(" << player2->get_mark() << ")\n";
        std:: cout << std:: endl;
        
    int i = 1; //for indexing the loop
    bool is_winner = false; //there might not be a winner
    Person winner = *player2; // player2 wins by default but we'll update it if necessary
    while(i <= 9) //the maximum number of moves in a game is 9
        
    {
        get_grid(); // print the empty grid so the user can visualize the first move
        if (i%2==0) //when i is even player 2 moves, and when i is odd player 1 moves
        {
            // instruct the player to move
            std :: cout << player2->get_name() << " (" << player2->get_mark()  << ") Mark location: ";
        }
        else
        {
            std :: cout << player1->get_name() << " (" << player1->get_mark()  << ") Mark location: ";
        }
        
        //declare the row column number, cin those numbers
        int x;
        int y;
        std :: cin >> x;
        std :: cin >> y;
        
        // this is important in case the user enters anythign that isnt a number: cin fails so we need to clear the buffer and tell the user to enter valid input
        if(std :: cin.fail())
        {
            std :: cin.clear();
            std :: cin.ignore( INT_MAX, '\n');
            std :: cout << "Invalid input: please enter numbers between 1 and 3" << std :: endl;
        }
        //next we need to check if the grid the user entered is taken: we use the is_in function through occuied
        else if( is_in(occupied, 10*x + y) == true)
        {
            std :: cout << "this square is already occupied: try again" << std :: endl;
        }
        
        //then we check that the numebrs the user entered are even valid coordinates:
        else if ((x<1) || (x>3) || y<1 || y>3)
        {
            std :: cout << "enter a valid coordinate" << std :: endl;
        }
        else if ((x<1) || (x>3) || y<1 || y>3)
        {
            std :: cout << "enter a valid coordinate" << std :: endl;
        }
        
        //if the imput is valid
        else if (i%2 == 0) //cheack which players turn it is
        {
            move(x,y, (*player2)); //use the move fucntion to add thier mark to the grid
            i+=1; //index the loop
            occupied.push_back(10*x +y); //add the grid to occupied so that it can't get used again
        }
        else
        {
            move(x,y, (*player1));
            i+=1;
            occupied.push_back(10*x + y);
        }
        
        
        //now we check to see if someone won
        
        
//3 down a column
        for( int i = 0; i <3; ++i) // 3 columns
            {
                if(grid[i] == grid[i+3] && grid[i] == grid[i+6] && grid[i]!=' ') //adding 3 so we are looking at the same column each time. if no one has entered in any of the columns, it will be true because the grid is initialied to ahve spaces. thats why we have to check grid[i]!= ' '
                    {
                        is_winner = true; // update is_winner
                        if(grid[i] == player1_mark) //update winner if it wasn't player2
                            {
                                winner = *player1;
                            }
            
                    }
            }
        
//3 down a row
        for( int i = 0; i < 9; i+=3) //this indexing is a bit weird but basically we want to check every sequence of 3 entries in grid
            {
                if(grid[i] == grid[i+1] && grid[i] == grid[i+2] && grid[i]!=' ' ) //check if they are the same and not a space
                    {
                        is_winner = true; // update is_winner
                        if(grid[i] == player1_mark)
                            {
                                winner = *player1; // update winner if it wasn't player2
                            }
         
                    }
            }
        
// checking the diagonals
        
        if(grid[0] == grid[4] && grid[4] == grid[8] && grid[0]!=' ')
            {
                is_winner = true; // update is_winner
                if(grid[4] == player1_mark)
                    {
                        winner = *player1; // update winner if it wasn't player2
                    }
            }
 
         if(grid[2] == grid[4] && grid[4] == grid[6] && grid[2]!=' ')
            {
                is_winner = true;
                if(grid[4] == player1_mark)
                    {
                        winner = *player1;
                    }
            }
 
        if(is_winner == true)
            {
                break; // if there was a winner, end the round. We don't want to keep playing out if someone already won
            }
    }
    
    
    if(is_winner == true)
    {
        get_grid(); // print the final grid
        std :: cout << winner.get_name() << " wins this round." <<  std :: endl;  //alert the user who won
            if(winner.get_mark() == player1->get_mark())
            {
                player1->change_score(player1->get_score() + 1);  // add 1 to the winners score
            }
            else
            {
                player2->change_score(player2->get_score() + 1);
            }
        }
    else
    {
        std :: cout << "It's a Tie!" <<  std :: endl;  // if no one won, print it was a tie
    }
        std :: cout << player1->get_name() << " : " << player1->get_score() << std :: endl; // print the players scores
        std :: cout << player2->get_name() << " : " << player2->get_score() << std :: endl;
    
    clear_grid(); // clear the grid for the next round
    clear_occupied(); //clear occupied for the next round
    
        std:: cout << std:: endl;
        
       player_swap(*player1, *player2);
        
    } // end the for loop the game is now over
    
    if(player1->get_score() > player2->get_score()) //determine who won the msot games or if it was a tie and alert the user
        {
            std :: cout << "Congratulations " << player1->get_name() << ". You won!\n";
        }
    else if(player1->get_score() < player2->get_score())
    {
        std :: cout << "Congratulations " << player2->get_name() << ". You won!\n";
    }
    else
    {
        std :: cout << "it was a tie!" << std :: endl;
    }
    
}
 



/**
 this procedure jsut prints the grid in a clean format  every time. not much innovative stuff happening here
 */
void Game :: get_grid() const
{
    std :: cout << "     1   " <<  "    2   " <<  "    3   "    << std :: endl;
    std :: cout << "         |       |       " << std :: endl;
    std :: cout << "1    " << grid[0] << "   |   " <<  grid[1] << "   |   " << grid[2] << std :: endl;
    std :: cout << "  _______|_______|_______" << std :: endl;
    std :: cout << "         |       |       " << std :: endl;
    std :: cout << "2    " << grid[3] << "   |   " <<  grid[4] << "   |   " << grid[5] << std :: endl;
    std :: cout << "  _______|_______|_______" << std :: endl;
    std :: cout << "         |       |       " << std :: endl;
    std :: cout << "3    " << grid[6] << "   |   " <<  grid[7] << "   |   " << grid[8] << std :: endl;
    std :: cout << "         |       |       " << std :: endl;
}

/**
 it becomes necessary to clear the grid after each round. This procedure does that
 */
void Game :: clear_grid()
    {
        for(int i = 0; i < grid.size(); ++i) // for each entry in grid
            {
                grid[i] = ' '; // update it to the space char
            }
    }



/**
 it becomes necessary to clear occupied  after each round. This procedure does that
 */
void Game :: clear_occupied()
{
    for(size_t i = occupied.size(); i>0; --i) //from the end of occupied to zero
            {
                occupied.pop_back(); // truncate the last entry of occupied
            }
    }










