#include "Student.h"
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>

Student::Student(const string &name, int regNo)
:Person(name)
{
    this->regNo = regNo;
}

int Student::getRegNo() const{
    return regNo;
}

void Student::addMark(const string& module, float mark){
    pair<string, float> p(module, mark);
    marks[p.first] = p.second;
}

float Student::getMark(const string &module)const{
    map<string, float>::const_iterator pos = marks.find(module);
    if(pos == marks.end()){
        return 0.0;
    }
    else
    {
        return pos->second;
    }
}

string Student::minMark()const{
    if(marks.empty()){
        return "No mark";
    }

    float mark = 100.0;
    map<string, float>::const_iterator it;
    for(it = marks.begin(); it != marks.end(); it++){
        if((it->second)<mark){
            mark = it->second;
        }
    }
    stringstream st;
    st<<mark;
    string str;
    st>>str;
    return str;
}

string Student::maxMark()const{
    if(marks.empty()){
        return "No mark";
    }

    float mark = 0.0;
    map<string, float>::const_iterator it;
    for(it = marks.begin(); it != marks.end(); it++){
        if((it->second)>mark){
            mark = it->second;
        }
    }
    stringstream st;
    st<<mark;
    string str;
    st>>str;
    return str;
}

string Student::avgMark()const{
    float mark = 0.0;
    int countMarks = 0;
    map<string, float>::const_iterator it;
    for(it = marks.begin(); it != marks.end(); it++){
        mark += it->second;
        countMarks++;
    }
    if(countMarks == 0){
        return "No mark";
    }

    float avg = mark/countMarks;
    stringstream st;
    st<<avg;
    string str;
    st>>str;
    return str;
}

map<string,float>& Student::getMap(){
    return this->marks;
}

ostream& operator<<(ostream &str, const Student &s){
    return str << "Name :: " << s.name << " Reg number:: " << s.regNo << " Minimum mark:: " << s.minMark() << " Maximum mark:: " << s.maxMark() << " Average mark:: " << s.avgMark();
}
