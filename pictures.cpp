//
// Created by Aaron Belyeu on 11/14/2021.
//

#include "pictures.h"

//do par construct
pictures::pictures() {}

pictures::pictures(string Name, string Year, string Nominations, string Rating, string Durtion, string Genre1,
                   string Genre2, string Release, string Metacritic, string Synopsis) {

    name = Name;
    year = Year;
    nominations = Nominations;
    rating = Rating;
    duration = Durtion;
    genre1 = Genre1;
    genre2 = Genre2;
    release = Release;
    metarcritic = Metacritic;
    synopsis = Synopsis;
}



