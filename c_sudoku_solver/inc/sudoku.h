#ifndef INC_SUDOKU_H_
#define INC_SUDOKU_H_

#include "common.h"
#include "cell.h"

int** create_sudoku();
void print_sudoku(sudoku_cell*** cell_grid);

#endif /* INC_SUDOKU_H_ */
