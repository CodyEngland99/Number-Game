#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

//function definition
int RandomNumberGenerator();
bool CheckWinProcess(int randomNumber, std::string userInput);
std::string InputValidate(std::string input);

int main() {
  std::cout << "Welcome to the number game" << std::endl;

  std::string playAgain = "Y";

  do {
    int lives = 3;

    int randomNumber = RandomNumberGenerator();

    while(lives > 0) {
      std::string userInput;

    std::cout << "Guess a number 1-10" << std::endl;

    std::getline(std::cin, userInput); 

    std::string inputChecking = InputValidate(userInput);
    
    bool checkWin = CheckWinProcess(randomNumber, inputChecking);

    if(checkWin) {
      std::cout << "Good job! You have won the game" << std::endl;
      break;
    } else {
      lives--;

      if(lives == 0) {
        std::cout << "Sorry you did not win. :(" << std::endl;
        break;
      }

      std::cout << "Sorry you did not guess the correct number you have " << lives << " lives left" << std::endl;
    }
    }

    std::cout << "Would you like to play again? (Y / N)" << std::endl;
    std::cin >> playAgain;

    std::cin.ignore();

  } while (playAgain == "y" || playAgain == "Y");


  return 0;
}

int RandomNumberGenerator() {
  return rand() % 10 + 1;
}

bool CheckWinProcess(int randomNumber, std::string userInput) {

  int input = std::stoi(userInput);

  if(input != randomNumber) {
    return false;
  }

  return true;
}

std::string InputValidate(std::string input) {
  for(char x : input) {
    if(!isdigit(x)) {
      return "0";
    }
  }

  return input;
}