#ifndef _INIT_IMAGES_H
#define _INIT_IMAGES_H

// TODO: MOVE THIS TO TARGET SPECIFIC SETTINGS
#define CPC_WHITE 1
#define CPC_YELLOW 2 
#define CPC_RED 3
#define CPC_BLACK 4


#ifndef COLOR_CYAN
	#define COLOR_CYAN COLOR_BLUE
#endif

#if defined(NO_GRAPHICS) || defined(NO_PRINT)
    #if !defined(COLOR_RED)
        #define COLOR_RED 0
    #endif
    #if !defined(COLOR_BLUE)
        #define COLOR_BLUE 0
    #endif
    #if !defined(COLOR_WHITE)
        #define COLOR_WHITE 0
    #endif
    #if !defined(COLOR_YELLOW)
        #define COLOR_YELLOW 0
    #endif
    #if !defined(COLOR_GREEN)
        #define COLOR_GREEN 0
    #endif
#endif 


#if defined(CPCRSLIB)
	#define _PLANE_COLOR CPC_YELLOW
	#define _SMALL_TWO_WINDOW_WALL_1_COLOR CPC_WHITE
	#define _TWO_WINDOW_WALL_1_COLOR CPC_YELLOW
	#define _WALL_1_COLOR CPC_RED
	#define _BOMB_COLOR CPC_WHITE
	#define _ROAD_COLOR CPC_WHITE
	#define _BRICK_COLOR CPC_YELLOW
    #define _WALL_2_COLOR CPC_YELLOW
	#define _THREE_WINDOW_WALL_2_COLOR CPC_WHITE
	#define _TWO_WINDOW_WALL_2_COLOR CPC_RED
	#define _SMALL_TWO_WINDOW_WALL_2_COLOR CPC_YELLOW	
#elif defined(__PC6001__) || defined(__SPC1000__)
	#define _PLANE_COLOR COLOR_BLUE 
	#define _SMALL_TWO_WINDOW_WALL_1_COLOR COLOR_CYAN
	#define _TWO_WINDOW_WALL_1_COLOR COLOR_YELLOW
	#define _WALL_1_COLOR COLOR_RED
	#define _BOMB_COLOR COLOR_CYAN
	#define _ROAD_COLOR COLOR_BLUE
	#define _BRICK_COLOR COLOR_YELLOW
    #define _WALL_2_COLOR COLOR_YELLOW
	#define _THREE_WINDOW_WALL_2_COLOR COLOR_YELLOW
	#define _TWO_WINDOW_WALL_2_COLOR COLOR_RED
	#define _SMALL_TWO_WINDOW_WALL_2_COLOR COLOR_YELLOW
#elif defined(NO_GRAPHICS)
	#define _PLANE_COLOR 0 
	#define _SMALL_TWO_WINDOW_WALL_1_COLOR 0
	#define _TWO_WINDOW_WALL_1_COLOR 0
	#define _WALL_1_COLOR 0
	#define _BOMB_COLOR 0
	#define _ROAD_COLOR 0
	#define _BRICK_COLOR 0
    #define _WALL_2_COLOR 0
	#define _THREE_WINDOW_WALL_2_COLOR 0
	#define _TWO_WINDOW_WALL_2_COLOR 0
	#define _SMALL_TWO_WINDOW_WALL_2_COLOR 0
#else
	#define _PLANE_COLOR COLOR_CYAN
	#define _SMALL_TWO_WINDOW_WALL_1_COLOR COLOR_WHITE
	#define _TWO_WINDOW_WALL_1_COLOR COLOR_YELLOW
	#define _WALL_1_COLOR COLOR_RED
	#define _BOMB_COLOR COLOR_WHITE
	#define _ROAD_COLOR COLOR_CYAN
	#define _BRICK_COLOR COLOR_GREEN
    #define _WALL_2_COLOR COLOR_YELLOW
	#define _THREE_WINDOW_WALL_2_COLOR COLOR_WHITE
	#define _TWO_WINDOW_WALL_2_COLOR COLOR_RED
	#define _SMALL_TWO_WINDOW_WALL_2_COLOR COLOR_YELLOW
#endif


void INIT_IMAGES(void);




#endif // _INIT_IMAGES_H

