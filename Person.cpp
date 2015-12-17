//Sasha Sirovica 912088932
#include <stdexcept>
#include "Person.h"
using namespace std;

Person::Person(string last, string first, string num) {
    for (string::iterator i = last.begin(); i != last.end(); i++) {
        if (!isalpha(*i)) {
            cout << "invalid characters in last name\n";
            throw invalid_argument("");
        }
    }
    for (string::iterator i = first.begin(); i != first.end(); i++) {
        if (!isalpha(*i)) {
            cout << "invalid characters in first name\n";
            throw invalid_argument("");
        }
    }
    if (num.length() == 12) {
        string::iterator s;
        for (s = num.begin(); s != num.end(); s++) {
            if (s == num.begin() + 3 || s == num.begin() + 7) {
                if (*s != '-') {
                    cout << "invalid number format\n";
                    throw invalid_argument("");

                }
            } else if (!isdigit(*s)) {
                cout << "invalid number format\n";
                throw invalid_argument("");

            }
        }
    } else {
        cout << "invalid number format\n";
        throw invalid_argument("");
    }
    lastname_ = last;
    firstname_ = first;
    number_ = num;
}

string Person::lastname(void) const{
    return lastname_;
}
string Person::firstname(void) const{
    return firstname_;
}
string Person::number(void) const{
    return number_;
}

bool Person::operator<(const Person& p) const{
    if(lastname_.compare(p.lastname()) < 0)
        return true;
    else if(lastname_.compare(p.lastname()) > 0)
        return false;
    else{
        if(firstname_.compare(p.firstname()) < 0)
            return true;
        else if(firstname_.compare(p.firstname()) > 0)
            return false;
        else
            return false;
    }
}

ostream& operator<<(std::ostream& os, const Person& p){
    os.setf(ios_base::left, ios_base::adjustfield);
    os.width(15);
    os << p.lastname();
    os.setf(ios_base::left, ios_base::adjustfield);
    os.width(15);
    os << p.firstname();
    os << p.number() << endl;
    return os;
}
