#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#define easySize 6
#define mediumSize 10
#define hardSize 14
#define SIZE 8

char easyMaze[easySize][SIZE];
char mediumMaze[mediumSize][SIZE];
char hardMaze[hardSize][SIZE];

int playAgain();
void updatingPlayerPos(char maze[][SIZE], int size);
void displayGrid(char maze[][SIZE], int size);
void placingObstacles(char maze[][SIZE], int size, int totalObstacles);
void initialize(char maze[][SIZE], int size);
void easyLevel();
void mediumLevel();
void hardLevel();
void clearScreen();

int main()
{
	system("COLOR AF");
	srand(time(NULL));
	int choice;
	bool exit = false;
	while (exit == false)
	{
		clearScreen();
		printf("\tEscape the Maze\n");
		printf("Choose the level:\n");
		printf("1: Easy\n");
		printf("2: Medium\n");
		printf("3: Hard\n");
		bool rightChoice = false;
		while (rightChoice == false)
		{
			printf("Enter the choice: ");
			scanf("%d", &choice);
			if(choice < 1 || choice > 3)
			{
				printf("Invalid Input!\n");
			}
			else
			{
				rightChoice = true;
			}				
		}
		switch (choice)
		{
			case 1:
				easyLevel();
				break;
			case 2:
				mediumLevel();
				break;
			case 3:
				hardLevel();
				break;
		}
				
		if(playAgain() == 0)
		{
			exit = true;
		}	
	}
 	
	return 0;
}
void initialize(char maze[][SIZE], int size)
{
	for(int x = 0; x < size; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			maze[x][y] = ' ';
		}
	}
	
}
void placingObstacles(char maze[][SIZE], int size, int totalObstacles)
{
	int obstacles = totalObstacles;
	while(obstacles > 0 && obstacles <= totalObstacles)
	{
		int x = rand() % size;
		int y = rand() % SIZE;
		if(maze[x][y] == ' ')
		{
			maze[x][y] = 'X';
			obstacles--;
		}
	}	
}
void displayGrid(char maze[][SIZE], int size)
{
	printf(" _________________________________\n");
	for (int x = 0; x < size; x++)
	{
		printf(" |");
		for (int y = 0; y < SIZE; y++)
		{	
			printf(" %c |", maze[x][y]);
		}
		printf("\n _________________________________\n");
	}	
}
void updatingPlayerPos(char maze[][SIZE], int size)
{
	int Xpos = 0, Ypos = 0, obstacles = 0, moveCount = 0;
	char move;
	bool flag = false;
	while ((flag == false) || ((Xpos == size - 1) && (Ypos == size - 1)))
	{
		printf("\'W\': up\n\'S\': down\n\'A\': left\n\'D\': right\n\'Q\': quit\n");
		printf("Enter the move: ");
		scanf(" %c", &move);
		move = toupper(move);
		
		switch(move)
		{	
			// moving up
			case 'W':
		    	Xpos--;
		    	clearScreen();
		    	if (Xpos >= 0 && maze[Xpos][Ypos] == ' ')
		    	{
		    		maze[Xpos][Ypos] = 'P';
		    		maze[Xpos + 1][Ypos] = ' ';
		    	}
				else if (Xpos >= 0 && maze[Xpos][Ypos] == 'X')
		    	{
		    		printf("There's an obstacle!\n");
		    		Xpos++;
		    		obstacles++;
		    	}
				else if (Xpos >= 0 && maze[Xpos][Ypos] == 'H')
				{
					maze[Xpos + 1][Ypos] = ' ';
					Xpos = size - 1;
					Ypos = SIZE - 1;
				}
				else
				{
					printf("Moving out of grid!\n");
					Xpos++;
				}  
		    	break;
		   	// moving down
			case 'S':
		    	Xpos++;
		    	clearScreen();
		    	if (Xpos < size && maze[Xpos][Ypos] == ' ')
		    	{
		    		maze[Xpos][Ypos] = 'P';
		    		maze[Xpos - 1][Ypos] = ' ';
		    	}		   
		    	else if (Xpos < size && maze[Xpos][Ypos] == 'X')
		    	{
		    		printf("There's an obstacle!\n");
		    		Xpos--;
		    		obstacles++;
		    	}
		    	else if (Xpos < size && maze[Xpos][Ypos] == 'H')
		    	{
		    		maze[Xpos - 1][Ypos] = ' ';
		    		Xpos = size - 1;
					Ypos = SIZE - 1;	
				}
				else
				{
					printf("Moving out of grid!\n");
					Xpos--;
				}  
		    	break;
			// moving left
			case 'A':
			    Ypos--;
			    clearScreen();
			    if (Ypos >= 0 && maze[Xpos][Ypos] == ' ')
			    {
				    maze[Xpos][Ypos] = 'P';
		    		maze[Xpos][Ypos + 1] = ' ';
		    	}
		    	else if (Ypos >= 0 && maze[Xpos][Ypos] == 'X')
		    	{
		    		printf("There's an obstacle!\n");
		    		obstacles++;
		    		Ypos++;
		    	}
		    	else if (Ypos >= 0 && maze[Xpos][Ypos] == 'H')
		    	{
		    		maze[Xpos][Ypos + 1] = ' ';
		    		Xpos = size - 1;
		    		Ypos = SIZE - 1;
				}
			    else
				{
			    	printf("Moving out of grid!\n");
		    		Ypos++;
				}	   
		    	break;
			// moving right	
			case 'D':
		    	Ypos++;
		    	clearScreen();
		    	if (Ypos < SIZE && maze[Xpos][Ypos] == ' ')
		    	{
		    		maze[Xpos][Ypos] = 'P';
		    		maze[Xpos][Ypos - 1] = ' ';
		    	}
				else if (Ypos < SIZE && maze[Xpos][Ypos] == 'X')
		    	{
				    printf("There's an obstacle!\n");
				    obstacles++;
				    Ypos--;
				}
				else if (Ypos < SIZE && maze[Xpos][Ypos] == 'H')
				{
					maze[Xpos][Ypos - 1] = ' ';
					Xpos = size - 1;
					Ypos = SIZE - 1;
					
				}
		    	else
		    	{
		    		printf("Moving out of grid!\n");
			    	Ypos--;
				}    
		    	break;
			case 'Q':
				clearScreen();
			    printf("You chose to quit the game!\n");
			    printf("You hit the obstacles %d times!\n", obstacles);
			    flag = true;
			    break;
		
			default:
				clearScreen();
			    printf("Incorrect move entered!\n");
		}
		if (Xpos == size - 1 && Ypos == SIZE - 1) 
		{ 
			maze[size - 1][SIZE - 1] = 'P';
			printf("Congratulations! You've reached the end of the maze in %d moves!\n", moveCount);
			printf("You hit the obstacles %d times!\n", obstacles); 
			flag = true;	
		}		
		if ((move == 'A') || (move == 'W') || (move == 'D') || (move == 'S'))
		{
			moveCount++;
			displayGrid(maze, size);
		}
	}
}
void easyLevel()
{
	initialize(easyMaze, easySize);
	easyMaze[0][0] = 'P';
	easyMaze[easySize - 1][SIZE - 1] = 'H';
	placingObstacles(easyMaze, easySize, 10);
	displayGrid(easyMaze, easySize);
	updatingPlayerPos(easyMaze, easySize);				
}

void mediumLevel()
{
	initialize(mediumMaze, mediumSize);
	mediumMaze[0][0] = 'P';
	mediumMaze[mediumSize - 1][SIZE - 1] = 'H';
	placingObstacles(mediumMaze, mediumSize, 15);
	displayGrid(mediumMaze, mediumSize);
	updatingPlayerPos(mediumMaze, mediumSize);				
	
}
void hardLevel()
{
	initialize(hardMaze, hardSize);
	hardMaze[0][0] = 'P';
	hardMaze[hardSize - 1][SIZE - 1] = 'H';
	placingObstacles(hardMaze, hardSize, 20);
	displayGrid(hardMaze, hardSize);
	updatingPlayerPos(hardMaze, hardSize);				
	
}
int playAgain()
{
	char continuePlaying;
	printf("Do you want to play again?(Y/N): ");
	scanf(" %c", &continuePlaying);
	continuePlaying = toupper(continuePlaying);
	if (continuePlaying == 'N')
	{
		printf("Thank you for playing!\n");
		return 0;
	}
	return 1;
}
void clearScreen()
{
	system("cls");
}
