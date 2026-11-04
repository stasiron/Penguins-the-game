#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void READ()
{
    int gameMode = 0;                                        // 0 - not selected, 1 - against Bot, 2 - against players
    char ans = 0;                                            // Variable
    char begin = 0;                                          // Variable to start the game
    int numPlayers = 0;                                      // number of players
    int N = 0;                                               // number of penguins
    int min_map_size = 0;                                    // minimum map size based on number of penguins and players
    int n = 0, m = 0;                                        // number of rows and columns for the map
    char player1[11], player2[11], player3[11], player4[11]; // player names

    while (begin != 'S' && begin != 's' && begin != 'N' && begin != 'n')
    {
        printf("Do you want to play against the Bot?\n");
        printf("Enter Y for Yes, N for No: ");
        scanf(" %c", &ans);
        while (getchar() != '\n');
        while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
        {
            printf("Invalid input. Please enter Y or N: ");
            scanf(" %c", &ans);
            while (getchar() != '\n');
        }
        if (ans == 'Y' || ans == 'y')
        {
            gameMode = 1;
            printf("Bot not available.\n");
            return;
        }
        else
        {
            gameMode = 2;
            printf("You chose to play against other players.\n");
        }
        printf("Enter the number of players (from 2 to 4): ");
        while (scanf("%d", &numPlayers) != 1 || numPlayers < 2 || numPlayers > 4)
        {
            while (getchar() != '\n');
            printf("Invalid number of players. Please enter a number between 2 and 4: ");
        }
        while (getchar() != '\n');
        printf("You chose %d players.\n", numPlayers);
        printf("Enter the number of penguins between 1 and 4: ");
        while (scanf("%d", &N) != 1 || N < 1 || N > 4)
        {
            while (getchar() != '\n');
            printf("Invalid number of penguins. Please enter a number between 1 and 4: ");
        }
        while (getchar() != '\n');
        printf("You chose %d penguins.\n", N);
        min_map_size = max(2 * N, numPlayers) + 2;
        printf("Enter the number of rows (n) for the map (minimum %d): ", min_map_size);
        while (scanf("%d", &n) != 1 || n < min_map_size)
        {
            while (getchar() != '\n');
            printf("Invalid map size. n must be at least %d. Please enter it again: ", min_map_size);
        }
        while (getchar() != '\n');
        printf("Enter the number of columns (m) for the map (minimum %d): ", min_map_size);
        while (scanf("%d", &m) != 1 || m < min_map_size)
        {
            while (getchar() != '\n');
            printf("Invalid map size. m must be at least %d. Please enter it again: ", min_map_size);
        }
        while (getchar() != '\n');
        printf("You chose a map size of %d rows and %d columns.\n", n, m);
        printf("chosen game mode: %d\n", gameMode);
        printf("number of players: %d\n", numPlayers);
        printf("number of penguins: %d\n", N);
        printf("map size: %d rows, %d columns\n", n, m);
        printf("Type S to start the game, N to quit and E to edit settings.\n");
        scanf(" %c", &begin);
        while (getchar() != '\n');
        while (begin != 'S' && begin != 's' && begin != 'N' && begin != 'n' && begin != 'E' && begin != 'e')
        {
            printf("Invalid input. Please type S to start the game or N to quit: ");
            scanf(" %c", &begin);
            while (getchar() != '\n');
        }
        if (begin == 'N' || begin == 'n')
        {
            printf("Quitting the game...\n");
            return;
        }
        if (begin == 'S' || begin == 's')
        {
            printf("Starting the game...\n");
        }
    }
    if (numPlayers>=2)
    {
        printf("Enter the name of player 1 (max 10 characters): ");
        scanf("%10s", player1);
        while (getchar() != '\n');
        printf("Enter the name of player 2 (max 10 characters): ");
        scanf("%10s", player2);
        while (getchar() != '\n');
    }
    if(numPlayers>=3)
    {
        printf("Enter the name of player 3 (max 10 characters): ");
        scanf("%10s", player3);
        while (getchar() != '\n');
    }
    if(numPlayers==4)
    {
        printf("Enter the name of player 4 (max 10 characters): ");
        scanf("%10s", player4);
        while (getchar() != '\n');
    }
}
int main()
{
    READ();
    // GENERATE_MAP();
    //  PLACE_PENGUINS();
    //  PLAYING_GAME();
    //  SCOREBOARD();
    printf("%s\n", "Game Over");
    return 0;
}