
/*********************************************************************
** Program name: SpaceRock.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 3:38 AM
** Description: Class specification file for SpaceRock. SpaceRock is
 *              derived from AsteroidObject class. It represents a
 *              medium-sized boulder on the surface of the asteroid.
 *              You can lift it up to check what's under it. There
 *              will either be an item or an alien creature waiting
 *              to attack you.
*********************************************************************/


#ifndef SPACE_ROCK_HPP
#define SPACE_ROCK_HPP

#include <iostream>
#include <string>
#include "AsteroidObject.hpp"
#include "Item.hpp"

class SpaceRock : public AsteroidObject
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
     *              default = SPACEROCK.
     *           string description: description of this space.
     *              default = see module header description.
     *           char icon: icon to visually represent this space.
     *              default = '#'.
    ** Returns:  None
    *********************************************************************/
    SpaceRock(int x = SPACE_CONFIG_LT[SPACEROCK].x_default,
                int y = SPACE_CONFIG_LT[SPACEROCK].y_default,
                SpaceType type = SPACE_CONFIG_LT[SPACEROCK].type_default,
                std::string description = SPACE_CONFIG_LT[SPACEROCK].description_default,
                char icon = SPACE_CONFIG_LT[SPACEROCK].icon_default);


    /********************************************************************
    ** Function: interact: Prints the description of the space rock. Then
     *              asks the user if they want to check under the rock
     *              and checks if there is anything there by calling the
     *              base AsteroidObject's interact function.
    ** Params:   Human * traveler: Pointer to human object in which to
     *              interact with this space. Used to deduct health
     *              points if attacked, or moves item into your inventory
     *              if treasure is found.
    ** Returns:  bool: true ends the game.
    *********************************************************************/
    virtual bool interact(Human *traveler = nullptr) override;

};

#endif
