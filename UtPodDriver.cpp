/* UtPod_driver.cpp
Driver for the UtPod.

Alvaro Erdozain
Laura Martinez
EE 312 03/28/2020

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    int result;

    Song s1("Beatles", "Hey Jude1", 4);
    result = t.addSong(s1);
    cout << "Main: add, expected result = 0, result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "Main: add, expected result = 0, result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "MAin: add, expected result = 0, result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "Main: add, expected result = 0, result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "Main: add, expected result = 0, result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s2);
    cout << "Main: delete, expected result = 0, result = " << result << endl;
    result = t.removeSong(s3);
    cout << "Main: delete, expected result = 0, result = " << result << endl;
    result = t.removeSong(s3);
    cout << "Main: delete, expected result = -2, result = " << result << endl;

    t.showSongList();

    cout << "Main: shuffling 3 times in a row " << endl;
    t.shuffle();
cout << "Primer shuffle hecho" << endl;
    t.showSongList();
    cout << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;

    result = t.removeSong(s1);
    cout << "Main: delete, expected result = 0, result = " << result << endl;
t.showSongList();

    result = t.removeSong(s5);
    cout << "Main: delete, expected result = 0, result = " << result << endl;
t.showSongList();

    result = t.removeSong(s4);
    cout << "Main: delete, expected result = 0, result = " << result << endl;
    t.showSongList();

    Song s6("Pereza", "Lady Madrid", 701);
    result = t.addSong(s6);
    cout << "Main: add, expected result = -1, result = " << result << endl;
    t.showSongList();

    cout << "Main: memory = " << t.getRemainingMemory() << endl;
}
