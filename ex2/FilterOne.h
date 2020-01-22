#ifndef ASSIGNMENT_2_FILTERONE_H
#define ASSIGNMENT_2_FILTERONE_H

#include "ReadFilteredWords.h"

// FILTER: At least one upper-case, no lower case

class FilterOne: public ReadFilteredWords{
public:
    // Constructor
    FilterOne(const char *fileName) : ReadFilteredWords(fileName){
    }

    // Override the filter function
    bool filter(std::string word) override;
};

#endif
