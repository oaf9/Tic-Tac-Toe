#ifndef person_h
#define person_h
#include<string>
#include <stdio.h> //idk what this does but it was here when I made the file


class Person
{
private:
    //private variables
    std :: string name;  // persons name
    int score;   // their score
    char mark; // their mark (i.e. X or O)
    
public:
    Person(std :: string name, int score, char mark) : name(name), score(score), mark(mark){};
    //only one constructor, since the user can't declare players in the program, we don't need to worry about defautl constructors.
    

    // the member functions (descriptions in person.cpp)
    
    void change_score(int y);
    int get_score() const;
    char get_mark () const;
    std :: string get_name() const;
    void change_name(const std:: string& y);
    void change_mark(char x);
    
};




#endif /* person_hpp */
