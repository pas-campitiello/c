#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include <signal.h>

#define ALIVE	1
#define DEAD	0

/* prototypes */
void config(int argc, char **argv);
void usage(void);
void init(void);

void init_grid1(void);
void init_grid2(void);
void kill_grid1(void);
void kill_grid2(void);

void clear_grid1();
void clear_grid2();

void copy_grid();

void print_grid(void);
void process_grid(void);
void process_cell(int, int);
void clean_exit(int);


/* global */
struct {
	char *prog;
	char c_alive, c_dead;
	int x, y;
	int manual;
} cfg;

int **grid1, **grid2;

int main(int argc, char **argv) {

	signal(SIGINT, clean_exit);

	config(argc, argv);

	init_grid1();
	init_grid2();
	print_grid();

	while(1) {
		usleep(750000);
		process_grid();
		print_grid();
	}

	return 0;

}

void clean_exit(int s) {

	printf("cya...\n");
	kill_grid1();
	kill_grid2();
	exit(0);

}

void config(int argc, char** argv) {

	int arg, opt_index;

	static struct option long_opt[] =
	{
		{"a", required_argument, NULL, 'a'},
		{"d", required_argument, NULL, 'd'},
		{"f", required_argument, NULL, 'f'},
		{"h", no_argument, NULL, 'h'},
		{"m", no_argument, NULL, 'm'},
		{"x", required_argument, NULL, 'x'},
		{"y", required_argument, NULL, 'y'},
		{0, 0, 0, 0}
	};


	cfg.prog =  argv[0];
	cfg.x = 10;
	cfg.y = 10;
	cfg.c_alive = '*';
	cfg.c_dead = ' ';

	while((arg =  getopt_long_only(argc, argv, "", long_opt, &opt_index)) != EOF) {
		switch(arg) {
		case 'a' :
			cfg.c_alive = optarg[0];
			break;
		case 'd' :
			cfg.c_dead= optarg[0];
			break;
		case 'f' :
			//input file
			break;
		case 'h' :
			usage();
			break;
		case 'm' : 
			cfg.manual = 1;
			break;
		case 'x' :
			cfg.x = atoi(optarg);
			break;
		case 'y' :
			cfg.y = atoi(optarg);
			break;
		default:
			printf("unknown option\n");
			usage();
		}
	}

}


void usage() {

	printf("\n");
	printf("Game of Life simulator by nad (nad@webs0r.net)\n");
	printf("\n");
	printf("  -a	alive character\n");
	printf("  -d 	dead character\n");
	printf("  -f	initial state input file\n");
	printf("  -h    duh\n");
	printf("  -m	initial state manual entry\n");
	printf("  -x	row size\n");
	printf("  -y	column size\n");
	printf("\n");
	exit(0);

}

void init_grid1() {

	int i, x, y, z;

	srand(time(NULL));

	if ((grid1 = (int **) malloc (cfg.x * sizeof(int *))) == NULL) {
		printf("Failure allocating row\n");
		exit(-1);
	}

	for(i=0; i<cfg.x; i++)
		if ((grid1[i] = (int *) malloc (cfg.y * sizeof(int *))) == NULL) {
			printf("failure allocating column\n");
			free(grid1);
			exit(-1);
		}

	/* if random, else manual */
	if (cfg.manual == 1)
		/* manual entry */;
	else {
		for(y=1; y<cfg.y-1; y++)
			for(x=1; x<cfg.x-1; x++) {
				z = rand() % 100;
				if (z<50) grid1[x][y] = ALIVE;
				else grid1[x][y] = DEAD;
			}
				
	}
	
}

void init_grid2() {

	int i, x, y, z;

	if ((grid2 = (int **) malloc (cfg.x * sizeof(int *))) == NULL) {
		printf("Failure allocating row\n");
		exit(-1);
	}

	for(i=0; i<cfg.x; i++)
		if ((grid2[i] = (int *) malloc (cfg.y * sizeof(int *))) == NULL) {
			printf("failure allocating column\n");
			free(grid2);
			exit(-1);
		}
	
}

void kill_grid1() {

	int i;

	for(i=0; i<cfg.x; i++)
		free(grid1[i]);

	free(grid1);

}

void kill_grid2() {

	int i;

	for(i=0; i<cfg.x; i++)
		free(grid2[i]);

	free(grid2);

}


void process_grid() {

	int x, y;

	for(y=1; y<cfg.y-1; y++)
		for(x=1; x<cfg.x-1; x++)
			process_cell(x,y);

	clear_grid1();
	copy_grid();

}

void process_cell(int x, int y) {

	int life;

        life =          grid1[x-1][y-1] +
                        grid1[x-1][y] +
                        grid1[x-1][y+1] +
                        grid1[x][y-1] +
                        grid1[x][y+1] +
                        grid1[x+1][y-1] +
                        grid1[x+1][y] +
                        grid1[x+1][y+1];

        switch(life) {
        case 0: case 1: case 4: case 5: case 6: case 7: case 8:
                grid2[x][y] = DEAD;
                break;
        case 3:
                grid2[x][y] = ALIVE;
                break;
        case 2:
                grid2[x][y] = grid1[x][y];
                break;
        }

} 

void print_grid() {

	int x, y;

	system("clear");

	for(y=0; y<cfg.y; y++)
		for(x=0; x<cfg.x; x++) {
			switch(grid1[x][y]) {
			case DEAD:
				printf("%c", cfg.c_dead);
				break;
			case ALIVE:
				printf("%c", cfg.c_alive);
				break;
			}

                        if (x == cfg.x-1)
                                printf("\n");
                }

}

void clear_grid1() {

	int x, y;

	for(y=1; y<cfg.y-1; y++)
		for(x=1; x<cfg.x-1; x++)
			grid1[x][y] = 0;

}

void clear_grid2() {

	int x, y;

	for(y=1; y<cfg.y-1; y++)
		for(x=1; x<cfg.x-1; x++)
			grid2[x][y] = 0;

}

void copy_grid() {

	int x, y;

	for(y=1; y<cfg.y-1; y++)
		for(x=1; x<cfg.x-1; x++)
			grid1[x][y] = grid2[x][y];

}

