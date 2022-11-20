/* --------------------------------------------------------------------------------------- */ 
// 
// CROSS SHOOT by Fabrizio Caruso
//
// Fabrizio_Caruso@hotmail.com
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.

// Permission is granted to anyone to use this software for non-commercial applications, 
// subject to the following restrictions:

// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software in
// a product, an acknowledgment in the product documentation would be
// appreciated but is not required.

// 2. Altered source versions must be plainly marked as such, and must not
// be misrepresented as being the original software.

// 3. This notice may not be removed or altered from any source distribution.
/* --------------------------------------------------------------------------------------- */ 

#include "cross_lib.h"

#define WORD_SIZE 5

#define MAX_HEIGHT 8

#define START_X ((XSize)/2-3)
#define START_Y (((YSize)-(MAX_HEIGHT)/2)-2)

#define MIN_PLAYER_X 0
#define MAX_PLAYER_X (1+WORD_SIZE)

#define PLAYER_Y (START_Y+1)


#define END_Y (START_Y+10)

#define LAST_LEVEL 10

#define VERTICAL_PLAYER_TILE _TILE_0

#define UP_ARROW_TILE _TILE_5
#define DOWN_ARROW_TILE _TILE_7
#define LEFT_ARROW_TILE _TILE_3 
#define RIGHT_ARROW_TILE _TILE_4
#define HORIZONTAL_LEFT_PLAYER_TILE _TILE_2
#define HORIZONTAL_RIGHT_PLAYER_TILE _TILE_8


#define PLAYER_COLOR _XL_WHITE
#define EMPTY_SLOT_TILE _TILE_1
#define EMPTY_SLOT_COLOR _XL_WHITE


#define INITIAL_DROP ((WORD_SIZE)*3)

#define NO_OF_PRECOMPUTED_WORDS 4

#define SIZE_OF_PRECOMPUTED_WORDS ((NO_OF_PRECOMPUTED_WORDS)*(WORD_SIZE))

#define NO_OF_RANDOM_LETTERS SIZE_OF_PRECOMPUTED_WORDS
//SIZE_OF_PRECOMPUTED_WORDS

#define NO_OF_PRECOMPUTED_LETTERS ((SIZE_OF_PRECOMPUTED_WORDS)+(NO_OF_RANDOM_LETTERS))

#include "dictionary.h"

uint8_t player_x;
uint8_t alive;
uint8_t slot_index;
uint8_t matrix[WORD_SIZE][MAX_HEIGHT];
uint8_t matrix_height[WORD_SIZE];
uint8_t victory;
uint8_t counter;
uint8_t first_index;
uint8_t last_index;
uint16_t points;
uint16_t record;
uint8_t level;

uint8_t precomputed_letter[NO_OF_PRECOMPUTED_LETTERS];
uint8_t next_letter_index;

// First letter position indices
extern const uint16_t dictionary_index[ALPHABET_SIZE+1];

// 16 most common letters in English 5-letter words
// E A R I O T N S L C U D P M H Y
const uint8_t letter[ALPHABET_SIZE] = {'E', 'A', 'R', 'I', 'O', 'T', 'N', 'S' ,'L', 'C', 'U', 'D', 'P', 'M', 'H', 'Y'};


const uint8_t LETTER_COLOR[ALPHABET_SIZE/4] = {_XL_WHITE, _XL_YELLOW, _XL_CYAN, _XL_GREEN };


#define SLOT_SPACING 2

void draw_slot(uint8_t x, uint8_t y, uint8_t letter_index)
{
    _XL_SET_TEXT_COLOR(LETTER_COLOR[letter_index>>2]);
    _XL_CHAR(START_X+SLOT_SPACING*x,START_Y-SLOT_SPACING*y,letter[letter_index]);
    _XL_SET_TEXT_COLOR(_XL_WHITE);
}

