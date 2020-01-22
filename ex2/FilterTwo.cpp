
#include "FilterTwo.h"

bool FilterTwo::filter(std::string word) {
    bool hasAlpha = false;
    bool hasDigit = false;

    // Iterate through the word one character at a time
    for(int i = 0; i < word.length(); i++){
        // If is alphanumeric character, make a note of it
        if(isalpha(word[i])){
            hasAlpha = true;
        }
        // If digit, make a note of it
        if(isdigit(word[i])){
            hasDigit = true;
        }
    }
    // If satisfies the filter, return true
    // Otherwise it hasn't satisfied the filter, thus return false
    return hasAlpha && hasDigit;
};
