
/*********************************************************************
** Program name: Space.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 06, 2019 at 8:24 PM
** Description: Class implementation file for Space. Space is an
 *              abstract base class. It represents a tile space on
 *              the game board, which represents the surface of the
 *              asteroid you crash landed on. Spaces are linked
 *              together by pointers to other spaces to the top,
 *              right, bottom, and left of the current space. A space
 *              also contains information about its coordinates on the
 *              game board.
*********************************************************************/


#include "Space.hpp"

using std::string;

/********************************************************************
** Function: Constructor/default: Initializes data members. Space is
 *              an abstract base class so it can't be instantiated.
** Params:   int x: x-coordinate of this space.
 *              default = 0.
 *           int y: y-coordinate of this space.
 *              default = 0.
 *           SpaceType type: type of this space.
 *              default = GROUND.
 *           string description: description of this space.
 *              default = "".
 *           char icon: icon to visually represent this space.
 *              default = '_'.
 *           Space *top: pointer to space to the top of this space.
 *              default = nullptr.
 *           Space *right: pointer to space to the right of this space.
 *              default = nullptr.
 *           Space *bottom: pointer to the space to the bottom of this
 *              space.
 *              default = nullptr.
 *           Space *left: pointer to the space to the left of this space.
 *              default = nullptr.
** Returns:  None
*********************************************************************/
Space::Space(int x, int y, SpaceType type, string description, char icon,
      Space *top, Space *right, Space *bottom, Space *left)
      : x_coord(x), y_coord(y), type(type), description(description), icon(icon),
        top(top), right(right), bottom(bottom), left(left)
{}


/********************************************************************
** Function: setTop: Sets top pointer to space to the top of this
 *              space.
** Params:   Space *value: pointer to space to the top of this space.
** Returns:  None
*********************************************************************/
void Space::setTop(Space *value)
{
    top = value;
}


/********************************************************************
** Function: setRight: Sets right pointer to space to the right of
 *              this space.
** Params:   Space *value: pointer to space to the right of this space.
** Returns:  None
*********************************************************************/
void Space::setRight(Space *value)
{
    right = value;
}


/********************************************************************
** Function: setBottom: Sets bottom pointer to space to the bottom of
 *              this space.
** Params:   Space *value: pointer to space to the bottom of this
 *              space.
** Returns:  None
*********************************************************************/
void Space::setBottom(Space *value)
{
    bottom = value;
}


/********************************************************************
** Function: setLeft: Sets left pointer to space to the left of this
 *              space.
** Params:   Space *value: pointer to space to the left of this space.
** Returns:  None
*********************************************************************/
void Space::setLeft(Space *value)
{
    left = value;
}


/********************************************************************
** Function: getTop: Returns pointer to space object to the top of
 *              this space.
** Params:   None
** Returns:  Space *: pointer to space to the top of this space.
*********************************************************************/
Space *Space::getTop() const
{
    return top;
}


/********************************************************************
** Function: getRight: Returns pointer to space object to the right
 *              of this space.
** Params:   None
** Returns:  Space *: pointer to space to the right of this space.
*********************************************************************/
Space *Space::getRight() const
{
    return right;
}


/********************************************************************
** Function: getBottom: Returns pointer to space object to the bottom
 *              of this space.
** Params:   None
** Returns:  Space *: pointer to space to the bottom of this space.
*********************************************************************/
Space *Space::getBottom() const
{
    return bottom;
}


/********************************************************************
** Function: getLeft: Returns pointer to space object to the left of
 *              this space.
** Params:   None
** Returns:  Space *: pointer to space to the left of this space.
*********************************************************************/
Space *Space::getLeft() const
{
    return left;
}


/********************************************************************
** Function: getX: Returns x-coordinate of this space.
** Params:   None
** Returns:  int: x-coordinate of this space.
*********************************************************************/
int Space::getX() const
{
    return x_coord;
}


/********************************************************************
** Function: getY: Returns y-coordinate of this space.
** Params:   None
** Returns:  int: y-coordinate of this space.
*********************************************************************/
int Space::getY() const
{
    return y_coord;
}


/********************************************************************
** Function: getType: Returns type of this space.
** Params:   None
** Returns:  SpaceType: type of this space.
*********************************************************************/
SpaceType Space::getType() const
{
    return type;
}


/********************************************************************
** Function: getDesc: Returns description of this space.
** Params:   None
** Returns:  string: description of this space.
*********************************************************************/
string Space::getDesc() const
{
    return description;
}


/********************************************************************
** Function: getIcon: Returns icon character of this space.
** Params:   None
** Returns:  char: icon character of this space.
*********************************************************************/
char Space::getIcon() const
{
    return icon;
}
