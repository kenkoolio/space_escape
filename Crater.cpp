
/*********************************************************************
** Program name: Crater.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 07, 2019 at 2:28 AM
** Description: Class implementation file for Crater. Crater is
 *              derived from AsteroidObject class. It represents a
 *              large, bowl-shaped hole on the surface of the
 *              asteroid. You can jump in if you want. When you jump
 *              in, you can search the crater. There will either be
 *              an item or an alien creature waiting to attack you.
*********************************************************************/


#include "Crater.hpp"

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
 *              default = CRATER.
 *           string description: description of this space.
 *              default = see module header description.
 *           char icon: icon to visually represent this space.
 *              default = 'O'.
** Returns:  None
*********************************************************************/
Crater::Crater(int x, int y, SpaceType type,
                string description, char icon)
        : AsteroidObject(x, y, type, description, icon)
{}


/********************************************************************
** Function: interact: Prints the description of the crater. Then
 *              asks the user if they want to jump in the crater and
 *              checks if there is anything there by calling the base
 *              AsteroidObject's interact function.
** Params:   Human * traveler: Pointer to human object in which to
 *              interact with this space. Used to deduct health
 *              points if attacked, or moves item into your inventory
 *              if treasure is found.
** Returns:  bool: true ends the game.
*********************************************************************/
bool Crater::interact(Human *traveler)
{
    if (traveler)
    {
        //print the description of the crater
        menu.formatPrompt(getDesc());

        //ask user if they want to jump in
        const string CRATER_PROMPT =
                "Do you want to jump in the crater?";

        if (menu.confirm(CRATER_PROMPT) == Menu::YES)
        {
            //print border
            menu.printBorder();
            cout << endl;

            //print that you jumped in
            cout << "You jumped into the crater..." << endl;

            //call parent AsteroidObject interact
            // to check for aliens or items
            AsteroidObject::interact(traveler);

            //print border
            menu.printBorder();
        }
    }

    return false;
}
