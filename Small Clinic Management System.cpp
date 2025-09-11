#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -------------------- CLASS Appointment --------------------
// Quản lý thông tin lịch hẹn giữa bệnh nhân và bác sĩ
class Appointment {
private:
    string date;        // Ngày hẹn
    string time;        // Giờ hẹn
    string doctorName;  // Tên bác sĩ
    string patientName; // Tên bệnh nhân
    string reason;      // Lý do khám
    string status;      // Trạng thái (Scheduled, Completed, Cancelled)

public:
    // Constructor
    Appointment(string d, string t, string dn, string pn, string rs, string st)
    {
        date = d; time = t; doctorName = dn; patientName = pn; reason = rs; status = st;
    }

    // Getter/Setter
    void setDate(string d) { date = d; }
    string getDate() { return date; }
    void setTime(string t) { time = t; }
    string getTime() { return time; }
    void setDoctorName(string dn) { doctorName = dn; }
    string getDoctorName() { return doctorName; }
    void setPatientName(string pn) { patientName = pn; }
    string getPatientName() { return patientName; }
    void setReason(string rs) { reason = rs; }
    void setStatus(string st) { status = st; }
    string getStatus() { return status; }

    // Hiển thị thông tin lịch hẹn
    void displayInfo() {
        cout << "Appointment Date: " << date << endl;
        cout << "Appointment Time: " << time << endl;
        cout << "Doctor Name: " << doctorName << endl;
        cout << "Patient Name: " << patientName << endl;
        cout << "Reason: " << reason << endl;
        cout << "Status: " << status << endl;
    }
};

// -------------------- CLASS Patient --------------------
// Lớp cha quản lý thông tin bệnh nhân
class Patient {
protected:
    string name;                    // Tên bệnh nhân
    string ID;                      // Mã bệnh nhân
    int age;                        // Tuổi
    vector<string> medicalHistory;  // Tiền sử bệnh
    vector<Appointment> appointments; // Danh sách lịch hẹn

public:
    // Constructor có tham số
    Patient(string n, string id, int a, vector<string> mh) {
        name = n; ID = id; age = a; medicalHistory = mh;
    }

    // Constructor mặc định
    Patient() { name = ""; ID = ""; age = 0; }

    // Getter/Setter
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setID(string id) { ID = id; }
    string getID() { return ID; }
    void setAge(int a) { age = a; }
    int getAge() { return age; }

    // Thêm tiền sử bệnh
    void addMedicalHistory(string mh) {
        medicalHistory.push_back(mh);
        cout << "Medical history added." << endl;
    }

    // Hiển thị tiền sử bệnh
    void displayMedicalHistory() {
        cout << "Medical history of " << name << ":" << endl;
        for (int i=0; i<medicalHistory.size(); i++) {
            cout << "- " << medicalHistory[i] << endl;
        }
    }

    // Đặt lịch hẹn mới
    virtual void scheduleAppointment(string date, string time, string doctorName, string reason, string status) {
        Appointment newAppointment(date, time, doctorName, name, reason, status);
        appointments.push_back(newAppointment);
        cout << "Appointment scheduled for " << name << " with Dr. " << doctorName
             << " on " << date << " at " << time << endl;
    }

    // Hiển thị toàn bộ lịch hẹn
    void displayAppointments() {
        cout << "Appointments for " << name << ":" << endl;
        for (int i=0; i<appointments.size(); i++) {
            appointments[i].displayInfo();
            cout << "------------------" << endl;
        }
    }

    // Hiển thị thông tin bệnh nhân
    void displayInfo() {
        cout << "Patient Name: " << name << endl;
        cout << "Patient ID: " << ID << endl;
        cout << "Age: " << age << endl;
        displayMedicalHistory();
        displayAppointments();
    }
};

// -------------------- CLASS Doctor --------------------
// Lớp quản lý thông tin bác sĩ
class Doctor {
private:
    string name;                 // Tên bác sĩ
    string specialty;            // Chuyên khoa
    string ID;                   // Mã bác sĩ
    vector<string> schedule;     // Lịch làm việc

public:
    Doctor(string n, string sp, string id, vector<string> sch) {
        name = n; specialty = sp; ID = id; schedule = sch;
    }

