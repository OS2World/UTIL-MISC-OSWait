/*
 DOSWAIT! (c) 1994, ITECH-CIS


  Compile as DOS EXE application.

  Description : DOS program to pause a batch/command file for
		a user specified number of seconds.  If the user
		presses "Q" the program will terminate with an errorlevel
		value of 1.  If the timer runs out, or the user presses
		the ENTER key, OSWAIT! will terminate with an errorlevel
		of 0.


  Disclaimer

  This program is provided for educational purposes only and may not be
  duplicated without the writtent consent of the author, John M. Warren.

  The author claims no responsibility for the use of this product.

*/


#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define  no 0
#define  yes 1
#define  return_key 0xD
#define  default_delay 5


/* prints a string in the current foreground color, with RETURNS number
   of carriage returns following the string
   cprintf() will not interprate \n formatting codes if your wondering.
*/
void cprintf_return(char *text, unsigned char returns, unsigned char whatcolor);


main(int numparams, char *params[]){
    int elapsed_seconds;
    int cursor_pos_x, cursor_pos_y;
    int seconds = 0;
    int stop;
    int c;
    int extended = 0;
    if(numparams != 1) {                   /* if a command line paramater was specified */
					   /* then convert the string params[1] to an */
       seconds = atoi(params[1]);          /* integer value */

    }

    if(seconds == 0)  seconds = default_delay;   /* delay default number of seconds */


    _setcursortype(_NOCURSOR);
    cprintf_return("DOSWAIT! v1 (c) 1994, ITECH-CIS",1,LIGHTGREEN);
    cprintf_return("Syntax :  DOSWAIT! [seconds].   Default = 5 Seconds.",2,GREEN);
    cprintf_return("Press [Q] to halt program, or press [ENTER] to continue..",2,YELLOW);


    textcolor(WHITE);
    cursor_pos_x = wherex();
    cursor_pos_y = wherey();   /* cursor location saved for gotoxy() moves */




    elapsed_seconds = 0;
    stop = no;

    do {                       /* keep going till the timer runs out or a key is pressed */

       sleep(1);
        if(kbhit()){
      c = getch();
      if (!c)
       extended = getch();
      if (!extended)
	switch(c){
	 case return_key : stop = yes; break;  /* on carriage return continue */
	 case 'q' :
	 case 'Q' :                            /* terminate with errorlevel */
	       printf("\n");                   /* remember the last cprinf() does not print a carriage return */
	       printf("**** User Break ****\n");
	       _setcursortype(_NORMALCURSOR);  /* turn the cursor back on */
	       exit(1);	}
     }

       gotoxy(cursor_pos_x, cursor_pos_y);
       cprintf("Seconds Remaining %i                 ",seconds - elapsed_seconds);
       elapsed_seconds++;
   }
   while( stop == no && (elapsed_seconds != seconds+1));

printf("\n");                   /* remember the last cprinf() does not print a carriage return */
_setcursortype(_NORMALCURSOR);  /* turn the cursor back on */
return(0);
}

/* user defined functions follow */

void cprintf_return(char *text, unsigned char returns, unsigned char whatcolor){
  int counter = 0;
  textcolor(whatcolor);
  cprintf("%s",text);
  for(counter = 0; counter < returns; counter++)  printf("\n");
}









