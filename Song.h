/* Song.h
Specification of Song class

Alvaro Erdozain
Laura Martinez
EE 312

*/

#pragma once
#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
using namespace std;

//For each song we will store the title (string), artist (string),  and size (int) in MB
//Preconditions: the title and artist cannot be blank
//               the size must be greater than zero
class Song {
    private:
        string title;
        string artist;
        int size;

    public:
        Song();
        Song(string t, string a, int s);
        
        string getTitle() const{
            return title;
        }
        string getArtist() const{
            return artist;
        }
        int getSize() const{
            return size;
        }

        bool operator >(Song const &rhs);
        bool operator ==(Song const &rhs);
        bool operator <(Song const &rhs);



};

#endif //UTPOD_SONG_H
