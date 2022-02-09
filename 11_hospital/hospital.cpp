#include <iostream>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

class IDoctor;

class IPatient
{
    public:

    virtual void add_doctor(IDoctor doctor);

    virtual string get_diagnosis();

    virtual string get_id();

    virtual list<IDoctor> get_doctors();

    virtual void remove_doctor(string IdDoctor);

    virtual ~IPatient();

};

class IDoctor
{
    public:

    virtual void add_patient(IPatient patient);

    virtual string get_spec();

    virtual string get_id();

    virtual list<IPatient> get_patients();

    virtual void remove_patient(string IdPatient);

    virtual ~IDoctor();

};

class Patient : public IPatient {

    private:

        string id;

        string diagnosis;

        map<string, IDoctor> doctors;

    public:

        Patient(string id, string diagnosis) : id{id}, diagnosis{diagnosis} {}

        void add_doctor(IDoctor doctor){
            doctors[doctor.get_id()] = doctor;
        }

        string get_diagnosis(){
            return this->diagnosis;
        }

        string get_id(){
            return this->id;
        }

        list<IDoctor> get_doctors(){
            list<IDoctor> doctors;
            for (auto doctor : this->doctors) {
                doctors.push_back(doctor.second);
            }
            return doctors;
        }

        void remove_doctor(string IdDoctor){
            this->doctors.erase(IdDoctor);
        }

        friend ostream& operator<<(ostream& os, const Patient& patient){
            os << "Patient: " << patient.id << " - " << patient.diagnosis << " Medics( ";
            for (auto doctor : patient.doctors) {
                os << doctor.second.get_id() << " ";
            }
            os << " )";
            return os;
        }
};

class Doctor : public IDoctor {
    private:

        string id;

        string spec;

        map<string, IPatient> patients;

    public:

        Doctor(string id, string spec) : id{id}, spec{spec} {}

        void add_patient(IPatient patient){
            patients[patient.get_id()] = patient;
        }

        string get_spec(){
            return this->spec;
        }

        string get_id(){
            return this->id;
        }

        list<IPatient> get_patients(){
            list<IPatient> patients;
            for (auto patient : this->patients) {
                patients.push_back(patient.second);
            }
            return patients;
        }

        void remove_patient(string IdPatient){
            this->patients.erase(IdPatient);
        }

        friend ostream& operator<<(ostream& os, const Doctor& doctor){
            os << "Doctor: " << doctor.id << " - " << doctor.spec << " Patients( ";
            for (auto patient : doctor.patients) {
                os << patient.second.get_id() << " ";
            }
            os << " )";
            return os;
        }
    };
    class Hospital{

    private: 

        map<string, IPatient> patients;
        map<string, IDoctor> doctors;

    public:

        Hospital(){}

        void add_patient(IPatient patient){
            patients[patient.get_id()] = patient;
        }

        void add_doctor(IDoctor doctor){
            doctors[doctor.get_id()] = doctor;
        }

        void remove_patient(string IdPatient){
            this->patients.erase(IdPatient);
        }

        void remove_doctor(string IdDoctor){
            this->doctors.erase(IdDoctor);
        }

        friend ostream& operator<<(ostream& os, const Hospital& hospital){
            os <<"Hospital " << endl ;
            os << "Patients( ";
            for (auto patient : hospital.patients) {
                os << patient.second << " ";
            }
            os << " )" << endl;
            os << "Doctors( ";
            for (auto doctor : hospital.doctors) {
                os << doctor.second << " ";
            }
            os << " )" << endl;
        }

        void vincular(string IdPatient, string IdDoctor){
            if (patients.find(IdPatient) != patients.end() && doctors.find(IdDoctor) != doctors.end()) {
                doctors[IdDoctor].add_patient(patients[IdPatient]);
                patients[IdPatient].add_doctor(doctors[IdDoctor]);
            }
            else(cout << "Não definido" << endl);
        }
    };

