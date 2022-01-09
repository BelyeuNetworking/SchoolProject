//
// Created by Aaron Belyeu on 11/14/2021.
//

#ifndef INC_3334_DATABASE_H
#define INC_3334_DATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "actor.h"
#include "pictures.h"

using namespace std;

class DataBase
{
private:
    vector<actor_actress> actors;
    vector<pictures> picture;

public:
    DataBase();

    void showWelcome();
    void showMenu();

    void addActor();
    void readInActor();
    void addPictures();
    void readInPictures();

    void writeActorFile();
    void DisplayActor();
    void writePictureFile();
    void DisplayPicture();

    void searchActor();
    void modActor();
    void searchPictures();
    void modPictures();
    void sortDataBase();

    void printMain();
};


#endif //INC_3334_DATABASE_H
