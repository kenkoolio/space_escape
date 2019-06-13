
/*********************************************************************
** Program name: Human.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 6:44 PM
** Description: Class specification file for Human. Human represents
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


#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "GameDefaults.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

class Human
{
private:
    int x_coord;
    int y_coord;
    int health;
    int oxygen;
    char icon;
    Inventory backpack;
    Menu menu;
    
public:
    
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
    Human(int x = 0, int y = 0, int health = 100, int oxygen = 100, char icon = '&');


    /********************************************************************
    ** Function: setHealth: Sets human's new health points.
    ** Params:   int value: new health value to set health to.
    ** Returns:  None
    *********************************************************************/
    void setHealth(int value);


    /********************************************************************
    ** Function: setOxygen: Sets human's new oxygen level.
    ** Params:   int value: new oxygen level to set oxygen to.
    ** Returns:  None
    *********************************************************************/
    void setOxygen(int value);


    /********************************************************************
    ** Function: setX: Sets this human's x-coordinate.
    ** Params:   int value: New x-coordinate.
    ** Returns:  None
    *********************************************************************/
    void setX(int value);


    /********************************************************************
    ** Function: setY: Sets this human's y-coordinate.
    ** Params:   int value: New y-coordinate.
    ** Returns:  None
    *********************************************************************/
    void setY(int value);


    /********************************************************************
    ** Function: getHealth: Returns health points.
    ** Params:   None
    ** Returns:  int: human's health points.
    *********************************************************************/
    int getHealth() const;


    /********************************************************************
    ** Function: getOxygen: Returns oxygen level.
    ** Params:   None
    ** Returns:  int: human's oxygen level.
    *********************************************************************/
    int getOxygen() const;


    /********************************************************************
    ** Function: getX: Returns x-coordinate.
    ** Params:   None
    ** Returns:  int: human's current x-coordinate.
    *********************************************************************/
    int getX() const;
    
    
    /********************************************************************
    ** Function: getY: Returns y-coordinate.
    ** Params:   None
    ** Returns:  int: human's current y-coordinate.
    *********************************************************************/
    int getY() const;


    /********************************************************************
    ** Function: getIcon: Returns human's icon character representation.
    ** Params:   None
    ** Returns:  char: human's icon character representation.
    *********************************************************************/
    char getIcon() const;


    /********************************************************************
    ** Function: getInventory: Returns pointer to human's inventory.
    ** Params:   None
    ** Returns:  const Inventory *: constant pointer to human's inventory.
    *********************************************************************/
    const Inventory *getInventory() const;


    /********************************************************************
    ** Function: viewInventory: Prints out the items in your inventory.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void viewInventory() const;


    /********************************************************************
    ** Function: selectItem: Accepts the user's choice of item to
     *              interact with. If the item is a ship part or
     *              plutonium ore, it will read the description. If the
     *              item is a health pack, it will read the description
     *              then ask if you want to use the health pack.
    ** Params:   int item_index: index of the item in your inventory.
    ** Returns:  None
    *********************************************************************/
    void selectItem(int item_index);


    /********************************************************************
    ** Function: addInventory: Adds an item to your inventory.
    ** Params:   Item * treasure: Item to add to your inventory.
    ** Returns:  None
    *********************************************************************/
    void addInventory(Item *treasure);


    /********************************************************************
    ** Function: useHealthPack: Adds 10 points to your health then
     *              removes the health pack from your inventory and
     *              deletes it.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void useHealthPack();

};

#endif
