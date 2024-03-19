#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MOD 1000000007

typedef struct {
  int x;
  int y;
} Coordinate;

int n, m, k;
Coordinate* minions;

// A utility function to check if a coordinate is within the grid
bool isWithinGrid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

// A utility function to check if a coordinate is occupied by a minion
bool isOccupiedByMinion(int x, int y) {
  for (int i = 0; i < k; i++) {
    if (minions[i].x == x && minions[i].y == y) {
      return true;
    }
  }
  return false;
}

// A recursive function to count the number of valid paths from a given coordinate to the safehouse
int countPaths(int x, int y) {
  // If we have reached the safehouse, return 1
  if (x == n - 1) {
    return 1;
  }

  // If the current coordinate is occupied by a minion, return 0
  if (isOccupiedByMinion(x, y)) {
    return 0;
  }

  // Count the number of valid paths from each of the four possible knight moves
  int count = 0;
  count += countPaths(x + 1, y + 2);
  count += countPaths(x + 1, y - 2);
  count += countPaths(x + 2, y + 1);
  count += countPaths(x + 2, y - 1);

  // Return the total number of valid paths modulo MOD
  return count % MOD;
}

int main() {
  // Read the input
  scanf("%d %d %d", &n, &m, &k);

  // Allocate memory for the minions array
  minions = malloc(sizeof(Coordinate) * k);

  // Read the coordinates of the minions
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &minions[i].x, &minions[i].y);
  }

  // Calculate the number of valid paths to each entrance of the safehouse
  int* paths = malloc(sizeof(int) * m);
  for (int i = 0; i < m; i++) {
    paths[i] = countPaths(0, i);
  }

  // Print the output
  for (int i = 0; i < m; i++) {
    printf("%d ", paths[i]);
  }
  printf("\n");

  // Free the allocated memory
  free(minions);
  free(paths);

  return 0;
}