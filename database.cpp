//
// Created by Aaron Belyeu on 11/14/2021.
//
#include "database.h"

DataBase::DataBase() {}

void DataBase::showWelcome()
{
    cout << "=========================================================================================";
    cout << "\nWelcome! You can add, save, display and modify your Actor/Actress and Movie files!" << endl;
    system ("pause");
    cout << "=========================================================================================\n";
}

void DataBase::showMenu()
{
    cout << "=========Choose a option=========" << endl
         << "1. Add data to actor/actress: " << endl
         << "2. Add data to pictures:  " << endl
         << "3  Read in to actor/actress:\n"
         << "4. Read int to pictures:\n"
         << "5. Save actor/actress to csv\n"
         << "6. Save pictures to csv\n"
         << "7. Display actor/actress to screen\n"
         << "8. Display pictures to screen\n"
         << "9. Search for actor/actress\n"
         << "10. Modify actor/actress\n"
         << "11. Search pictures by rating\n"
         << "12. Modify pictures\n"
         << "13. Sort data base\n"
         << "14. Quit\n";
    cout << "=========================================================================================\n";
}

void DataBase::readInActor()
{
    //Open the file
    string infile;
    string year, award, winner, name, film;

    cout << "What is the fileName? " << endl;
    cin >> infile;

    ifstream in(infile);

    while (in)
    {
        //Line contains string of lenght > 0 then save it in vector
        getline(in,year, ',');
        getline(in,award,',');
        getline(in,winner,',');
        getline(in,name,',');
        getline(in,film);

        actor_actress temp = actor_actress(year,award,winner,name,film);
        this->actors.push_back(temp);

    }
    //close the file
    in.close();
}

void DataBase::readInPictures()
{
    //Open the file
    string infile;
    string name, genre1, genre2, release, metarcritic, synopsis;
    string year, nominations, rating, duration;

    cout << "What is the fileName? " << endl;
    cin >> infile;

    ifstream in(infile);

    //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
    while (in)
    {
        //Line contains string of lenght > 0 then save it in vector
        getline(in,name, ',');
        getline(in,year,',');
        getline(in,nominations,',');
        getline(in,rating,',');
        getline(in,duration,',');
        getline(in,genre1,',');
        getline(in,genre2,',');
        getline(in,release,',');
        getline(in,metarcritic,',');
        getline(in,synopsis);

        pictures temp = pictures(name,year,nominations,rating,duration,
                                 genre1,genre2,release,metarcritic,synopsis);

        this->picture.push_back(temp);

    }
    //close the file
    in.close();
}

void DataBase::DisplayActor()
{
    cout << "year\taward\t\t\tWinner\tName\t\tFilm\n";

    for (int i = 0; i < actors.size() > 0 ; ++i) {
        //cout << actors[i] << endl;  //ostream operator overload //in actor class
        cout << actors[i].getYear();
        cout <<"\t" << actors[i].getAward();
        cout <<"\t" << actors[i].getWinner();
        cout <<"\t" << actors[i].getName();
        cout <<"\t" << actors[i].getFilm() << endl;

    }
}

void DataBase::DisplayPicture()
{
    //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
    cout <<"name\tyear\tnominations\trating\tduration\tgenre1\tgenre2\trelease\tmetacritic\tsynopsis\n";


    for (int i = 0; i < picture.size() > 0 ; ++i) {
        //cout << actors[i] << endl;  //ostream operator overload //in actor class
        cout << picture[i].getName();
        cout <<"\t" << picture[i].getYear();
        cout <<"\t" << picture[i].getNominations();
        cout <<"\t" << picture[i].getRating();
        cout <<"\t" << picture[i].getDuration();
        cout <<"\t" << picture[i].getGenre1();
        cout <<"\t" << picture[i].getGenre2();
        cout <<"\t" << picture[i].getRelease();
        cout <<"\t" << picture[i].getMetacrticitc();
        cout <<"\t" << picture[i].getSynopsis();
        cout << endl;

    }
}

