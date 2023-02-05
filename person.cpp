#include "person.h"
#include<string>


//memeber function/procedures for person class


/**
 this procedure  changes the persons score by a number, y
 @param y the score increment
 */
void Person :: change_score(int y)
{
    score = y;
}
/**
 this function will return the persons mark (i.e. X or O)
 @return mark the persons mark
 */
char Person :: get_mark() const
{
    return mark;
}
/**
 this function will return the persons score
 @return score the persons score.
 */
int Person :: get_score() const
{
    return score;
}

/**
 this function will return the persons name
 @return name the persons name.
 */
std :: string Person :: get_name() const
{
    return name;
}
/*
void Person :: change_mark(char x)
{
    mark = x;
}
 */

/**
 this procedure  changes the persons name by to a new name, y
 @param y the new name
 */
void Person :: change_name(const std :: string& y)
{
    name = y;
}
