
/*********************************************************************
** Program name: Crater.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 2:28 AM
** Description: Class specification file for Crater. Crater is
 *              derived from AsteroidObject class. It represents a
 *              large, bowl-shaped hole on the surface of the
 *              asteroid. You can jump in if you want. When you jump
 *              in, you can search the crater. There will either be
 *              an item or an alien creature waiting to attack you.
*********************************************************************/


#ifndef CRATER_HPP
#define CRATER_HPP

#include <iostream>
#include <string>
#include "AsteroidObject.hpp"
#include "Item.hpp"

class Crater : public AsteroidObject
{
public:

    /********************************************************************
    ** Function: Constructor/default: Sets coordinates, type, description
     *              and icon. Sets treasure, has alien, and alien name to
     *              defaults via the AsteroidObject constructor.
    ** Params:   int x: x-coordinate of this space.
     *              default = 0.
     *           int y: y-coordinate of this space.
     *              default = 0.
     *           SpaceType type: type of this space.
     *              default = CRATER.
     *           string description: description of this space.
     *              default = see module header description.
     *           char icon: icon to visually represent this space.
     *              default = 'O'.
    ** Returns:  None
    *********************************************************************/
    Crater(int x = SPACE_CONFIG_LT[CRATER].x_default,
            int y = SPACE_CONFIG_LT[CRATER].y_default,
            SpaceType type = SPACE_CONFIG_LT[CRATER].type_default,
            std::string description = SPACE_CONFIG_LT[CRATER].description_default,
            char icon = SPACE_CONFIG_LT[CRATER].icon_default);


    /********************************************************************
    ** Function: interact: Prints the description of the crater. Then
     *              asks the user if they want to jump in the crater and
     *              checks if there is anything there by calling the base
     *              AsteroidObject's interact function.
    ** Params:   Human * traveler: Pointer to human object in which to
     *              interact with this space. Used to deduct health
     *              points if attacked, or moves item into your inventory
     *              if treasure is found.
    ** Returns:  bool: true ends the game.
    *********************************************************************/
    virtual bool interact(Human *traveler = nullptr) override;

};

#endif
