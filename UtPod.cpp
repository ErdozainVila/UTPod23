/* UtPod.cpp
Driver for the UtPod.

Alvaro Erdozain
Laura Martinez
EE 312 03/28/2020

*/

#include "UtPod.h"
#include "Song.h"

UtPod::UtPod(){
  memSize = MAX_MEMORY;
  songs = NULL;
}

UtPod::UtPod(int size){
  if(size>512 || size<=0)
    memSize = MAX_MEMORY;
  else
    memSize = size;
  songs = NULL;
}

int UtPod::addSong(Song &s){

  if(s.getSize() > getRemainingMemory() ){
    cout << "Impossible to add song, no enough memory" << endl;
    return NO_MEMORY;
  }

  SongNode *temp = new SongNode;
  temp->s = s;

  // Is it the first song¿?
  if(songs == NULL){
    songs = temp;
    temp->next = NULL;
  }else{
    temp->next = songs;
    songs = temp;
  }

  return SUCCESS;
}


int UtPod::removeSong(Song &s){
  if (songs->s.getTitle() == s.getTitle() &&
      songs->s.getArtist() == s.getArtist() &&
      songs->s.getSize() == s.getSize() ){
    //Founded
    SongNode *temp = songs;
    songs = songs->next;
    delete(temp);

    return SUCCESS;
  }

  SongNode *temp = songs->next;
  SongNode *previous = songs;

  while (temp != NULL){

    if (temp->s.getTitle() == s.getTitle() &&
        temp->s.getArtist() == s.getArtist() &&
        temp->s.getSize() == s.getSize() ){
      //Founded
      previous->next = temp->next;
      delete(temp);

      return SUCCESS;
    }else{
      previous = temp;
      temp = temp->next;
      continue;
    }

  }

  return NOT_FOUND;
}

void UtPod::swap(SongNode *s1, SongNode *s2){
//cout<< "s1 -> "  << s1 << endl;
//cout<< "s2 -> " << s2 << endl;
    Song temp = s1->s;
    s1->s = s2->s;
    s2->s =temp;
}

void UtPod::shuffle(){
  // initialize random seed:
  unsigned int currentTime = (unsigned)time(0);
  srand (currentTime);

  SongNode *curNode = songs;
  int numSongs = getNumSongs();

  //cout<<rand()<<endl; //testing random numbers
  while( curNode != NULL ){ //curNode != NULL
    int randIndex = (rand()%numSongs);
    SongNode *temp = getSongNodeAtIndex(randIndex);
    swap(curNode, temp);
    // cout<< curNode << endl;
    curNode = curNode->next;
    cout<< "curNode " << curNode << endl;
  }
  // cout<< "Llego aqui 3" << endl;
}

int UtPod::getNumSongs() const{
    int numSongs = 0;
    SongNode* head = songs;
    while(head !=NULL){
        numSongs++;
        head = head->next;
    }

    return numSongs;
}


void UtPod::showSongList(){
  SongNode *head = songs;

  while (head != NULL){
    cout << head->s.getTitle() << " by "
        << head->s.getArtist() << " size of "
        << head->s.getSize() << endl;
    head = head->next;
  }

}

void UtPod::sortSongList(){

}

void UtPod::clearMemory(){
  SongNode *temp = songs;

  while(temp != NULL){
    songs = songs->next;
    delete(temp);
    temp = songs;
  }
  songs = NULL;

}

int UtPod::getRemainingMemory(){
  SongNode *temp = songs;
  int sum = 0;

  while (temp != NULL){
    //sum += temp->s.size //Invalid, private variable
    sum += temp->s.getSize();
    temp = temp->next;
  }

  return (memSize - sum);
}

UtPod::~UtPod(){
  clearMemory();
}
