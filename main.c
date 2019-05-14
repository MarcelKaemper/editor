#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "src/readFile.h"

int main(int argc, char ** argv) {

    initscr();

    int h,w;
    getmaxyx(stdscr, h, w);
    
    WINDOW *win = newwin(h,w,0,0);

    noecho();
    keypad(stdscr, TRUE);

	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++){
			if((i==0) || (i==h-1)){
				mvaddch(i,j,ACS_BLOCK);
			}else{
				mvaddch(i, 0, ACS_BLOCK);
				mvaddch(i, w-1, ACS_BLOCK);
			}
		}
	}

	refresh();
	getch();

    endwin();

	readFile();

    return 0;
}
