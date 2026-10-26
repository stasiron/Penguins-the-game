#include <stdio.h>

int main()
{
	char bot[5];//yes no variable asking if you want to play against bot
	int player_count = 0; //amount of players in game
	int penguins_per_player = 0; // amount of penguins for each player	
	int map_size = 0; //size of a map (player_count*penguins_per_player + 5)




	printf("Would you like to play against bot? yes/no\n");
	scanf("%4s", bot);

	if (bot[0] == 'Y' || bot[0] == 'y') {
		return 0;
	}
	

	gamesettings:
		printf("How many players?\n");
		scanf("%d", &player_count);
		printf("How many penguins per player?\n");
		scanf("%d", &penguins_per_player);
	if (player_count <2) goto gamesettings;
	if (penguins_per_player<1) goto gamesettings;
	map_size = player_count*penguins_per_player+5;

	int map[map_size][map_size];

	for (int i = 0;i < map_size ;i++){
		for (int j = 0; j<map_size ;j++) {
			map[i][j] = 0;

		}
	}
	for (int i = 0; i<map_size; i++){
		for (int j = 0; j<map_size;j++){
			printf("%3d",map[i][j]);
		}
		printf("\n");
	}
	printf("all good %d %d %d \n\n" , player_count, penguins_per_player, map_size);



	end:
	return 0;
}
