
#include "FilterOne.h"

bool FilterOne::filter(std::string word) {
    bool hasUpperCase = false;
    bool hasLowerCase = false;

    // Iterate through the word one character at a time
    for(int i = 0; i < word.length(); i++){
        // if its upper case, make a note of it
        // If lower case, make a note of it
        if(isupper(word[i])){
            hasUpperCase = true;
        } else if(islower(word[i])){
            hasLowerCase = true;
        }
    }
    // If satisfies the filter, return true
    // Otherwise it hasn't satisfied the filter, thus return false
    return hasUpperCase && (!hasLowerCase);
};
