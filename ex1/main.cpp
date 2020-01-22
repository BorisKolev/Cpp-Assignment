#include <iostream>
#include "Person.h"
#include "Student.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>

void firstFunction(vector<Student>&, float);
// firstFunction - printing the students who have a maximum mark that is greater than or equal to the second argument
// @param vector<Student>& collection of students, float - user input

void secondFunction(vector<Student>&, string, float);
// secondFunction - print the name and the mark of the students for the module who have less or equal to the third argument
// @param vector<Student>& collection of students, string - module, float - mark

int main()
{
    char studsFileName[50]; // The name of the student file will be stored here
    ifstream studsFileObj; // this file object will be used for reading
    cout << "Enter the name of the file ---> ";
    cin.getline(studsFileName, 50); // store the name in studsFileName
    studsFileObj.open(studsFileName); // opens the file

    // In case file cannot be opened
    if(!studsFileObj.is_open()){
        cout << "Wrong file" << endl;
        exit(EXIT_FAILURE);
    }

    // Students information will be stored in myClass vector
    vector<Student> myClass;
    int regNumber;
    string fName;
    string sName;
    string fullName;

    // Reading from the file, creating the objects and then passing them to the vector
    while(studsFileObj.good()){
        studsFileObj >> regNumber;
        studsFileObj >> fName;
        studsFileObj >> sName;
        fullName = fName + " " + sName;
        Student newStudent(fullName, regNumber);
        myClass.push_back(newStudent);
    }

    char marksFileName[50];
    ifstream marksFileObj; // this file object will be used for reading
    cout << "Enter the name of the file ---> ";
    cin.getline(marksFileName, 50);
    marksFileObj.open(marksFileName); // opens the file

    // In case file cannot be opened
    if(!marksFileObj.is_open()){
        cout << "Wrong file" << endl;
        exit(EXIT_FAILURE);
    }

    string moduleNum;
    int regNum;
    float mark;
    unsigned int vectorSize = myClass.size();

    // ADDING THE MARKS FOR EACH STUDENT IN THE VECTOR
    vector<Student>::iterator it;
    while(marksFileObj.good()){
        marksFileObj >> moduleNum;
        marksFileObj >> regNum;
        marksFileObj >> mark;
        for(it = myClass.begin(); it != myClass.end(); it++){
            regNumber = it->getRegNo();
            if(regNum == regNumber){
                it->addMark(moduleNum, mark);
            }
        }
    }

    cout << endl;

    // Creating iterators for the vector and the map
    vector<Student>::iterator vecIt;
    map<string, float>::iterator mapIt;
    map<string, float> map;
    for(vecIt = myClass.begin(); vecIt != myClass.end(); ++vecIt){ // Iterating the student vector
        map = vecIt->getMap(); // Getting the map
        for(mapIt = map.begin(); mapIt != map.end(); ++mapIt){ // Iterating the map
            cout << "Name:: " << vecIt->getName() << " Module:: " << mapIt->first << " " << " Mark:: " << mapIt->second << endl;
        }
    }


    // Interactive while loop letting the user to use the first and the second function
    int usrChoice = 0;
    while(usrChoice != 3){

        cout << endl;
        // getting the user input
        cout << "Enter 1 run the first function, Enter 2 to run the second function, Enter 3 to quit --> ";
        cin >> usrChoice;
        cout << endl;

        // break out of the while loop if the choice is 3
        if(usrChoice == 3){
            cout << "Bye" << endl;
            break;
        }

        // if choice is 1 it will take the user input for the mark and call first function
        else if(usrChoice == 1){
            float usrMark;
            cout << "Enter a mark to see the students with maximum value that is higher or equal to that mark " << endl;
            cout << "Enter the mark ---> ";
            cin >> usrMark;
            firstFunction(myClass, usrMark);
        }

        // if the choice is 2 it will take the user input for the module and mark and it will call the second function
        else if(usrChoice == 2){ // If
            string usrModule;
            float usrMark;
            cout << "Enter a module and a mark to see the students with marks lower or equal than this mark in this module " << endl;
            cout << "Enter the module with upper case e.g. CE151 ---> ";
            cin >> usrModule;
            cout << "Enter the mark ---> ";
            cin >> usrMark;
            secondFunction(myClass, usrModule, usrMark);
        }

    }

    return 0;
}

void firstFunction(vector<Student>& myClass, float usrFloat){

    cout << endl;
    cout << "Students who have a maximum mark that is greater than or equal to that mark " << usrFloat << endl;
    vector<Student>::iterator studentIt; // creating a vector iterator
    for(studentIt = myClass.begin(); studentIt != myClass.end(); studentIt++){

        // converting the string to int
        // STOF FUNCTION DOES NOT WORK ON MY COMPILER
        string str = studentIt->maxMark();
        stringstream intValue(str);
        int maxValue = 0;
        intValue >> maxValue;

        if(maxValue >= usrFloat){
            cout << *studentIt << endl;
        }
    }

}

void secondFunction(vector<Student>& myClass, string module, float mark){

    cout << endl;
    cout << "Students with lower and equal than this mark in that module " << endl;
    vector<Student>::iterator studentIt; // creating iterator for the vector
    map<string, float> m;
    for(studentIt = myClass.begin(); studentIt != myClass.end(); studentIt++){
        m = studentIt->getMap(); // getting the map
        if(m[module] != 0 && m[module] <= mark){ // check whether module mark exist and is mark <= than the input
            cout << studentIt->getName() << " " << module << " " << m[module] << endl;
        }
    }
}
