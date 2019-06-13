
/*********************************************************************
** Program name: Game.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 08, 2019 at 11:30 PM
** Description: Class implementation file for Game. Game is the driver
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


#include "Game.hpp"

using std::cout;
using std::endl;
using std::string;

//initialize static game constants
const int Game::ROWS = 10;
const int Game::COLS = 10;
const int Game::TRAVELER_START_X = 6;
const int Game::TRAVELER_START_Y = 5;

/********************************************************************
** Function: Constructor/default: Initializes a game object. Sets up
 *              the map and all map assets, such as the spaces, the
 *              aliens, and the treasure items. Sets up the traveler.
** Params:   None
** Returns:  None
*********************************************************************/
Game::Game() : game_over(false)
{
    setupSpaces();
    setupAliens();
    setupTreasure();
    setupTraveler();
}


/********************************************************************
** Function: Destructor: Responsible for de-allocating all Space
 *              objects and pointing the board's pointer to nullptr.
 *              Also responsible for checking if the Space object has
 *              any item objects, then de-allocating those as well.
** Params:   None
** Returns:  None
*********************************************************************/
Game::~Game()
{
    //check and delete items left on the map
    for (int y=0; y<ROWS; y++)
    {
        for (int x=0; x<COLS; x++)
        {
            //AsteroidObject spaces hold items
            AsteroidObject *landmark =
                    dynamic_cast<AsteroidObject*>(asteroid->getSpace(x, y));

            if (landmark && landmark->hasTreasure())
            {
                //if there is an item there, delete it
                delete landmark->getTreasure();
            }
        }
    }

    //delete all space pointers
    for (int y=0; y<ROWS; y++)
    {
        for (int x=0; x<COLS; x++)
        {
            Space *garbage_space = asteroid->getSpace(x, y);
            delete garbage_space;
            garbage_space = nullptr;
        }
    }

    //de-allocate asteroid board pointer
    delete asteroid;
    asteroid = nullptr;

    //de-allocate human traveler pointer
    delete traveler;
    traveler = nullptr;
}


/********************************************************************
** Function: start: Starts the game, prints out the background story,
 *              presents instructions. Runs the game in a loop and
 *              presents a menu for the user to play the game. The
 *              loop ends when the user either runs out of health,
 *              runs out of oxygen, or completes the game.
** Params:   None
** Returns:  None
*********************************************************************/
void Game::start()
{
    //initialize prompts
    const string PADDING = string(10, char(32));
    const string WELCOME = PADDING + "Welcome to Space Escape";
    const string FAREWELL = PADDING + "Thanks for playing!";

    //print welcome with title art
    menu.formatPrompt("\n\n" + WELCOME + "\n\n" + TITLE_ART);

    //print story, objective, time limit, and legend
    //open border
    menu.printBorder();
    cout << endl;
    //story
    cout << STORY << endl << endl;
    //objective
    cout << OBJECTIVE << endl << endl;
    //time limit
    cout << TIME_LIMIT << endl;
    //close border
    menu.printBorder();

    //menu to play the game or exit
    if (menu.play() == Menu::START_VALUE_DEFAULT)
    {
        //initialize variable to hold user action
        // initialized with dummy value, CHECK_SPACE, will be over-written
        Action user_selection = CHECK_SPACE;

        //loop game play until user dies or completes the mission
        while (!game_over && traveler->getHealth() > 0 && traveler->getOxygen() > 0)
        {
            //print map and game stats
            print();

            //print menu and get user selection
            user_selection = playMenu();

            //perform action
            performAction(user_selection);
        }

        if (traveler->getHealth() < 1 || traveler->getOxygen() < 1)
        {
            //if game over is result of traveler dying,
            // print to user that they died
            menu.formatPrompt("You died.. x_x");
        }

        //print farewell
        menu.formatPrompt("\n\n" + FAREWELL + "\n\n");
    }
}


