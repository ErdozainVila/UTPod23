//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"
#include <ctime> //Time to random seed
#include <cstdlib> //Import random function

//UtPod class declaration
class UtPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;

      struct SongNode{
         Song s;
         SongNode *next;
      };

      SongNode *songs;  //the head pointer

      int memSize;

      int getNumSongs() const;
      void swap(SongNode *s1, SongNode *s2);

      SongNode* getSongNodeAtIndex (int _index) const{
          SongNode* rVal = songs;
          int index = 0;

          while(index !=_index && rVal != NULL){
              index++;
              rVal = rVal->next;
          }
          return rVal;  //NULL or pointer to index
      }

      /* FUNCTION - void smallerSongList
       *  search for the smaller node in a lists

         input parms - node address to start search
         output parms -
      */
      SongNode* smallerSongList(SongNode *sn){
        SongNode *smaller = sn;
//cout << "temp->next->s.getTitle() " << sn->s.getTitle() << endl;
        if (sn->next == NULL){
          cout << "sn->next problem" << endl;
          return smaller;
        }
        SongNode *temp = sn->next;

//cout << "Dentro del smallersonglist antes del while" << endl;
        while (temp != NULL){
          if ( smaller->s > temp->s )
            smaller = temp;
          temp = temp->next;
        }
//cout << "Dentro del smallersonglist despues del while" << endl;
        return smaller;
      }

   public:
      //Default constructor
      //set the memory size to MAX_MEMORY
      UtPod();

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod(int size);

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song
       input parms -
       output parms -
      */
      int addSong(Song &s);

      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -1 if nothing is removed

         input parms -
         output parms -
      */
      int removeSong(Song &s);

      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -
         output parms -
      */
      void shuffle();

      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -
         output parms -
      */
      void showSongList();

      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms -
         output parms -
      */
      void sortSongList();

      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms -
         output parms -
      */
      void clearMemory();

      /* FUNCTION - int getTotalMemory
       *  returns the total amount of memory in the UtPod
          o will do nothing if there are less than two songs in the current list

         input parms -
         output parms -
      */
      int getTotalMemory() {
         return memSize;
      }

      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -

         output parms -
      */
      int getRemainingMemory();


      ~UtPod();

};



#endif