void draw_empty_slot(uint8_t x, uint8_t y)
{
    _XL_DRAW(START_X+SLOT_SPACING*x,START_Y-SLOT_SPACING*y,EMPTY_SLOT_TILE,EMPTY_SLOT_COLOR);
}


void display_bottom_row(void)
{
    uint8_t i;
    
    for(i=0;i<WORD_SIZE;++i)
    {
        draw_slot(i,0,matrix[i][0]);
    }
}


void display_column(uint8_t row)
{
    uint8_t i;
    
    for(i=0;i<matrix_height[row];++i)
    {
        draw_slot(row,i,matrix[row][i]);
    }  
    for(;i<MAX_HEIGHT;++i)
    {
        //_XL_DELETE(row,i);
        // TODO: Debug
        draw_empty_slot(row,i);
        //_XL_DRAW(START_X+row,START_Y-i,EMPTY_SLOT_TILE,EMPTY_SLOT_COLOR);
    }
}


void display_player_column(void)
{
    display_column(player_x-1);
}


void display_matrix(void)
{
    uint8_t i;
    
    for(i=0;i<WORD_SIZE;i++)
    {
        display_column(i);
    }

}

#if XSize>=32 
    #define DISPLAY_DROPPED_LETTERS
#endif

#if defined(DISPLAY_DROPPED_LETTERS)
void display_dropped_letters(void)
{
    _XL_PRINTD(30,0,4,next_letter_index);
}
#endif


void drop_letter(void)
{
    uint8_t height;
    uint8_t new_letter;
    
    _XL_PING_SOUND();
    
    height = matrix_height[slot_index];
    
    
    // TODO: DEBUGGING why EEEEE (0,0,0,0,0) is seen in the dictionary
    // new_letter = 0;
    
    
    if(next_letter_index<NO_OF_PRECOMPUTED_LETTERS)
    {
        new_letter = precomputed_letter[next_letter_index];
        ++next_letter_index;
    }
    else
    {
        new_letter = _XL_RAND()%ALPHABET_SIZE;
    }

    #if defined(DISPLAY_DROPPED_LETTERS)
    display_dropped_letters();
    #endif

    matrix[slot_index][height]= new_letter;
    draw_slot(slot_index,height,new_letter);
    if(height==MAX_HEIGHT-1)
    {
        alive = 0;
    }
    
    ++matrix_height[slot_index];
                
    slot_index = (slot_index + 1) % WORD_SIZE;
}

// Player display routines
void delete_player(void)
{
    if(player_x==MIN_PLAYER_X)
    {
        _XL_DELETE(START_X-SLOT_SPACING+MIN_PLAYER_X, PLAYER_Y-1);
    }
    else if(player_x==MAX_PLAYER_X)
    {
        _XL_DELETE(START_X-SLOT_SPACING+SLOT_SPACING*MAX_PLAYER_X, PLAYER_Y-1);
    }
    else
    {
        _XL_DELETE(START_X-SLOT_SPACING+SLOT_SPACING*player_x, PLAYER_Y);
    }
}


void display_vertical_player(uint8_t player_tile)
{
    _XL_DRAW(START_X-SLOT_SPACING+SLOT_SPACING*player_x, PLAYER_Y, player_tile, PLAYER_COLOR);
}


void display_horizontal_left_player(uint8_t player_tile)
{
    _XL_DRAW(START_X-SLOT_SPACING+MIN_PLAYER_X, PLAYER_Y-1, player_tile, PLAYER_COLOR);
}


void display_horizontal_right_player(uint8_t player_tile)
{
    _XL_DRAW(START_X-SLOT_SPACING+SLOT_SPACING*MAX_PLAYER_X, PLAYER_Y-1, player_tile, PLAYER_COLOR); 
}


void display_player(void)
{
    
    if(player_x==MIN_PLAYER_X)
    {
        display_horizontal_left_player(HORIZONTAL_LEFT_PLAYER_TILE);
    }
    else if(player_x==MAX_PLAYER_X)
    {
        display_horizontal_right_player(HORIZONTAL_RIGHT_PLAYER_TILE);
    }
    else
    {
        display_vertical_player(VERTICAL_PLAYER_TILE);
    }
}
    
