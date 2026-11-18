// input.c - getting decisions from the human player:
// field coordinates from the keyboard (later also mouse clicks in the SDL version)
// and checking that the input has a sensible format.
// It does NOT check the game rules - that is done in rules.c.
// Task list: GitHub issue #1.

#include <stdio.h>
#include <string.h>
#include "input.h"

// TODO (issue #1):
// - [x] read the game settings: mode, number of players, number of penguins, map size, player names
//       (moved here from READ() on branch "mikolaj")
// - [ ] read field coordinates
// - [ ] read a move (from -> to)
// - [ ] handle invalid input (a letter instead of a number, an empty line)
// - [ ] (later) convert an SDL click to field coordinates

// Purpose: Returns the bigger of two numbers (used for the minimum map size).
// Arguments: a, b - numbers to compare.
// Result: The bigger number.
static int max_int(int a, int b)
{
    return (a > b) ? a : b;
}

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int all_names_different(char names[][MAX_NAME_LEN + 1], int count)
{
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (strcmp(names[i], names[j]) == 0)
                return 0;   // found two identical names
    return 1;               // all names are different
}

void read_player_names(char names[][MAX_NAME_LEN + 1], int count)
{
    int ok = 0;
    do
    {
        for (int i = 0; i < count; i++)
        {
            printf("Enter the name of player %d (max %d characters): ", i + 1, MAX_NAME_LEN);
            scanf("%10s", names[i]);
            clear_input_buffer();
        }
        ok = all_names_different(names, count);
        if (!ok)
            printf("All player names must be different. Please enter them again.\n");
    } while (!ok);
}

int read_settings(Settings *settings)
{
    int max_map_size = 100;   // maximum number of rows / columns
    int min_map_size = 0;     // minimum map size based on number of penguins and players
    char ans = 0;             // answer to the "play against the Bot?" question
    char begin = 0;           // B - begin the game, Q - quit, E - edit settings

    // start with everything set to 0, so no field contains random values if the user quits early
    settings->mode = 0;       // 0 - not selected, 1 - against the Bot, 2 - against other players
    settings->num_players = 0;
    settings->num_penguins = 0;
    settings->rows = 0;
    settings->cols = 0;

    while (begin != 'B' && begin != 'b')
    {
        printf("Do you want to play against the Bot?\n");
        printf("Enter Y for Yes, N for No: ");
        scanf(" %c", &ans);
        clear_input_buffer();
        while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
        {
            printf("Invalid input. Please enter Y or N: ");
            scanf(" %c", &ans);
            clear_input_buffer();
        }
        if (ans == 'Y' || ans == 'y')
        {
            settings->mode = 1;
            printf("Bot not available.\n");
            return 0;
        }
        settings->mode = 2;
        printf("You chose to play against other players.\n");

        printf("Enter the number of players between 2 and 4: ");
        while (scanf("%d", &settings->num_players) != 1 || settings->num_players < 2 || settings->num_players > 4)
        {
            clear_input_buffer();
            printf("Invalid number of players. Please enter a number between 2 and 4: ");
        }
        clear_input_buffer();
        printf("You chose %d players.\n", settings->num_players);

        printf("Enter the number of penguins between 1 and 4: ");
        while (scanf("%d", &settings->num_penguins) != 1 || settings->num_penguins < 1 || settings->num_penguins > 4)
        {
            clear_input_buffer();
            printf("Invalid number of penguins. Please enter a number between 1 and 4: ");
        }
        clear_input_buffer();
        printf("You chose %d penguins.\n", settings->num_penguins);

        min_map_size = max_int(settings->num_penguins, settings->num_players) * 2 + 2;
        printf("Enter the number of rows (n) for the map between %d and %d: ", min_map_size, max_map_size);
        while (scanf("%d", &settings->rows) != 1 || settings->rows < min_map_size || settings->rows > max_map_size)
        {
            clear_input_buffer();
            printf("Invalid map size. n must be between %d and %d. Please enter it again: ", min_map_size, max_map_size);
        }
        clear_input_buffer();
        printf("Enter the number of columns (m) for the map between %d and %d: ", min_map_size, max_map_size);
        while (scanf("%d", &settings->cols) != 1 || settings->cols < min_map_size || settings->cols > max_map_size)
        {
            clear_input_buffer();
            printf("Invalid map size. m must be between %d and %d. Please enter it again: ", min_map_size, max_map_size);
        }
        clear_input_buffer();
        printf("You chose a map size of %d rows and %d columns.\n", settings->rows, settings->cols);

        printf("chosen game mode: %d\n", settings->mode);
        printf("number of players: %d\n", settings->num_players);
        printf("number of penguins: %d\n", settings->num_penguins);
        printf("map size: %d rows, %d columns\n", settings->rows, settings->cols);
        printf("Type B to begin the game, Q to quit and E to edit settings.\n");
        scanf(" %c", &begin);
        clear_input_buffer();
        while (begin != 'B' && begin != 'b' && begin != 'Q' && begin != 'q' && begin != 'E' && begin != 'e')
        {
            printf("Invalid input. Type B to begin the game, Q to quit and E to edit settings: \n");
            scanf(" %c", &begin);
            clear_input_buffer();
        }
        if (begin == 'Q' || begin == 'q')
        {
            printf("Quitting the game...\n");
            return 0;
        }
    }

    read_player_names(settings->names, settings->num_players);
    printf("Starting the game...\n");
    return 1;
}
