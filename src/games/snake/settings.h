#ifndef _SETTINGS_H
#define _SETTINGS_H

#define INITIAL_LEVEL 1
// #define DEBUG_LEVELS
// #define DEBUG_SLOWDOWN
// #define DEBUG_APPLES
// #define DEBUG_ACHIEVEMENTS
// #define NO_EXTRA_TITLE
// #define DEBUG_FREEZ
// #define NO_ACHIEVEMENTS_SCREEN

#define FINAL_LEVEL 32

#define INITIAL_LIVES       5U

#define EXTRA_POINTS        5U
#define APPLE_POINTS       20U
#define COIN_POINTS        25U
#define SUPER_COIN_POINTS 100U

#define EXTRA_LIFE_THRESHOLD 5000U

#define INITIAL_APPLE_COUNT 10U

#define APPLE_COUNT_INCREASE 2U

#define SOME_EXTRA 10
#define MANY_EXTRA ((XSize)+16)

#define MAX_COIN_COUNT 3U

#define SPEED_INCREASE_THRESHOLD 20U

#define SPAWNED_APPLE_START 2U

#define EXTRA_COIN_SPAWN_THRESHOLD 2U

// BONUS/SECRET LEVELS THRESHOLD
#define MAGIC_WALL_THRESHOLD 12
#define SUPER_COIN_THRESHOLD (12+XSize)
#define EXTRA_1UP_THRESHOLD ((SUPER_COIN_THRESHOLD)+15)

#define TRANSPARENT_TRIGGER 20

#define FEW_MINES_SLOWDOWN ((SLOW_DOWN)/8)

#define MAX_APPLES 24

// This is to accout for extra length gained by eating extra points ($)
#define EXTRA_LENGTH 10

#if !defined(MAX_SNAKE_LENGTH)
    #define MAX_SNAKE_LENGTH ((XSize/4)+((NUMBER_OF_MAPS-1)/4)+(MAX_APPLES)+((MAX_APPLES)/8)+EXTRA_LENGTH)
#endif

#define MAX_NUMBER_OF_HORIZONTAL_MINES 4
#define MAX_NUMBER_OF_VERTICAL_MINES 2

#define NUMBER_OF_MAPS 16

#define NUMBER_OF_STRINGS 5

#define MAX_STRING_SIZE (6+1)


#endif // _SETTINGS_H

