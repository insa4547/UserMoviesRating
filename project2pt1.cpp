#include <iostream>
#include <string>
#include <fstream>
#include "movie.h"
#include "user.h"

using namespace std;

int readMovies(string fileName, Movie movieArray[], int numMoviesStored, int movieArrSize){
     if (numMoviesStored== movieArrSize){
        return -2;
    }
    ifstream input_file(fileName);
    if(!input_file.is_open()) {
        
        return -1;
    }
    string line;
    string temp="";
    int counter=numMoviesStored;;
    while (getline(input_file, line)){
    Movie tempMovie;
    if (line.size()==0){
        continue;
    }
    for(int i = 0; i < line.size(); i++){
             if(line[i]!= ','){
                 //adds titile or year characters to temp variable
                temp += line[i];


            }if(line[i]== ','){
                    tempMovie.setTitle(temp);
                    temp="";
               
                }
                if (i==line.size()-1 && 0!=line.size()){
                    tempMovie.setReleaseYear(temp);
                    temp="";
                }

    }
    //add the temp movie object to the movies array 
    movieArray[counter]= tempMovie;
    counter++;
    if(counter==movieArrSize){
        return counter;
    }
}

return counter;
}

void printMoviesByYear(Movie movieArray[], int numMoviesStored, string year){




    
    if (numMoviesStored<=0){
        cout<<"No movies are stored"<< endl;
    }
    else{
        
        int check = 0;
        string tempYear = "";
        Movie tempMovie;
        
        for(int i = 0; i < numMoviesStored; i++){
        
            tempMovie = movieArray[i];
            tempYear = tempMovie.getReleaseYear();
            
            if ( tempYear == year){
                
                if (check == 0){
                    cout << "Here is a list of movies released in " << year << endl;
                    check++;
                }
                
                cout << tempMovie.getTitle() << endl;
                
            }
        }
        if(check==0){
            cout<<"There are no stored movies released in "<<year<<endl;
        }
    }
}

int readRatings(string fileName, User users[], int numUsersStored, int usersArrSize,  int maxRatings){
     if (numUsersStored== usersArrSize){
        return -2;
    }
    ifstream input_file(fileName);
    if(!input_file.is_open()) {
        
        return -1;
    }
    
    string line;
    string temp="";
    int counter=numUsersStored;
    while (getline(input_file, line)){
    User tempUser;
    if (line.size()==0){
        continue;
    }
    int checker = 0;
    int movieStored =0;
    for(int i = 0; i < line.size(); i++){
             if(line[i]!= ','){
                 //adds titile or year characters to temp variable
                temp += line[i];


            }if(line[i]== ','){
                if(checker ==0){
                   users[numUsersStored].setUsername(temp);
                   checker++;
                }else{
                    users[numUsersStored].setRatingAt(movieStored,stoi(temp));
                    movieStored++;
                }
                    
                    temp="";
               
                }
                if (i==line.size()-1 && 0!=line.size()){
                    users[numUsersStored].setRatingAt(movieStored,stoi(temp));
                    temp="";
                }

    }
     numUsersStored++;
     if(numUsersStored==usersArrSize){
         return numUsersStored;
     }
   
}

 return(numUsersStored);
}

int split(string str, char separator, string arr[], int size) { 
    
    int length = str.length();

    if(length > 0) {
        int j = 0;
        int substrStart = 0;

        for(int i = 0; i < length; i++) {

            if(str[i] == separator) {
                arr[j] = str.substr(substrStart, (i - substrStart));
                j++;
                substrStart = i + 1;
            }

            if(i == length - 1) {
                arr[j] = str.substr(substrStart, (i + 1 - substrStart));
            }
        }

        int count = j + 1;

        if(count <= size && j > 0) {
            return count;
        } 
        
        else if(j == 0) 
        {
            arr[0] = str;
            return 1;
        } 
        else 
        {
            return -1;
        }

    } 
    else 
    {
        return 0;
    }
}

int getRating(string username, string title, User users[], Movie movie[], int numUsersStored, int numMoviesStored){
    bool foundUser= false;
    bool foundMovie=false;
    int userLocation;
    int movieLocation;
    
    for(int i=0; i<username.size(); i++){
        username[i]=tolower(username[i]);
    }
    int j=0;
    string locatedUser;
    while (j<numUsersStored){
        
        locatedUser=users[j].getUsername();
        for(int i=0; i<locatedUser.size(); i++){
        locatedUser[i]=tolower(locatedUser[i]);
    }
    if(locatedUser==username){
        foundUser=true;
        userLocation=j;
    }
         j++;
    }
    for (int i=0; i<title.size();i++){
        title[i]=tolower(title[i]);
    }
    j=0;
    string locatedTitle;
    while(j<numMoviesStored){
        locatedTitle=movie[j].getTitle();
        for (int i=0;i<locatedTitle.size();i++){
            locatedTitle[i]=tolower(locatedTitle[i]);
        }
        if(locatedTitle==title){
            foundMovie=true;
            movieLocation=j;
        }
        j++;
    }
    if(foundUser && foundMovie){
        return users[userLocation].getRatingAt(movieLocation);
    }
    else{
        return -3;
    }
}

