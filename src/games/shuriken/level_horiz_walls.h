

// LEVEL 2

#if YSize>24
    #define LV_HORIZ_WALLS_WIDTH ((XSize)/2+2)
    #define LV_HORIZ_WALLS_ADJUST 1
#else
    #define LV_HORIZ_WALLS_WIDTH (XSize)/2
    #define LV_HORIZ_WALLS_ADJUST 0
#endif

#define LV_HORIZ_WALLS_NO_OF_OBJECTS 6


#define LV_HORIZ_WALLS_OBJECTS \
    LV_HORIZ_WALLS_NO_OF_OBJECTS, \
	\
    1,1+YSize/5,LV_HORIZ_WALLS_WIDTH,1,WALL,_XL_YELLOW, \
    XSize-1-LV_HORIZ_WALLS_WIDTH,1+2*(YSize/5)-LV_HORIZ_WALLS_ADJUST,LV_HORIZ_WALLS_WIDTH,1,WALL,_XL_YELLOW, \
    \
    XSize-1-LV_HORIZ_WALLS_WIDTH,YSize-1-YSize/5,LV_HORIZ_WALLS_WIDTH,1,WALL,_XL_YELLOW, \
    1,YSize-1-2*(YSize/5)+LV_HORIZ_WALLS_ADJUST,LV_HORIZ_WALLS_WIDTH,1,WALL,_XL_YELLOW, \
    \
    1,YSize/5,LV_HORIZ_WALLS_WIDTH,1,DIAMOND,_XL_GREEN, \
    XSize-1-LV_HORIZ_WALLS_WIDTH,YSize-1-YSize/5+1,LV_HORIZ_WALLS_WIDTH,1,DIAMOND,_XL_GREEN


#define LV_HORIZ_WALLS_OBJECTS_SIZE LV_OBJECTS_SIZE(LV_HORIZ_WALLS_NO_OF_OBJECTS)


//

#define LV_HORIZ_WALLS_SHURIKENS \
    4,4,0, \
    2,2,\
    XSize-2,3, \
    2,YSize-2, \
    XSize-2,YSize-3, \
    \
    XSize/3-3,2, \
    XSize-1-XSize/3+3,2, \
    XSize/3-3,YSize-2, \
    XSize-1-XSize/3+3,YSize-2 \
    \

    

#define LV_HORIZ_WALLS_SHURIKENS_SIZE LV_SHURIKENS_SIZE(4,4,2)



#define LV_HORIZ_WALLS_NO_OF_WALLS 0

#define LV_HORIZ_WALLS_WALLS \
    0


#define LV_HORIZ_WALLS_WALLS_SIZE LC_WALLS_SIZE(LV_HORIZ_WALLS_NO_OF_WALLS)


