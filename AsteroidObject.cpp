
/*********************************************************************
** Program name: AsteroidObject.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 12:13 AM
** Description: Class implementation file for AsteroidObject.
 *              AsteroidObject is derived from Space class. It is an
 *              abstract base that that represents a landmark on the
 *              surface of the asteroid. There will either be an item
 *              or an alien creature waiting to attack you.
*********************************************************************/


#include "AsteroidObject.hpp"

using std::cout;
using std::endl;
using std::string;

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
AsteroidObject::AsteroidObject(int x, int y, SpaceType type,
                                string description, char icon)
                : Space(x, y, type, description, icon),
                treasure(nullptr), has_alien(false), alien("")
{}


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
bool AsteroidObject::interact(Human *traveler)
{
    if (traveler)
    {
        //check for alien
        if (has_alien)
        {
            //initialize damage amount
            const int DAMAGE = 10;

            //you got attacked by an alien
            cout << "Uh-oh! You just got attacked by a "
                 << alien << endl;
            cout << "..." << endl;
            cout << "You lost 10 health points!" << endl;
            cout << "..." << endl;
            cout << "The alien ran away." << endl;

            //deduct health points
            traveler->setHealth(traveler->getHealth() - DAMAGE);

            //alien ran away
            has_alien = false;
        }
        //check for treasure
        else if (hasTreasure())
        {
            //print that you found treasure
            cout << "You found a "
                 << treasure->getName()
                 << "!" << endl;

            //move treasure to your inventory
            traveler->addInventory(getTreasure());

            //set treasure to nullptr
            treasure = nullptr;
        }
        //no alien or treasure
        else
        {
            //print that there's nothing there
            cout << "There's nothing there... " << endl;
        }
    }

    return false;
}


/********************************************************************
** Function: hasTreasure: Checks if this space has a hidden item.
 *              This function is also used in the destructor for the
 *              Game class to deallocate stray item pointers.
** Params:   None
** Returns:  bool: True if this space has an item, false otherwise.
*********************************************************************/
bool AsteroidObject::hasTreasure() const
{
    return treasure != nullptr;
}


/********************************************************************
** Function: getTreasure: Returns pointer to treasure item.
 *              Sets treasure to nullptr.
** Params:   None
** Returns:  Item *: Pointer to treasure item.
*********************************************************************/
Item *AsteroidObject::getTreasure()
{
    //cache item
    Item *treasure_out = treasure;

    //point treasure to nullptr
    treasure = nullptr;

    //return the item
    return treasure_out;
}


/********************************************************************
** Function: setTreasure: Sets an item pointer to treasure to hide
 *              an item in this space.
** Params:   Item * treasure: Pointer to item to hide in this space.
** Returns:  None
*********************************************************************/
void AsteroidObject::setTreasure(Item *treasure)
{
    this->treasure = treasure;
}


/********************************************************************
** Function: setAlien: Sets the alien's description and has_alien
 *              flag to true.
** Params:   string description: Description of the alien.
** Returns:  None
*********************************************************************/
void AsteroidObject::setAlien(std::string description)
{
    //set alien description
    alien = description;

    //set has alien flag to true
    has_alien = true;
}