void DataBase::writeActorFile()
{
    //Open the file
    string outfile;
    ofstream out(outfile);

    cout << "What is the fileName? " << endl;
    cin >> outfile;

    cout << "year\taward\tWinner\tName\tFilm\n";

    for (int i = 0; i < actors.size() > 0 ; ++i) {

        //cout << actors[i] << endl;  //ostream operator overload //in actor class
        out << actors[i].getYear();
        out <<"\t" << actors[i].getAward();
        out <<"\t" << actors[i].getWinner();
        out <<"\t" << actors[i].getName();
        out <<"\t" << actors[i].getFilm() << endl;

    }

    cout << "File was saved!\n";

    //close the file
    out.close();

}

void DataBase::writePictureFile() {
    //Open the file
    string outfile;
    ofstream out(outfile);

    cout << "What is the fileName? " << endl;
    cin >> outfile;

    cout << "name\tyear\tnominations\trating\tduration\tgenre1\tgenre2\trelease\tmetacritic\tsynopsis\n";

    for (int i = 0; i < picture.size() > 0; ++i) {
        //cout << actors[i] << endl;  //ostream operator overload //in actor class
        cout << picture[i].getName();
        cout << "\t" << picture[i].getYear();
        cout << "\t" << picture[i].getNominations();
        cout << "\t" << picture[i].getRating();
        cout << "\t" << picture[i].getDuration();
        cout << "\t" << picture[i].getGenre1();
        cout << "\t" << picture[i].getGenre2();
        cout << "\t" << picture[i].getRelease();
        cout << "\t" << picture[i].getMetacrticitc();
        cout << "\t" << picture[i].getSynopsis();

    }

}

void DataBase::addActor()
{
    string year, award, winner, name, film;

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

    cout << "Note: Hit the space button before entry.\n";
    cout << "What was the film: " << endl;
    cin.ignore();
    getline(cin,film);

    //create a temp actor with par contructor with the user input var
    actor_actress temp = actor_actress(year,award,winner,name,film);
    //puts the information into a vector
    this->actors.push_back(temp);
}

void DataBase::addPictures() {

    //creat strings
    string name, genre1, genre2, release, metarcritic, synopsis;
    string year, nominations, rating, duration;

    cout << "Hit space before entry\n";
    cout << "What is the Name: " << endl;
    cin.ignore();
    getline(cin,  name);

    cout << "What was the year: " << endl;
    cin.ignore();
    getline(cin, year);

    cout << "How many nominations: " << endl;
    cin.ignore();
    getline(cin, nominations);

    cout << "What was the rating: " << endl;
    cin.ignore();
    getline(cin, rating);

    cout << "How long was the film: " << endl;
    cin.ignore();
    getline(cin, duration);

    cout << "Hit space before entry\n";
    cout << "What was genre1: " << endl;
    cin.ignore();
    getline(cin, genre1);

    cout << "Hit space before entry\n";
    cout << "What was genre2: " << endl;
    cin.ignore();
    getline(cin, genre2);

    cout << "Hit space before entry\n";
    cout << "When was the film realased date: " << endl;
    cin.ignore();
    getline(cin, release);

    cout << "Hit space before entry\n";
    cout << "What is the metatric for the film: " << endl;
    cin.ignore();
    getline(cin, metarcritic);

    cout << "Hit space before entry\n";
    cout << "What is the synopsis for the film: " << endl;
    cin.ignore();
    getline(cin, synopsis);

    //creat temp pic with par contrcu this->picture.push_back(temp)
    pictures temp = pictures(name,year,nominations,rating,duration,
                                       genre1,genre2,release,metarcritic,synopsis);
    this->picture.push_back(temp);

}

void DataBase::searchActor()
{
    string year, award, winner, name, film;
    string searchValue;

    cout << "Search for the actor or actress:\n";
    cin.ignore();
    getline(cin,searchValue);

    bool found = false;
    for (int i = 0; i < actors.size(); i++)
        {
            if (actors[i].getName() == searchValue)
             {
                 cout << "Actor/Actress " << searchValue << " found: "
                      << "Movie/Movies: " << actors[i].getFilm() << endl;  //actors[i].setName(newName)
                 found = true;
             }
         }
    if(!found)
    {
        cout << "Actor/Actress " << searchValue << " not found\n";
    }
}