//

void right_rotate_row(void)
{
    uint8_t old_first;
    uint8_t i;
    
    _XL_TICK_SOUND();

    old_first = matrix[0][0];
    
    for(i=0;i<WORD_SIZE-1;++i)
    {
        matrix[i][0] = matrix[i+1][0];
    }
  
    matrix[WORD_SIZE-1][0] = old_first;
}


void left_rotate_row(void)
{
    uint8_t old_last;
    uint8_t i;
    
    _XL_TICK_SOUND();
    
    old_last = matrix[WORD_SIZE-1][0];
    
    for(i=WORD_SIZE-1;i>0;--i)
    {
        matrix[i][0] = matrix[i-1][0];
    }
  
    matrix[0][0] = old_last;
}


void up_rotate_column(void)
{
    uint8_t old_top;
    uint8_t i;
    
    _XL_TICK_SOUND();    
    
    old_top = matrix[player_x-1][matrix_height[player_x-1]-1];
    
    for(i=matrix_height[player_x-1]-1;i>0;--i)
    {
        matrix[player_x-1][i] = matrix[player_x-1][i-1];
    }
  
    matrix[player_x-1][0] = old_top;
    
}


void down_rotate_column(void)
{
    uint8_t old_bottom;
    uint8_t i;

    _XL_TICK_SOUND();
    
    old_bottom = matrix[player_x-1][0];
    
    for(i=0;i<matrix_height[player_x-1]-1;++i)
    {
        matrix[player_x-1][i] = matrix[player_x-1][i+1];
    }
  
    matrix[player_x-1][matrix_height[player_x-1]-1] = old_bottom;
    
}


// 'E', 'A', 'R', 'I', 
// 'O', 'T', 'N', 'S' ,
// 'L', 'C', 'U', 'D', 
// 'P', 'M', 'H', 'Y'


uint8_t letter_index(uint8_t letter)
{
    switch(letter)
    {
        case 'E':
            return 0;
        case 'A':
            return 1;
        case 'R':
            return 2;
        case 'I':
            return 3;
        case 'O':
            return 4;
        case 'T':
            return 5;
        case 'N':
            return 6;
        case 'S':
            return 7;
        case 'L':
            return 8;
        case 'C':
            return 9;
        case 'U':
            return 10;
        case 'D':
            return 11;
        case 'P':
            return 12;
        case 'M':
            return 13;
        case 'H':
            return 14;
        case 'Y':
            return 15;
    }
    return 16;
}


// Score for guessed word (less common letters give more points)
// 'E', 'A', 'R', 'I',  ->  1 point
// 'O', 'T', 'N', 'S' , ->  4 points
// 'L', 'C', 'U', 'D',  ->  7 points
// 'P', 'M', 'H', 'Y'   -> 10 points
uint16_t word_score(void)
{
    uint16_t score = 0;
    uint8_t i;
    
    for(i=0;i<WORD_SIZE;++i)
    {
        // score+=1+((letter_index(matrix[i][0])>>2));
        score+=1+3*((matrix[i][0])>>2);

        // _XL_PRINTD(i*4,YSize-2,2,1+((letter_index(matrix[i][0])>>2)));
    }
    return score;
}


uint8_t first_letter(uint16_t index)
{
    uint8_t i;
    
    i = 1;
    
    while(i<15)
    {
        if(index<dictionary_index[i])
        {
            return i-1;
        }
        ++i;
    }
    return 15;
}


