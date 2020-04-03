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

void testCase ( string operation, int expected, int result );

int main(int argc, char *argv[])
{
    UtPod t;
    int result;

    cout << "***** Adding 1 song  *****" << endl;
    Song s1("Beatles", "Yellow submarine", 40);
    result = t.addSong(s1);
    testCase ( "Addition" , 0 , result );
    t.showSongList(); cout << endl;

    cout << "***** Adding 6 songs  *****" << endl;
    Song s2("Beatles", "Eleanor Rigby", 35);
    result = t.addSong(s2);
    testCase ( "Addition" , 0 , result );
    Song s3("Beatles", "Hey Jude", 92);
    result = t.addSong(s3);
    testCase ( "Addition" , 0 , result );
    Song s4("ABBA", "Waterloo", 52);
    result = t.addSong(s4);
    testCase ( "Addition" , 0 , result );
    Song s5("ADC", "Highway to hell", 84);
    result = t.addSong(s5);
    testCase ( "Addition" , 0 , result );
    Song s6("Queen", "Bohemian Rhapsody", 70);
    result = t.addSong(s6);
    testCase ( "Addition" , 0 , result );
    Song s7("Queen", "We will rock you", 41);
    result = t.addSong(s7);
    testCase ( "Addition" , 0 , result );
    Song s8("Elton John", "Sacrifice", 50);
    result = t.addSong(s8);
    testCase ( "Addition" , 0 , result );
    t.showSongList(); cout << endl;
    cout << "Main: Remaining memory = " << t.getRemainingMemory() << endl; cout << endl;

    cout << "***** Adding 1 song bigger than the memory in the UtPod  *****" << endl;
    Song s9("Pereza", "Lady Madrid", 701);
    result = t.addSong(s9);
    testCase ( "No addition" , -1 , result );
    t.showSongList(); cout << endl;

    cout << "***** Shuffling 4 times in a row  *****" << endl;
    t.shuffle();
    t.showSongList();cout << endl;
    t.shuffle();
    t.showSongList();cout << endl;
    t.shuffle();
    t.showSongList();cout << endl;
    t.shuffle();
    t.showSongList();cout << endl;

    cout << "***** Sorting  *****" << endl;
    t.sortSongList();
    t.showSongList();cout << endl;

    cout << "***** Removing 6 songs *****" << endl;
    result = t.removeSong(s1);
    testCase ( "Removal" , 0 , result );
    result = t.removeSong(s2);
    testCase ( "Removal" , 0 , result );
    result = t.removeSong(s3);
    testCase ( "Removal" , 0 , result );
    result = t.removeSong(s3);
    testCase ( "Removal" , -2 , result );
    result = t.removeSong(s4);
    testCase ( "Removal" , 0 , result );
    result = t.removeSong(s5);
    testCase ( "Removal" , 0 , result );
    t.showSongList();cout << endl;

    cout << "Main: Remaining memory = " << t.getRemainingMemory() << endl;
}

void testCase ( string operation, int expected, int result ){
  if ( expected == result ){
    cout << operation << " PASS" << endl;
  }else{
    cout << operation << " FAIL" << endl;
  }
}
