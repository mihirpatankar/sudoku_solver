#include "common.h"
#include "sudoku.h"
#include "cell.h"

int main(){
  int** sudoku = NULL;
  sudoku = create_sudoku();

  sudoku_cell*** cell_grid = create_init_cell_grid(sudoku);
  print_sudoku(cell_grid);
  for(int i=0;i<1;i++)
  {
    update_cell_grid(cell_grid);
  }
  print_sudoku(cell_grid);
  return 0;
}
