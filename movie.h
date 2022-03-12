#include <iostream>
#include <string>

using namespace std; 
class Movie
{
private:
    string title;
    string releaseYear;

public:
    Movie();
    Movie(string, string);

    string getTitle();
    void setTitle(string);
    string getReleaseYear();
    void setReleaseYear(string);
}

Movie::Movie()
{
    title = "";
    releaseYear = "";
}

Movie::Movie(string title_, string releaseYear_)
{
    title = title_;
    releaseYear = releaseYear_;
}

string Movie::getTitle()
{
    return title;
}

string Movie::getReleaseYear()
{
    return releaseYear;
}

void Movie::setTitle(string title_)
{
    title=title_;
}

void Movie::setReleaseYear(string releaseYear_)
{
    releaseYear = releaseYear_;
}