// It compresses the last 4 letters of the bottom matrix in 4-bit per letter format
uint16_t compress_bottom_word(void)
{    
    // TODO: Optimize space with a loop
    // return (uint16_t)letter_index(matrix[4][0])+(((uint16_t)letter_index(matrix[3][0]))<<4)+(((uint16_t)letter_index(matrix[2][0]))<<8)+(((uint16_t)letter_index(matrix[1][0]))<<12);
    return (uint16_t)matrix[4][0]+(((uint16_t)matrix[3][0])<<4)+(((uint16_t)matrix[2][0])<<8)+(((uint16_t)matrix[1][0])<<12);

}


// Indices are unsigned and the minimum input for last_index is 1
// If last_index becomes 0, then first_index>last_index and it returns 0
uint8_t binary_search(uint16_t search_word, uint16_t first_index, uint16_t last_index)
{
    uint16_t middle_index;
    uint16_t middle_word;
    
    while(last_index>=first_index)
    {    
        middle_index = (first_index+last_index)/2;
        
        middle_word = dictionary[middle_index];
        
        if(dictionary[middle_index]==search_word)
        {
            return 1;
        }
        else if(middle_word<search_word)
        {
            first_index = middle_index + 1;
        }
        else
        {
            last_index = middle_index - 1;
        }

    }

    return 0;
}


uint8_t word_in_dictionary(void)
{
    uint8_t first_char_index = matrix[0][0];    
    
    return binary_search(compress_bottom_word(),dictionary_index[first_char_index], dictionary_index[first_char_index+1]-1);
}


void remove_bottom_word(void)
{
    uint8_t i;
    uint8_t j;
    
    for(i=0;i<WORD_SIZE;++i)
    {
        
        for(j=0;j<matrix_height[i]-1;++j)
        {
            matrix[i][j]=matrix[i][j+1];
        }
        if(matrix_height[i])
        {
           --matrix_height[i]; 
        }
        if(!matrix_height[i])
        {
            victory = 1;
        }
    }
    display_matrix();
}


void display_score(void)
{
    _XL_PRINTD(0,0,4,points);
}


void handle_input(void)
{
    uint8_t input; 
    input = _XL_INPUT();
        
    if(_XL_LEFT(input))
    {
        if(player_x > MIN_PLAYER_X)
        {
            delete_player();
            --player_x;
        }
        else
        {
            display_horizontal_left_player(LEFT_ARROW_TILE);
            _XL_SLOW_DOWN(_XL_SLOW_DOWN_FACTOR);

            right_rotate_row();
            display_bottom_row();
        }
    }
    else if(_XL_RIGHT(input))
    {
        if((player_x < MAX_PLAYER_X))
        {
            delete_player();
            ++player_x;
        }
        else
        {
            display_horizontal_right_player(RIGHT_ARROW_TILE);
            _XL_SLOW_DOWN(_XL_SLOW_DOWN_FACTOR);
    
            left_rotate_row();
            display_bottom_row();
        }
    }
    else if(_XL_UP(input) && player_x>MIN_PLAYER_X && player_x<MAX_PLAYER_X)
    {
        display_vertical_player(UP_ARROW_TILE);
        _XL_SLOW_DOWN(_XL_SLOW_DOWN_FACTOR);

        up_rotate_column();
        display_player_column();
    }
    else if(_XL_DOWN(input))
    {
        if(player_x>MIN_PLAYER_X && player_x<MAX_PLAYER_X)
        {
            display_vertical_player(DOWN_ARROW_TILE);
            _XL_SLOW_DOWN(_XL_SLOW_DOWN_FACTOR);

            down_rotate_column();   
            display_player_column();
        }
        else if(player_x==MIN_PLAYER_X)
        {
            delete_player();
            ++player_x;
        }
        else if(player_x==MAX_PLAYER_X)
        {
            delete_player();
            --player_x;
        }
    }
    else if(_XL_FIRE(input))
    {
        if(word_in_dictionary())
        {
            
            _XL_SET_TEXT_COLOR(_XL_YELLOW);
            _XL_PRINT(XSize/2-3,YSize-3, "WORD FOUND");
            _XL_ZAP_SOUND();
            
            points += word_score();
            display_score();
            _XL_SLOW_DOWN(_XL_SLOW_DOWN_FACTOR);
            _XL_PRINT(XSize/2-3,YSize-3, "          ");
            _XL_EXPLOSION_SOUND();
            remove_bottom_word();
        }
        else
        {
            _XL_PING_SOUND();
            drop_letter();
        }
    }
    display_player();
}


