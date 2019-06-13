
/*********************************************************************
** Program name: GameDefaults.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Jun 05, 2019 at 5:58 PM
** Description: Class implementation file for GameDefaults.
 *              GameDefaults is a class that holds all of the default
 *              values, constants, configurations, and descriptions
 *              for the derived Space classes, alien types, and item
 *              types. Also holds coordinates for all spaces, alien
 *              locations, and item locations for initialization of
 *              the board.
*********************************************************************/


#include "GameDefaults.hpp"

//initialize static game constants
const int GameDefaults::ZERO = 0;
const int GameDefaults::CONFIG_SIZE = 6;
const int GameDefaults::ALIEN_SIZE = 3;
const int GameDefaults::ITEM_SIZE = 3;
const int GameDefaults::SPACE_LOCATION_SIZE = 100;
const int GameDefaults::ALIEN_LOCATION_SIZE = 10;
const int GameDefaults::ITEM_LOCATION_SIZE = 10;

//initialize extern alias to lookup tables
const GameDefaults::SpaceConfig *SPACE_CONFIG_LT = GameDefaults::SPACE_CONFIG;
const GameDefaults::AlienInfo *ALIEN_DESC_LT = GameDefaults::ALIEN_DESC;
const GameDefaults::ItemInfo *ITEM_DESC_LT = GameDefaults::ITEM_DESC;
const GameDefaults::SpaceMap *SPACE_LOCATIONS_LT = GameDefaults::SPACE_LOCATIONS;
const GameDefaults::AlienMap *ALIEN_LOCATIONS_LT = GameDefaults::ALIEN_LOCATIONS;
const GameDefaults::ItemMap *ITEM_LOCATIONS_LT = GameDefaults::ITEM_LOCATIONS;

//initialize story description
const std::string GameDefaults::STORY =
        "MISSION:\nYour rocket ship ran out of fuel and crash landed on a mysterious "
        "asteroid floating through space. Your sensors have detected a source of "
        "plutonium ore, which can be used to power your ship, scattered throughout "
        "the asteroid's surface. You must scavenge the asteroid in search of "
        "plutonium ore for fuel, as well as find pieces of your rocket ship "
        "that broke off during the crash. Be careful, you never know what "
        "could be lurking in the shadows...";

//initialize game objective
const std::string GameDefaults::OBJECTIVE =
        "OBJECTIVE:\nYou must search the asteroid for 5 pieces of plutonium ore and "
        "5 pieces of your space ship before you can fix the ship and leave. "
        "Once all material is collected, go to your rocket ship to fix it "
        "and blast off.";

//initialize game time limit
const std::string GameDefaults::TIME_LIMIT =
        "TIME LIMIT:\nYou are low on oxygen. You can only take 100 steps before "
        "you run out and suffocated in the coldness of space. You also start "
        "with 100 health points. You only have 4 health packs left that will "
        "recover 10 health points each. If you run out of health, you will die.";

//initialize legend
const std::string GameDefaults::LEGEND =
        "Legend:\n"
        " - You = &\n"
        " - Rocket ship = ^\n"
        " - Craters = O\n"
        " - Space rocks = #\n"
        " - Worm holes = @";

//initialize title art
const std::string GameDefaults::TITLE_ART =
        "                                               *     .--.\n"
        "                                                    / /  `\n"
        "                                   +               | |\n"
        "                                          '         \\ \\__,\n"
        "                                      *          +   '--'  *\n"
        "                                          +   /\\\n"
        "                             +              .'  '.   *\n"
        "                                    *      /======\\      +\n"
        "                                          ;:.  _   ;\n"
        "                                          |:. (_)  |\n"
        "                                          |:.  _   |\n"
        "                                +         |:. (_)  |          *\n"
        "                                          ;:.      ;\n"
        "                                        .' \\:.    / `.\n"
        "                                       / .-'':._.'`-. \\\n"
        "                                       |/    /||\\    \\|\n"
        "                                 jgs _..--\"\"\"````\"\"\"--.._\n"
        "                               _.-'``                    ``'-._\n"
        "                             -'                                '-";

