
/*********************************************************************
** Program name: Wormhole.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 5:47 PM
** Description: Class implementation file for Wormhole. Wormhole is
 *              derived from Space class. It represents a physical
 *              anomaly that is a rift in the fabric of time and
 *              space. You can walk through the wormhole if you want.
 *              It will teleport you to a random location on the
 *              asteroid.
*********************************************************************/


#include "Wormhole.hpp"

using std::cout;
using std::endl;
using std::string;

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
Wormhole::Wormhole(int x, int y, SpaceType type,
        string description, char icon)
        : Space(x, y, type, description, icon)
{
    //seed random number generator
    MyRandom::seed();
}


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
bool Wormhole::interact(Human *traveler)
{
    if (traveler)
    {
        //print the description of the worm hole
        menu.formatPrompt(getDesc());

        //ask user if they want to walk through the worm hole
        const string WORMHOLE_PROMPT =
                "Do you want to walk through the worm hole?";

        if (menu.confirm(WORMHOLE_PROMPT) == Menu::YES)
        {
            //initialize constants
            const int LOWER = 0;
            const int UPPER = 9;

            //print that you walked through the worm hole
            // and got teleported to a random location
            menu.formatPrompt("You walked through the worm hole "
                    "and got teleported to a random location...");

            //generate random coordinates
            int new_x = MyRandom::randomInteger(LOWER, UPPER);
            int new_y = MyRandom::randomInteger(LOWER, UPPER);

            //set traveler's new coordinates
            traveler->setX(new_x);
            traveler->setY(new_y);
        }
    }

    return false;
}
