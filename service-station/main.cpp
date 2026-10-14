#include "project.h"
#include <string>

int main() {
  string arr[15] = {"Car 1",  "Car 2",  "Car 3",  "Car 4",  "Car 5",
                   "Car 6",  "Car 7",  "Car 8",  "Car 9",  "Car 10",
                   "Car 11", "Car 12", "Car 13", "Car 14", "Car 15"};
                   
  timeBasedSimulation(arr, 15);

  return 0;
}