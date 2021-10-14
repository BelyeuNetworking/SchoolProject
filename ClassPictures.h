//
// Created by Aaron Belyeu on 9/14/2021.
//

#ifndef BELYEUAARONPHASE1_CLASSPICTURES_H
#define BELYEUAARONPHASE1_CLASSPICTURES_H

#include <iostream>

using namespace std;

//template <class P>
class pictures
{
   //name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis
private:
    string name, genre1, genre2, release, metarcritic, synopsis;
    string year, nominations, rating, duration;

public:
    pictures();

    string getName(string n);
    string getGenre1(string g1);
    string getGenre2(string g2);
    string getRelease(string r);
    string getMetacritic(string m);
    string getSynopsis(string s);
    string getYear(string y);
    string getNominations(string n);
    string getRating(string ra);
    string getDurtion(string d);


    template<typename RP>
    bool getReadPictures(string fileName, vector<RP> &rp) const;

    template<typename WP>
    bool getWritePictures(vector<WP> &wp) const;

    template<typename DP>
    void getDisplayPictures( vector<DP> &dp) const;

    template <typename R>
    void getREAD(vector<R> &r);

    template<typename W>
    void getWrite(vector<W> &w);

    template<typename D>
    void getDisplay(vector<D> &d);

};

pictures::pictures() {}

string pictures::getName(string n)
{
    name = n;
    return n;
}

string pictures::getGenre1(string g1)
{
    genre1 = g1;
    return g1;
}

string pictures::getGenre2(string g2)
{
    genre2 = g2;
    return g2;
}

string pictures::getMetacritic(string m)
{
    metarcritic = m;
    return m;
}

string pictures::getRelease(string r)
{
    release = r;
    return r;
}

string pictures::getSynopsis(string s)
{
    synopsis = s;
    return s;
}

string pictures::getYear(string y)
{
    year = y;
    return y;
}

string pictures::getRating(string ra)
{
    rating = ra;
    return ra;
}

string pictures::getDurtion(string d)
{
    duration = d;
    return d;
}

string pictures::getNominations(string n)
{
    nominations = n;
    return n;
}

template <typename RP>
bool pictures::getReadPictures(string fileName, vector<RP> & rp) const
{
    //Open the file
    fstream in(fileName.c_str() );

    //Check the file
    if (fileName != "pictures.csv")
    {
        cout << "You entered the wrong file! \n";
        cout << "Cannot open the File : "<< fileName << endl;
        return false;
    }

    //Read the next line from file untill it reaches the end
    string str;
    while (getline(in, str))
    {
        //Line contains string of lenght > 0 then save it in vector
        if(str.size() > 0)
            rp.push_back(str);

    }
    //close the file
    in.close();
    return true;
}

template <typename WP>
bool pictures::getWritePictures(vector<WP> &wp) const
{
    //Open the file
    ofstream out("pictures.csv", ios::app );

    //Check the file
    if(!out)
    {
        cout << "Cannot open the File : "  << endl;
        return false;
    }

    for (int i = 0; i<wp.size(); ++i)
    {
        out << wp[i] << endl;
    }

    //close the file
    out.close();
    return true;
}

template <typename DP>
void pictures::getDisplayPictures(vector<DP> &dp) const
{
    //Open the file
    ifstream in("pictures.csv");

    string str;
    if(in.is_open())
    {
        while (getline(in, str))
        {
            cout << str << endl;
        }
        //close the file
        in.close();
    } else
        cout << "Could not open file. \n";
}

#endif //BELYEUAARONPHASE1_CLASSPICTURES_H
