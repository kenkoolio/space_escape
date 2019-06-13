
/********************************************************************* 
** Program name: Space.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 06, 2019 at 8:24 PM
** Description: Class specification file for Space. Space is an
 *              abstract base class. It represents a tile space on
 *              the game board, which represents the surface of the
 *              asteroid you crash landed on. Spaces are linked
 *              together by pointers to other spaces to the top,
 *              right, bottom, and left of the current space. A space
 *              also contains information about its coordinates on the
 *              game board.
*********************************************************************/


#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include "Menu.hpp"
#include "GameDefaults.hpp"
#include "Human.hpp"

class Space
{
protected:
    const int x_coord;
    const int y_coord;
    const SpaceType type;
    const std::string description;
    const char icon;
    Space *top;
    Space *right;
    Space *bottom;
    Space *left;
    Menu menu;

public:

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
    Space(int x = SPACE_CONFIG_LT[DEFAULTSPACE].x_default,
            int y = SPACE_CONFIG_LT[DEFAULTSPACE].y_default,
            SpaceType type = SPACE_CONFIG_LT[DEFAULTSPACE].type_default,
            std::string description = SPACE_CONFIG_LT[DEFAULTSPACE].description_default,
            char icon = SPACE_CONFIG_LT[DEFAULTSPACE].icon_default,
            Space *top = nullptr, Space *right = nullptr,
            Space *bottom = nullptr, Space *left = nullptr);


    /********************************************************************
    ** Function: Destructor: Virtual destructor to avoid unexpected
     *              behavior because this is an abstract base class.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    virtual ~Space() {}


    /********************************************************************
    ** Function: interact: Pure virtual function for derived spaces to
     *              define.
    ** Params:   Human * traveler: pointer to human object in which to
     *              interact with this space.
     *              default = nullptr.
    ** Returns:  bool: true ends the game.
    *********************************************************************/
    virtual bool interact(Human *traveler = nullptr) = 0;


    /********************************************************************
    ** Function: setTop: Sets top pointer to space to the top of this
     *              space.
    ** Params:   Space *value: pointer to space to the top of this space.
    ** Returns:  None
    *********************************************************************/
    void setTop(Space *value);


    /********************************************************************
    ** Function: setRight: Sets right pointer to space to the right of
     *              this space.
    ** Params:   Space *value: pointer to space to the right of this space.
    ** Returns:  None
    *********************************************************************/
    void setRight(Space *value);


    /********************************************************************
    ** Function: setBottom: Sets bottom pointer to space to the bottom of
     *              this space.
    ** Params:   Space *value: pointer to space to the bottom of this
     *              space.
    ** Returns:  None
    *********************************************************************/
    void setBottom(Space *value);


    /********************************************************************
    ** Function: setLeft: Sets left pointer to space to the left of this
     *              space.
    ** Params:   Space *value: pointer to space to the left of this space.
    ** Returns:  None
    *********************************************************************/
    void setLeft(Space *value);


    /********************************************************************
    ** Function: getTop: Returns pointer to space object to the top of
     *              this space.
    ** Params:   None
    ** Returns:  Space *: pointer to space to the top of this space.
    *********************************************************************/
    Space *getTop() const;


    /********************************************************************
    ** Function: getRight: Returns pointer to space object to the right
     *              of this space.
    ** Params:   None
    ** Returns:  Space *: pointer to space to the right of this space.
    *********************************************************************/
    Space *getRight() const;


    /********************************************************************
    ** Function: getBottom: Returns pointer to space object to the bottom
     *              of this space.
    ** Params:   None
    ** Returns:  Space *: pointer to space to the bottom of this space.
    *********************************************************************/
    Space *getBottom() const;


    /********************************************************************
    ** Function: getLeft: Returns pointer to space object to the left of
     *              this space.
    ** Params:   None
    ** Returns:  Space *: pointer to space to the left of this space.
    *********************************************************************/
    Space *getLeft() const;


    /********************************************************************
    ** Function: getX: Returns x-coordinate of this space.
    ** Params:   None
    ** Returns:  int: x-coordinate of this space.
    *********************************************************************/
    int getX() const;


    /********************************************************************
    ** Function: getY: Returns y-coordinate of this space.
    ** Params:   None
    ** Returns:  int: y-coordinate of this space.
    *********************************************************************/
    int getY() const;


    /********************************************************************
    ** Function: getType: Returns type of this space.
    ** Params:   None
    ** Returns:  SpaceType: type of this space.
    *********************************************************************/
    SpaceType getType() const;


    /********************************************************************
    ** Function: getDesc: Returns description of this space.
    ** Params:   None
    ** Returns:  string: description of this space.
    *********************************************************************/
    std::string getDesc() const;


    /********************************************************************
    ** Function: getIcon: Returns icon character of this space.
    ** Params:   None
    ** Returns:  char: icon character of this space.
    *********************************************************************/
    char getIcon() const;

};

#endif
