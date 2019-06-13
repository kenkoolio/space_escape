
/*********************************************************************
** Program name: main.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 10, 2019 at 12:32 AM
** Description: Main is the driver function for the Space Escape game.
 *              It creates an instance of the Game driver class, then
 *              starts the game by calling the start function.
*********************************************************************/


#include "Game.hpp"

int main() {

    //create game object
    Game space_escape;

    //start the game
    space_escape.start();

    return 0;
}
