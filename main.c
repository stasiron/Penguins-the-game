#include <stdio.h>
#include <stdlib.h>

void game_settings(char bot[5], int *player_count, int *penguins_per_player, int *map_size);

void Map_Creator(int map_size, int map[map_size][map_size]);

void Map_Printer(int map_size, int player_count, int penguins_per_player, int map[map_size][map_size]);

void Clear_Screen(void);


int main()
{
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

//-----------this function prints map (this particular for the first time)-------------
	Map_Printer(map_size, player_count, penguins_per_player, map);

//

	





	return 0;
}

//function clearing terminal
void Clear_Screen(void){
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	return;
}

void game_settings(char bot[5], int *player_count, int *penguins_per_player, int *map_size)
{
	//char bot[5];//yes no variable asking if you want to play against bot
	//int player_count = 0; //amount of players in game
	//int penguins_per_player = 0; // amount of penguins for each player	
	//int map_size = 0; //size of a map (player_count*penguins_per_player + 5)

	printf("v2");

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

	return;
}

void Map_Printer(int map_size, int player_count, int penguins_per_player, int map[map_size][map_size]){
	//
	//--------------prints map and coordinates-----------------
	//
		Clear_Screen();
		printf("< 0 >");
		for (int i = 0; i<map_size;i++){
				printf(" <%2d >", i+1);
		}
		printf("\n");
		for (int i = 0; i<map_size; i++){
			printf("<%2d >", i+1);
			for (int j = 0; j<map_size;j++){
				printf(" %3d  ",map[i][j]);
			}
			printf("\n");
		}
		printf("all good %d %d %d \n\n" , player_count, penguins_per_player, map_size);

		return;
}