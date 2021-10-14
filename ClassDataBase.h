//
// Created by Aaron Belyeu on 9/10/2021.
//

#ifndef BELYEUAARONPHASE1_CLASSDATABASE_H
#define BELYEUAARONPHASE1_CLASSDATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include "ClassActor-Actress.h"
#include "ClassPictures.h"

using namespace std;

class DataBase : public actor_actress, pictures
{
private:
    string fileName;
    string delimeter;
    int linesCount;

public:
    DataBase();
    DataBase(string filename, string delm= ",") : fileName(filename), delimeter(delm), linesCount(0)
    {}
    void showWelcome();
    void showMenu();
    template<typename F>
    void addData(F first, F last);
    template<typename A>
    void askUserInfo(string year, string award, string winner, string name,
                     string film, vector<A> &com);
    template<typename P>
    void askUserInforPictures(string name, string year, string nominations, string ratting, string duration,
                              string genre1, string genre2, string release,
                              string metacritic, string synopsis, vector<P> &add);
    void combine();
    void combinePic();
};
DataBase::DataBase() {}

void DataBase::showWelcome()
{
    cout << "=========================================================================================";
    cout << "\nWelcome to game!" << endl;
    system ("pause");
    cout << "=========================================================================================";
}

void DataBase::showMenu()
{
    cout << "\nPlease choose a option" << endl
         << "1. Add data to actor actress list: " << endl
         << "2. Add data to picture list:  " << endl
         << "3  Read and add to actor actress list: \n"
         << "4. Read and add pictures data to list\n"
         << "5. Save actor-actress to csv\n"
         << "6. Save pictures to csv\n"
         << "7. Display actor-actress to screen\n"
         << "8. Display picture to screen\n"
         << "9. Quit\n";
}

template<typename F>
void DataBase::addData(F first, F last)
{
    fstream file;
    file.open(fileName, ios::out | (ios::app));

    //interates over the range and adds it to the file seperated by the delimeter
   for(; first != last;)
    {
        file << *first;
        if(++first != last)
            file << delimeter;
    }
    file << "\n";
    linesCount ++;
    file.close();
}

template<typename A>
void DataBase::askUserInfo(string year, string award, string winner, string name, string film, vector<A> &add)
{
    DataBase one;

    cout << "What is the year: " << endl;
    cin >> year;

    cout << "What is the award: " << endl;
    cin.ignore();
    getline(cin,award);

    cout << "Was it a winner: " << endl;
    cin >> winner;

    cout << "Who was the actor or actress: " << endl;
    cin.ignore();
    getline(cin,name);

    cout << "What was the film: " << endl;
    cin.ignore();
    getline(cin,film);

    //puts the information into a vector
    add.push_back(one.getyear(year));
    add.push_back(one.getaward(award));
    add.push_back(one.getwinner(winner));
    add.push_back(one.getname(name));
    add.push_back(one.getfilm(film));
}

void DataBase::combine()
{
    DataBase one("actor-actress.csv");
    vector<string> com;
    string year, winner, award, name, film;

    //calling the user input
    askUserInfo(one.getyear(year), (one.getaward(award)), one.getwinner(winner),
                one.getname(name),one.getfilm(film), com);

    //This takes the user info and add it to the end of the vector (actor-actress list)
    one.addData(com.begin(),com.end());
}

void PrintVectactor_actress()
{
    DataBase one;
    one.combine();
}

template<typename P>
void DataBase::askUserInforPictures(string name, string year, string nominations, string ratting, string duration,
                          string genre1, string genre2, string release,
                          string metacritic, string synopsis, vector<P> &add) {
    DataBase one;

    cout << "What is the Name: " << endl;
    cin.ignore();
    getline(cin,  name);

    cout << "What was the year: " << endl;
    cin >> year;

    cout << "How many nominations: " << endl;
    cin >> nominations;

    cout << "What was the rating: " << endl;
    cin >> ratting;

    cout << "How long was the film: " << endl;
    cin.ignore();
    getline(cin, duration);

    cout << "What was genre1: " << endl;
    cin.ignore();
    getline(cin, genre1);

    cout << "What was genre2: " << endl;
    cin.ignore();
    getline(cin, genre2);

    cout << "When was the film realased date: " << endl;
    cin.ignore();
    getline(cin, release);

    cout << "What is the metatric for the film: " << endl;
    cin.ignore();
    getline(cin, metacritic);

    cout << "What is the synopsis for the film: " << endl;
    cin.ignore();
    getline(cin, synopsis);

    //puts the information into a vector
    add.push_back(one.getName(name));
    add.push_back(one.getYear(year));
    add.push_back(one.getNominations(nominations));
    add.push_back(one.getRating(ratting));
    add.push_back(one.getDurtion(duration));
    add.push_back(one.getGenre1(genre1));
    add.push_back(one.getGenre2(genre2));
    add.push_back(one.getRelease(release));
    add.push_back(one.getMetacritic(metacritic));
    add.push_back(one.getSynopsis(synopsis));

}

