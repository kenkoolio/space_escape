
/*********************************************************************
** Program name: Board.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 08, 2019 at 9:04 PM
** Description: Class implementation file for Board. Board is the game
 *              board class in which to play the Space Escape game.
 *              It represents the surface of the asteroid, split into
 *              a 2D grid of pointers to Space objects. Each tile cell
 *              on the board is a type of derived Space. It could be
 *              a ground tile, a crater tile, a space rock tile, or
 *              a rocket ship tile. Each Space tile will have four
 *              pointers that link it to its adjacent neighboring
 *              tile.
*********************************************************************/


#include "Board.hpp"

using std::cout;
using std::endl;

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
Board::Board(int rows, int cols) : rows(rows), cols(cols)
{
    //make array of rows for the board
    board = new Space**[rows];

    //at each row, make an array of columns
    for (int i=0; i<rows; i++)
    {
        board[i] = new Space*[cols];
    }

    //set each cell in board to nullptr
    for (int y=0; y<rows; y++)
    {
        for (int x=0; x<cols; x++)
        {
            board[y][x] = nullptr;
        }
    }
}


/********************************************************************
** Function: Destructor: De-allocates all arrays of the 2D board
 *              array but does not de-allocate the space pointers.
** Params:   None
** Returns:  None
*********************************************************************/
Board::~Board()
{
    //loop through the board and delete each row array
    for (int i=0; i<rows; i++)
    {
        delete [] board[i];
    }

    //delete the main board array
    delete [] board;
}


/********************************************************************
** Function: linkSpaces: Links all spaces to their adjacent
 *              neighboring cell.
** Params:   None
** Returns:  None
*********************************************************************/
void Board::linkSpaces()
{
    //link tops
    for (int y=0; y<rows; y++)
    {
        for (int x=0; x<cols; x++)
        {
            //if not the first row, link the space's
            // top pointer to the space to the top
            if (y != 0)
            {
                board[y][x]->setTop(board[y-1][x]);
            }
        }
    }

    //link rights
    for (int y=0; y<rows; y++)
    {
        for (int x=0; x<cols; x++)
        {
            //if not the last column, link the space's
            // right pointer to the space to the right
            if (x != cols-1)
            {
                board[y][x]->setRight(board[y][x+1]);
            }
        }
    }

    //link bottoms
    for (int y=0; y<rows; y++)
    {
        for (int x=0; x<cols; x++)
        {
            //if not the last row, link the space's
            // bottom pointer to the space to the bottom
            if (y != rows-1)
            {
                board[y][x]->setBottom(board[y+1][x]);
            }
        }
    }

    //link lefts
    for (int y=0; y<rows; y++)
    {
        for (int x=0; x<cols; x++)
        {
            //if not the first column, link the space's
            // left pointer to the space to the left
            if (x != 0)
            {
                board[y][x]->setLeft(board[y][x-1]);
            }
        }
    }
}


/********************************************************************
** Function: setSpace: Sets a cell to point to a Space object.
** Params:   int x: x-coordinate of space to set.
 *           int y: y-coordinate of space to set.
 *           Space *space: pointer to space object to add to cell.
** Returns:  None
*********************************************************************/
void Board::setSpace(int x, int y, Space *space)
{
    board[y][x] = space;
}


/********************************************************************
** Function: getSpace: Returns a reference to a pointer to Space
 *              object pointed to by specified cell.
** Params:   int x: x-coordinate of space to get.
 *           int y: y-coordinate of space to get.
** Returns:  Space *&: reference to pointer to Space object to get.
*********************************************************************/
Space *&Board::getSpace(int x, int y)
{
    return board[y][x];
}


/********************************************************************
** Function: getRows: Returns number of rows.
** Params:   None
** Returns:  int: number of rows.
*********************************************************************/
int Board::getRows() const
{
    return rows;
}


/********************************************************************
** Function: getCols: Returns number of columns.
** Params:   None
** Returns:  int: number of columns.
*********************************************************************/
int Board::getCols() const
{
    return cols;
}


/********************************************************************
** Function: print: Prints the icons of the space at each cell of
 *              the board.
** Params:   None
** Returns:  None
*********************************************************************/
void Board::print() const
{
    //print top border
    for (int i=0; i<cols; i++)
    {
        cout << " _";
    }
    cout << endl;

    //print board contents
    for (int y=0; y<rows; y++)
    {
        for (int x=0; x<cols; x++)
        {
            //print left cell border
            cout << "|";

            //print space icon
            cout << board[y][x]->getIcon();
        }
        //print right cell border
        cout << "|";
        cout << endl;
    }
}


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
void Board::print(int x, int y, char special_character) const
{
    //print top border
    for (int i=0; i<cols; i++)
    {
        cout << " _";
    }
    cout << endl;

    //print board contents
    for (int i=0; i<rows; i++)
    {
        for (int k=0; k<cols; k++)
        {
            //print left cell border
            cout << "|";

            //print space icon, unless the coordinates
            // match the special character coordinates
            if (i == y && k == x)
            {
                cout << special_character;
            }
            else
            {
                cout << board[i][k]->getIcon();
            }
        }
        //print right cell border
        cout << "|";
        cout << endl;
    }
}