/********************************************************************
** Function: setupSpaces: Creates board instance and space objects
 *              according to level design and inserts them into the
 *              game board.
** Params:   None
** Returns:  None
*********************************************************************/
void Game::setupSpaces()
{
    //initialize board
    asteroid = new Board(ROWS, COLS);

    //initialize variables to hold Space configs
    int x = 0;
    int y = 0;
    SpaceType type = DEFAULTSPACE;
    string description = "";
    char icon = '\0';

    //set up the map spaces according to level design
    for (int i=0; i<GameDefaults::SPACE_LOCATION_SIZE; i++)
    {
        //retrieve space config
        x = SPACE_LOCATIONS_LT[i].x;
        y = SPACE_LOCATIONS_LT[i].y;
        type = SPACE_LOCATIONS_LT[i].type;

        description = SPACE_CONFIG_LT[type].description_default;
        icon = SPACE_CONFIG_LT[type].icon_default;

        switch (type)
        {
            case ROCKETSHIP :
                asteroid->setSpace(x, y, new Rocketship(x, y, type, description, icon));
                break;
            case CRATER :
                asteroid->setSpace(x, y, new Crater(x, y, type, description, icon));
                break;
            case SPACEROCK :
                asteroid->setSpace(x, y, new SpaceRock(x, y, type, description, icon));
                break;
            case WORMHOLE :
                asteroid->setSpace(x, y, new Wormhole(x, y, type, description, icon));
                break;
            case GROUND :
                asteroid->setSpace(x, y, new Ground(x, y, type, description, icon));
                break;
            default :
                break;
        }
    }

    //link the spaces together
    asteroid->linkSpaces();
}


/********************************************************************
** Function: setupAliens: Hides "aliens" in Space objects on the game
 *              board according to level design.
** Params:   None
** Returns:  None
*********************************************************************/
void Game::setupAliens()
{
    //initialize variables to hold alien configs, these are dummy values
    int x = 0;
    int y = 0;
    AlienType type = KHALEESI;
    string description = "";

    //hide aliens on the map according to level design
    for (int i=0; i<GameDefaults::ALIEN_LOCATION_SIZE; i++)
    {
        //retrieve alien config
        x = ALIEN_LOCATIONS_LT[i].x;
        y = ALIEN_LOCATIONS_LT[i].y;
        type = ALIEN_LOCATIONS_LT[i].type;

        description = ALIEN_DESC_LT[type].description;

        //cast space to AsteroidObject, only those can hide aliens
        AsteroidObject *landmark = dynamic_cast<AsteroidObject*>(asteroid->getSpace(x, y));
        if (landmark)
        {
            //hide alien in space
            landmark->setAlien(description);
        }
    }
}


/********************************************************************
** Function: setupTreasure: Hides "treasure" items in Space objects
 *              on the game board according to the level design.
** Params:   None
** Returns:  None
*********************************************************************/
void Game::setupTreasure()
{
    //initialize variables to hold item configs, there are dummy variables
    int x = 0;
    int y = 0;
    ItemType type = HEALTHPACK;
    string name = "";
    string description = "";
    Item *new_item = nullptr;

    //hide items on the map according to level design
    for (int i=0; i<GameDefaults::ITEM_LOCATION_SIZE; i++)
    {
        //retrieve item config
        x = ITEM_LOCATIONS_LT[i].x;
        y = ITEM_LOCATIONS_LT[i].y;
        type = ITEM_LOCATIONS_LT[i].type;

        name = ITEM_DESC_LT[type].name;
        description = ITEM_DESC_LT[type].description;

        //cast space to AsteroidObject, only those can hide items
        AsteroidObject *landmark = dynamic_cast<AsteroidObject*>(asteroid->getSpace(x, y));
        if (landmark)
        {
            //create new item
            new_item = new Item(type, name, description);

            //hide item in space
            landmark->setTreasure(new_item);
        }
    }
}


/********************************************************************
** Function: setupTraveler: Creates human instance at default
 *              location coordinates. Creates and gives the traveler
 *              4 health packs.
** Params:   None
** Returns:  None
*********************************************************************/
void Game::setupTraveler()
{
    //create human traveler
    traveler = new Human(TRAVELER_START_X, TRAVELER_START_Y);

    const int HEALTH_PACK_COUNT = 4;

    //create and give traveler 4 health packs
    for (int i=0; i<HEALTH_PACK_COUNT; i++)
    {
        traveler->addInventory(
                new Item(
                        HEALTHPACK,
                        ITEM_DESC_LT[HEALTHPACK].name,
                        ITEM_DESC_LT[HEALTHPACK].description
                        )
                );
    }
}


/********************************************************************
** Function: playMenu: Prints a menu of actions to perform and
 *              prompts user to choose one. They can choose to go up,
 *              go right, go down, go left, check the space they are
 *              in, or look in their inventory.
** Params:   None
** Returns:  Action: user's selected action.
*********************************************************************/
Game::Action Game::playMenu()
{
    //initialize prompts
    const int CHOICES_SIZE = 6;
    const string ACTION_PROMPT = "What do you want to do?";
    const string CHOICES[] = {"Go Up",
                              "Go Right",
                              "Go Down",
                              "Go Left",
                              "Check Space",
                              "View Inventory"};

    //prompt user for selection and return it
    return static_cast<Action>
        (menu.chooseOne(CHOICES, CHOICES_SIZE, ACTION_PROMPT));
}


