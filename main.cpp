#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
#define DISP_HEI 30
#define DISP_WID 50


#define WAIT 500000


void wait() {
	unsigned long long i,j;
	for (i = 0; i < 30; ++i)
	{
		for(j=0;j < WAIT; j++) {

		}
	}
}
void cleanScreen() {
	unsigned int i;
	for (i = 0; i < DISP_HEI*3; ++i)
	{
		printf("\n");
	}
}

void getSnakePos(unsigned int* snake) {
	int i;
	for (i = 0; i < LENGTH; ++i) //this displays the actual pos of snake
		printf("snake[%d] = %d\n", i, snake[i]);
}

void sortArray(unsigned int* tab) {
	int i,n,b=1;
	while(b)
	{
		b=0;
		for(i=0; i<LENGTH-1; i++) {
			/*while((int) difftime(now, start) %5 != 4)
				time(&now);*/
			if(tab[i] > tab[i+1]) {
				//printf("tab[%d] = %d > %d\n", i, tab[i], tab[i+1]);
				n = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = n;
				b=1;
			}
		}
	}
}

void displaySnake(unsigned int* snake) {
	unsigned int* display = (unsigned int*) malloc(sizeof(unsigned int) * LENGTH);
	int i,j;

	for (i = 0; i < LENGTH; ++i){
		display[i] = snake[i];
	}

	int index = 0;
	sortArray(snake);
	printf("\t");
	for (i = 0; i < DISP_HEI; ++i)
	{
		for (j = 0; j < DISP_WID; ++j)
		{
			//printf("Actual value : %d | snake[%d] = %d\n", i*DISP_WID+j, index, snake[index]);
			if (i*DISP_WID +j == snake[index])
			{
				printf("=");
				index++;
			}
			else {
				printf(" ");
			}
		}
		printf("\n\t");
	}
	printf("\n");
}

int move(unsigned int* snake, int direction) { //bugs
	unsigned int i, *head;
	head = &snake[LENGTH-1];
	for (i = 0; i < LENGTH-1; ++i) {
		snake[i] = snake[i+1];
	}
	if(*head/DISP_WID == (*head+1)/DISP_WID && *head/DISP_HEI == (*head+1)/DISP_HEI) {
		*head +=1;
	}
	else if (*head/DISP_WID != (*head+1)/DISP_WID) {
		*head+=DISP_WID;
	}
	else if (*head/DISP_HEI != (*head+1)/DISP_HEI){
		*head-=1;
	}
}

void moveRight(unsigned int* snake, int direction) {
	unsigned int i, *head;
	head = &snake[LENGTH-1];
	for (i = 0; i < LENGTH-1; ++i) {
		snake[i] = snake[i+1];
	}
	*head += direction;
}

void randomMove(unsigned int* snake) { //not working
	unsigned int i;
	for (i = 0; i < DISP_WID*DISP_HEI; ++i)
	{
		move(snake, 1);
		displaySnake(snake);
		wait();
		cleanScreen();
	}
}

int main(int argc, char const *argv[])
{
	unsigned int* snake;
	unsigned int i;
	const int UP = -DISP_WID;
	const int RIGHT = 1;
	const int DOWN = DISP_WID;
	const int LEFT = -1;

	int directions[4] = {UP, RIGHT, DOWN, LEFT};

	snake = (unsigned int*) malloc(sizeof(unsigned int) * LENGTH);
	for (i = 0; i < LENGTH; ++i){
		snake[i] = i;
		//printf("snake[%d] = %d\n", i, snake[i]);
	}
	displaySnake(snake);
	int dir = 1;
	for(i=0; i < DISP_WID*DISP_HEI; i++) {
		moveRight(snake, dir);
		displaySnake(snake);
		wait();
		cleanScreen();
	}

	
	return 0;
}