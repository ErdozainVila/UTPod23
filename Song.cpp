//Song.cpp

#include "Song.h"

Song::Song(string t, string a, int s){
    if(t != "")
        title = t;
    else{
        cout<<"NO TITLE"<<endl;
        return;
    }
    if(a != "")
        artist = a;
    else{
        cout<<"NO ARTIST NAME"<<endl;
        return;
    }
    if(s > 0)
        size = s;
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
    if(size == rhs.size && title == rhs.title && artist == rhs.artist)
        return true;
    return false;
}
bool Song::operator <(Song const &rhs){
    if(artist<rhs.artist)
        return true;
    else if(title<rhs.title)
        return true;
    else if(size<rhs.size)
        return true;

    return false;
}
bool Song::operator >(Song const &rhs){
    if(artist>rhs.artist)
        return true;
    else if(title>rhs.title)
        return true;
    else if(size>rhs.size)
        return true;

    return false;
}