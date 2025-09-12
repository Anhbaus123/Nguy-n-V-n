#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> Appointments;

class Appointment 
{
    private:
    string time;
    string date;
    string reason;
    string status; // scheduled, completed, cancelled
    public:
    Appointment (string t, string d, string rs, string st) 
    {
        time = t;
        date = d;
        reason = rs;
        status = st;
    }

    void setTime (string t) {time = t; }
    string getTime () {return time;}
    void setDate (string d) {date = d;}
    string getDate () {return date;}
    void setReason (string rs) {reason = rs;}
    string getReason () {return reason;}
    void setStatus (string st) {status = st;}
    string getStatus () {return status;}

    void cancelAppointment() {
        status = "Cancelled";
        cout << "Appointment Cancelled" << endl;

    }
    void completeAppointment() {
        status = "Completed";
        cout << "Appointment Completed" << endl;
    
    }
    void rescheduleAppointment(string newDate, string newTime)
    {
        date = newDate;
        time = newTime;
        status = "Rescheduled";
        cout << "Appointment Rescheduled" << endl;
    }
    void displayAppointment()
    {
        cout << "Time: " << time << endl;
        cout << "Date: " << date << endl;
        cout << "Reason: " << reason << endl;
    }
};
class Dotor 
{
    private:
    string nameDoctor;
    string specialization;
    string IDDoctor;
    public:
    Dotor (string n, string s, string id)
    {
        nameDoctor = n;
        specialization = s;
        IDDoctor = id;
    }
    void setNameDoctor(string n) { nameDoctor = n; }
    string getNameDoctor() { return nameDoctor; }
    void setSpecialization(string s) { specialization = s; }
    string getSpecialization() { return specialization; }
    void setIDDoctor(string id) { IDDoctor = id; }
    string getIDDoctor() { return IDDoctor; }
    void checkAppointments()
    {
        for (int i=0; i< Appointments.size(); i++)
        {
            cout << Appointments[i] << endl;
        }
    }
    void updateStatus(Appointment &app, string newStatus)
    {
        app.setStatus(newStatus);
    } 
    void displayInfo()
    {
        cout << "Name: "<< nameDoctor << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "ID: " << IDDoctor << endl;
    }
};

class Patient {
    protected:
    string name;
    int age;
    string ID;
    vector<string> medicalHistory;
    public:
    Patient(string n, int a, string id, vector<string> mh)
    {
        name =n;
        age = a;
        ID = id;
        medicalHistory = mh;
    }
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setAge(int a) { age = a; }
    int getAge() { return age; }
    void setID(string id) { ID = id; }
    string getID() { return ID; }
    void updateMedicalHistory(string update)
    {
        medicalHistory.push_back(update);
    };
    void displayMedicalHistory()
    {
        for (int i=0; i< medicalHistory.size(); i++)
        {
            cout << medicalHistory[i] << endl;
        }
    }
    void scheduleAppointment (string app)
    {
        Appointments.push_back(app);
    }
    void displayAppointments()
    {
        for (int i=0; i< Appointments.size(); i++)
        {
            cout << Appointments[i] << endl;
        }
    }
    virtual void displayInfo()
    {
        cout << "Name: "<< name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << ID << endl; 
    };
};

class ChronicPatient : public Patient {
    private:
    string condition;
    public:
    ChronicPatient(string n, int a, string id, vector<string> mh, string c) : Patient(n, a, id, mh)
    {
        condition = c;
    }
    void setCondition(string c) { condition = c; }
    string getCondition() { return condition; }
    void lastCheckup()
    {
        string date;
        cout << "Enter date of last checkup: "<< endl;
        cin >> date;
        cout << "Last checkup date updated to: " << date << endl; 
    }
    void displayInfo() override
    {
        Patient::displayInfo();
        cout << "Condition: " << condition << endl;
    }

};

class Regular : public Patient 
{
    private:
    string lastVisitDate;
    public:
    Regular(string n, int a, string id, vector<string> mh, string lvd) : Patient(n, a, id, mh)
    {
        lastVisitDate = lvd;
    }
    void setLastVisitDate(string lvd) { lastVisitDate = lvd; }
    string getLastVisitDate() { return lastVisitDate; }
    void scheduleCheckup()
    {
        string date;
        cout << "Enter date for checkup: "<< endl;
        cin >> date;
        lastVisitDate = date;
        cout << "Checkup scheduled for: " << date << endl; 
    }
    void displayInfo() override
    {
        Patient::displayInfo();
        cout << "Last Visit Date: " << lastVisitDate << endl;
    }
};

int main()
{
    vector<string> mh = {"Flu - 2021", "Allergy - 2022"};
    ChronicPatient cp("John Doe", 45, "CP123", mh, "Diabetes");
    cp.displayInfo();
    cp.lastCheckup();
    cp.updateMedicalHistory("Blood Test - 2023");
    cp.displayMedicalHistory();
    cp.scheduleAppointment("Appointment on 2023-10-10 at 10:00 AM");
    cp.displayAppointments();

    Regular rp("Jane Smith", 30, "RP456", mh, "2023-01-15");
    rp.displayInfo();
    rp.scheduleCheckup();
    rp.updateMedicalHistory("Vaccination - 2023");
    rp.displayMedicalHistory();
    rp.scheduleAppointment("Appointment on 2023-11-20 at 2:00 PM");
    rp.displayAppointments();

    Dotor doc("Dr. Alice", "General Practitioner", "D789");
    doc.displayInfo();
    doc.checkAppointments();

    Appointment app("10:00 AM", "2023-10-10", "Routine Checkup", "Scheduled");
    app.displayAppointment();
    app.completeAppointment();
    app.displayAppointment();

    return 0;

};