//initialize blast off art
const std::string GameDefaults::BLAST_OFF_ART =
        "                                                   ,:\n"
        "                                                 ,' |\n"
        "                                                /   :\n"
        "                                             --'   /\n"
        "                                             \\/ />/\n"
        "                                             / <//_\\\n"
        "                                          __/   /\n"
        "                                          )'-. /\n"
        "                                          ./  :\\\n"
        "                                           /.' '\n"
        "                                         '/'\n"
        "                                         +\n"
        "                                        '\n"
        "                                      `.\n"
        "                                  .-\"-\n"
        "                                 (    |\n"
        "                              . .-'  '.\n"
        "                             ( (.   )8:\n"
        "                         .'    / (_  )\n"
        "                          _. :(.   )8P  `\n"
        "                      .  (  `-' (  `.   .\n"
        "                       .  :  (   .a8a)\n"
        "                      /_`( \"a `a. )\"'\n"
        "                  (  (/  .  ' )=='\n"
        "                 (   (    )  .8\"   +\n"
        "                   (`'8a.( _(   (\n"
        "                ..-. `8P    ) `  )  +\n"
        "              -'   (      -ab:  )\n"
        "            '    _  `    (8P\"Ya\n"
        "          _(    (    )b  -`.  ) +\n"
        "         ( 8)  ( _.aP\" _a   \\( \\   *\n"
        "       +  )/    (8P   (88    )  )\n"
        "          (a:f   \"     `\"       `";

//initialize extern aliases to static game descriptions, title art, and blast off art
const std::string STORY = GameDefaults::STORY;
const std::string OBJECTIVE = GameDefaults::OBJECTIVE;
const std::string TIME_LIMIT = GameDefaults::TIME_LIMIT;
const std::string LEGEND = GameDefaults::LEGEND;
const std::string TITLE_ART = GameDefaults::TITLE_ART;
const std::string BLAST_OFF_ART = GameDefaults::BLAST_OFF_ART;


//initialize lookup tables
const GameDefaults::SpaceConfig GameDefaults::SPACE_CONFIG[GameDefaults::CONFIG_SIZE] =
        {{0, 0, '^', ROCKETSHIP,
          "Your rocket ship is a beautiful, large, crimson red, "
          "cone-shaped contraption that your father bought for your "
          "18th birthday. It has 4 rocket engines, a kitchen, dry bath, sleep "
          "compartment, and warp drive capable of travelling millions of light-years "
          "in the blink of an eye. It is powered by plutonium ore."}, //rocketship defaults
         {0, 0, 'O', CRATER,
          "A large, bowl-shaped hole on the surface of the asteroid. You can "
          "jump in if you want."}, //crater defaults
         {0, 0, '#', SPACEROCK,
          "A medium-sized boulder on the surface of the asteroid. You can lift it up "
          "to check what's under it."}, //spacerock defaults
         {0, 0, '@', WORMHOLE,
          "A physical anomaly that is a rift in the fabric of time and space. "
          "You can walk through the worm hole if you want."}, //wormhole defaults
         {0, 0, '_', GROUND,
          "The ground is dusty, and the gray dirt feels like a silky powder. "
          "There is nothing on the ground."}, //ground defaults
         {0, 0, '_', GROUND, ""}}; //default space

const GameDefaults::AlienInfo GameDefaults::ALIEN_DESC[GameDefaults::ALIEN_SIZE] =
        {{"PCMustard",
          "PCMustard, a species of alien only found in the coldest parts "
          "of space. They have silky, blonde hair, golden bronze complexion, "
          "and razor-sharp fangs capable of biting you at 120 fps."}, //PCMustard description
         {"Vapebro",
          "Vapebro, a species of alien that lurks underground, waiting to "
          "ambush its prey with a mysterious fog of poison while bombarding "
          "them with awareness that they like to vape."}, //Vapebro description
         {"Khaleesi",
          "Khaleesi, first of their name, breaker of chains, mother of "
          "dragons. They are an advanced species of alien that has leathery "
          "wings capable of flying, sharp claws, scaly skin, can breathe "
          "fire, and has voluminous silver hair."}}; //Khaleesi description

const GameDefaults::ItemInfo GameDefaults::ITEM_DESC[GameDefaults::ITEM_SIZE] =
        {{"Health pack",
          "A first aid kit that can slightly heal your wounds and recover 10 "
          "health points."}, //health pack description
         {"Plutonium ore",
          "A small, dense, metallic-looking substance. It's quite mesmerizing "
          "to look at, but you can already feel the radiation."}, //plutonium ore description
         {"Ship part",
          "A piece of your rocket ship that fell off in the crash."}}; //ship part description

