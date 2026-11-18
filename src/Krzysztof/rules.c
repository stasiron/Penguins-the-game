// rules.h
// Only "is it allowed?" questions: checks if placing a penguin or moving from A to B is legal (straight line, no holes, no jumping over penguins), if a penguin/player has any move left, and if the game is over.
// Does NOT change anything on the board – it only returns 1 (true) or 0 (false).
// Note: More rules and validation conditions will be added during the development of the game functions.

// Purpose: Checks if it is allowed to place a penguin on the specified field.
// Arguments: board - pointer to the game board (read-only), row - target row index, col - target column index.
// Result: Returns 1 if placement is legal, 0 otherwise.


// Purpose: Checks if moving a penguin from field A to field B is legal (straight line, no holes, no jumping over penguins).
// Arguments: board - pointer to the game board (read-only), from_row, from_col - starting coordinates (A), to_row, to_col - destination coordinates (B).
// Result: Returns 1 if the move is allowed, 0 otherwise.


// Purpose: Checks if a specific penguin has at least one valid move in any direction.
// Arguments: board - pointer to the game board (read-only), row, col - current coordinates of the penguin.
// Result: Returns 1 if at least one move is possible, 0 otherwise.


// Purpose: Checks if a given player has any valid move left with any of their penguins.
// Arguments: board - pointer to the game board (read-only), player_id - ID of the player being checked.
// Result: Returns 1 if the player can make a move, 0 otherwise.


// Purpose: Checks if the game has ended (no player has any legal moves left).
// Arguments: board - pointer to the game board (read-only).
// Result: Returns 1 if the game is over, 0 otherwise.