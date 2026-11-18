#ifndef INPUT_H
#define INPUT_H

// input.h - declarations of the input module (see input.c and GitHub issue #1).
// The input module only reads data from the player and checks its FORMAT
// (a number where a number is expected, a letter from the allowed set, no empty line).
// It does NOT check the game rules - that is done in rules.c.

#define MAX_PLAYERS 9     // agree with the team: src/main.c allows 2-9, READ() on branch "mikolaj" allows 2-4
#define MAX_NAME_LEN 10   // maximum length of a player name (without the terminating zero)

// Game settings chosen by the user before the game starts.
// Filled by read_settings(), used by game_init() in game.c.
typedef struct {
    int mode;                                   // 1 - against the bot, 2 - human players only
    int num_players;                            // number of players (2..MAX_PLAYERS)
    int num_penguins;                           // penguins per player (1..4)
    int rows;                                   // number of rows of the board (n)
    int cols;                                   // number of columns of the board (m)
    char names[MAX_PLAYERS][MAX_NAME_LEN + 1];  // player names, all different
} Settings;

// Purpose: Reads all game settings from the keyboard (mode, number of players, number of penguins,
//          map size, player names). Every value is validated and asked again if it is wrong.
//          At the end shows a summary and asks: start / enter again / quit.
// Arguments: settings - pointer to the struct that will be filled.
// Result: Returns 1 if the user chose to start the game, 0 if the user chose to quit.
int read_settings(Settings *settings);

// Purpose: Reads names of all players; repeats until every name is non-empty and all names are different.
// Arguments: names - array to fill (one row per player), count - number of players.
// Result: none.
void read_player_names(char names[][MAX_NAME_LEN + 1], int count);

// Purpose: Checks if all player names are different.
// Arguments: names - array of names, count - number of names to check.
// Result: Returns 1 if all names are different, 0 if at least two are the same.
int all_names_different(char names[][MAX_NAME_LEN + 1], int count);

// Purpose: Reads one integer from the keyboard; repeats until the input is a number from min to max.
// Arguments: prompt - text shown to the user, min, max - allowed range (inclusive).
// Result: Returns the number entered by the user (always min..max).
int read_int_in_range(const char *prompt, int min, int max);

// Purpose: Reads one letter; repeats until it is one of the allowed letters (case does not matter).
// Arguments: prompt - text shown to the user, allowed - allowed letters, e.g. "YN".
// Result: Returns the chosen letter as an uppercase character.
char read_choice(const char *prompt, const char *allowed);

// Purpose: Reads coordinates of one field (row and column), e.g. where to place a penguin.
//          Checks only the format (two integers); whether the field is inside the board
//          and allowed is checked by board.c and rules.c.
// Arguments: row, col - pointers where the read coordinates are stored.
// Result: Returns 1 if the coordinates were read, 0 if the input ended (EOF).
int read_coordinates(int *row, int *col);

// Purpose: Reads a move: coordinates of the starting field (from) and the destination field (to).
// Arguments: from_row, from_col - pointers for the starting field, to_row, to_col - pointers for the destination field.
// Result: Returns 1 if the move was read, 0 if the input ended (EOF).
int read_move(int *from_row, int *from_col, int *to_row, int *to_col);

// Purpose: Removes the rest of the current input line (everything up to and including the newline),
//          so that wrong characters do not break the next read.
// Arguments: none.
// Result: none.
void clear_input_buffer(void);

// (later, SDL version) Purpose: Converts a mouse click position to field coordinates.
// int click_to_field(int x, int y, int *row, int *col);

#endif
