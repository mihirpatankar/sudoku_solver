#ifndef INC_CELL_H_
#define INC_CELL_H_

#include "common.h"

#define POSSIBILITIES 9

typedef struct sudoku_cell{
  int number;
  int row, col, box;
  int possible_cnt;
  int possible[POSSIBILITIES];
}sudoku_cell;

sudoku_cell*** create_init_cell_grid(int** sudoku);
void remove_possibilities(sudoku_cell*** cell_grid, int row, int col, int box);
void check_sudoku(sudoku_cell*** cell_grid);
void update_sudoku_number(sudoku_cell* cell);
void decrement_possible_cnt(sudoku_cell* cell);
void update_cell_grid(sudoku_cell*** cell_grid);

#endif /* INC_CELL_H_ */
