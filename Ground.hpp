
/********************************************************************* 
** Program name: Ground.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 06, 2019 at 9:19 PM
** Description: Class specification file for Ground. Ground is derived
 *              from Space class. It represents the ground on the
 *              asteroid. The ground is dusty, and the gray dirt feels
 *              like a silky powder. There is nothing on the ground.
 *              Interacting with the ground returns the ground's
 *              description.
*********************************************************************/


#ifndef GROUND_HPP
#define GROUND_HPP

#include <iostream>
#include <string>
#include "Space.hpp"

class Ground : public Space
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
     *              default = GROUND.
     *           string description: description of this space.
     *              default = see module header description.
     *           char icon: icon to visually represent this space.
     *              default = '_'.
    ** Returns:  None
    *********************************************************************/
    Ground(int x = SPACE_CONFIG_LT[GROUND].x_default,
            int y = SPACE_CONFIG_LT[GROUND].y_default,
            SpaceType type = SPACE_CONFIG_LT[GROUND].type_default,
            std::string description = SPACE_CONFIG_LT[GROUND].description_default,
            char icon = SPACE_CONFIG_LT[GROUND].icon_default);


    /********************************************************************
    ** Function: interact: Prints description of the ground by calling
     *              getDesc.
    ** Params:   Human * traveler: Pointer to human object in which to
     *              interact with this space. The human will not interact
     *              with the ground.
     *              default = nullptr.
    ** Returns:  bool: true ends the game.
    *********************************************************************/
    virtual bool interact(Human *traveler = nullptr) override;

};

#endif