void DataBase::modActor()
{
    string year, award, winner, name, film;
    string searchValue;

    cout << "Who is the actor or actress?\n";
    cin.ignore();
    getline(cin,searchValue);

    bool found = false;
    for (int i = 0; i < actors.size(); i++)
    {
        if (actors[i].getName() == searchValue)
        {
            cout << "Actor/Actress found\n";  //actors[i].setName(newName)
            actors[i].setName(name);
            actors[i].setYear(year);
            actors[i].setFilm(film);
            actors[i].setWinner(winner);
            actors[i].setAward(award);
            found = true;
        }
    }
    if(found)
    {
        cout << "==========================================\n";
        cout << "Modify the line of " << searchValue << endl;

        cout << "What is the new year: " << endl; //what is new year
        cin >> year;

        cout << "What is the new award: " << endl;
        cin.ignore();
        getline(cin,award);

        cout << "Was it a winner: " << endl;
        cin >> winner;

        cout << "Who is the new actor or actress: " << endl;
        cin.ignore();
        getline(cin,name);

        cout << "Note: Hit the space button before entry.\n";
        cout << "What was the new film: " << endl;
        cin.ignore();
        getline(cin,film);

        actor_actress temp = actor_actress(year,award,winner,name,film);
        //puts the information into a vector
        this->actors.push_back(temp);
    }
    if(!found)
    {
        cout << "Actor/Actress not found, need to add a new actor/actress\n";
    }
}

void DataBase::searchPictures()
{
    string name, genre1, genre2, release, metarcritic, synopsis;
    string year, nominations, rating, duration;
    string searchValue;

    cout << "Search film by rating:\n";
    cin.ignore();
    getline(cin,searchValue);

    bool found = false;
    for (int i = 0; i < picture.size(); i++)
    {
        if (picture[i].getRating() == searchValue)
        {
            cout << "Rating " << searchValue << " found: " << "Movie:"
                 << picture[i].getName() << endl;  //actors[i].setName(newName)
            found = true;
        }
    }
    if(!found)
    {
        cout << "Rating " << searchValue << " not found\n";
    }
}

void DataBase::modPictures()
{
    string name, genre1, genre2, release, metarcritic, synopsis;
    string year, nominations, rating, duration;
    string searchValue, searchRating;

    cout << "What is the rating of the film you what to modify?\n";
    cin.ignore();
    getline(cin,searchRating);

    bool found = false;

    for (int i = 0; i < picture.size(); i++)
    {
        if (picture[i].getRating() == searchRating) {
            cout << "Rating " << searchRating << " found: " << "Movie:"
                 << picture[i].getName() << endl;  //actors[i].setName(newName)
            found = true;
        }
    }
    if(!found)
    {
        cout << "Rating " << searchValue << " not found\n";
        //exit(-1);
    }

    cout << "==============================================================\n";
    cout << "If you don't know the rating or its not found you can modify by film name\n";
    cout << "Hit space before entry\n";
    cout << "What is the film you want to modify?\n";
    cin.ignore();
    getline(cin,searchValue);

    for (int i = 0; i < picture.size(); i++)
    {
        if (picture[i].getName() == searchValue)
        {
            picture[i].setYear(year);
            picture[i].setName(name);
            picture[i].setDuration(duration);
            picture[i].setGenre1(genre1);
            picture[i].setGenre2(genre2);
            picture[i].setMetacritic(metarcritic);
            picture[i].setNominations(nominations);
            picture[i].setRating(rating);
            picture[i].setRelease(release);
            picture[i].setSynopsis(synopsis);
            found = true;
        }
    }
    if(found)
    {
        cout << "==========================================\n";
        cout << "Modify the line of the film " << searchValue << endl;
        cout << "==========================================\n";

        cout << "Hit space before entry\n";
        cout << "What is the new film name: " << endl;
        cin.ignore();
        getline(cin,  name);

        cout << "What was the new year: " << endl;
        cin >> year;

        cout << "How many new nominations: " << endl;
        cin >> nominations;

        cout << "What was the new rating: " << endl;
        cin >> rating;

        cout << "How long was the new film: " << endl;
        cin.ignore();
        getline(cin, duration);

        cout << "Hit space before entry\n";
        cout << "What is the new genre1: " << endl;
        cin.ignore();
        getline(cin, genre1);

        cout << "Hit space before entry\n";
        cout << "What is the new genre2: " << endl;
        cin.ignore();
        getline(cin, genre2);

        cout << "Hit space before entry\n";
        cout << "New film release date: " << endl;
        cin.ignore();
        getline(cin, release);

        cout << "Hit space before entry\n";
        cout << "What is the new metatric for the film: " << endl;
        cin.ignore();
        getline(cin, metarcritic);

        cout << "Hit space before entry\n";
        cout << "What is the new synopsis for the film: " << endl;
        cin.ignore();
        getline(cin, synopsis);

        //creat temp pic with par contrcu this->picture.push_back(temp)
        pictures temp = pictures(name,year,nominations,rating,duration,
                                 genre1,genre2,release,metarcritic,synopsis);

        this->picture.push_back(temp);
    }
    if(!found)
    {
        cout << "Film not found, add a new film\n";
    }
}

