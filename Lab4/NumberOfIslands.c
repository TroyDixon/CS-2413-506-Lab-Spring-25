#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
void visit(char **grid, int i, int j, int gridSize, int *gridColSize) {
  if (i < 0 || j < 0 || i >= gridSize) {
    return;
  }
  if (j >= gridColSize[i]) {
    return;
  }
  if (grid[i][j] == '0') {
    return;
  }
  grid[i][j] = '0';
  visit(grid, i - 1, j, gridSize, gridColSize);
  visit(grid, i + 1, j, gridSize, gridColSize);
  visit(grid, i, j - 1, gridSize, gridColSize);
  visit(grid, i, j + 1, gridSize, gridColSize);
}
int numIslands(char **grid, int gridSize, int *gridColSize) {
  int i;
  int j;
  int count;

  for (i = 0; i < gridSize; i++) {
    for (j = 0; j < gridColSize[i]; j++) {
      if (grid[i][j] == '1') {
        visit(grid, i, j, gridSize, gridColSize);
        count++;
      }
    }
  }
  return count;
}
