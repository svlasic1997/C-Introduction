// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
//Updated for Esplora 2013 TeamRursch185

// Headers
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>

// Mathematical constants
#define PI 3.14159

// Screen geometry
// Use ROWS and COLS for the screen height and width (set by system)
// MAXIMUMS
#define COLNUM 100
#define ROWNUM 80

// Character definitions taken from the ASCII table
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

// Number of samples taken to form an average for the accelerometer data
// Feel free to tweak this.  You may actually want to use the moving averages
// code you created last week 
#define NUM_SAMPLES 10  
#define TRUE 1
#define FALSE 0


// 2D character array which the maze is mapped into
char MAZE[COLNUM][ROWNUM];


// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty);

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void);

// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
void draw_character(int x, int y, char use);

// PRE: -1.0 < y_mag < 1.0
// POST: Returns tilt magnitude scaled to -1.0 -> 1.0
// You may want to reuse the pitch function written in previous labs.  
float calc_pitch(float y_mag);

void updatebuffer(double buffer[], int length, double new_item);

double calc_roll(double x_mag);

// Main - Run with './explore.exe -t -a -b' piped into STDIN
void main(int argc, char* argv[])
{
    double ax, ay, az; // Values for the accelerations
    int b1, b2, b3, b4, b5, b6; // Variables for the buttons, slider, etc.
    int time = 0;
    int inittime;
    int posx = 45;
    int posy = 0;
    int move;
    int difficulty = 20;
    double arcsin = 0.0;
    int winner = TRUE;
    
    // setup screen    
    initscr();
    refresh();
    
    if (argc>1) {
        sscanf(argv[1], "%d", &difficulty );
        printf("You entered a buffer length of %d\n", difficulty);
    }
    else {
        printf("Enter a length on the command line\n");
        return;
    }
    
    // Generate and draw the maze, with initial avatar
    generate_maze(difficulty);
    draw_maze();
    draw_character(posx, posy, AVATAR);
    
    // Read accelerometer data to get ready for using moving averages.    
    scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &time, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &b6);
    inittime = time;
    //updatebuffer(double MAZE[], int length, double new_item)

    
    // Event loop
    do
    {
        
        // Read data, update average
        scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &time, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &b6);
        
        // Is it time to move?  if so, then move avatar
        if(time > inittime + 100)
        {
                //Checks if Avatar should move down
                if(MAZE[posx][posy + 1] != WALL)
                {
                    posy++;                 
                }

                draw_character(posx, posy, AVATAR);
                inittime = time;
                
                draw_character(posx, posy - 1 , ' ');
                
                // Calculate the sin  of the tilt in the x direction
                arcsin = calc_roll(ax);
                
                //Check if the avatar should move left
                if(arcsin < -PI / 6 && posx > 0 && MAZE[posx + 1][posy] != WALL)
                {
                    draw_character(posx, posy, ' ');
                    posx++;
                    draw_character(posx, posy, AVATAR);
                    
                        
                    
                }
                //Check if the avatar should move right
                else if(arcsin > PI / 6 && posx < COLNUM-1 && MAZE[posx - 1][posy] != WALL)
                {
                    draw_character(posx, posy, ' ');
                    posx--;
                    draw_character(posx, posy, AVATAR);
                    
                }
                //Check if the avatar can even move. If not break the loop
                if(MAZE[posx + 1][posy] == WALL && MAZE[posx - 1][posy] == WALL && MAZE[posx][posy + 1] == WALL)
                {
                    winner = FALSE;
                    break;
                }
        }   
    } while(posy != ROWNUM-1); // Change this to end game at right time 

    // Print the win message
    endwin();
    
    //Check if the avatar won
    if(winner == FALSE)
    {
        printf("YOU LOSE!\n");
    }
    else
    {
        printf("YOU WIN!\n");
    }
}



// PRE: 0 < x < COLS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//YOU DO NOT NEED TO CHANGE THIS FUNCTION.
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);    
    refresh();
}

// POST: Generates a random maze structure into MAZE[][]
//You will want to use the rand() function and maybe use the output %100.  
//You will have to use the argument to the command line to determine how 
//difficult the maze is (how many maze characters are on the screen).
void generate_maze(int difficulty)
{
    for(int i = 0; i < COLNUM; i++)
    {
        for(int j = 0; j < ROWNUM; j++)
        {
            if(rand() % 100 <= difficulty)
            {
                MAZE[i][j] = EMPTY_SPACE;
            }
            else
            {
                MAZE[i][j] = WALL;
            }
        }
    }
}

// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void)
{
    for(int i = 0; i < COLNUM; i++)
    {
        for(int j = 0; j < ROWNUM; j++)
        {
            draw_character(i, j, MAZE[i][j]);
        }
    }
}

// Takes the accelaration of x and checks if its greater 1 and sets it to 1, if its less than 1. Then returns the arcsin of
// the acceleration of x
double calc_roll(double x_mag)
{
    if(x_mag > 1.0)
        x_mag = 1.0;
    if(x_mag < -1.0)
        x_mag = -1.0;
    return asin(x_mag);
}