#include <list>
#include <iostream>
#include <string>

using namespace std;

class Fone{

    private:

        string id;

        string number;

    public:

        Fone(string id, string number){
            this->id = id;
            this->number = number;
        }

        bool validate(string number){
            if (id.size()==2 && number.size()==8) {
                return true;
            }
        }

        void is_valid(){
            if (validate(number)==true) {
                cout << "Fone valido" << endl;
            } else {
                cout << "Fone invalido" << endl;
            }
        }

        friend ostream& operator<<(ostream& os, const Fone& f){
            os << "(" << f.id << ")" << " - " << f.number;
            return os;
        }

        void get_id(string id){
            id = this->id;
        }

        void get_number(string number){
            number = this->number;
        }

        void set_id(string id){
            this->id = id;
        }

        void set_number(string number){
            this->number = number;
        }
};

class Contact{

    private:

        string prefix;

        list <Fone> fones;

        string name;


    public:

        Contact(string name, list<Fone> fones){

            this->name = name;
            this->fones = fones;

        }

       void add_fone(Fone fone){

            fones.push_back(fone);

        }

        friend ostream& operator<<(ostream& os, const Contact& contact){

            os << contact.name << endl;

            for (Fone fone : contact.fones) {
                os << fone << endl;
            }

            return os;
        }

        void get_fones(list<Fone> fones){
            fones = this->fones;
        }

        void get_name(string name){
            name = this->name;
        }

        void set_fones(list<Fone> fones){
            this->fones = fones;
        }

        void set_name(string name){
            this->name = name;
        }
};

int main(){
    Contact c1("Victor", list<Fone>());
    Contact c2("Emilly", list<Fone>());
    Fone f1("31", "93526547");
    Fone f2("31", "23453784");
    Fone f3("85", "99105640");
    c1.add_fone(f1);
    c2.add_fone(f2);
    c2.add_fone(f3);
    cout << c1 << endl;
    cout << c2 << endl;
    cout << f1 << " "; f1.is_valid();
    cout << f2 << " "; f2.is_valid();
    cout << f3 << " "; f3.is_valid();
}