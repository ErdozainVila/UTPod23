/* Song.cpp
Driver for the UtPod.

Alvaro Erdozain
Laura Martinez
EE 312 03/28/2020

*/

#include "Song.h"

Song::Song(string _title, string _artist, int _size){
    if(_title != "")
        title = _title;
    else{
        cout<<"NO TITLE"<<endl;
        return;
    }
    if(_artist != "")
        artist = _artist;
    else{
        cout<<"NO ARTIST NAME"<<endl;
        return;
    }
    if(_size > 0)
        size = _size;
    else{
        cout<<"SIZE MUST BE GREATER THAN 0"<<endl;
        return;
    }
}

Song::Song(){
    title = "";
    artist = "";
    size = 0;
}

bool Song::operator ==(Song const &rhs){
    if(artist == rhs.artist && title == rhs.title && size == rhs.size)
        return true;
    return false;
}

bool Song::operator <(Song const &rhs){
    if( artist < rhs.artist )
        return true;
    else if( title < rhs.title)
        return true;
    else if( size < rhs.size )
        return true;

    return false;
}

bool Song::operator >(Song const &rhs){
    if( artist > rhs.artist )
        return true;
    else if( title > rhs.title )
        return true;
    else if( size > rhs.size )
        return true;

    return false;
}
