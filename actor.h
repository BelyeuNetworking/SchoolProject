//
// Created by Aaron Belyeu on 11/14/2021.
//

#ifndef INC_3334_ACTOR_H
#define INC_3334_ACTOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

// Function are to read data and add it to a list
// Function to save data to csv file
// also have to ask user for file input

class actor_actress
{
private:
    //Year,Award,Winner,Name,Film
    string award, name, film, year;
    string winner;

public:
    actor_actress();
    actor_actress(string Year, string Award, string Winner, string Name, string Film);


    void setYear(string y) {this->year=y;}
    void setAward(string a){this->award=a;}
    void setWinner(string w) {this->winner=w;}
    void setName(string n) {this->name=n;}
    void setFilm(string f){this->film=f;}

    string getYear() {return this->year;}
    string getAward() {return this->award;}
    string getWinner(){return this->winner;}
    string getName() {return this->name;}
    string getFilm() {return this->film;}

};


#endif //INC_3334_ACTOR_H
