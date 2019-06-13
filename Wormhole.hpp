
/*********************************************************************
** Program name: Wormhole.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 5:47 PM
** Description: Class specification file for Wormhole. Wormhole is
 *              derived from Space class. It represents a physical
 *              anomaly that is a rift in the fabric of time and
 *              space. You can walk through the wormhole if you want.
 *              It will teleport you to a random location on the
 *              asteroid.
*********************************************************************/


#ifndef WORMHOLE_HPP
#define WORMHOLE_HPP

#include <iostream>
#include <string>
#include "MyRandom.hpp"
#include "Space.hpp"

class Wormhole : public Space
{
public:

    /********************************************************************
    ** Function: Constructor/default: Sets coordinates, type, description
     *              and icon. Seeds the random number generator.
    ** Params:   int x: x-coordinate of this space.
     *              default = 0.
     *           int y: y-coordinate of this space.
     *              default = 0.
     *           SpaceType type: type of this space.
     *              default = WORMHOLE.
     *           string description: description of this space.
     *              default = see module header description.
     *           char icon: icon to visually represent this space.
     *              default = '@'.
    ** Returns:  None
    *********************************************************************/
    Wormhole(int x = SPACE_CONFIG_LT[WORMHOLE].x_default,
            int y = SPACE_CONFIG_LT[WORMHOLE].y_default,
            SpaceType type = SPACE_CONFIG_LT[WORMHOLE].type_default,
            std::string description = SPACE_CONFIG_LT[WORMHOLE].description_default,
            char icon = SPACE_CONFIG_LT[WORMHOLE].icon_default);


    /********************************************************************
    ** Function: interact: Prints the description of the worm hole. Asks
     *              the user if they want to walk through the worm hole
     *              and get teleported. Calculates random coordinates to
     *              teleport you to. Uses the traveler pointer to set
     *              your new coordinates on the asteroid.
    ** Params:   Human * traveler: Pointer to human object in which to
     *              interact with this space. Used to check your
     *              inventory.
    ** Returns:  bool: true ends the game.
    *********************************************************************/
    virtual bool interact(Human *traveler = nullptr) override;

};

#endif
