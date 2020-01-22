
#ifndef ASSIGNMENT_2_FILTERTHREE_H
#define ASSIGNMENT_2_FILTERTHREE_H

#include "ReadFilteredWords.h"

// FILTER: Exactly one punctuation character

class FilterThree : public ReadFilteredWords{
public:
    // Constructor
    FilterThree(const char *fileName) : ReadFilteredWords(fileName){

    }

    // Override the filter function
    bool filter(std::string word) override;
};

#endif
