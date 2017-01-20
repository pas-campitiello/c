#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XSIZE	22
#define YSIZE	22

#define DEAD	0
#define ALIVE	1

void init_grid(void);
void print_grid(void);
void clear_grid(void);
void clear_tmp_grid(void);
void copy_grid(void);
void process_grid(void);
void process_cell(int, int);

int grid[XSIZE][YSIZE];
int  tmp[XSIZE][YSIZE];
char alive_char='*';

int main(int argc, char **argv) {

	int x,y;

	if (argc == 2)
		alive_char = argv[1][0];
	
	init_grid();
	print_grid();

	while(1) {
		usleep(750000);
		process_grid();
		print_grid();
	}

	return 0;

}

void init_grid() {

	int x,y,z;
	srand(time(NULL));

	for(y=1; y<YSIZE-1; y++)
		for(x=1; x<XSIZE-1; x++) {
			z = rand() % 100;
			if (z < 50) grid[x][y] = ALIVE;
			else grid[x][y] = DEAD;
		}
	
}

void process_grid() {

	int x,y;

	clear_tmp_grid();

	for(y=1; y<YSIZE-1; y++) 
		for(x=1; x<XSIZE-1; x++) 
			process_cell(x,y);	

	clear_grid();
	copy_grid();

}

void process_cell(int x, int y) {

	int life;

	life =		grid[x-1][y-1] +
			grid[x-1][y] +
			grid[x-1][y+1] +
			grid[x][y-1] +
			grid[x][y+1] +
			grid[x+1][y-1] +
			grid[x+1][y] +
			grid[x+1][y+1];

	switch(life) {
	case 0: case 1: case 4: case 5: case 6: case 7: case 8:
		tmp[x][y] = DEAD;
		break;
	case 3:
		tmp[x][y] = ALIVE;
		break;
	case 2:
		tmp[x][y] = grid[x][y];
		break;
	}

} 

void print_grid() {

	int x,y;

	system("clear");

	for(y=0; y<YSIZE; y++) 
		for(x=0; x<XSIZE; x++) {
			switch(grid[x][y]) {
			case 0:
				printf("  ");
				break;
			case 1:
				printf("%c ", alive_char);
				break;
			}
			if (x == XSIZE-1) 
				printf("\n");
		}

}

void clear_tmp_grid() {

	int x,y;

	for(y=1; y<YSIZE-1; y++) 
		for(x=1; x<XSIZE-1; x++) 
			tmp[x][y] = 0;

}

void clear_grid() {

	int x,y;

	for(y=1; y<YSIZE-1; y++) 
		for(x=1; x<XSIZE-1; x++) 
			grid[x][y] = 0;

}

void copy_grid() {

	int x,y;

	for(y=1; y<YSIZE-1; y++) 
		for(x=1; x<XSIZE-1; x++) 
			grid[x][y] = tmp[x][y];

}

