#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <algorithm>


int main()
{
    srand(time(NULL));

    bool gameOver = false;
    std::string words[5] = {"snowman", "train", "penguin", "lion", "computer"};
    std::string answer = words[rand() % 5];
    
    std::vector<int> letterIndex;
    std::vector<char> allGuesses;
    int foundAmt = 0;
    int lives = 6;

    while(!gameOver && foundAmt < (answer.size())) {
        foundAmt = 0;

        std::cout << "\nyou have: " << lives << " lives" << std::endl;
        //for checking contents of the vector
        // for(std::vector<char>::const_iterator i = allGuesses.begin(); i != allGuesses.end(); ++i) {
        //     std::cout << *i << ' ';
        // }

        for(int i = 0; i < answer.length(); ++i) {
            auto findLetter = std::find(letterIndex.begin(), letterIndex.end(), i);

            if(findLetter != letterIndex.end()) {
                std::cout << answer[i];
                foundAmt++;
            } else {
                std::cout << "_ ";
            }
        }


        char guess = ' ';
        bool correct = false;
        std::cout << "\nGive a letter: ";
        std::cin >> guess;

        if(guess) {
            allGuesses.push_back(guess);
        }

        for(int j = 0; j < answer.length(); j++) {
            if(guess == answer[j]) {
                correct = true;
                letterIndex.push_back(j);
            }
        }

        auto dup = std::unique(allGuesses.begin(), allGuesses.end());
        bool wasUnique = (dup == allGuesses.end() );
        if(wasUnique == false) {
            std::cout << "You already guessed that" << std::endl;
        } else if(wasUnique == true && correct == false) {
            lives -= 1;
        } else if(wasUnique == false && correct == false) {
            lives = lives;
        }

        if(lives == 0) {
            gameOver = true;
            break;
        }
    }

    if(lives != 0) {
        std::cout << "You win!!\nThe word was " + answer << std::endl;
    } else {
        std::cout << "You lose" << std::endl;
    }

    return 0;
}