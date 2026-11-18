#ifndef GAME_H
#define GAME_H

// game.h - declarations of the game flow module (see game.c and GitHub issue #5).
// game.c connects all the other modules: it asks input.c for decisions, rules.c whether they are allowed,
// changes the board (board.c), adds points (player.c) and shows the result (display.c).

#include "input.h"   // Settings

// The full definitions are in board.h (issue #2) and player.h (issue #3).
// IMPORTANT for board.h / player.h: define them WITH the same tag name, e.g.
//   typedef struct Board { ... } Board;   and   typedef struct Player { ... } Player;
typedef struct Board Board;
typedef struct Player Player;

// Phase of the game.
typedef enum {
    PHASE_PLACEMENT,   // players place their penguins
    PHASE_MOVEMENT,    // players move their penguins and collect fish
    PHASE_GAME_OVER    // no player can move
} Phase;

// Game state: everything needed to know where the game is right now.
typedef struct {
    Board *board;              // the board (fields, fish, penguins)
    Player *players;           // array of players
    int num_players;           // number of players
    int penguins_per_player;   // how many penguins each player places
    Phase phase;               // current phase of the game
    int current_player;        // index of the player whose turn it is (0..num_players-1)
} GameState;

// Purpose: Prepares a new game from the settings: creates the board with random fish and the players.
// Arguments: game - pointer to the game state to fill, settings - settings read by read_settings().
// Result: Returns 1 if the game was prepared, 0 if there was not enough memory.
int game_init(GameState *game, const Settings *settings);

// Purpose: Runs the whole game: placement phase, movement phase, then shows the winner.
// Arguments: game - pointer to a game prepared by game_init().
// Result: none.
void game_run(GameState *game);

// Purpose: Placement phase loop: players take turns placing penguins until all penguins are placed.
// Arguments: game - pointer to the game state.
// Result: none (after it ends, game->phase is PHASE_MOVEMENT).
void run_placement_phase(GameState *game);

// Purpose: Movement phase loop: players take turns moving penguins until no player can move.
// Arguments: game - pointer to the game state.
// Result: none (after it ends, game->phase is PHASE_GAME_OVER).
void run_movement_phase(GameState *game);

// Purpose: Places a penguin of the current player on a field, if rules.c allows it.
// Arguments: game - pointer to the game state, row, col - coordinates of the field.
// Result: Returns 1 if the penguin was placed, 0 if the field is not allowed (nothing changes).
int place_penguin(GameState *game, int row, int col);

// Purpose: Makes a move of the current player: checks it in rules.c, then updates the board
//          (moves the penguin, removes the ice floe it left) and adds the fish to the player's score.
// Arguments: game - pointer to the game state, from_row, from_col - field with the penguin,
//            to_row, to_col - destination field.
// Result: Returns 1 if the move was made, 0 if the move is not allowed (nothing changes).
int make_move(GameState *game, int from_row, int from_col, int to_row, int to_col);

// Purpose: Switches the turn to the next player, skipping players who cannot act
//          (no penguins left to place in the placement phase, no possible move in the movement phase).
// Arguments: game - pointer to the game state.
// Result: none (game->current_player is updated).
void next_player(GameState *game);

// Purpose: Finds the player with the highest score at the end of the game.
// Arguments: game - pointer to the game state (read-only).
// Result: Returns the index of the winner, or -1 if there is a draw.
int determine_winner(const GameState *game);

// Purpose: Frees all memory used by the game (board and players).
// Arguments: game - pointer to the game state.
// Result: none.
void game_free(GameState *game);

#endif
