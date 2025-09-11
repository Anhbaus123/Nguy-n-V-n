#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

class Appointment
{
    private:
    string date;
    string time;
    string doctorName;
    string patientName;
    string reason;
    string status; // Scheduled, Completed, Cancelled
    public:
    Appointment(string d, string t, string dn, string pn, string rs, string st) {date=d; time=t; doctorName=dn; patientName=pn; reason=rs; status=st;}
    void setDate(string d) {date=d;}
    string getDate() {return date;}
    void setTime(string t) {time=t;}
    string getTime() {return time;}
    void setDoctorName(string dn) {doctorName=dn;}
    string getDoctorName() {return doctorName;}
    void setPatientName(string pn) {patientName=pn;}
    string getPatientName() {return patientName;}
    void setReason(string rs) {reason=rs;}
    void setStatus(string st) {status=st;}
    string getStatus() {return status;}
    void displayInfo() {
        cout << "Appointment Date: " << date << endl;
        cout << "Appointment Time: " << time << endl;
        cout << "Doctor Name: " << doctorName << endl;
        cout << "Patient Name: " << patientName << endl;
        cout << "Reason: " << reason << endl;
        cout << "Status: " << status << endl;
    }

};

class Patient
{
    private:
    string name;
    string ID;
    int age;
    vector<string> medicalHistory;
    public:
    Patient(string n, string id, int a, vector <string> mh) {name=n; ID=id; age=a; medicalHistory=mh;}

    void setName(string n) {name=n;}
    string getName() {return name;}
    void setID(string id) {ID=id;}
    string getID() {return ID;}
    void setAge(int a) {age=a;}
    int getAge() {return age;} 
    void addMedicalHistory(string mh) {
        medicalHistory.push_back(mh);
        cout <<" Medical history added." << endl;
    }
    void displayMedicalHistory()
    {
        cout << "Medical history of " << name << endl;
        for (int i=0; i<medicalHistory.size();i++)
        {
            cout <<medicalHistory[i]<<endl;
        }
    }

    void scheduleAppointment(string date, string time, string doctorName, string reason, string status) {
        Appointment newAppointment(date, time, doctorName, name, reason, "Scheduled");
        cout << "Appointment scheduled for " << name << " with Dr. " << doctorName << " on " << date << " at " << time << endl;
    }
    Patient(){// default constructor
        name = "";
        ID = "";
        age = 0;
        medicalHistory = {};
    }


    void displayInfo() {
        cout << "Patient Name: " << name << endl;
        cout << "Patient ID: " << ID << endl;
        cout << "Age: " << age << endl;
        displayMedicalHistory();
    }

};

class Doctor
{
    private:
    string name;
    string specialty;
    string ID;
    vector<string> schedule; // Available time slotse
    public:
    Doctor (string n, string specialty, string id, vector<string> sch) {name=n; specialty=specialty; ID=id; schedule=sch;}
    void setName(string n) {name=n;}
    string getName() {return name;}
    void setSpecialty(string s) {specialty=s;}
    string getSpecialty() {return specialty;}
    void setID(string id) {ID=id;}
    string getID() {return ID;}
    void addSchedule(string sch) {
        schedule.push_back(sch);
        cout <<" Schedule added." << endl;
    }
    void displaySchedule() // Displays the doctor's schedule
    {
        cout << "Schedule of Dr. " << name << endl;
        for (int i=0; i<schedule.size();i++)
        {
            cout <<schedule[i]<<endl;
        }
    }
    void cancelAppointment(Appointment app) // Cancels an appointment
    {
        app.setStatus("Cancelled");
        cout << "Appointment on " << app.getDate() << " at " << app.getTime() << " with Dr. " << name << " has been cancelled." << endl;
    }
    void displayInfo() {
        cout << "Doctor Name: " << name << endl;
        cout << "Specialty: " << specialty << endl;
        cout << "Doctor ID: " << ID << endl;
        displaySchedule();
    }


};

class chronic : public Patient
{
    private :
    string condition;
    public :
    chronic (string n, string id, string a, vector <string> mh, string c)
    {
        setName(n);
        setID(id);
        setAge(stoi(a));
        addMedicalHistory(c);
        condition = c;
    }
    void setCondition(string c) {condition=c;}
    string getCondition() {return condition;}
    void addChronicCondition(string c)
    {
        condition = c;
        cout <<" Chronic condition added." << endl;
    }
    void lastCheckupDate(string d)
    {
        cout << "Last checkup date: " << d << endl;
    }
    



    void displayChronicInfo()
    {
        displayInfo();
        cout << "Chronic Condition: " << condition << endl;
    }
};
int main()
{
    vector<string> mh = {"Diabetes", "Hypertension"};
    chronic patient1("John Doe", "P001", "45", mh, "Diabetes");
    patient1.displayChronicInfo();
    patient1.lastCheckupDate("2024-06-15");

    vector<string> sch = {"09:00 AM - 10:00 AM", "10:00 AM - 11:00 AM"};
    Doctor doctor1("Dr. Smith", "Cardiology", "D001", sch);
    doctor1.displayInfo();

    patient1.scheduleAppointment("2024-07-01", "09:00 AM", doctor1.getName(), "Regular Checkup", "Scheduled");

    return 0;

}
