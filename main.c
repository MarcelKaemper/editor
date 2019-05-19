#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "src/readFile.h"

void drawHome(int h, int w);
void drawPanel(int h, int w);

int main(int argc, char ** argv) {

    initscr();

    int h,w;
    getmaxyx(stdscr, h, w);
    
    WINDOW *win = newwin(h,w,0,0);

    noecho();
    keypad(stdscr, TRUE);

	for(;;){
		drawHome(h,w);

		int c;
		unsigned int cursorPos;
		cursorPos = 0;

		if((c = getch()) == 'c'){
			drawPanel(h,w);

			move(h-2, cursorPos+2);

			char * cmd;
			char * cb;
			int size = 1;
			cmd = (char *) malloc(size);

			while((c = getch()) != 10){
				if(c == KEY_BACKSPACE){
					if(cursorPos > 0){
						cursorPos -= 1;
						mvdelch(h-2, w-1);
						mvdelch(h-2, cursorPos+2);
					}
				}else{
					mvaddch(h-2, cursorPos+2, c);
					cmd[cursorPos] = c;
					cursorPos += 1;

					cb = malloc(1);
					cb = memset(cb,c,1);
					strcat(cmd, cb);
					size += 1;
					cmd = (char *) realloc(cmd, size);
					free(cb);
				}

				mvaddstr(10,10,cmd);

				drawHome(h,w);
				drawPanel(h,w);
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

void drawHome(int h, int w){
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
}

void drawPanel(int h, int w){
	for(int i = 0; i<w; i++){
		mvaddch(h-3, i, ACS_BLOCK);
	}
	refresh();
}