//map
const GameDefaults::SpaceMap GameDefaults::SPACE_LOCATIONS[GameDefaults::SPACE_LOCATION_SIZE] =
        {{0, 0, GROUND},
         {1, 0, CRATER},
         {2, 0, GROUND},
         {3, 0, SPACEROCK},
         {4, 0, SPACEROCK},
         {5, 0, GROUND},
         {6, 0, GROUND},
         {7, 0, GROUND},
         {8, 0, GROUND},
         {9, 0, GROUND},

         {0, 1, CRATER},
         {1, 1, CRATER},
         {2, 1, GROUND},
         {3, 1, GROUND},
         {4, 1, SPACEROCK},
         {5, 1, GROUND},
         {6, 1, GROUND},
         {7, 1, CRATER},
         {8, 1, GROUND},
         {9, 1, GROUND},

         {0, 2, CRATER},
         {1, 2, GROUND},
         {2, 2, GROUND},
         {3, 2, GROUND},
         {4, 2, GROUND},
         {5, 2, WORMHOLE},
         {6, 2, GROUND},
         {7, 2, GROUND},
         {8, 2, CRATER},
         {9, 2, GROUND},

         {0, 3, GROUND},
         {1, 3, GROUND},
         {2, 3, GROUND},
         {3, 3, GROUND},
         {4, 3, GROUND},
         {5, 3, GROUND},
         {6, 3, GROUND},
         {7, 3, GROUND},
         {8, 3, GROUND},
         {9, 3, GROUND},

         {0, 4, GROUND},
         {1, 4, SPACEROCK},
         {2, 4, GROUND},
         {3, 4, CRATER},
         {4, 4, GROUND},
         {5, 4, GROUND},
         {6, 4, GROUND},
         {7, 4, GROUND},
         {8, 4, SPACEROCK},
         {9, 4, SPACEROCK},

         {0, 5, GROUND},
         {1, 5, GROUND},
         {2, 5, GROUND},
         {3, 5, GROUND},
         {4, 5, GROUND},
         {5, 5, ROCKETSHIP},
         {6, 5, GROUND},
         {7, 5, GROUND},
         {8, 5, GROUND},
         {9, 5, SPACEROCK},

         {0, 6, GROUND},
         {1, 6, GROUND},
         {2, 6, WORMHOLE},
         {3, 6, GROUND},
         {4, 6, GROUND},
         {5, 6, GROUND},
         {6, 6, GROUND},
         {7, 6, GROUND},
         {8, 6, GROUND},
         {9, 6, GROUND},

         {0, 7, CRATER},
         {1, 7, GROUND},
         {2, 7, GROUND},
         {3, 7, SPACEROCK},
         {4, 7, GROUND},
         {5, 7, GROUND},
         {6, 7, GROUND},
         {7, 7, GROUND},
         {8, 7, GROUND},
         {9, 7, GROUND},

         {0, 8, GROUND},
         {1, 8, CRATER},
         {2, 8, GROUND},
         {3, 8, GROUND},
         {4, 8, SPACEROCK},
         {5, 8, GROUND},
         {6, 8, SPACEROCK},
         {7, 8, WORMHOLE},
         {8, 8, GROUND},
         {9, 8, GROUND},

         {0, 9, GROUND},
         {1, 9, CRATER},
         {2, 9, GROUND},
         {3, 9, GROUND},
         {4, 9, GROUND},
         {5, 9, GROUND},
         {6, 9, GROUND},
         {7, 9, GROUND},
         {8, 9, GROUND},
         {9, 9, GROUND}};

//hidden aliens
const GameDefaults::AlienMap GameDefaults::ALIEN_LOCATIONS[GameDefaults::ALIEN_LOCATION_SIZE] =
        {{1, 0, PCMUSTARD},
         {3, 0, KHALEESI},
         {0, 1, VAPEBRO},
         {4, 1, PCMUSTARD},
         {0, 2, KHALEESI},
         {8, 2, VAPEBRO},
         {1, 4, PCMUSTARD},
         {8, 4, KHALEESI},
         {4, 8, VAPEBRO},
         {1, 9, KHALEESI}};

//hidden treasure items
const GameDefaults::ItemMap GameDefaults::ITEM_LOCATIONS[GameDefaults::ITEM_LOCATION_SIZE] =
        {{4, 0, PLUTONIUMORE},
         {1, 1, SHIPPART},
         {7, 1, SHIPPART},
         {3, 4, PLUTONIUMORE},
         {9, 4, SHIPPART},
         {9, 5, PLUTONIUMORE},
         {0, 7, PLUTONIUMORE},
         {3, 7, PLUTONIUMORE},
         {1, 8, SHIPPART},
         {6, 8, SHIPPART}};
