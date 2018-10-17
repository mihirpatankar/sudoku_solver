#include "sudoku.h"

int** create_sudoku()
{
  int** sudoku = NULL;
  /* TODO : read input from file and update input */
  int input[ROWS][COLS] = {  {0,1,9,   0,0,2,    0,0,0},
                             {4,7,0,   6,9,0,    0,0,1},
                             {0,0,0,   4,0,0,    0,9,0},

                             {8,9,4,   5,0,7,    0,0,0},
                             {0,0,0,   0,0,0,    0,0,0},
                             {0,0,0,   2,0,1,    9,5,8},

                             {0,5,0,   0,0,6,    0,0,0},
                             {6,0,0,   0,2,8,    0,7,9},
                             {0,0,0,   1,0,0,    8,6,0}};

  sudoku = (int**)malloc(sizeof(int*)*ROWS);

  for(int i=0;i<ROWS;i++)
  {
    sudoku[i] = (int*)malloc(sizeof(int)*COLS);
    for(int j=0;j<COLS;j++)
    {
      sudoku[i][j] = input[i][j];
    }
  }

  return sudoku;
}

void print_sudoku(sudoku_cell*** cell_grid)
{
  printf("-------------------------------\n");
  for(int i=0;i<ROWS;i++)
  {
    printf("|");
    for(int j=0;j<COLS;j++)
    {
      printf(" %d ",cell_grid[i][j]->number);
      if(((j+1)%3) == 0)
      {
        printf("|");
      }
    }
    printf("\n");
    if(((i+1)%3) == 0)
    {
      printf("-------------------------------\n");
    }
  }
}
