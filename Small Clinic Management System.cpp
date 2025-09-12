#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> Appointments; // Lịch hẹn chung (dùng cho bác sĩ)
// =============================
// Lớp Appointment (lịch hẹn)
// =============================
class Appointment
{
private:
    string time;     // Thời gian của lịch hẹn
    string date;     // Ngày của lịch hẹn
    string reason;   // Lý do hẹn khám
    string status;   // Trạng thái (Scheduled / Completed / Cancelled)
public:
    // Constructor: khởi tạo lịch hẹn
    Appointment(string t, string d, string r, string s)
    {
        time = t;
        date = d;
        reason = r;
        status = s;
    }

    // Các phương thức getter
    string getTime() { return time; }
    string getDate() { return date; }
    string getReason() { return reason; }
    string getStatus() { return status; }

    // Các phương thức setter
    void setTime(string t) { time = t; }
    void setDate(string d) { date = d; }
    void setReason(string r) { reason = r; }
    void setStatus(string s) { status = s; }

    // Huỷ lịch hẹn
    void cancelAppointment() { status = "Cancelled"; }

    // Hoàn tất lịch hẹn
    void completeAppointment() { status = "Completed"; }

    // Đổi lịch hẹn
    void rescheduleAppointment(string t, string d)
    {
        time = t;
        date = d;
        status = "Rescheduled";
    }

    // In ra thông tin lịch hẹn
    void displayAppointment()
    {
        cout << "Time: " << time << endl;
        cout << "Date: " << date << endl;
        cout << "Reason: " << reason << endl;
        cout << "Status: " << status << endl; // Nên thêm dòng này
    }
};

// =============================
// Lớp Patient (bệnh nhân cơ bản)
// =============================
class Patient
{
protected:
    string name;               // Tên bệnh nhân
    int age;                   // Tuổi
    string ID;                 // Mã số bệnh nhân
    string medicalHistory;     // Lịch sử bệnh án
public:
    // Constructor: khởi tạo bệnh nhân
    Patient(string n, int a, string i)
    {
        name = n;
        age = a;
        ID = i;
    }

    // Getter
    string getName() { return name; }
    int getAge() { return age; }
    string getID() { return ID; }
    string getMedicalHistory() { return medicalHistory; }

    // Setter
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setID(string i) { ID = i; }
    void setMedicalHistory(string mh) { medicalHistory = mh; }

    // Hiển thị thông tin bệnh nhân
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << ID << endl;
        cout << "Medical History: " << medicalHistory << endl;
    }

    // Lịch hẹn (dùng vector<string>, hơi đơn giản)
    vector<string> Appointments;

    // Thêm lịch hẹn
    void scheduleAppointment(string app)
    {
        Appointments.push_back(app);
    }
};

// =============================
// Lớp ChronicPatient (bệnh nhân mãn tính)
// Kế thừa từ Patient
// =============================
class ChronicPatient : public Patient
{
private:
    string condition; // Loại bệnh mãn tính
public:
    ChronicPatient(string n, int a, string i, string c)
        : Patient(n, a, i), condition(c) {}

    // Getter/Setter cho condition
    string getCondition() { return condition; }
    void setCondition(string c) { condition = c; }

    // Hiển thị thông tin (override)
    void displayInfo()
    {
        Patient::displayInfo();
        cout << "Condition: " << condition << endl;
    }

    // Thêm lần khám cuối
    void lastCheckup()
    {
        string c;
        cout << "Enter last checkup date: ";
        cin >> c;
        setMedicalHistory(getMedicalHistory() + "\nLast checkup: " + c);
    }
};

// =============================
// Lớp Regular (bệnh nhân thường)
// =============================
class Regular : public Patient
{
public:
    Regular(string n, int a, string i) : Patient(n, a, i) {}

    // Hiển thị thông tin
    void displayInfo()
    {
        Patient::displayInfo();
        cout << "Regular Patient" << endl;
    }

    // Hẹn lịch khám định kỳ
    void scheduleCheckup()
    {
        string c;
        cout << "Enter checkup date: ";
        cin >> c;
        setMedicalHistory(getMedicalHistory() + "\nCheckup scheduled: " + c);
    }
};

// =============================
// Lớp Doctor (bác sĩ)
// =============================
class Dotor // (nên sửa thành Doctor)
{
private:
    string name;            // Tên bác sĩ
    string specialization;  // Chuyên khoa
public:
    Dotor(string n, string s)
    {
        name = n;
        specialization = s;
    }

    string getName() { return name; }
    string getSpecialization() { return specialization; }

    void setName(string n) { name = n; }
    void setSpecialization(string s) { specialization = s; }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
    }

    // Kiểm tra lịch hẹn (chỉ in chuỗi)
    void checkAppointments()
    {
        cout << "Appointments: " << endl;
        for (int i = 0; i < Appointments.size(); i++)
        {
            cout << Appointments[i] << endl;
        }
    }
};

// =============================
// Hàm main: test hệ thống
// =============================
int main()
{
    // Tạo bệnh nhân mãn tính
    ChronicPatient cp("John", 30, "001", "Diabetes");
    cp.displayInfo();
    cp.setMedicalHistory("High blood pressure");
    cp.lastCheckup();

    // Tạo bệnh nhân thường
    Regular r("Jane", 25, "002");
    r.displayInfo();
    r.setMedicalHistory("Flu");
    r.scheduleCheckup();

    // Tạo bác sĩ
    Dotor d("Dr. Smith", "Cardiologist");
    d.displayInfo();

    // Thêm lịch hẹn cho bệnh nhân
    cp.scheduleAppointment("Appointment 1");
    cp.scheduleAppointment("Appointment 2");

    // Bác sĩ kiểm tra lịch hẹn
    d.checkAppointments();

    // Tạo đối tượng Appointment riêng
    Appointment a("10:00 AM", "2023-10-10", "Routine Checkup", "Scheduled");
    a.displayAppointment();
    a.completeAppointment();
    a.displayAppointment();
    a.rescheduleAppointment("11:00 AM", "2023-10-11");
    a.displayAppointment();
    // Huỷ lịch hẹn
    a.cancelAppointment();
    a.displayAppointment();

    return 0;
}
