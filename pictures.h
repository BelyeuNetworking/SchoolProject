//
// Created by Aaron Belyeu on 11/14/2021.
//

#ifndef INC_3334_PICTURES_H
#define INC_3334_PICTURES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

class pictures
{
    //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
private:
    string name, genre1, genre2, release, metarcritic, synopsis;
    string year, nominations, rating, duration;


public:
    pictures();
    pictures(string Name, string Year, string Nominations, string Rating, string Durtion, string Genre1, string Genre2,
             string Release, string Metacritic, string Synopsis);


    void setName(string n) {this->year=n;}
    void setYear(string y){this->year=y;}
    void setNominations(string n) {this->nominations=n;}
    void setRating(string ra) {this->rating=ra;}
    void setDuration(string d){this->duration=d;}
    void setGenre1(string g1){this->genre1=g1;}
    void setGenre2(string g2){this->genre2=g2;}
    void setRelease(string re){this->release=re;}
    void setMetacritic(string me){this->metarcritic=me;}
    void setSynopsis(string s){this->synopsis=s;}

    string getName(){return this->name;}
    string getYear(){return this->year;}
    string getNominations(){return this->nominations;}
    string getRating(){return this->rating;}
    string getDuration(){return this->duration;}
    string getGenre1(){return this->genre1;}
    string getGenre2(){return this->genre2;}
    string getRelease(){return this->release;}
    string getMetacrticitc(){return this->metarcritic;}
    string getSynopsis(){return this->synopsis;}


};


#endif //INC_3334_PICTURES_H
