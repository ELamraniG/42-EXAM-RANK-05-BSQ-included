# Game of Life - Code Explanation

## Overview
This program implements Conway's Game of Life. You provide a grid size and number of iterations, draw initial cells using WASD controls, and it simulates the cellular automaton.

---

## Functions

### 1. `print_map(t_game game)` (lines 3-11)
Prints the current state of the game board to stdout.
- Loops through each row (`y`) and column (`x`)
- Prints each cell character (`'O'` for alive, `' '` for dead)
- Adds a newline after each row

---

### 2. `free_map(t_game *game)` (lines 13-22)
Frees all dynamically allocated memory for the map.
- First frees each row (`game->map[i]`)
- Then frees the array of row pointers (`game->map`)
- Checks for NULL before freeing to avoid crashes

---

### 3. `fill_map(t_game *game)` (lines 24-43)
Reads user input to draw cells on the map using WASD controls.

**Variables:**
- `x, y` = cursor position (starts at 0,0)
- `draw` = toggle for drawing mode (false initially)

**Controls:**
| Key | Action |
|-----|--------|
| `w` | Move cursor up |
| `a` | Move cursor left |
| `s` | Move cursor down |
| `d` | Move cursor right |
| `x` | Toggle draw mode on/off |

When `draw` is true, sets current cell to `'O'` (alive) after each move.

---

### 4. `count_neighbors(t_game game, int y, int x)` (lines 45-63)
Counts how many alive neighbors a cell has (for Game of Life rules).
- Checks all 8 surrounding cells (dx and dy from -1 to 1)
- Skips the cell itself (`dx == 0 && dy == 0`)
- Checks bounds to avoid out-of-bounds access
- Returns count of neighbors with `'O'`

---

### 5. `play_game(t_game *game)` (lines 65-92)
Executes one iteration of Conway's Game of Life.
- Creates a new map to store the next generation

**Rules applied:**
| Current State | Neighbors | Result |
|---------------|-----------|--------|
| Alive (`'O'`) | 2 or 3 | Survives |
| Alive (`'O'`) | < 2 or > 3 | Dies |
| Dead (`' '`) | Exactly 3 | Becomes alive |
| Dead (`' '`) | != 3 | Stays dead |

- Frees the old map and replaces it with the new one

---

### 6. `init_game(t_game *game, const char **argv)` (lines 94-106)
Initializes the game state from command-line arguments.
- Parses `argv[1]` → width
- Parses `argv[2]` → height
- Parses `argv[3]` → number of iterations
- Allocates the 2D map and fills it with spaces (dead cells)

---

### 7. `main(int argc, const char **argv)` (lines 108-125)
Entry point - orchestrates everything:
1. Validates that exactly 3 arguments are provided
2. Calls `init_game()` to set up the board
3. Calls `fill_map()` to read user input and place cells
4. Runs `play_game()` for the specified number of iterations
5. Prints the final state with `print_map()`
6. Cleans up memory with `free_map()`

---

## Usage Example

```bash
# Create a 3x3 grid, run 1 iteration
./life 3 3 1

# Type: dxss (move right, enable draw, move down twice)
# Press Ctrl+D to end input
```

This draws a vertical line of 3 cells, then applies Game of Life rules once.

---

## Conway's Game of Life Rules Summary

1. **Underpopulation:** A live cell with < 2 neighbors dies
2. **Survival:** A live cell with 2-3 neighbors survives
3. **Overpopulation:** A live cell with > 3 neighbors dies
4. **Reproduction:** A dead cell with exactly 3 neighbors becomes alive