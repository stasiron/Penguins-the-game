#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int gameMode=0;// 0 - not selected, 1 - against Bot, 2 - not against Bot
    char ans; // Variable 
    int numPlayers; //number of players
    int N; //number of penguins
    int min_map_size; //minimum map size based on number of penguins and players
    int n, m; //number of rows and columns for the map
    printf("Do you want to play against the Bot?\n");
    printf("Enter Y for Yes, N for No: ");
    scanf(" %c", &ans);
    if (ans == 'Y' || ans == 'y') {
        gameMode = 1;
        printf("Bot not available.\n");
        return 0;
    } else if (ans == 'N' || ans == 'n') {
        gameMode = 2;
        printf("You chose not to play against the Bot.\n");
    } else {
        printf("Invalid input. Please enter Y or N.\n");
    }
    printf("Enter the number of players (from 2 to 9): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > 9) {
        printf("Invalid number of players. Please enter a number between 2 and 9.\n");
    } else {
        printf("You chose %d players.\n", numPlayers);
    }
    printf("Enter the number of penguins between 1 and 4: ");
    scanf("%d", &N);
    if (N < 1 || N > 4) {
        printf("Invalid number of penguins. Please enter a number between 1 and 4.\n");
    } else {
        printf("You chose %d penguins.\n", N);
    }
    min_map_size = max(2 * N, numPlayers)+2;
    printf("Enter the number of rows (n) for the map (minimum %d): ", min_map_size);
    scanf("%d", &n);
    printf("Enter the number of columns (m) for the map (minimum %d): ", min_map_size);
    scanf("%d", &m);
    if (n < min_map_size || m < min_map_size) {
        printf("Invalid map size. Both n and m must be at least %d.\n", min_map_size);
    } else {
        printf("You chose a map size of %d rows and %d columns.\n", n, m);
    }
    printf("chosen game mode: %d\n", gameMode);
    printf("number of players: %d\n", numPlayers);
    printf("number of penguins: %d\n", N);
    printf("map size: %d rows, %d columns\n", n, m);
    printf("Type S to start the game.\n");
    scanf("%s", &ans);
    if (ans == 'S' || ans == 's') {
        printf("Starting the game...\n");
    } else {
        printf("Game not started. Exiting.\n");
    }
    return 0;
}