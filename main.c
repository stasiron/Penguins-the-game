#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//------------this function changes game setting (variables from up)--------------
void game_settings(char bot[5], int *player_count, int *penguins_per_player, int *map_size);

//--------------this function creates a map and (in the future, places an ice floes and fishes-------------------
void Map_Creator(int map_size, int map[map_size][map_size]);

//-----------this function prints map (this particular for the first time)-------------
void Map_Printer(int map_size, int player_count, int penguins_per_player, int map[map_size][map_size]);

//--------function clearing terminal, uses stdlib (system command)
void Clear_Screen(void);

//-----------this functions prints Informations about a game such as: whos turn it it is, what score is and so on
void Data_Printer();

//--------------This function uses time.h and stdlib.h library and generates random number up to given variable
int Random(int Random_Up_To);

int main()
{
	srand(time(NULL));


	Clear_Screen();
	//cc main.c
	//.\a.exe

	//
	//	im storing next 4 variables in main
	//	then im using game function to change those variables, but bc they are not created in function, they are stored in main, and they stay with new numbers :))
	//

	char bot[5];//yes no variable asking if you want to play against bot
	int player_count = 0; //amount of players in game
	int penguins_per_player = 0; // amount of penguins for each player	
	int map_size = 0; //size of a map (player_count*penguins_per_player + 5)



//------------this function changes game setting (variables from up)--------------
	game_settings(bot, &player_count, &penguins_per_player, &map_size);

	int map[map_size][map_size];

//-----------this function creates map------------------------

	Map_Creator(map_size, map);

//-----------this functions, clear terminal, prints Data, and then second map (this particular for the first time)-------------

	Clear_Screen(); //clear
	Data_Printer(); //data
	Map_Printer(map_size, player_count, penguins_per_player, map); //map

//-----------this functions prints Informations about a game such as: whos turn it it is, what score is and so on
	





	return 0;
}

//random number gen funcitons
int Random(int Random_Up_To){
	if (Random_Up_To<=0) return 0;
	return rand()%(Random_Up_To);
}


//function clearing terminal
void Clear_Screen(void){
/*#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
*/
printf("Clear\n");
	return;
}

void game_settings(char bot[5], int *player_count, int *penguins_per_player, int *map_size)
{
	//char bot[5];//yes no variable asking if you want to play against bot
	//int player_count = 0; //amount of players in game
	//int penguins_per_player = 0; // amount of penguins for each player	
	//int map_size = 0; //size of a map (player_count*penguins_per_player + 5)

	//printf("v2\n");

	while(1==1){ //loop asking if you want to play against a bot
		printf("Would you like to play against bot? yes/no \n");
		scanf("%4s", bot);

		if (bot[0] == 'Y' || bot[0] == 'y') { //program doesnt care about the whole awnser, it checks only first letter so the length is irrelevant and small spelling mistakes doesnt matter
			//its a dev shortcat, it changes settings for hardcoded preset
			*player_count = 2; //amount of players in game
			*penguins_per_player = 3; // amount of penguins for each player	
			*map_size = (*player_count) * (*penguins_per_player) +3;	

			return; //if awnser correct it finishes program (not implemented yet)
		}
		else if (bot[0] == 'N' || bot[0] == 'n') {
			break; //if awnsered no it breaks a loop and moves forward with questions
		}
		else{
			printf("Give an awnser Yes or No (or tak or nie)");
		}
	}
	gamesettings:
		printf("How many players?\n");
		scanf("%d", player_count);
		printf("How many penguins per player?\n");
		scanf("%d", penguins_per_player);
	if (*player_count <2) goto gamesettings;
	if (*penguins_per_player<1) goto gamesettings;

	*map_size = (*player_count) * (*penguins_per_player) +3;
	return;
}


