#include <iostream>
#include <vector>
#pragma pack(1)
using namespace std;
class Movie{
    /*Class attributes || member variables*/
private:
    string name{};
    string rating{};
    size_t watched{0};
    /*Class methods || member functions*/
public:
    /*Constructor*/
    Movie(const string name = "", const string rating = "", const size_t watched = 0):name{name}, rating{rating}, watched{watched}{}
    /*Copy constructor with delegating the constructor*/
    Movie(const Movie &source):Movie{source.name, source.rating, source.watched}{}
    ~Movie(){} /*Destructor*/
    /*Basic setters and getters methods*/
    void setName(const string name = ""){this->name = name;} /*const variable is not supported by this pointer*/
    string getName(void)const{return name;}

    void setRating(const string rating = ""){this->rating = rating;}
    string getRating(void)const{return rating;}

    void setWatched(const size_t watched = 0){this->watched = watched;}
    size_t getWatched(void) const {return watched;}
    void incrementWatched(void){++watched;}

    void display(void)const{
        cout<<name<<", "<<rating<<", "<<watched<<endl;  
    }
};

class Movies{
private:
    vector <Movie> moviesList; /*Movie type data-type; pointer vector*/
public:
    Movies(){}/*Constructor*/
    ~Movies(){} /*Destructor*/
    void display(void)const{
        if(moviesList.empty()){
            cout<<"Sory, no movies to display....!\n"<<endl;
            return;
        }
        // cout<<"Movie-Name\tMovie-Rating\tMovieWatchedTimes"<<endl;
        cout<<"\n==========================================================="<<endl;
        for(const auto &movie: moviesList){
            movie.display(); /*This is movie classed member-function*/
        }
        cout<<"==========================================================="<<endl;      
    }

    bool addMovie(const string name = "", const string rating = "", size_t watched = 0){
        /*Efficient way for '&' in for-each loop*/
        for(const auto &movie: moviesList){
            if(movie.getName() == name){
                return false;
            }
        }
        /*Movie class has three attributes*/
        const Movie temp {name, rating, watched}; /*Parameterized loacal 3 variables*/
        moviesList.push_back(temp); /*We can add all attributes at a time by push_back()*/
        return true;
    }
    bool incrementWatched(const string name = ""){
        for(auto &movie : moviesList){ /*Efficient way fo & in for-each loop*/
            if(movie.getName() == name){ /*Just linear search*/
                movie.incrementWatched(); /*This is movie classed member-function*/
                return true;
            }
        }
        return false;
    }
};

void incrementWatched(Movies &moveies, const string name){
    if(moveies.incrementWatched(name)){
        cout<<name<<" watch incremented++."<<endl;
    }else{
        cout<<name<<" not found..!"<<endl;
    }
}

void addMovie(Movies &movies, const string name, const string rating, size_t watched){
    if(movies.addMovie(name, rating, watched)){
        cout<<name<<" is added.->"<<endl;
    }else{
        cout<<name<<" already exist...!<-"<<endl;
    }
}

int main(int argc, char const *argv[]){
    /* code */
    system("cls");
    Movies myMovies;
    myMovies.display(); /*Member function calling*/
    addMovie(myMovies, "Big", "PG-13", 2);/*Regular function*/
    addMovie(myMovies, "Star War", "PG", 5); /*Regular function*/
    addMovie(myMovies, "Cinderella", "PG", 7);

    myMovies.display(); /*Big, Star War, Cinderella*/

    addMovie(myMovies, "Cinderella", "PG", 7); /*Already exists*/
    addMovie(myMovies, "Ice Age", "PG", 12); /*OK*/

    incrementWatched(myMovies, "Big"); /*OK*/
    incrementWatched(myMovies, "Ice Age"); /*OK*/
    myMovies.display(); /*Big and Ice Age watched count increment by 1*/

    incrementWatched(myMovies, "XXX"); /*XXX not found*/
    return 0;
}