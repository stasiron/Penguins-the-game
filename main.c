#include <stdio.h>
#include <string.h>
int all_names_different(char names[][11], int count)
{
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (strcmp(names[i], names[j]) == 0)
                return 0;   // znaleziono dwie takie same nazwy
    return 1;               // wszystkie różne
}
int max(int a, int b)
{
    return (a > b) ? a : b; //makro or define for more efficient 
}
void READ()
{
    int max_map_size = 100;                                  // maximum map size based on number of penguins and players
    int gameMode = 0;                                        // 0 - not selected, 1 - against Bot, 2 - against players
    char ans = 0;                                            // Variable
    char begin = 0;                                          // Variable to start the game
    int numPlayers = 0;                                      // number of players
    int N = 0;                                               // number of penguins
    int min_map_size = 0;                                    // minimum map size based on number of penguins and players
    int n = 0, m = 0;                                        // number of rows and columns for the map
    char players[4][11];                                     // player names

    while (begin != 'B' && begin != 'b' && begin != 'Q' && begin != 'q')
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
        printf("Enter the number of players between 2 and 4: ");
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
        min_map_size = max(N, numPlayers)*2 + 2;
        printf("Enter the number of rows (n) for the map beetween %d and %d: ", min_map_size, max_map_size);
        while (scanf("%d", &n) != 1 || n < min_map_size || n > max_map_size)
        {
            while (getchar() != '\n');
            printf("Invalid map size. n must be between %d and %d. Please enter it again: ", min_map_size, max_map_size);
        }
        while (getchar() != '\n');
        printf("Enter the number of columns (m) for the map between %d and %d: ", min_map_size, max_map_size);
        while (scanf("%d", &m) != 1 || m < min_map_size || m > max_map_size)
        {
            while (getchar() != '\n');
            printf("Invalid map size. m must be between %d and %d. Please enter it again: ", min_map_size, max_map_size);
        }
        while (getchar() != '\n');
        printf("You chose a map size of %d rows and %d columns.\n", n, m);
        printf("chosen game mode: %d\n", gameMode);
        printf("number of players: %d\n", numPlayers);
        printf("number of penguins: %d\n", N);
        printf("map size: %d rows, %d columns\n", n, m);
        printf("Type B to begin the game, Q to quit and E to edit settings.\n");
        scanf(" %c", &begin);
        while (getchar() != '\n');
        while (begin != 'B' && begin != 'b' && begin != 'Q' && begin != 'q' && begin != 'E' && begin != 'e')
        {
            printf("Invalid input. Type B to begin the game, Q to quit and E to edit settings: \n");
            scanf(" %c", &begin);
            while (getchar() != '\n');
        }
        if (begin == 'Q' || begin == 'q')
        {
            printf("Quitting the game...\n");
            return;
        }
        if (begin == 'B' || begin == 'b')
        {
            printf("Starting the game...\n");
        }
    }
        int ok = 0;
    do
    {
        for (int i = 0; i < numPlayers; i++)
        {
            printf("Enter the name of player %d (max 10 characters): ", i + 1);
            scanf("%10s", players[i]);
            while (getchar() != '\n');
        }
        ok = all_names_different(players, numPlayers);
        if (!ok)
            printf("All player names must be different. Please enter them again.\n");
    } while (!ok);
}
int main()
{
    READ();
    // GENERATE_MAP();
    //  PLACE_PENGUINS();
    //  PLAYING_GAME();
    //  SCOREBOARD();
    return 0;
}