#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char ** argv) {

    initscr();

    int h,w;
    getmaxyx(stdscr, h, w);
    
    WINDOW *win = newwin(h,w,0,0);

    noecho();
    keypad(stdscr, TRUE);

	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++){
			if((i == h-1) || (i == 0)){
				mvaddch(i,j,ACS_BLOCK);
			}else if((j == 0) || (j == w-1)){
				mvaddch(i,j,ACS_BLOCK);
			}
		}
	}
	refresh();
	getch();

    endwin();

    return 0;
}
