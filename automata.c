/**
 * Creates 1D cellular automata.
 * Notable rules: 30, 110, 126. Set random_flag to 1 for random starting values, otherwise only center will be enabled.
 * Ideal settings for a 1080p monitor is 150x60. Weird glitches can occur in certain numbers...
 * @author Lloyd Degnan (wldegnan)
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define RULE 1
#define WIDTH 2
#define GENERATIONS 3
#define MODE 4

/** Main loop. */
int main( int argc, char *argv[] ) {

  //Get the values from the params
  if(argc != 5) {
    fprintf(stderr, "usage: automata <rule> <width> <generations> <random_flag>\n");
    exit(1);
  }

  int type = atoi(argv[RULE]), range = atoi(argv[WIDTH]), gen = atoi(argv[GENERATIONS]);
  int midRange = (range/2); //Set up the array
  unsigned char width[range], newWidth[range];

  srand(time(0)); //Fill the initial set

  //Convert the type to its binary values
  char binType[8] = {0,0,0,0,0,0,0,0};

  for(int i = 0; i < 8; i++){
    binType[i] = type & 1;
    type >>= 1;
  }

  while(1){ //Loop until interrupted, make new colors and random values
    int col1 = rand() % 200, col2 = rand() % 200;
    for(int i = 0; i < range; i++){
      width[i] = atoi(argv[MODE]) ? rand() % 2 : 0; //Set random values if enabled
      newWidth[i] = 0;
    }
    width[midRange] = atoi(argv[MODE]) ? 0 : 1; //Set the center value if random is disabled

    printf("\033[H\033[2J\033[38;5;%dm\033[48;5;%dm", col1, col2); //Reset the screen and set the colors
    //printf("\033[H\033[2J"); //Monochrome mode - reset screen only

    //Generation loop
    for(int i = 0; i <= gen; i++){
      //Print the generation
      for(int i = 0; i < range; i++) width[i] ? printf( "█") : printf(" "); //█░

      //Create the new set
      for(int i = 0; i < range; i++){
        //Create the 'spot' and check each pattern
        char spot[3] = {width[i - 1], width[i], width[i + 1]};
        newWidth[i] = spot[0] ? (spot[1] ? (spot[2] ? binType[7] : binType[6]) : (spot[2] ? binType[5] : binType[4])) : (spot[1] ? (spot[2] ? binType[3] : binType[2]) : (spot[2] ? binType[1] : binType[0]));
      }

      //Update the automata
      memcpy(width, newWidth, sizeof(char) * range);
      printf("\n"); //Set for next line
    }
    usleep(100000);
  } return 0;
}
