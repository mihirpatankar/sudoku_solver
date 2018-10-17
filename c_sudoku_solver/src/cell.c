#include "cell.h"

sudoku_cell*** create_init_cell_grid(int** sudoku)
{
  sudoku_cell*** cell_grid = NULL;

  cell_grid = (sudoku_cell***)malloc(sizeof(sudoku_cell**)*ROWS);

  for(int i=0;i<ROWS;i++)
  {
    cell_grid[i] = (sudoku_cell**)malloc(sizeof(sudoku_cell*)*COLS);
    for(int j=0;j<COLS;j++)
    {
      cell_grid[i][j] = (sudoku_cell*)malloc(sizeof(sudoku_cell));
      cell_grid[i][j]->row = i;
      cell_grid[i][j]->col = j;
      cell_grid[i][j]->box = (i/3)*3 + (j/3);
      cell_grid[i][j]->number = sudoku[i][j];
      cell_grid[i][j]->possible_cnt = 0;
      if(cell_grid[i][j]->number == 0)
      {
        cell_grid[i][j]->possible_cnt = POSSIBILITIES;
        for(int p=0;p<POSSIBILITIES;p++)
        {
          cell_grid[i][j]->possible[p] = 1;
        }
      }
      else
      {
        /* TODO: Update a global unsolved count */
      }
    }
  }

  return cell_grid;
}

void update_cell_grid(sudoku_cell*** cell_grid)
{
  for(int i=0;i<ROWS;i++)
  {
    for(int j=0;j<COLS;j++)
    {
      if(cell_grid[i][j]->number != 0)
      {
        remove_possibilities(cell_grid,
                             cell_grid[i][j]->row,
                             cell_grid[i][j]->col,
                             cell_grid[i][j]->box);
      }
    }
  }
}

void decrement_possible_cnt(sudoku_cell* cell)
{
  cell->possible_cnt--;
  if(cell->possible_cnt == 1)
  {
    update_sudoku_number(cell);
    /* TODO: Update a global unsolved count */
  }
}

void update_sudoku_number(sudoku_cell* cell)
{
  for(int p=0;p<POSSIBILITIES;p++)
  {
    if(cell->possible[p] == 1)
    {
      cell->number = p+1;
      cell->possible[p] = 0;
      decrement_possible_cnt(cell);
      break;
    }
  }
}

void remove_possibilities(sudoku_cell*** cell_grid, int row, int col, int box)
{
  int number = cell_grid[row][col]->number - 1;

  /* Remove the number from row */
  for(int i=0;i<ROWS;i++)
  {
    if(cell_grid[i][col]->number == 0 &&
        cell_grid[i][col]->possible[number] == 1)
    {
      cell_grid[i][col]->possible[number] = 0;
      decrement_possible_cnt(cell_grid[i][col]);
    }
  }

  /* Remove the number from column */
  for(int j=0;j<COLS;j++)
  {
    if(cell_grid[row][j]->number == 0 &&
        cell_grid[row][j]->possible[number] == 1)
    {
      cell_grid[row][j]->possible[number] = 0;
      decrement_possible_cnt(cell_grid[row][j]);
    }
  }

  /* TODO : Remove the number from box */
}
