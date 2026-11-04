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
    while (getchar() != '\n');
    while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n') {
        printf("Invalid input. Please enter Y or N: ");
        scanf(" %c", &ans);
        while (getchar() != '\n');
    }
    if (ans == 'Y' || ans == 'y') {
        gameMode = 1;
        printf("Bot not available.\n");
        return 0;
    } else {
        gameMode = 2;
        printf("You chose not to play against the Bot.\n");
    }
    printf("Enter the number of players (from 2 to 9): ");
    while (scanf("%d", &numPlayers) != 1 || numPlayers < 2 || numPlayers > 9) {
        while (getchar() != '\n');
        printf("Invalid number of players. Please enter a number between 2 and 9: ");
    }
    while (getchar() != '\n');
    printf("You chose %d players.\n", numPlayers);
    printf("Enter the number of penguins between 1 and 4: ");
    while (scanf("%d", &N) != 1 || N < 1 || N > 4) {
        while (getchar() != '\n');
        printf("Invalid number of penguins. Please enter a number between 1 and 4: ");
    }
    while (getchar() != '\n');
    printf("You chose %d penguins.\n", N);
    min_map_size = max(2 * N, numPlayers)+2;
    printf("Enter the number of rows (n) for the map (minimum %d): ", min_map_size);
    while (scanf("%d", &n) != 1 || n < min_map_size) {
        while (getchar() != '\n');
        printf("Invalid map size. n must be at least %d. Please enter it again: ", min_map_size);
    }
    while (getchar() != '\n');
    printf("Enter the number of columns (m) for the map (minimum %d): ", min_map_size);
    while (scanf("%d", &m) != 1 || m < min_map_size) {
        while (getchar() != '\n');
        printf("Invalid map size. m must be at least %d. Please enter it again: ", min_map_size);
    }
    while (getchar() != '\n');
    printf("You chose a map size of %d rows and %d columns.\n", n, m);
    printf("chosen game mode: %d\n", gameMode);
    printf("number of players: %d\n", numPlayers);
    printf("number of penguins: %d\n", N);
    printf("map size: %d rows, %d columns\n", n, m);
    printf("Type S to start the game or N if you want to quit.\n");
    scanf(" %c", &ans);
    while (getchar() != '\n');
    while (ans != 'S' && ans != 's' && ans != 'N' && ans != 'n') {
        printf("Invalid input. Please type S to start the game or N to quit: ");
        scanf(" %c", &ans);
        while (getchar() != '\n');
    }
    if (ans == 'N' || ans == 'n') {
        printf("Quitting the game...\n");
        return 0;
    }
    printf("Starting the game...\n");
    return 0;
}