/********************************************************************
** Function: performAction: Takes user's selected action and then
 *              performs the action by calling the appropriate
 *              function.
** Params:   Action choice: the user's selected action.
** Returns:  None
*********************************************************************/
void Game::performAction(Action choice)
{
    switch (choice)
    {
        case CHECK_SPACE :
            checkArea();
            break;
        case CHECK_INVENTORY :
            checkInventory();
            break;
        default :
            //if it's not check space or check inventory,
            // then its to move. Move Action maps directly to Direction.
            move(static_cast<Direction>(choice));
            break;
    }
}


/********************************************************************
** Function: move: Moves the character on space in specified
 *              direction. A successful movement subtracts one oxygen
 *              point.
** Params:   Direction direction: the direction in which to move the
 *              character.
** Returns:  None
*********************************************************************/
void Game::move(Direction direction)
{
    //initialize variables to make the move
    int current_x = traveler->getX();
    int current_y = traveler->getY();
    int new_x = 0;
    int new_y = 0;
    Space *current_space = asteroid->getSpace(current_x, current_y);
    Space *new_space = nullptr;

    //get space in specified direction
    switch (direction)
    {
        case UP :
            new_space = current_space->getTop();
            break;
        case RIGHT :
            new_space = current_space->getRight();
            break;
        case DOWN :
            new_space = current_space->getBottom();
            break;
        case LEFT :
            new_space = current_space->getLeft();
            break;
    }

    //if space in specified direction is not out of bounds (nullptr)
    if (new_space)
    {
        //get new coordinates
        new_x = new_space->getX();
        new_y = new_space->getY();

        //move character to new coordinates
        traveler->setX(new_x);
        traveler->setY(new_y);

        //deduct oxygen level
        traveler->setOxygen(traveler->getOxygen() - 1);
    }
    else
    {
        //it was nullptr, out of bounds
        menu.formatPrompt("You can't go there.");
    }
}


/********************************************************************
** Function: checkArea: Allows the character to interact with the
 *              space they are in. Calls the space's interact
 *              function. Can potentially end the game.
** Params:   None
** Returns:  None
*********************************************************************/
void Game::checkArea()
{
    //initialize variables to hold coordinates
    int x = traveler->getX();
    int y = traveler->getY();

    //interact with the space
    bool end_game = asteroid->getSpace(x, y)->interact(traveler);

    //check if game is over
    if (end_game)
    {
        game_over = end_game;
    }
}


/********************************************************************
** Function: checkInventory: Checks the character's inventory and
 *              lets them interact with their items.
** Params:   None
** Returns:  None
*********************************************************************/
void Game::checkInventory()
{
    //initialize item selection index variable
    int chosen_item_index = 0;

    //initialize prompts
    const string ITEM_TITLE = "Your Inventory: ";
    const string ITEM_PROMPT = "What do you want to do?";

    //initialize limits
    const int EXIT = 0;
    int UPPER_LIMIT = traveler->getInventory()->size();

    //print border
    menu.printBorder();
    cout << endl;

    //print inventory
    cout << ITEM_TITLE << endl << endl;
    traveler->viewInventory();

    //print exit option
    cout << "0: Exit" << endl;

    //print border
    menu.printBorder();

    //get user selection
    chosen_item_index = menu.promptForInteger(ITEM_PROMPT, EXIT, UPPER_LIMIT);

    //perform action with item if user didn't choose exit
    if (chosen_item_index != EXIT)
    {
        //let the traveler use the item
        traveler->selectItem(chosen_item_index);
    }
}


/********************************************************************
** Function: print: Prints the current state of the board, with the
 *              character, and prints the character's current oxygen
 *              level and health points. Also prints the legend.
** Params:   None
** Returns:  None
*********************************************************************/
void Game::print()
{
    //initialize traveler data
    int x = traveler->getX();
    int y = traveler->getY();
    char icon = traveler->getIcon();
    int health = traveler->getHealth();
    int oxygen = traveler->getOxygen();

    //print border
    menu.printBorder();
    cout << endl;

    //print title
    cout << "Space Escape" << endl << endl;

    //print game status
    cout << "Health: " << health << "\tOxygen: " << oxygen << endl << endl;

    //print game board
    cout << "Map: " << endl;
    asteroid->print(x, y, icon);
    cout << endl;

    //print legend
    cout << LEGEND << endl;

    //print border
    menu.printBorder();
}