void title_screen(void)
{
    _XL_CLEAR_SCREEN();

    _XL_SET_TEXT_COLOR(_XL_WHITE);

    _XL_PRINT_CENTERED("WORDIZ");
    
    _XL_WAIT_FOR_INPUT();
}


void initialize_input_output(void)
{
    _XL_INIT_GRAPHICS();

    _XL_INIT_INPUT();
    
    _XL_INIT_SOUND();
}


void initialize_game(void)
{
    
    points = 0;
    level = 1; 
    alive = 1;
    
}


void display_level(void)
{
    _XL_PRINTD(XSize-3,0,2,level);
}


// TODO: Broken
void print_word(uint8_t x, uint8_t y, uint16_t dictionary_index)
{
    uint8_t i;
    
    uint16_t compressed_code = dictionary[dictionary_index];

    
    _XL_CHAR(x,y,letter[first_letter(dictionary_index)]);
    for(i=1;i<WORD_SIZE;++i)
    {
        _XL_CHAR(x+i,y,letter[(compressed_code>>((4-i)*4))&0x000F]);
    }
}


// TODO: check whether XOR trick is better
void swap(uint8_t i, uint8_t j)
{
    uint8_t aux;
    
    aux = precomputed_letter[i];
    precomputed_letter[i] = precomputed_letter[j];
    precomputed_letter[j] = aux;
}


// Shuffle with Fisher-Yates algorithm
void shuffle(void)
{
    uint8_t i;
    
    for(i=NO_OF_PRECOMPUTED_LETTERS-1;i>0;--i)
    {
        swap(i,(_XL_RAND())%i);
    }
}


void display_record(void)
{
    _XL_SET_TEXT_COLOR(_XL_CYAN);
    _XL_PRINT(6,0,"HI");
    _XL_SET_TEXT_COLOR(_XL_WHITE);
    _XL_PRINTD(8,0,4,record);
}


// Score for guessed word (less common letters give more points)
// 'E', 'A', 'R', 'I',  ->  1 point
// 'O', 'T', 'N', 'S' , ->  4 points
// 'L', 'C', 'U', 'D',  ->  7 points
// 'P', 'M', 'H', 'Y'   -> 10 points

#define INSTRUCTIONS_START_Y YSize/4

#if XSize>=32
    #define INSTR_X_SPACING 2
#else
    #define INSTR_X_SPACING 1
#endif



void display_instructions(void)
{
    _XL_SET_TEXT_COLOR(_XL_WHITE);
    
    _XL_PRINTD(5*INSTR_X_SPACING,INSTRUCTIONS_START_Y,  2, 1);
    _XL_PRINTD(5*INSTR_X_SPACING,INSTRUCTIONS_START_Y+2,2, 4);
    _XL_PRINTD(5*INSTR_X_SPACING,INSTRUCTIONS_START_Y+4,2, 7);
    _XL_PRINTD(5*INSTR_X_SPACING,INSTRUCTIONS_START_Y+6,2,10);
    
    #if INSTR_X_SPACING==2
        _XL_PRINT(1,INSTRUCTIONS_START_Y,   "E A R I");
        
        _XL_SET_TEXT_COLOR(_XL_YELLOW);
        _XL_PRINT(1,INSTRUCTIONS_START_Y+2, "O T N S");
        
        _XL_SET_TEXT_COLOR(_XL_CYAN);
        _XL_PRINT(1,INSTRUCTIONS_START_Y+4, "L C U D");

        _XL_SET_TEXT_COLOR(_XL_GREEN);
        _XL_PRINT(1,INSTRUCTIONS_START_Y+6, "P M H Y");
    #else
        _XL_PRINT(0,INSTRUCTIONS_START_Y,   "EARI");
        
        _XL_SET_TEXT_COLOR(_XL_YELLOW);
        _XL_PRINT(0,INSTRUCTIONS_START_Y+2, "OTNS");
        
        _XL_SET_TEXT_COLOR(_XL_CYAN);
        _XL_PRINT(0,INSTRUCTIONS_START_Y+4, "LCUD");

        _XL_SET_TEXT_COLOR(_XL_GREEN);
        _XL_PRINT(0,INSTRUCTIONS_START_Y+6, "PMHY");        
    #endif
    
}