    // Getter/Setter
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setSpecialty(string s) { specialty = s; }
    string getSpecialty() { return specialty; }
    void setID(string id) { ID = id; }
    string getID() { return ID; }

    // Thêm lịch làm việc
    void addSchedule(string sch) {
        schedule.push_back(sch);
        cout << "Schedule added." << endl;
    }

    // Hiển thị lịch làm việc
    void displaySchedule() {
        cout << "Schedule of Dr. " << name << ":" << endl;
        for (int i=0; i<schedule.size(); i++) {
            cout << "- " << schedule[i] << endl;
        }
    }

    // Hủy lịch hẹn
    void cancelAppointment(Appointment &app) { // dùng tham chiếu để thay đổi trạng thái
        app.setStatus("Cancelled");
        cout << "Appointment on " << app.getDate() << " at " << app.getTime()
             << " with Dr. " << name << " has been cancelled." << endl;
    }

    // Hiển thị thông tin bác sĩ
    void displayInfo() {
        cout << "Doctor Name: " << name << endl;
        cout << "Specialty: " << specialty << endl;
        cout << "Doctor ID: " << ID << endl;
        displaySchedule();
    }
};

// -------------------- CLASS chronic (bệnh nhân mãn tính) --------------------
class chronic : public Patient {
private:
    string condition; // Tình trạng bệnh mãn tính
public:
    chronic(string n, string id, int a, vector<string> mh, string c) : Patient(n, id, a, mh) {
        condition = c;
        addMedicalHistory(c);
    }

    void setCondition(string c) { condition = c; }
    string getCondition() { return condition; }

    void addChronicCondition(string c) {
        condition = c;
        cout << "Chronic condition added." << endl;
    }

    void lastCheckupDate(string d) { cout << "Last checkup date: " << d << endl; }

    void displayChronicInfo() {
        displayInfo();
        cout << "Chronic Condition: " << condition << endl;
    }
};

// -------------------- CLASS regular (bệnh nhân khám định kỳ) --------------------
class regular : public Patient {
private:
    string requires; // Nhu cầu khám định kỳ
public:
    regular(string n, string id, int a, vector<string> mh, string r) : Patient(n, id, a, mh) {
        requires = r;
        addMedicalHistory(r);
    }

    void setRequires(string r) { requires = r; }
    string getRequires() { return requires; }

    void periodicCheckupDate(string d) { cout << "Next periodic checkup date: " << d << endl; }

    void displayRegularInfo() {
        displayInfo();
        cout << "Requires: " << requires << endl;
    }
};

// -------------------- MAIN --------------------
int main() {
    // Bệnh nhân mãn tính
    vector<string> mh1 = {"Hypertension"};
    chronic patient1("John Doe", "P001", 45, mh1, "Diabetes");
    patient1.displayChronicInfo();
    patient1.lastCheckupDate("2024-05-01");
    patient1.scheduleAppointment("2024-06-15", "10:00 AM", "Smith", "Routine Checkup", "Scheduled");

    // Bệnh nhân khám định kỳ
    vector<string> mh2 = {"Allergy to Penicillin"};
    regular patient2("Jane Smith", "P002", 30, mh2, "Annual Physical");
    patient2.displayRegularInfo();
    patient2.periodicCheckupDate("2024-12-01");
    patient2.scheduleAppointment("2024-07-20", "02:00 PM", "Brown", "Flu Symptoms", "Scheduled");

    // Bác sĩ 1
    vector<string> sch1 = {"09:00 AM - 12:00 PM", "01:00 PM - 05:00 PM"};
    Doctor doctor1("Dr. Smith", "General Practitioner", "D001", sch1);
    doctor1.displayInfo();

    // Bác sĩ 2
    vector<string> sch2 = {"10:00 AM - 01:00 PM", "02:00 PM - 06:00 PM"};
    Doctor doctor2("Dr. Brown", "Pediatrician", "D002", sch2);
    doctor2.displayInfo();

    // Hiển thị lịch hẹn
    cout << "\n--- Patient Appointments ---" << endl;
    patient1.displayAppointments();
    patient2.displayAppointments();

    return 0;
}
