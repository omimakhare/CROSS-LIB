#ifndef _MOVE_SNAKE_H
#define _MOVE_SNAKE_H


#define SNAKE_UP 0

#define SNAKE_DOWN 1

#define SNAKE_LEFT 2

#define SNAKE_RIGHT 3

#define HORIZONTAL(movement) ((movement)>SNAKE_DOWN)
#define VERTICAL(movement) ((movement)<SNAKE_LEFT)

#define hits_wall(x,y) \
    ((x)<1 || ((x)>=XSize-1) || (y)<1 || ((y)>=YSize-1))


uint8_t move_snake(void);

#endif // _MOVE_SNAKE_H
