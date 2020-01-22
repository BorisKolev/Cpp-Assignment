#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
    public:
       Person(const string &name);
	   string getName() const;
	   void changeName(const string &newName);

    protected:
	   string name;
};

#endif // PERSON_H
