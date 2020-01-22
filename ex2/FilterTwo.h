
#ifndef ASSIGNMENT_2_FILTERTWO_H
#define ASSIGNMENT_2_FILTERTWO_H

#include "ReadFilteredWords.h"

// FILTER: At least one letter, and at least one numeric digit

class FilterTwo : public ReadFilteredWords{
public:
    // Constructor
    FilterTwo(const char *fileName) : ReadFilteredWords(fileName){
    }

    // Override the filter function
    bool filter(std::string word) override;
};


#endif
