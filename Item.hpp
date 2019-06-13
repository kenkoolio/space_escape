
/********************************************************************* 
** Program name: Item.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 10:04 PM
** Description: Class specification file for Item. Item represents
 *              objects/resources that you can use to aid you in your
 *              journey in the Space Escape game.
*********************************************************************/


#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "GameDefaults.hpp"

class Item
{
private:
    ItemType type;
    std::string name;
    std::string description;

public:

    /********************************************************************
    ** Function: Constructor/default: Creates an item instance and sets
     *              its traits.
    ** Params:   ItemType type: type of item.
     *              default = HEALTHPACK.
     *           string name: name of item.
     *              default = "".
     *           string description: description of item.
     *              default = "".
    ** Returns:  None
    *********************************************************************/
    Item(ItemType type = HEALTHPACK, std::string name = "", std::string description = "");


    /********************************************************************
    ** Function: getType: Returns the ItemType type of the item.
    ** Params:   None
    ** Returns:  ItemType: type of the item.
    *********************************************************************/
    ItemType getType() const;


    /********************************************************************
    ** Function: getName: Returns the name of the item.
    ** Params:   None
    ** Returns:  string: name of the item.
    *********************************************************************/
    std::string getName() const;


    /********************************************************************
    ** Function: getDesc: Returns the description of the item.
    ** Params:   None
    ** Returns:  string: description of the item.
    *********************************************************************/
    std::string getDesc() const;

};

#endif
