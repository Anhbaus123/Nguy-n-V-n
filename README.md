📝 OOA Document – Small Clinic Management System

Student: Nguyen Van
ID: 24110146
System: Small Clinic Management System

1. Introduction

The Small Clinic Management System (SCMS) is designed to support the management of patients, doctors, and appointments in a small medical clinic. The system provides a simplified yet realistic simulation of the interactions between these entities. The core objective is to apply Object-Oriented Analysis (OOA) and Object-Oriented Programming (OOP) concepts to design and implement a working solution.

This document presents the OOA model for the system, including the identification of objects, attributes, methods, inheritance structure, and relationships among entities.

2. Object Identification

Based on the problem scenario, the following key objects are identified:

Patient

Represents a person receiving medical care in the clinic.

Subclasses: ChronicPatient and Regular.

Doctor

Represents a medical professional working at the clinic.

Appointment

Represents a scheduled meeting between a patient and a doctor for medical consultation.

3. Attributes of Objects
Patient

name (string): Full name of the patient.

age (int): Patient’s age.

ID (string): Unique identifier for the patient.

medicalHistory (string): Record of patient’s past medical conditions.

Appointments (vector<string>): List of scheduled appointments.

ChronicPatient (inherits from Patient)

condition (string): Type of chronic disease (e.g., Diabetes, Hypertension).

Regular (inherits from Patient)

Inherits attributes from Patient.

Doctor

name (string): Doctor’s name.

specialization (string): Doctor’s area of expertise.

Appointment

time (string): Appointment time.

date (string): Appointment date.

reason (string): Reason for the appointment.

status (string): Status of the appointment (Scheduled, Completed, Cancelled, Rescheduled).

4. Methods of Objects
Patient

getName() / setName(): Manage patient’s name.

getAge() / setAge(): Manage age.

getID() / setID(): Manage ID.

getMedicalHistory() / setMedicalHistory(): Manage medical records.

displayInfo(): Print patient’s details.

scheduleAppointment(): Add new appointment (simplified as string).

ChronicPatient

getCondition() / setCondition(): Manage chronic condition.

lastCheckup(): Record the last checkup date.

displayInfo(): Override parent method to display chronic condition.

Regular

scheduleCheckup(): Record regular checkup schedule.

displayInfo(): Override parent method to indicate patient type.

Doctor

getName() / setName(): Manage doctor’s name.

getSpecialization() / setSpecialization(): Manage doctor’s field.

displayInfo(): Show doctor’s details.

checkAppointments(): Display all scheduled appointments.

Appointment

getTime() / setTime(): Manage appointment time.

getDate() / setDate(): Manage appointment date.

getReason() / setReason(): Manage reason.

getStatus() / setStatus(): Manage status.

cancelAppointment(): Cancel an appointment.

completeAppointment(): Mark appointment as completed.

rescheduleAppointment(): Reschedule with new time and date.

displayAppointment(): Display appointment details.

5. Inheritance

The system demonstrates inheritance with the following hierarchy:

Patient (Base class)

ChronicPatient (Subclass)

Regular (Subclass)

This design allows for common patient data to be stored in the parent class, while specialized behavior (chronic disease management, regular checkups) is defined in the subclasses.

6. Relationships

Patient ↔ Appointment: A patient can have one or more appointments. In the current implementation, appointments are stored as strings in a vector. Ideally, this should be a vector of Appointment objects.

Doctor ↔ Appointment: A doctor can check scheduled appointments. In a more advanced system, each appointment would be linked to both a patient and a doctor.

Inheritance: ChronicPatient and Regular both inherit from Patient.

7. System Scenarios

Register a new patient: The system creates a new Patient (or subclass) with basic details.

Schedule an appointment: A patient can schedule a new appointment.

Doctor checks appointments: The doctor can view all scheduled appointments.

Update patient history: Chronic patients can add details of their last checkup; regular patients can record periodic checkups.

Manage appointments: Appointment objects can be completed, rescheduled, or cancelled.

8. Strengths and Limitations
Strengths

Correct use of encapsulation with getters and setters.

Inheritance and polymorphism demonstrated via subclasses and overridden methods.

System covers main clinic operations (patient registration, appointment scheduling, doctor assignment).

Code compiles and runs successfully, producing correct outputs.

Limitations

Appointments are stored as simple strings rather than linked objects. This reduces realism.

Global vector for doctor’s appointments is not ideal design. It should be encapsulated in Doctor.

No persistent storage (all data lost when program ends).

Limited user interaction (no menus, only hardcoded test cases).

9. Conclusion

The Small Clinic Management System demonstrates key OOP concepts (encapsulation, inheritance, polymorphism, object interaction) in a real-world healthcare scenario. The analysis identifies appropriate objects, attributes, and methods, while the implementation provides a functional prototype.

Future improvements could include stronger associations between classes (e.g., appointments explicitly linking a patient and doctor), user-friendly interface, and persistent storage (database or file).

Overall, the OOA and C++ implementation meet the requirements and provide a strong example of applying OOP to solve real-world problems.
