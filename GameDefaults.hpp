
/*********************************************************************
** Program name: GameDefaults.hpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 05, 2019 at 5:58 PM
** Description: Class specification file for GameDefaults.
 *              GameDefaults is a class that holds all of the default
 *              values, constants, configurations, and descriptions
 *              for the derived Space classes, alien types, and item
 *              types. Also holds coordinates for all spaces, alien
 *              locations, and item locations for initialization of
 *              the board.
*********************************************************************/


#ifndef GAME_DEFAULTS_HPP
#define GAME_DEFAULTS_HPP

#include <string>

class GameDefaults
{
public:
    //initialize array size constants
    static const int ZERO;
    static const int CONFIG_SIZE;
    static const int ALIEN_SIZE;
    static const int ITEM_SIZE;
    static const int SPACE_LOCATION_SIZE;
    static const int ALIEN_LOCATION_SIZE;
    static const int ITEM_LOCATION_SIZE;

    //enums for asset types
    enum SpaceType
    {
        ROCKETSHIP,
        CRATER,
        SPACEROCK,
        WORMHOLE,
        GROUND,
        DEFAULTSPACE
    };

    enum AlienType
    {
        PCMUSTARD,
        VAPEBRO,
        KHALEESI
    };

    enum ItemType
    {
        HEALTHPACK,
        PLUTONIUMORE,
        SHIPPART
    };

    //structs to hold constant asset data
    struct SpaceConfig
    {
        int x_default;
        int y_default;
        char icon_default;
        SpaceType type_default;
        std::string description_default;
    };

    struct AlienInfo
    {
        std::string name;
        std::string description;
    };

    struct ItemInfo
    {
        std::string name;
        std::string description;
    };

    struct SpaceMap
    {
        int x;
        int y;
        SpaceType type;
    };

    struct AlienMap
    {
        int x;
        int y;
        AlienType type;
    };

    struct ItemMap
    {
        int x;
        int y;
        ItemType type;
    };

    //lookup tables to hold constants, configurations, descriptions,
    // and coordinate locations
    static const SpaceConfig SPACE_CONFIG[];
    static const AlienInfo ALIEN_DESC[];
    static const ItemInfo ITEM_DESC[];
    static const SpaceMap SPACE_LOCATIONS[];
    static const AlienMap ALIEN_LOCATIONS[];
    static const ItemMap ITEM_LOCATIONS[];

    //Game description
    static const std::string STORY;
    //Game objective
    static const std::string OBJECTIVE;
    //Game time limit
    static const std::string TIME_LIMIT;
    //Game legend
    static const std::string LEGEND;

    //title ascii art
    // SOURCE: http://www.ascii-art.de/ascii/pqr/rockets.txt
    static const std::string TITLE_ART;

    //blast-off ascii art
    // SOURCE: http://www.ascii-art.de/ascii/pqr/rockets.txt
    static const std::string BLAST_OFF_ART;

};

//Make aliases for quick access

//Typedef for easy aliasing in other modules
typedef GameDefaults::SpaceType SpaceType;
typedef GameDefaults::AlienType AlienType;
typedef GameDefaults::ItemType ItemType;

//Alias to lookup tables
extern const GameDefaults::SpaceConfig  *SPACE_CONFIG_LT;
extern const GameDefaults::AlienInfo    *ALIEN_DESC_LT;
extern const GameDefaults::ItemInfo     *ITEM_DESC_LT;
extern const GameDefaults::SpaceMap     *SPACE_LOCATIONS_LT;
extern const GameDefaults::AlienMap     *ALIEN_LOCATIONS_LT;
extern const GameDefaults::ItemMap      *ITEM_LOCATIONS_LT;

//Alias to SpaceType enums
const SpaceType ROCKETSHIP = GameDefaults::ROCKETSHIP;
const SpaceType CRATER = GameDefaults::CRATER;
const SpaceType SPACEROCK = GameDefaults::SPACEROCK;
const SpaceType WORMHOLE = GameDefaults::WORMHOLE;
const SpaceType GROUND = GameDefaults::GROUND;
const SpaceType DEFAULTSPACE = GameDefaults::DEFAULTSPACE;

//Alias to AlienType enums
const AlienType PCMUSTARD = GameDefaults::PCMUSTARD;
const AlienType VAPEBRO = GameDefaults::VAPEBRO;
const AlienType KHALEESI = GameDefaults::KHALEESI;

//Alias to ItemType enums
const ItemType HEALTHPACK = GameDefaults::HEALTHPACK;
const ItemType PLUTONIUMORE = GameDefaults::PLUTONIUMORE;
const ItemType SHIPPART = GameDefaults::SHIPPART;

//Alias for game description
extern const std::string STORY;
//Alias for game objective
extern const std::string OBJECTIVE;
//Alias for game time limit
extern const std::string TIME_LIMIT;
//Alias for game legend
extern const std::string LEGEND;

//Alias for title art
extern const std::string TITLE_ART;
//Alias for blast off art
extern const std::string BLAST_OFF_ART;

#endif
