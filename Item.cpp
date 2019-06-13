
/*********************************************************************
** Program name: Item.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 10:04 PM
** Description: Class implementation file for Item. Item represents
 *              objects/resources that you can use to aid you in your
 *              journey in the Space Escape game.
*********************************************************************/


#include "Item.hpp"

using std::string;

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
Item::Item(ItemType type, string name, string description)
        : type(type), name(name), description(description)
{}


/********************************************************************
** Function: getType: Returns the ItemType type of the item.
** Params:   None
** Returns:  ItemType: type of the item.
*********************************************************************/
ItemType Item::getType() const
{
    return type;
}


/********************************************************************
** Function: getName: Returns the name of the item.
** Params:   None
** Returns:  string: name of the item.
*********************************************************************/
string Item::getName() const
{
    return name;
}


/********************************************************************
** Function: getDesc: Returns the description of the item.
** Params:   None
** Returns:  string: description of the item.
*********************************************************************/
string Item::getDesc() const
{
    return description;
}
