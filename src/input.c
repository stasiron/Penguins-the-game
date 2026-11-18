// input.c - getting decisions from the human player:
// field coordinates from the keyboard (later also mouse clicks in the SDL version)
// and checking that the input has a sensible format.
// It does NOT check the game rules - that is done in rules.c.
// Task list: GitHub issue #1.

#include "input.h"

// TODO (issue #1):
// - read the game settings: mode, number of players, number of penguins, map size, player names
//   (code ready in READ() on branch "mikolaj" - not listed in issue #1 yet)
// - read field coordinates
// - read a move (from -> to)
// - handle invalid input (a letter instead of a number, an empty line)
// - (later) convert an SDL click to field coordinates
