#include <iostream>
#include <vector>
#include "ufo_functions.hpp"

int main() {
  std::string codeword = "codecademy";
  std::string answer = "__________";
  int misses = 0;
  int totalGuesses = 7;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;
  greet();
  while(answer != codeword && misses < totalGuesses){
      int difference = totalGuesses - misses;
    std::cout<< "\nHint: the word is " << codeword.size() << " letters long \n";
    std::cout<< "You have this number of guesses left: "<< difference << "\n";
    std::cout<< "What is your guess? ";\
    std::cin>> letter;
    for(int k = 0; k < codeword.size(); k++){
      if(letter == codeword[k]){
        answer[k] = letter;
        guess = true;
      }
    }
    if(guess){
      std::cout<< "Correct!\n";
    }else {
      std::cout<< "Incorrect guess\n";
      incorrect.push_back(letter);
      misses++;
    }
    display_misses(misses);
    display_status(incorrect, answer);
    guess = false;
  }
  end_game(answer, codeword);
}
