#include "cross_lib.h"
#include "snake.h"
#include "move_snake.h"

uint8_t snake_x[MAX_SNAKE_LENGTH];
uint8_t snake_y[MAX_SNAKE_LENGTH];

uint8_t snake_length;

uint8_t snake_head;

Image *head_image_ptr;

uint8_t map[XSize][YSize];
uint8_t snake_copy_x[MAX_SNAKE_LENGTH];
uint8_t snake_copy_y[MAX_SNAKE_LENGTH];

uint8_t snake_direction;

extern Image BODY_IMAGE;
extern Image HORIZONTAL_HEAD_IMAGE;
extern Image VERTICAL_HEAD_IMAGE;

extern uint8_t snake_head_x;
extern uint8_t snake_head_y;

extern uint8_t level;

uint8_t initial_snake_length[] = {XSize/2,XSize/4,XSize/2,XSize/2,2*XSize/3,XSize/4,XSize/2-2,XSize/4,3*XSize/4,2*XSize/3,5*XSize/6,XSize-5,3,XSize-5,XSize-5,XSize-5};


void draw_head(void)
{
    _XLIB_DRAW(snake_x[snake_head],snake_y[snake_head],head_image_ptr);
}

void delete_body_part(uint8_t i)
{
    _XLIB_DELETE(snake_x[i],snake_y[i]);
    map[snake_x[i]][snake_y[i]] = EMPTY;
}

void draw_body_part(uint8_t i)
{
    _XLIB_DRAW(snake_x[i],snake_y[i],&BODY_IMAGE);
    map[snake_x[i]][snake_y[i]] = DEADLY;
}


void init_map(void)
{
    uint8_t i;
    uint8_t j;
    
    for(i=0;i<XSize;++i)
    {
        for(j=0;j<YSize;++j)
        {
            map[i][j]=EMPTY;
        }
    }
}


void init_snake(void)
{

    uint8_t i;
    
    snake_length = initial_snake_length[(level-1)&15];
    
    snake_head = 0;
    
    for(i=0;i<snake_length;++i)
    {
        snake_x[(i+snake_head)%snake_length] = XSize/2+snake_length/2-i-1;
        snake_y[(i+snake_head)%snake_length] = YSize/2;
        draw_body_part((i+snake_head) % snake_length);
        DO_SLOW_DOWN(SLOW_DOWN);
    }
    
    
    head_image_ptr = &HORIZONTAL_HEAD_IMAGE;
    
    snake_direction = SNAKE_RIGHT;
    
    draw_head();
    
    snake_head_x = snake_x[snake_head];
    snake_head_y = snake_y[snake_head];
    

}

void snake_grows(void)
{
    uint8_t i;
    uint8_t x;
    uint8_t y;
    
    if(snake_length<MAX_SNAKE_LENGTH)
    {
        // Generate head at index 0
        
        x = snake_head_x; 
        y = snake_head_y;

        switch(snake_direction)
        {
            case SNAKE_RIGHT:
                x = snake_head_x+1;
            case SNAKE_LEFT:
                x = snake_head_x-1;
            break;
            case SNAKE_UP:
                y = snake_head_y-1;
            break;
            case SNAKE_DOWN:
                y = snake_head_y+1;
            break;
        }
        
        if(!(map[x][y]))
        {
            
            snake_copy_x[0] = x;
            snake_copy_y[0] = y;
        
            // Copy snake body starting at index 1
            for(i=0;i<snake_length;++i)
            {   
                x = (i+snake_head)%snake_length; // store
                snake_copy_x[i+1]=snake_x[x];
                snake_copy_y[i+1]=snake_y[x];
            }
            
            // New head is at index 0
            snake_head = 0;
            
            // New length = old length + 1
            ++snake_length;
            
            // Copy the new snake into snake array
            for(i=0;i<snake_length;++i)
            {
                snake_x[i] = snake_copy_x[i];
                snake_y[i] = snake_copy_y[i];
                
                if(i)
                {
                    draw_body_part(i);
                }
            }
            draw_head();
            snake_head_x = snake_x[snake_head];
            snake_head_y = snake_y[snake_head];
        }
    }
}