void DataBase::combinePic()
{
    DataBase one("pictures.csv");
    vector<string> com;
    string name, year, nomination, rating, duration, genre1, genre2, release, metacritic, synopsis;

    //calling the user input from function
    askUserInforPictures(one.getName(name), one.getYear(year), one.getNominations(nomination),
                         one.getRating(rating), one.getDurtion(duration), one.getGenre1(genre1),
                         one.getGenre2(genre2), one.getRelease(release), one.getMetacritic(metacritic),
                         one.getSynopsis(synopsis), com);

    //using the addData fucntion put the user info to the back of the pictures list
    one.addData(com.begin(),com.end());
}

void PrintVecPic()
{
    DataBase one;
    one.combinePic();
}

template <typename R>
void actor_actress::getREAD(vector<R> &r)
{
    actor_actress one;

    string myfile;

    cout << "what is file: \n";
    cin >> myfile;

    bool result = one.getReadContent(myfile, r);

    if (result) {

        cout << "Your file was added: \n";
    }
}

template<typename W>
void actor_actress::getWrite(vector<W> &w)
{
    actor_actress one;
    //vector<string> vevOfStr;

    bool result = one.template getWriteContent(w);

    if (result)
    {
        cout << "File was saved! \n";
    }

}

template<typename D>
void actor_actress::getDisplay(vector<D> &d)
{
    actor_actress one;

    string userFile;
    cout << "What is the file name? " << endl;
    cin >> userFile;
    if (userFile == "actor-actress.csv")
    {
        one.getDisplayContent(userFile, d);

    } else
    {
        cout << "You entered the wrong file! \n";
        cout << "Cannot open the File : "<< userFile << endl;
    }
}

template <typename R>
void pictures::getREAD(vector<R> &r)
{
    pictures one;

    string myfile;

    cout << "what is file: \n";
    cin >> myfile;

    bool result = one.getReadPictures(myfile, r);

    if (result) {

        cout << "Your file was added: \n";
    }
}

template <typename W>
void pictures::getWrite(vector<W> &w)
{
    pictures one;

    bool result = one.getWritePictures(w);

    if (result)
    {
        cout << "File was saved! \n";
    }

}

template <typename D>
void pictures::getDisplay(vector<D> &d)
{
    pictures one;
    cout << "===============================Here are the contents of the Picture file=============================== \n";

    one.getDisplayPictures(d);
}

void printMain()
{
    int choice;

    const int Add_to_actor_actress_list = 1,
            Add_to_pictures_list = 2,
            Read_actor_actress_data = 3,
            Read_pictures_data = 4,
            Save_actor_actress_csv = 5,
            Save_pictures_csv = 6,
            Display_actor_actress = 7,
            Display_pictures = 8,
            Quit_Choice = 9;

    do
    {
        DataBase show;
        show.showWelcome();
        show.showMenu();

        cin >> choice;

        while (choice < Add_to_actor_actress_list || choice > Quit_Choice)
        {
            cout << "Please enter a valid menu choice: ";
            cin >> choice;
        }

        if (choice != Quit_Choice)
        {
            switch (choice)
            {
                case Add_to_actor_actress_list:{
                    PrintVectactor_actress();
                }
                    break;
                case Add_to_pictures_list:{
                    PrintVecPic();
                }
                    break;
                case  Read_actor_actress_data:{
                    actor_actress one;
                    vector<string> v;
                    one.getREAD(v);
                }
                    break;

                case Read_pictures_data:
                {
                    pictures one;
                    vector<string> v;
                    one.getREAD(v);
                }
                    break;

                case Save_actor_actress_csv:
                {
                    actor_actress one;
                    vector<string> v;
                    one.getWrite(v);
                }
                    break;

                case Save_pictures_csv:
                {
                    pictures one;
                    vector<string> v;
                    one.getWrite(v);
                }
                    break;

                case Display_actor_actress:
                {
                    actor_actress one;
                    vector<string> v;
                    one.getDisplay(v);
                }
                    break;

                case Display_pictures:
                {
                    pictures one;
                    vector<string> v;
                    one.getDisplay(v);
                }
                    break;
            }
        }
    } while (choice != Quit_Choice);
        cout << "You have quit the game! \n";
}

#endif //BELYEUAARONPHASE1_CLASSDATABASE_H
