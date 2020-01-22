#include "ReadFilteredWords.h"

string ReadFilteredWords::getNextFilteredWord() {
    string nextWord;
    // While there is another word, get the word and put it through the filter
    while(isNextWord()){
        nextWord = getNextWord();
        if(filter(nextWord)){
            return nextWord;
        }
    }
    // Clear the next word variable just in case it messes with the output of the next test
    nextWord = "";

    return nextWord;
}
