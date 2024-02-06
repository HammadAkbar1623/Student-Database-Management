#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string name;
    int rollNumber;
    int marks;
};

void enterRecords(Student students[], int& count) {
    cout << "Enter the number of students: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        cout << "Enter details for student " << i + 1 << endl;
        cout << "Name: ";
        cin>>students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Marks: ";
        cin >> students[i].marks;
    }
}

void displayRecords(const Student students[], int count) {
    cout << "Student Records:";
    cout << "---------------------------------\n";
    cout<<"RollNumber"<<setw(8)<<"Name"<<setw(8)<<"Marks"<<endl;
    for (int i = 0; i < count; ++i) {
        cout<<setw(5)<<students[i].rollNumber<<setw(13) << students[i].name<<setw(8)<<students[i].marks<<endl;
    }
    cout << "---------------------------------\n";
}

int searchRecord(const Student students[], int count, int targetRollNumber) {
    for (int i = 0; i < count; ++i) {
        if (students[i].rollNumber == targetRollNumber) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    int choice;
    do {
        cout << "Student Database Management System by Hammad Niazi"<<endl;
        cout << "1. Enter Records"<<endl;
        cout << "2. Display Records"<<endl;
        cout << "3. Search for a Student"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enterRecords(students, numStudents);
                break;
            case 2:
                displayRecords(students, numStudents);
                break;
            case 3: {
                int targetRoll;
                cout << "Enter the Roll Number to search: ";
                cin >> targetRoll;
                int index = searchRecord(students, numStudents, targetRoll);
                if (index != -1) {
                    cout << "Student found:"<<endl;
                    cout << "Roll Number: " << students[index].rollNumber << endl;
                    cout << "Name: " << students[index].name << endl;
                    cout << "Marks: " << students[index].marks << endl;
                } else {
                    cout << "Student with Roll Number " << targetRoll << " not found"<<endl;
                }
                break;
            }
            case 4:
                cout << "Exiting the program. Goodbye!"<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again."<<endl;
        }
    } while (choice != 4);

    return 0;
}