void initialize_level(void)
{
    uint8_t i;
    uint8_t j;
    
    uint16_t random_dictionary_index;
    uint16_t compressed_code;
    
    alive = 1;
    victory = 0;
    slot_index = 0;
    player_x = 2;
    counter = 1;
    next_letter_index = 0;
    
    display_player();
    
    
    for(i=0;i<WORD_SIZE;++i)
    {
        matrix_height[i]=0;
    }

    for(i=0;i<NO_OF_PRECOMPUTED_WORDS;++i)
    {
        random_dictionary_index = _XL_RAND()%DICTIONARY_SIZE;
        
        // print_word(0,YSize-2, random_dictionary_index);
        // _XL_WAIT_FOR_INPUT();
        
        compressed_code = dictionary[random_dictionary_index];
        
        precomputed_letter[WORD_SIZE*i] = first_letter(random_dictionary_index);
        for(j=1;j<WORD_SIZE;++j)
        {
            precomputed_letter[WORD_SIZE*i+j]=(compressed_code>>((4-j)*4))&0x000F;
        }
    }

    for(i=SIZE_OF_PRECOMPUTED_WORDS;i<NO_OF_PRECOMPUTED_LETTERS;++i)
    {
        precomputed_letter[i]=_XL_RAND()%ALPHABET_SIZE;
    }

    // Fisher-Yates shuffle
    shuffle();

    // display_borders();

    display_matrix();
    
    display_instructions();
    
    #if defined(DISPLAY_DROPPED_LETTERS)
    display_dropped_letters();
    #endif
    
    display_record();
    
}


void re_start_game(void)
{
    title_screen();
    
    _XL_CLEAR_SCREEN();

    initialize_game();
    
    display_score();
}


void end_game(void)
{
    _XL_PRINT(XSize/2-4, YSize-3, "GAME OVER");
    _XL_SLEEP(1);
    _XL_WAIT_FOR_INPUT();
}


void handle_drop(void)
{
    if(!(counter&63))
    {
        drop_letter();
    }
}


void handle_record_update(void)
{
    if(points>record)
    {
        record = points;
    }
}


void initial_letter_drop(void)
{
    uint8_t i;
    
    _XL_WAIT_FOR_INPUT();
    
    for(i=0;i<INITIAL_DROP;++i)
    {
        drop_letter();
        _XL_SLOW_DOWN(_XL_SLOW_DOWN_FACTOR);
    }     
    
    display_level();
}



//
int main(void)
{        
    initialize_input_output();
    
    record = 0;
    
    // main loop
    while(1)
    {
        re_start_game();

        // game main loop
        while((level<LAST_LEVEL+1) && alive)
        {
            initialize_level();

            initial_letter_drop();

            // level main loop
            while(alive && !victory)
            {    
                handle_drop();
                
                handle_input();
                
                _XL_SLOW_DOWN(_XL_SLOW_DOWN_FACTOR);
                
                ++counter;
                
            }
            if(alive)
            {
                ++level;
            }
            else
            {
               _XL_SHOOT_SOUND();   
            }
        }
        end_game();
        handle_record_update();
    }

    return EXIT_SUCCESS;
}

