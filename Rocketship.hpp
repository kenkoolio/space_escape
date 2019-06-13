
/********************************************************************* 
** Program name: Rocketship.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 06, 2019 at 10:56 PM
** Description: Class specification file for Rocketship. Rocketship
 *              is derived from Space class. It represents your
 *              vessel that carries you across the vast emptiness of
 *              space. Your rocket ship is a beautiful, large,
 *              crimson red, cone-shaped contraption that your father
 *              bought for your 18th birthday. It has 4 rocket
 *              engines, a kitchen, dry bath, sleep compartment, and
 *              warp drive capable of travelling millions of
 *              light-years in the blink of an eye. It is powered by
 *              plutonium ore.
*********************************************************************/


#ifndef ROCKETSHIP_HPP
#define ROCKETSHIP_HPP

#include <iostream>
#include <string>
#include "Space.hpp"
#include "Inventory.hpp"

class Rocketship : public Space
{
public:

    /********************************************************************
    ** Function: Constructor/default: Sets coordinates, type, description
     *              and icon.
    ** Params:   int x: x-coordinate of this space.
     *              default = 0.
     *           int y: y-coordinate of this space.
     *              default = 0.
     *           SpaceType type: type of this space.
     *              default = ROCKETSHIP.
     *           string description: description of this space.
     *              default = see module header description.
     *           char icon: icon to visually represent this space.
     *              default = '^'.
    ** Returns:  None
    *********************************************************************/
    Rocketship(int x = SPACE_CONFIG_LT[ROCKETSHIP].x_default,
            int y = SPACE_CONFIG_LT[ROCKETSHIP].y_default,
            SpaceType type = SPACE_CONFIG_LT[ROCKETSHIP].type_default,
            std::string description = SPACE_CONFIG_LT[ROCKETSHIP].description_default,
            char icon = SPACE_CONFIG_LT[ROCKETSHIP].icon_default);


    /********************************************************************
    ** Function: interact: Provides a menu to fix the ship or check out
     *              the ship. If you choose to fix the ship, the game
     *              checks if you have enough material. If so, it fixes
     *              the rocket and blasts off, ending the game. If not,
     *              it will tell you that you don't have enough resources
     *              to fix the ship yet. If you choose to check out the
     *              ship, it prints the description of the ship.
    ** Params:   Human * traveler: Pointer to human object in which to
     *              interact with this space. Used to check your
     *              inventory.
    ** Returns:  bool: true ends the game.
    *********************************************************************/
    virtual bool interact(Human *traveler = nullptr) override;


    /********************************************************************
    ** Function: fixShip: Attempts to fix the rocket ship and leave to
     *              complete the game. Checks your inventory to see if
     *              you have enough resources.
    ** Params:   const Inventory * resources: Constant pointer to your
     *              inventory, used to check if you have all the required
     *              material.
    ** Returns:  bool: true ends the game.
    *********************************************************************/
    bool fixShip(const Inventory *resources);

};

#endif
