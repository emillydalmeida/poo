#include <list>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

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
            if (id.size()>2 && number.size()==8) {
                return true;
            }
        }

        friend ostream& operator<<(ostream& os, const Fone& fone){
            os << fone.id << " " << fone.number;
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

        Contact(string name = "", string prefix =""):name(name), prefix(prefix){}

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

        list<Fone> get_fones(){
            return fones;
        }

        string get_name(string name){
            return name;
        }

        void set_fones(list<Fone> fones){
            this->fones = fones;
        }

        void set_name(string name){
            this->name = name;
        }
};

class Agenda{
    private:

    map<string, Contact> contacts;
    
    int findPosByName(string name);
    
    public:

    Agenda (){}

     friend ostream& operator<<(ostream& os, const Agenda& agenda) {

        for (auto it = agenda.contacts.begin(); it != agenda.contacts.end(); it++) {
            os << it->first << " - " << it->second << endl;
        }
        return os;
    }  

    void merge_contact(Contact contact, string name){
            
            if (contacts.find(name) == contacts.end()) {
                contacts[name] = contact;
            } else {
                contacts[name].set_fones(contact.get_fones());
            }
    } 

    void add_contact(Contact contact, string name) {
            
        auto it = contacts.find(name);
        if (it == contacts.end()) {
            contacts.insert(pair<string, Contact>(name, contact));
        } else {
            contacts[name] = contact;
        }

    }

    list<Contact> search;
    
    list <Contact> get_contacts()
    {
        return search;
    }

};

int main (){
    
    return 0;
}