int getCountWatchedMovies(string username, User users[], int numUsersStored, int numMoviesStored){
    bool foundUser=false;
    int userLocation;
    int numRatings=0;
    if (numMoviesStored==0){
    return -3;
    }
    for(int i=0; i<username.size();i++){
        username[i]=tolower(username[i]);
    }
    string tempUser;
    
    
    for(int x=0; x<numUsersStored; x++){
        
        tempUser=users[x].getUsername();
        
        for(int j=0;j<tempUser.size();j++){
            tempUser[j]=tolower(tempUser[j]);
        }
        if (tempUser==username){
            userLocation=x;
            foundUser=true;
        }
        
    }
   
    if (foundUser==false){
    return -3;
    }
    
    for(int i=0;i<numMoviesStored;i++){
        if(users[userLocation].getRatingAt(i)>0){
            numRatings++;
        }
    }
    
    if (foundUser==false){
    return -3;
    }
return numRatings;
}

int main(){
    const int userSize=100;
    const int movieSize=50;
    char title_[50];
    User users[userSize];
    Movie movies[movieSize];
    int numUsersStored=0;
    int numMoviesStored=0;
    string option;

    while(option!="6"){
        cout << "======Main Menu=====" << endl;
        cout << "1. Read movies" << endl;
        cout << "2. Read ratings" << endl;
        cout << "3. Print movies by year" << endl;
        cout << "4. Get rating " << endl;
        cout << "5. Find number of movies user rated" << endl;
        cout << "6. Quit" << endl;
        cin >> option;

        if(option == "1"){
            string file;
            cout<<"Enter a movie file name: "<<endl;
            cin>>file;
            numMoviesStored =readMovies(file,movies,numMoviesStored,movieSize);
            if(numMoviesStored==-1){
                numMoviesStored=0;
                cout<<"No movies saved to the database."<<endl;
            }
            else if(numMoviesStored==-2){
                numMoviesStored=50;
                cout<<"Database is already full. No movies were added."<<endl;
            }
            else if(numMoviesStored==movieSize){
                numMoviesStored=50;
                cout<<"Database is full. Some movies may have not been added."<<endl;
            }
            else if(numMoviesStored>=0&&numMoviesStored<movieSize){
                cout<<"Total movies in the database: "<<numMoviesStored<<endl;
            }
        }
        if (option=="2"){
            string file;
            cout<<"Enter a user file name: "<<endl;
            cin>>file;
            
            int temp1;
            temp1=readRatings(file,users,numUsersStored,userSize,50);
            if(temp1!= -1){
                numUsersStored= temp1;
            }
            if(numUsersStored==userSize){
               
                cout<<"Database is full. Some users may have not been added."<<endl;
            }
            if(numUsersStored==-2){
                numUsersStored=100;
                cout<<"Database is already full. No users were added."<< endl;
            }
            
            else if (temp1 ==-1){
                cout<<"No users saved to the database."<< endl;
            }
            else if(numUsersStored>0&&numUsersStored<userSize){
                cout<<"Total users in the database: "<<numUsersStored<<endl;
            }
            
            
            
        }
        if(option=="3"){
            string year;
            cout<<"Enter release year of movie:"<<endl;
            cin>>year;
            printMoviesByYear(movies,numMoviesStored,year);
        }
        if(option=="4"){
            string userName;
            string title;
            int rating;
            cout<<"Enter a user name: "<<endl;
            cin>>userName;
            cin.ignore();
            cout<<"Enter a movie title: "<<endl;
            getline(cin,title);
            
            rating=getRating(userName,title,users,movies,numUsersStored,numMoviesStored);
            if(rating==0){
                cout<<userName<<" has not rated "<< title<<endl;
            }
            else if(rating==-3){
                cout<<userName<<" or "<<title<<" does not exist."<<endl;
            }
            else{
              cout<<userName<<" rated "<<title<<" with "<<rating<<endl;  
            }

        }
        if(option=="5"){
            string userName;
            int numMoviesRated=0;
            cout<<"Enter a user name: "<< endl;
            cin>>userName;
            numMoviesRated=getCountWatchedMovies(userName,users,numUsersStored,numMoviesStored);
            if(numMoviesRated==0){
               cout<<userName<<" has not rated any movies"<<endl;
            }
            else if(numMoviesRated==-3){
                cout<<userName<<" does not exist."<<endl;
            }
            else{
               cout<<userName<<" rated "<<numMoviesRated<<" movies"<<endl;
            }

        }
        if(option=="6"){
            cout<<"Good bye!"<<endl;
        }
        if(stoi(option)>6 || stoi(option) < 1){
            cout<<"Invalid input."<< endl;
        }
    }
return 0;
}