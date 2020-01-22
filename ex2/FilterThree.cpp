
#include "FilterThree.h"

bool FilterThree::filter(std::string word) {
    int puncCount = 0;

    // Iterate through the word one character at a time
    for(int i = 0; i < word.length(); i++){
        // Check if character is punctuation, if it is then add to count
        if(ispunct(word[i])){
            puncCount++;
        }
    }
    // If word contains punctuation character return true
    // Otherwise return false
    return puncCount == 1;
};
