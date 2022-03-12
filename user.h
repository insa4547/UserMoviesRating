#ifndef USER_H
#define USER_H
#include <string>

using namespace  std;

class User{
    private:
    string username;
    int numRatings;
    static const int size = 50;
    int ratings[size];
    
    
    public:
    User();
    User(string username, int ratings[], int numRatings);
    
    string getUsername();
    void setUsername(string username);
    int getRatingAt(int index);
    bool setRatingAt(int index,int value);
    int getNumRatings();
    void setNumRatings(int numRatings);
    int getSize(); 
};


User::User()
{
    username="";
    numRatings=0;
    for (int i=0;i<size;i++){
        ratings[i]=0;
    }
    
    
}

User::User(string username1, int ratings1[], int numRatings1){
    username=username1;
    numRatings=numRatings1;
    for(int i=0; i<numRatings1;i++){
        ratings[i]=ratings1[i];
    }
    for(int i=numRatings1; i<size; i++){
        ratings[i]=0;
    }

}
void User::setUsername(string username1){
            username = username1;

        }
        bool User::setRatingAt(int index, int value){
            if(index>=0 && index<=49 && value >=0 && value <=5){
                ratings[index] = value;
                return 1;
            }
            else{
                return 0;
            }

        }
        void User::setNumRatings(int numRatings1){
            numRatings = numRatings1;
        }

     
        string User::getUsername(){
            return username;
        }
        int User::getRatingAt(int index){
            if(index<0 || index>=size) {
                return -1;
            }
            else {
                return ratings[index];
            }

        }
        int User::getNumRatings(){
            return numRatings;
        }
        int User::getSize(){
            return size;
        };
#endif
