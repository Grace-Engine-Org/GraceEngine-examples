#include <iostream>

//Include example programs
#include "../BlankWindow/BlankWindow.h"
#include "../BouncingBall/BouncyBall.h"

void openProgram(int programNumber) {
  switch (programNumber) {
    case 1:
      blankWindow();
      break;
    case 2:
      bouncyBall();
      break;
    default:
      std::cout << "Invalid Program Number: " << programNumber << ". Terminating session.";
  }
}


int main() {
  std::string inputStream;

  std::cout << "Welcome to GraceEngine-examples, here we have a set of demo projects you can view, such as:\n";
  std::cout << "1. Blank Window\n";
  std::cout << "2. Bouncing Ball\n";
  std::cout << "\n";

  //Get user input
  getline(std::cin, inputStream);

  int programNum = 0;
  //Exit program if it is not an int
  try {
    programNum = stoi(inputStream);
  }
  catch (const std::exception& e) {
    std::cout << "Error, stopping program.";
    return 0;
  }

  std::cout << "Opening program " << programNum << "...\n";
  openProgram(programNum);


  return 0;
}