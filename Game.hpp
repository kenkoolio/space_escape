
/*********************************************************************
** Program name: Game.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 08, 2019 at 11:30 PM
** Description: Class specification file for Game. Game is the driver
 *              class for the Space Escape game. It creates a game
 *              instance, initializes the player, initializes the
 *              game board, and sets all the assets of the
 *              level(Spaces, hidden items, and hidden aliens). It
 *              is also responsible for de-allocating the Space
 *              objects and stray items upon destruction. The game
 *              provides an introduction to the story and detailed
 *              game instructions, provides menus to move around the
 *              map and interact with space objects, and implements a
 *              time/step limit to complete the game. You can finish
 *              the game by completing the objectives or die by
 *              either running out of oxygen or running out of
 *              health.
*********************************************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "GameDefaults.hpp"
#include "Space.hpp"
#include "Ground.hpp"
#include "Rocketship.hpp"
#include "AsteroidObject.hpp"
#include "Crater.hpp"
#include "SpaceRock.hpp"
#include "Wormhole.hpp"
#include "Board.hpp"
#include "Human.hpp"
#include "Item.hpp"

class Game
{
private:
    //initialize enums
    enum Action
    {
        GO_UP = 1,
        GO_RIGHT,
        GO_DOWN,
        GO_LEFT,
        CHECK_SPACE,
        CHECK_INVENTORY
    };

    enum Direction
    {
        UP = 1,
        RIGHT,
        DOWN,
        LEFT
    };

    //initialize constant configurations
    static const int ROWS;
    static const int COLS;
    static const int TRAVELER_START_X;
    static const int TRAVELER_START_Y;

    //initialize player
    Human *traveler;

    //initialize board
    Board *asteroid;

    //initialize game status flag
    bool game_over;

    //initialize menu object
    Menu menu;

public:

    /********************************************************************
    ** Function: Constructor/default: Initializes a game object. Sets up
     *              the map and all map assets, such as the spaces, the
     *              aliens, and the treasure items. Sets up the traveler.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    Game();


    /********************************************************************
    ** Function: Destructor: Responsible for de-allocating all Space
     *              objects and pointing the board's pointer to nullptr.
     *              Also responsible for checking if the Space object has
     *              any item objects, then de-allocating those as well.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    ~Game();


    /********************************************************************
    ** Function: start: Starts the game, prints out the background story,
     *              presents instructions. Runs the game in a loop and
     *              presents a menu for the user to play the game. The
     *              loop ends when the user either runs out of health,
     *              runs out of oxygen, or completes the game.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void start();

private:

    /********************************************************************
    ** Function: setupSpaces: Creates board instance and space objects
     *              according to level design and inserts them into the
     *              game board.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void setupSpaces();


    /********************************************************************
    ** Function: setupAliens: Hides "aliens" in Space objects on the game
     *              board according to level design.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void setupAliens();


    /********************************************************************
    ** Function: setupTreasure: Hides "treasure" items in Space objects
     *              on the game board according to the level design.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void setupTreasure();


    /********************************************************************
    ** Function: setupTraveler: Creates human instance at default
     *              location coordinates. Creates and gives the traveler
     *              4 health packs.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void setupTraveler();
    
    
    /********************************************************************
    ** Function: playMenu: Prints a menu of actions to perform and
     *              prompts user to choose one. They can choose to go up,
     *              go right, go down, go left, check the space they are
     *              in, or look in their inventory.
    ** Params:   None
    ** Returns:  Action: user's selected action.
    *********************************************************************/
    Action playMenu();


    /********************************************************************
    ** Function: performAction: Takes user's selected action and then
     *              performs the action by calling the appropriate
     *              function.
    ** Params:   Action choice: the user's selected action.
    ** Returns:  None
    *********************************************************************/
    void performAction(Action choice);


    /********************************************************************
    ** Function: move: Moves the character on space in specified
     *              direction. A successful movement subtracts one oxygen
     *              point.
    ** Params:   Direction direction: the direction in which to move the
     *              character.
    ** Returns:  None
    *********************************************************************/
    void move(Direction direction);


    /********************************************************************
    ** Function: checkArea: Allows the character to interact with the
     *              space they are in. Calls the space's interact
     *              function. Can potentially end the game.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void checkArea();


    /********************************************************************
    ** Function: checkInventory: Checks the character's inventory and
     *              lets them interact with their items.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void checkInventory();


    /********************************************************************
    ** Function: print: Prints the current state of the board, with the
     *              character, and prints the character's current oxygen
     *              level and health points. Also prints the legend.
    ** Params:   None
    ** Returns:  None
    *********************************************************************/
    void print();

};

#endif
