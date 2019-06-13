
/*********************************************************************
** Program name: Rocketship.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 06, 2019 at 10:56 PM
** Description: Class implementation file for Rocketship. Rocketship
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


#include "Rocketship.hpp"

using std::cout;
using std::endl;
using std::string;

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
Rocketship::Rocketship(int x, int y, SpaceType type,
            string description, char icon)
            : Space(x, y, type, description, icon)
{}


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
bool Rocketship::interact(Human *traveler)
{
    if (traveler)
    {
        //initialize selection enum
        enum Actions {VIEW_SHIP = 1, FIX_SHIP};
        //initialize prompts
        const int CHOICES_SIZE = 2;
        const string ROCKET_PROMPT =
                "This is your rocket ship. What do you want to do?";
        const string CHOICES[] = {"Check out the rocket ship",
                                  "Fix the rocket ship"};

        //get user selection
        Actions selection = static_cast<Actions>
                (menu.chooseOne(CHOICES, CHOICES_SIZE, ROCKET_PROMPT));

        if (selection == VIEW_SHIP)
        {
            //print the description of the rocket ship
            menu.formatPrompt(getDesc());
        }
        else
        {
            //user fixes the ship
            bool isFixed = fixShip(traveler->getInventory());

            //return if rocket is fixed, if true this ends the game
            return isFixed;
        }
    }
    return false;
}


/********************************************************************
** Function: fixShip: Attempts to fix the rocket ship and leave to
 *              complete the game. Checks your inventory to see if
 *              you have enough resources.
** Params:   const Inventory * resources: Constant pointer to your
 *              inventory, used to check if you have all the required
 *              material.
** Returns:  bool: true ends the game.
*********************************************************************/
bool Rocketship::fixShip(const Inventory *resources)
{
    const int REQUIRED = 5;
    int plutonium_count = resources->count(PLUTONIUMORE);
    int ship_part_count = resources->count(SHIPPART);
    bool end_game = false;

    //print border
    menu.printBorder();
    cout << endl;

    //check for plutonium ore
    if (plutonium_count < REQUIRED)
    {
        cout << "You still need "
             << (REQUIRED - plutonium_count)
             << " more piece(s) of plutonium ore." << endl;
    }

    //check for ship parts
    if (ship_part_count < REQUIRED)
    {
        cout << "You still need "
             << (REQUIRED - ship_part_count)
             << " more ship part(s)." << endl;
    }

    //has everything, blast off!
    if (plutonium_count == REQUIRED && ship_part_count == REQUIRED)
    {
        cout << "Great! You have all the necessary material." << endl << endl;
        cout << "Fixing the ship ... " << endl;
        cout << "..." << endl << endl;
        cout << "Okay, ready to go!" << endl;
        cout << "Ignition stared..." << endl;
        cout << "Blast off commencing in ..." << endl << endl;
        cout << "...3" << endl;
        cout << "...2" << endl;
        cout << "...1" << endl;
        cout << "..." << endl << endl;
        cout << "BLASTOFF!" << endl << endl;

        //print ascii art
        cout << BLAST_OFF_ART << endl;

        //end the game
        end_game = true;
    }

    //print border
    menu.printBorder();

    //return if game is over
    return end_game;
}