void Map_Creator(int map_size, int map[map_size][map_size]){
	//
	//--------------sets map to 0----------------
	//
		for (int i = 0;i < map_size ;i++){
			for (int j = 0; j<map_size ;j++) {
				map[i][j] = 0;
			}
		}

	// parametres for ice floe generator
		int Corner=0; //selecred Corner
		int x = 0; // position of x change
		int y = 0; // position of y change
		int xi = 0; // if tile is occupied it will change by this variable and try again
		int yi = 0;
		//im generating a static ice floes = the map_size (or bigger it can change)
		//for (int i = 0;i<map_size;i++){
		for (int i = 0;i<(map_size)*2;i++){
		
			Corner = Random(4); //im randomising witch Corner i will change
			if (Corner == 0 || Corner == 2){ //this if statemant sets corrects variable for each tile
				x = 0;	//coordinate variable
				xi=1;	//change if neseseraly
				if (Corner == 0){
					y = 0;
					yi=1;
				}
				else{
					y = map_size-1;
					yi=-1;
				}
			}
			else{
				x = map_size-1;
				xi=-1;
				if (Corner == 1){
					y = 0;
					yi=1;
				}
				else{
					y = map_size-1;
					yi=1;
				}
			}
			//
			//	0(0,0)1,1			1(map_size,0)-1,1
			//
			//	2(0,map_size)1,-1	3(map_size,map_size)-1,-1
			//

			icefloe:

			if (map[x][y]==-1){
				int temp =Random(2);
				if (temp == 0){
						x+=xi;
				}
				else{
					y+=yi;
				}
				goto icefloe;
			}
			else map[x][y] = -1;


			printf("%d\t%d\t%d\n", Corner, x, y);
		}




	return;
}

void Map_Printer(int map_size, int player_count, int penguins_per_player, int map[map_size][map_size]){
	//
	//--------------prints map and coordinates-----------------
	//
		printf("\t%20.20s < 0 >", "");
		for (int i = 0; i<map_size;i++){
				printf(" <%2d >", i+1);
		}
		printf("\n");
		for (int i = 0; i<map_size; i++){
			printf("\t%20s <%2d >", "", i+1);
			for (int j = 0; j<map_size;j++){
				printf(" %3d  ",map[i][j]);
			}
			printf("\n");
		}
		return;
}

void Data_Printer(){
/*
//	|----------LeaderBoard----------|-------Whos Turn is it---------|-----------All time Highscore----------|
//	|	540p	Player One			|		>>> Player Two <<<		|			1567p	67%covered			|
//	|	230p	Player Two			|--------------Phase------------|			1987p	57%covered			|
//	|	132p	Player Three		|		> Moving Penguins <		|			1109p	56%covered			|
//	|-------------------------------|-------------------------------|---------------------------------------|
//							< 0 > < 1 > < 2 > < 3 > < 4 > < 5 > < 6 > < 7 > < 8 > < 9 >
//							< 1 >   0     0     0     0     0     0     0     0     0  
//							< 2 >   0     0     0     0     0     0     0     0     0  
//							< 3 >   0     0     0     0     0     0     0     0     0  
//							< 4 >   0     0     0     0     0     0     0     0     0  
//							< 5 >   0     0     0     0     0     0     0     0     0  
//							< 6 >   0     0     0     0     0     0     0     0     0  
//							< 7 >   0     0     0     0     0     0     0     0     0  
//							< 8 >   0     0     0     0     0     0     0     0     0  
//							< 9 >   0     0     0     0     0     0     0     0     0  


printf("|%s|, "Player One") --> |Player One|

printf("|%20s|, "Player One") --> |              Player One|
%20s 20 means > minimum 20 symbols from left

printf("|%-20s|, "Player One") --> |Player One              |
%20s 20 means > minimum 20 symbols from right

printf("|%-10.10s|, "Player One") --> |Player One              |
%-10.10s means > minum 10 symbols from right, maximum 10

*/

char Player_Score_First[] = "Player One";
char Player_Score_Second[] = "Player Two";
char Player_Score_Third[] = "Player Three";

char Player_Turn[] = "Player One";

char All_Time_First[] = "1543 78p";
char All_Time_Second[] = "1893 69p";
char All_Time_Third[] = "1193 51p";

char Phase_name[]="Moving Penguins";

	printf("\t|----------LeaderBoard----------|-------Whos Turn is it---------|-----All time Highscore--------|\n");
	printf("\t|     1. %-23.23s|        %-23.23s|        %-23.23s|\n", Player_Score_First, Player_Turn, All_Time_First);
	printf("\t|     2. %-23.23s|------------Phase--------------|        %-23.23s|\n", Player_Score_Second, All_Time_Second);
	printf("\t|     3. %-23.23s|        %-23.23s|        %-23.23s|\n", Player_Score_Third, Phase_name, All_Time_Third);
	printf("\t|-------------------------------|-------------------------------|-------------------------------|\n");

	return;
}