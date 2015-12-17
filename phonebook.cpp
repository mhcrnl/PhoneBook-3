//Sasha Sirovica 912088932
#include "Person.h"
#include <set>
#include <fstream>
#include <sstream>
using namespace std;

int main(int arc, char **argv){
    set<Person> book;
    ifstream file(argv[1]);
    string line, last, first, num;
    while(getline(file, line)){
        istringstream is(line);
        is >> last >> first >> num;
        try{
            book.insert(Person(last, first, num));
        }catch(const invalid_argument &e){
            return 0;
        }
    }
    for(set<Person>::iterator i = book.begin(); i != book.end(); i++){
        cout << *i;
    }
}