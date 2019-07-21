// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0  // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename);

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) ;

void draw_character(int y, int x, char use);

void printWord(int y, int x, int num);

char* wordlist[MAXWORDS];

int main(int argc, char* argv[]) {
 int wordCount;
 int num, ubutt, dbutt, lbutt, rbutt, joybutt, jup, jleft, jdown, jright, temp1, temp2, s, time;
 int x = 0;
 int y = 0;
 int posx = 0;
 int posy = 0;
 int u = 0, v = 0;
 int lengths[80];
 int iterator = 0;
 wordCount = readWords(wordlist, argv[1]);
 if (DEBUG)
 {
  printf("Read %d words from %s \n",wordCount, argv[1]);
  for (int i = 0; i< wordCount; i++) 
  {
   printf("%s,", wordlist[i]);
  }
  printf("\n");
 }
// most of your code goes here. Don't forget to include the ncurses library 
 
 initscr();
 
 for(int a = 0; a < wordCount; a++)
 { 
  mvprintw(x, (y * 15) + 1, wordlist[a]);
  x = x + 1;
  
  if(x == 20)
  {
   y = y + 1;
   x = 0;
  }
  
 }
 
 scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &dbutt, &ubutt, &lbutt, &rbutt, &joybutt, &s, &jdown, &jup, &jleft, &jright, &temp1, &temp2);
 
 while(dbutt + joybutt != 2)
 {
  scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &dbutt, &ubutt, &lbutt, &rbutt, &joybutt, &s, &jdown, &jup, &jleft, &jright, &temp1, &temp2);
  
  if(time % 50 == 0)
  {
   if(jup == 1 && posx > 0)
   {
    draw_character(posx, posy * 15, ' ');
    posx = posx - 1;
    draw_character(posx, posy * 15, '>');
   }
   
   if(jleft == 1 && posy > 0)
   {
    draw_character(posx, posy * 15, ' ');
    posy = posy - 1;
    draw_character(posx, posy * 15, '>');
   }
   if(ubutt == 1 && posx + posy * 20 <= wordCount - 1)
   {
    v++;
    printWord(30, u + 1, posx + posy * 20);
    u = u + 1 + strlen(wordlist[posx + posy * 20]);
    lengths[v] = 1 + strlen(wordlist[posx + posy * 20]);
   }
   if(jright == 1 && posy != 3)
   {
    draw_character(posx, posy * 15, ' ');
    posy = posy + 1;
    draw_character(posx, posy * 15, '>');
   }
   if(lbutt == 1 && posx + posy * 20 <= wordCount - 1)
   {
    printWord(30, u, posx + posy * 20);
    u = u + strlen(wordlist[posx + posy * 20]);
    v++;
    lengths[v] = strlen(wordlist[posx + posy * 20]);
   }
   if(jdown == 1 && posx < 19)
   {
    draw_character(posx, posy * 15, ' ');
    posx = posx + 1;
    draw_character(posx, posy * 15, '>');
   }
   if(dbutt == 1)
   {
    for(int a = 0; a < lengths[v]; a++)
    {
     mvdelch(30, u);
     refresh();
     u--;
    }
    v--;
   }
   if(joybutt == 1)
   {
    move(30, 0);
    clrtoeol();
    refresh();
    u = 0;
   }
   if(rbutt == 1 && posx + posy * 20 <= wordCount-1)
   {
    printWord(30, u + 1, posx + posy * 20);
    mvaddch(30, u + 1, toupper(*wordlist[posx + posy * 20]));
    u = u + 1 + strlen(wordlist[posx + posy * 20]);
    v++;
    lengths[v] = 1 + strlen(wordlist[posx + posy * 20]);
   }
   
  }
  refresh(); 
 }
 
 endwin();
 
    return 0;
 
}
 

// DO NOT MODIFY THIS FUNCTION
void trimws(char* s)
 {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
        }
}

// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
 int numread =0;
 char line[WORDLEN];
 char *p;
 FILE* fp = fopen(filename,"r");
 while (!feof(fp)) {
  p=fgets(line, WORDLEN, fp);
  if (!feof(fp) && p !=NULL) {
   trimws(line);
   wl[numread] = (char *)  malloc(strlen(line)+1);
   strcpy(wl[numread], line);
   numread++;
   }
  } 
 fclose(fp);
 return numread; 
}
 
void printWord(int y, int x, int num)
{
 mvprintw(y, x, wordlist[num]);
 refresh();
}
void draw_character(int y, int x, char use)
{
 mvaddch(y,x,use);    
 refresh();
}