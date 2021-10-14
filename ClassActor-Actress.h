//
// Created by Aaron Belyeu on 9/9/2021.
//

#ifndef BELYEUAARONPHASE1_CLASSACTOR_ACTRESS_H
#define BELYEUAARONPHASE1_CLASSACTOR_ACTRESS_H
#include <iostream>

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
    string delimeter;
    string filename;
    int linescout;


public:
    actor_actress();
    actor_actress(string fileN, int Year, string Award, int Winner, string Name, string Film)
    {
        filename = fileN;
        year = Year;
        award = Award;
        winner = Winner;
        name = Name;
        film = Film;
        linescout = 0;
    }

    string getyear(string y);
    string getaward(string a);
    string getwinner(string w);
    string getname(string n);
    string getfilm(string f);

    template<typename R>
    bool getReadContent(string fileName, vector<R> &r) const;

    template<typename W>
    bool getWriteContent(vector<W> &w) const;

    template<typename D>
    void getDisplayContent(string fileName, vector<D> & d) const;

    template <typename R>
    void getREAD(vector<R> &v);

    template<typename W>
    void getWrite(vector<W> &w);

    template<typename D>
    void getDisplay(vector<D> & w);

};

actor_actress::actor_actress() {}

string actor_actress::getyear(string y)
{
    year = y;
    return y;
}

string actor_actress::getaward(string a)
{
    award = a;
    return a;
}

string actor_actress::getwinner(string w)
{
    winner = w;
    return w;
}

string actor_actress::getname(string n)
{
    name = n;
    return n;
}

string actor_actress::getfilm(string f)
{
    film = f;
    return f;
}

template <typename R>
bool actor_actress::getReadContent(string fileName, vector<R> &r) const
{
    //Open the file
    ifstream in(fileName);

    //Check the file
    if (fileName != "actor-actress.csv")
    {
        cout << "You entered the wrong file! \n";
        cout << "Cannot open the File : "<< fileName << endl;
        return false;
    }
    string str;
    while (getline(in, str))
    {
        //Line contains string of lenght > 0 then save it in vector
        if(str.size() > 0)
            r.push_back(str);

    }
    //close the file
    in.close();
    return true;
}

template <typename W>
bool actor_actress::getWriteContent(vector<W> &w) const
{
    //Open the file
    ofstream out("actor.actress.csv", ios::app );
    //in.open(ios::app);

    //Check the file
    if(!out)
    {
        cout << "Cannot open the File! "  << endl;
        return false;
    }

    //for(auto it = w.begin(); it != w.end(); ++it)
    //out << *it << endl;

    for(int i = 0; i<w.size(); ++i)
    {
        out<< w[i] << endl;
    }

    //copy(vecOfStrs.begin(), vecOfStrs.end(),
    //ostream_iterator<std::string>(out, "\n"));

    //close the file
    out.close();
    return true;
}

template <typename D>
void actor_actress::getDisplayContent(string fileName, vector<D> & d) const
{
    //Open the file
    ifstream in(fileName);

    string str;
    if(in.is_open())
    {
        while (getline(in, str))
        {
            cout << str << endl;
        }
    } else
    {
        cout << "Could not display file." << endl;
    }

};


#endif //BELYEUAARONPHASE1_CLASSACTOR_ACTRESS_H
