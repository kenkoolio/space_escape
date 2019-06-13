
/*********************************************************************
** Program name: SpaceRock.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 3:38 AM
** Description: Class implementation file for SpaceRock. SpaceRock is
 *              derived from AsteroidObject class. It represents a
 *              medium-sized boulder on the surface of the asteroid.
 *              You can lift it up to check what's under it. There
 *              will either be an item or an alien creature waiting
 *              to attack you.
*********************************************************************/


#include "SpaceRock.hpp"

using std::cout;
using std::endl;
using std::string;

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
SpaceRock::SpaceRock(int x, int y, SpaceType type,
                    string description, char icon)
            : AsteroidObject(x, y, type, description, icon)
{}


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
bool SpaceRock::interact(Human *traveler)
{
    if (traveler)
    {
        //print the description of the space rock
        menu.formatPrompt(getDesc());

        //ask user if they want to check under the rock
        const string SPACE_ROCK_PROMPT =
                "Do you want to check under the space rock?";

        if (menu.confirm(SPACE_ROCK_PROMPT) == Menu::YES)
        {
            //print border
            menu.printBorder();
            cout << endl;

            //print that you lifted up the rock
            cout << "You lifted up the space rock..." << endl;

            //call parent AsteroidObject interact
            // to check for aliens or items
            AsteroidObject::interact(traveler);

            //print border
            menu.printBorder();
        }
    }

    return false;
}
