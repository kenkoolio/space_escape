
/*********************************************************************
** Program name: Human.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 6:44 PM
** Description: Class implementation file for Human. Human represents
 *              a race of species that originates from the terrestrial
 *              planet Earth. You are a human. Humans have a certain
 *              level of health and oxygen requirements that must be
 *              met or else they die. You, as a human, are the
 *              protagonist in our Space Escape game, where you can
 *              move around the asteroid, which is the game board,
 *              to collect resources to fix your rocket ship and
 *              escape to safety. If you run out of health or oxygen,
 *              you will die. Humans are also capable of carrying
 *              items with them as part of their inventory.
*********************************************************************/


#include "Human.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/********************************************************************
** Function: Constructor/default: Creates a default human instance
 *              and initializes data members.
** Params:   int x: x-coordinate of human.
 *              default = 0.
 *           int y: y-coordinate of human.
 *              default = 0.
 *           int health: health points of human.
 *              default = 100.
 *           int oxygen: oxygen level of human.
 *              default = 100.
 *           char icon: character representation of human.
 *              default = '&'.
** Returns:  None
*********************************************************************/
Human::Human(int x, int y, int health, int oxygen, char icon)
        : x_coord(x), y_coord(y), health(health), oxygen(oxygen), icon(icon)
{}


/********************************************************************
** Function: setHealth: Sets human's new health points.
** Params:   int value: new health value to set health to.
** Returns:  None
*********************************************************************/
void Human::setHealth(int value)
{
    health = value;
}


/********************************************************************
** Function: setOxygen: Sets human's new oxygen level.
** Params:   int value: new oxygen level to set oxygen to.
** Returns:  None
*********************************************************************/
void Human::setOxygen(int value)
{
    oxygen = value;
}


/********************************************************************
** Function: setX: Sets this human's x-coordinate.
** Params:   int value: New x-coordinate.
** Returns:  None
*********************************************************************/
void Human::setX(int value)
{
    x_coord = value;
}


/********************************************************************
** Function: setY: Sets this human's y-coordinate.
** Params:   int value: New y-coordinate.
** Returns:  None
*********************************************************************/
void Human::setY(int value)
{
    y_coord = value;
}


/********************************************************************
** Function: getHealth: Returns health points.
** Params:   None
** Returns:  int: human's health points.
*********************************************************************/
int Human::getHealth() const
{
    return health;
}


/********************************************************************
** Function: getOxygen: Returns oxygen level.
** Params:   None
** Returns:  int: human's oxygen level.
*********************************************************************/
int Human::getOxygen() const
{
    return oxygen;
}


/********************************************************************
** Function: getX: Returns x-coordinate.
** Params:   None
** Returns:  int: human's current x-coordinate.
*********************************************************************/
int Human::getX() const
{
    return x_coord;
}


/********************************************************************
** Function: getY: Returns y-coordinate.
** Params:   None
** Returns:  int: human's current y-coordinate.
*********************************************************************/
int Human::getY() const
{
    return y_coord;
}


/********************************************************************
** Function: getIcon: Returns human's icon character representation.
** Params:   None
** Returns:  char: human's icon character representation.
*********************************************************************/
char Human::getIcon() const
{
    return icon;
}


/********************************************************************
** Function: getInventory: Returns pointer to human's inventory.
** Params:   None
** Returns:  const Inventory *: constant pointer to human's inventory.
*********************************************************************/
const Inventory *Human::getInventory() const
{
    return &backpack;
}


/********************************************************************
** Function: viewInventory: Prints out the items in your inventory.
** Params:   None
** Returns:  None
*********************************************************************/
void Human::viewInventory() const
{
    backpack.print();
}


/********************************************************************
** Function: selectItem: Accepts the user's choice of item to
 *              interact with. If the item is a ship part or
 *              plutonium ore, it will read the description. If the
 *              item is a health pack, it will read the description
 *              then ask if you want to use the health pack.
** Params:   int item_index: index of the item in your inventory.
** Returns:  None
*********************************************************************/
void Human::selectItem(int item_index)
{
    //find item
    Item *selected_item = backpack.find(item_index);

    if (selected_item)
    {
        //print item description
        menu.formatPrompt(selected_item->getDesc());

        //if item is a health pack, ask if use wants to use it
        if (selected_item->getType() == HEALTHPACK)
        {
            const string USE_HEALTH_PACK_PROMPT =
                    "Do you want to use the health pack?";

            //if user wants to use it
            if (menu.confirm(USE_HEALTH_PACK_PROMPT) == Menu::YES)
            {
                useHealthPack();
            }
        }
    }
    else
    {
        cout << "Error: item not found" << endl;
    }
}


/********************************************************************
** Function: addInventory: Adds an item to your inventory.
** Params:   Item * treasure: Item to add to your inventory.
** Returns:  None
*********************************************************************/
void Human::addInventory(Item *treasure)
{
    if (treasure)
    {
        backpack.push(treasure);
    }
}


/********************************************************************
** Function: useHealthPack: Adds 10 points to your health then
 *              removes the health pack from your inventory and
 *              deletes it.
** Params:   None
** Returns:  None
*********************************************************************/
void Human::useHealthPack()
{
    //add 10 health points
    const int RESTORE_POINTS = 10;
    setHealth(getHealth() + RESTORE_POINTS);

    //print that you restored 10 health points
    menu.formatPrompt
    ("You recovered " + std::to_string(RESTORE_POINTS) + " health points.");

    //remove health pack from inventory and delete it,
    // health packs are at the front of the inventory.
    backpack.pop();
}