void DataBase::sortDataBase() {
    string year, award, winner, name, film;
    string searchDatabase;

    string name1, genre1, genre2, release, metarcritic, synopsis;
    string year1, nominations, rating, duration;

    cout << "Actors/Actress data bases sorts by year and pictures data base sorts by rating.\n";
    cout << "Search database. Enter actors or pictures to search their database\n";

    cin.ignore();
    getline(cin, searchDatabase);

    if (searchDatabase == "actors")
    {
        for(int i=0;i<actors.size();i++)
        {
            for(int j= i+1; j<actors.size(); j++)
            {
                if(actors[i].getYear() > actors[j].getYear())
                {
                    actor_actress temp  = actors[i];
                    actors[i] = actors[j];
                    actors[j]=temp;
                }
            }
        }
        for(int i=0; i < actors.size(); i++)
        {
            cout << actors[i].getYear() << "," << actors[i].getAward() << "," << actors[i].getWinner() << "," <<
            actors[i].getAward() << "," << actors[i].getFilm() << endl;
        }
        actor_actress temp = actor_actress(year,award,winner,name,film);
        this->actors.push_back(temp);
    }
    else if (searchDatabase == "pictures")
    {
        for(int i=0;i<picture.size();i++)
        {
            for(int j= i+1; j<picture.size(); j++)
            {
                if(picture[i].getRating() > picture[j].getRating())
                {
                    pictures temp  = picture[i];
                    picture[i] = picture[j];
                    picture[j] = temp;
                }
            }
        }
        //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
        for(int i=0; i < picture.size(); i++)
        {
            cout << picture[i].getRating() << "," << picture[i].getName() << "," << picture[i].getYear() << "," <<
                 picture[i].getNominations() << "," << picture[i].getDuration() << "," << picture[i].getGenre1() <<
                 picture[i].getGenre1() << "," << picture[i].getGenre2() << "," << picture[i].getRelease() << "," <<
                 picture[i].getMetacrticitc() << "," << picture[i].getSynopsis() << endl;
        }
        pictures temp = pictures(name,year,nominations,rating,duration,
                                 genre1,genre2,release,metarcritic,synopsis);
        this->picture.push_back(temp);
    }
}

void DataBase::printMain()
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
            Search_Actors = 9,
            mod_Actor = 10,
            Search_pictures = 11,
            mod_pictures = 12,
            sort_DataBase = 13,
            Quit_Choice = 14;

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
                case Add_to_actor_actress_list:
                {
                    this->addActor();
                }
                    break;

                case Add_to_pictures_list:
                {
                    this->addPictures();
                }
                    break;

                case  Read_actor_actress_data:
                {
                    this->readInActor();
                }
                    break;

                case Read_pictures_data:
                {
                    this->readInPictures();
                }
                    break;

                case Save_actor_actress_csv:
                {
                    this->writeActorFile();
                }
                    break;

                case Save_pictures_csv:
                {
                    this->writePictureFile();
                }
                    break;

                case Display_actor_actress:
                {
                    this->DisplayActor();
                }
                    break;

                case Display_pictures:
                {
                    this->DisplayPicture();
                }
                    break;

                case Search_Actors:
                {
                    this->searchActor();
                }
                    break;
                case mod_Actor:
                {
                    this->modActor();
                }
                    break;

                case Search_pictures:
                {
                    this->searchPictures();
                }
                    break;
                case mod_pictures:
                {
                    this->modPictures();
                }
                    break;
                case sort_DataBase:
                {
                    this->sortDataBase();
                }
                    break;
            }
        }
    } while (choice != Quit_Choice);
    cout << "You have quit! \n";
}


