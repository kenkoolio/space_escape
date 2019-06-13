
/*********************************************************************
** Program name: Board.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 08, 2019 at 9:04 PM
** Description: Class specification file for Board. Board is the game
 *              board class in which to play the Space Escape game.
 *              It represents the surface of the asteroid, split into
 *              a 2D grid of pointers to Space objects. Each tile cell
 *              on the board is a type of derived Space. It could be
 *              a ground tile, a crater tile, a space rock tile, or
 *              a rocket ship tile. Each Space tile will have four
 *              pointers that link it to its adjacent neighboring
 *              tile.
*********************************************************************/


#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "Space.hpp"

class Board
{
private:
    int rows;
    int cols;
    Space ***board;

public:

    /********************************************************************
    ** Function: Constructor/default: Creates a Board instance,
     *              initializes data members, creates board arrays and
     *              sets all cells to nullptr.
    ** Params:   int rows: number of rows of the board.
     *              default = 0.
     *           int cols: number of columns of the board.
     *              default = 0.
    ** Returns:  None
    *********************************************************************/
    Board(int rows = 0, int cols = 0);


    /********************************************************************
    ** Function: Destructor: De-allocates all arrays of the 2D board
     *              array but does not de-allocate the space pointers.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    ~Board();


    /********************************************************************
    ** Function: linkSpaces: Links all spaces to their adjacent
     *              neighboring cell.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void linkSpaces();


    /********************************************************************
    ** Function: setSpace: Sets a cell to point to a Space object.
    ** Params:   int x: x-coordinate of space to set.
     *           int y: y-coordinate of space to set.
     *           Space *space: pointer to space object to add to cell.
    ** Returns:  None
    *********************************************************************/
    void setSpace(int x, int y, Space *space);


    /********************************************************************
    ** Function: getSpace: Returns a reference to a pointer to Space
     *              object pointed to by specified cell.
    ** Params:   int x: x-coordinate of space to get.
     *           int y: y-coordinate of space to get.
    ** Returns:  Space *&: reference to pointer to Space object to get.
    *********************************************************************/
    Space *&getSpace(int x, int y);


    /********************************************************************
    ** Function: getRows: Returns number of rows.
    ** Params:   None
    ** Returns:  int: number of rows.
    *********************************************************************/
    int getRows() const;


    /********************************************************************
    ** Function: getCols: Returns number of columns.
    ** Params:   None
    ** Returns:  int: number of columns.
    *********************************************************************/
    int getCols() const;


    /********************************************************************
    ** Function: print: Prints the icons of the space at each cell of
     *              the board.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void print() const;


    /********************************************************************
    ** Function: print(overloaded): Prints the icons of the space at each
     *              cell of the board and prints a special character at
     *              specified coordinates.
    ** Params:   int x: x-coordinate of special character to print.
     *           int y: y-coordinate of special character to print.
     *           char special_character: character icon of special
     *              character to print.
    ** Returns:  None
    *********************************************************************/
    void print(int x, int y, char special_character) const;

};

#endif
