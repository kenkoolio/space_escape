
/*********************************************************************
** Program name: AsteroidObject.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 12:13 AM
** Description: Class specification file for AsteroidObject.
 *              AsteroidObject is derived from Space class. It is an
 *              abstract base that that represents a landmark on the
 *              surface of the asteroid. There will either be an item
 *              or an alien creature waiting to attack you.
*********************************************************************/


#ifndef ASTEROID_OBJECT_HPP
#define ASTEROID_OBJECT_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include "Item.hpp"

class AsteroidObject : public Space
{
protected:
    Item *treasure;
    bool has_alien;
    std::string alien;

public:

    /********************************************************************
    ** Function: Constructor/default: Sets coordinates, type, description
     *              and icon. Sets treasure, has alien, and alien to
     *              defaults.
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
    ** Returns:  None
    *********************************************************************/
    AsteroidObject(int x = SPACE_CONFIG_LT[DEFAULTSPACE].x_default,
                    int y = SPACE_CONFIG_LT[DEFAULTSPACE].y_default,
                    SpaceType type = SPACE_CONFIG_LT[DEFAULTSPACE].type_default,
                    std::string description = SPACE_CONFIG_LT[DEFAULTSPACE].description_default,
                    char icon = SPACE_CONFIG_LT[DEFAULTSPACE].icon_default);


    /********************************************************************
    ** Function: interact: Pure virtual function. Checks if this space
     *              has an alien. If so, the alien will attack you
     *              causing you to lose 10 health points then run away.
     *              Then checks for treasure. If there is treasure, moves
     *              the item into the traveler's inventory. If there's
     *              nothing there, prints that there is nothing there.
    ** Params:   Human * traveler: Pointer to human object in which to
     *              interact with this space. Used to deduct health
     *              points if attacked, or moves item into your inventory
     *              if treasure is found.
    ** Returns:  bool: true ends the game.
    *********************************************************************/
    virtual bool interact(Human *traveler = nullptr) = 0;


    /********************************************************************
    ** Function: hasTreasure: Checks if this space has a hidden item.
     *              This function is also used in the destructor for the
     *              Game class to deallocate stray item pointers.
    ** Params:   None
    ** Returns:  bool: True if this space has an item, false otherwise.
    *********************************************************************/
    bool hasTreasure() const;


    /********************************************************************
    ** Function: getTreasure: Returns pointer to treasure item.
     *              Sets treasure to nullptr.
    ** Params:   None
    ** Returns:  Item *: Pointer to treasure item.
    *********************************************************************/
    Item *getTreasure();


    /********************************************************************
    ** Function: setTreasure: Sets an item pointer to treasure to hide
     *              an item in this space.
    ** Params:   Item * treasure: Pointer to item to hide in this space.
    ** Returns:  None
    *********************************************************************/
    void setTreasure(Item *treasure);


    /********************************************************************
    ** Function: setAlien: Sets the alien's description and has_alien
     *              flag to true.
    ** Params:   string description: Description of the alien.
    ** Returns:  None
    *********************************************************************/
    void setAlien(std::string description);

};

#endif
