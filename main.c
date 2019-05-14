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

	while(1){
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

		char c;
		
		if((c = getch()) == 'c'){
			for(int i = 0; i<w; i++){
				mvaddch(h-3, i, ACS_BLOCK);
			}
			move(h-2, 2);
			while((c = getch()) != 10){
				addch(c);
			}
		}else if(c == 10){
			break;	
		}

		clear();
	}


    endwin();

	readFile();

    return 0;
}
