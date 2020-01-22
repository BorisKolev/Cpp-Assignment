#include <map>
#include <algorithm>
#include "ReadWords.h"
#include "ReadFilteredWords.h"
#include "FilterOne.h"
#include "FilterTwo.h"
#include "FilterThree.h"

using namespace std;

int main(){
    ofstream o("output.txt");
    // Variables
    string fileName;
    string filterToUse;
    map<string, int>theMap;
    int f1Occ = 0, f2Occ = 0, f3Occ = 0;

    // Enter file name
    cout << "Enter a file name: " << endl;
    getline(cin, fileName);

    // Get which filter
    cout << "Which filter would you like to use? (1,2,3): " << endl;
    getline(cin, filterToUse);

    bool useOne = false, useTwo = false, useThree = false;

    // Decide which option user has chosen
    if(filterToUse == "1"){
        useOne = true;
    }

    else if(filterToUse == "2"){
        useTwo = true;
    }

    else if(filterToUse == "3"){
        useThree = true;
    }

    /* If they choose filter 1
     * Open the file
    */
     if(useOne){
        FilterOne f1(fileName.c_str());

        bool end = false;
        string word;

        // While not at the end of the file
        // Get filtered words until an empty string is returned
        while(!end){
            word = f1.getNextFilteredWord();
            if(word.empty()){
                end = true;
            }
            // If word is already in map -> Add to its value
            // If not, add word to map with initial value of 1
            else{
                if(theMap.count(word) != 0){
                    theMap[word]++;
                } else if(theMap.count(word) == 0){
                    theMap.emplace(word, 1);
                }
                o << word << ": " << theMap.count(word) << endl;
            }
        }
        f1.close();
    }

    // Same functionality except it uses filter 2
    else if(useTwo){
        FilterTwo f2(fileName.c_str());
        bool end = false;
        string word;

        while(!end){
            word = f2.getNextFilteredWord();
            if(word.empty()){
                end = true;
            }
            else{
                if(theMap.count(word) > 0){
                    theMap[word]++;
                } else{
                    theMap.emplace(word, 1);
                }
            }
        }
        f2.close();
    }

    // Same functionality except uses filter 3
    else if(useThree){
        FilterThree f3(fileName.c_str());
        bool end = false;
        string word;

        while(!end){
            word = f3.getNextFilteredWord();
            if(word.empty()){
                end = true;
            }
            else{
                if(theMap.count(word) > 0){
                    theMap[word]++;
                } else{
                    theMap.emplace(word, 1);
                }
            }
        }
        f3.close();
    }

    cout << "Size of map: " << theMap.size() << endl;

    // Iterate through map, compare values to find largest
    map<string, int>::iterator it;
    string maxKey;
    int max = 0;
    int numOfSameMax = 0;

    for(it = theMap.begin(); it != theMap.end(); ++it){
        if(it->second > max){
            maxKey = it->first;
            max = it->second;
        }

    }

    // Check to see how many have the same value as the max value
    for(it = theMap.begin(); it != theMap.end(); ++it){
        if(it->second == max){
            numOfSameMax++;
        }
    }

    string minKey;
    int min = max;
    int numOfSameMin = 0;

    // Iterate through map, compare values to find smallest
    for(it = theMap.begin(); it != theMap.end(); ++it){
        if(it ->second <= min){
            minKey = it ->first;
            min = it ->second;
        }
    }

    // Check how many others have the same value as the min value
    for(it = theMap.begin(); it != theMap.end(); ++it){
        if(it->second == min){
            numOfSameMin++;
        }
    }

    cout << "Word with the most occurrences: '" << maxKey << "':" << max << "  ---  and " << numOfSameMax - 1 << " more words." << endl;
    cout << "Word with the least occurrences: '" << minKey << "':"<< min << "  ---  and " << numOfSameMin - 1 << " more words." << endl;

    for(auto pair: theMap) o << pair.first << ": " << pair.second << std::endl;
}