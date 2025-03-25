#include <iostream>
#include <string>

using namespace std;

struct Student {
    int studentID = 0;
    string firstName;
    string lastName;
    string course;
    float gpa = 0.0;
};

//first try to figure the array part abd search about the temp sorting for the view part

int main() {
    const int size = 1000;
    Student studentDatabase[size];
    int studentCount = 0;
    int choice;

    do {
        cout << " === Student Management System === \n";
        cout << " [1] Add Student\n";
        cout << " [2] Edit Student\n";
        cout << " [3] Delete Student\n";
        cout << " [4] View Students\n";
        cout << " [5] Exit Program\n";
        cout << " Enter your option: ";
        cin >> choice;

        system("CLS");

        switch (choice) {
            case 1: {
                if (studentCount >= size) {
                    cout << "The student database is full. Cannot add more students.\n";
                    break;
                }
//unique id name??
                for (int i = 0; i < size; ++i) {
                    if (studentDatabase[i].studentID == 0) {
                        int newID;
                        bool unique;
                        do {
                            unique = true;
                            cout << "Enter Student ID: ";
                            cin >> newID;

                            for (int j = 0; j < size; ++j) {
                                if (studentDatabase[j].studentID == newID) {
                                    cout << "Student with this ID already exists. Try again.\n";
                                    unique = false;
                                    break;
                                }
                            }
                        } while (!unique);

                        studentDatabase[i].studentID = newID;
                        cout << "Enter First Name: ";
                        cin >> studentDatabase[i].firstName;
                        cout << "Enter Last Name: ";
                        cin >> studentDatabase[i].lastName;
                        cout << "Enter Course: ";
                        cin >> studentDatabase[i].course;
                        cout << "Enter GPA: ";
                        cin >> studentDatabase[i].gpa;

                        studentCount++;
                        cout << "STUDENT ENTERED SUCCESSFULLY!!!.\n";
                
                        break;
                    }
                }
                break;
            }

            case 2: {
                if (studentCount == 0) {
                    cout << "No students in the database to edit.\n";
                    break;
                }

                int id;
                cout << "Enter the Student ID to edit: ";
                cin >> id;

                bool found = false;
                for (int i = 0; i < size; ++i) {
                    if (studentDatabase[i].studentID == id) {
                        cout << " === EDIT STUDENT === \n";
                        cout << "Enter New First Name: ";
                        cin >> studentDatabase[i].firstName;
                        cout << "Enter New Last Name: ";
                        cin >> studentDatabase[i].lastName;
                        cout << "Enter New Course: ";
                        cin >> studentDatabase[i].course;
                        cout << "Enter New GPA: ";
                        cin >> studentDatabase[i].gpa;

                        cout << "STUDENT RECORD UPDATED SUCCESSFULLY.\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student ID not found.\n";
                }
                break;
            }

            case 3: {
                if (studentCount == 0) {
                    cout << "No students in the database to delete.\n";
                    break;
                }

                int id;
                cout << "Enter the Student ID to delete: ";
                cin >> id;
//how to do tolower??? search
                bool found = false;
                for (int i = 0; i < size; ++i) {
                    if (studentDatabase[i].studentID == id) {
                        cout << "Are you sure you want to delete this record? (y/n): ";
                        char confirm;
                        cin >> confirm;
                        if (confirm == 'y' || confirm == 'Y') {
                            studentDatabase[i] = Student();
                            studentCount--;
                            cout << "STUDENT RECORD DELETED SUCCESSFULLY.\n";
                        } else {
                            cout << "Deletion canceled.\n";
                        }
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student ID not found.\n";
                }
                break;
            }

            case 4: {
                if (studentCount == 0) {
                    cout << "The student database is empty.\n";
                    break;
                }

                cout << " === VIEW STUDENTS === \n";
                for (int i = 0; i < size; ++i) {
                    if (studentDatabase[i].studentID != 0) {
                        cout << "Student ID: " << studentDatabase[i].studentID
                             << ", Name: " << studentDatabase[i].firstName << " " << studentDatabase[i].lastName
                             << ", Course: " << studentDatabase[i].course
                             << ", GPA: " << studentDatabase[i].gpa << "\n";
                    }
                }
                break;
            }

            case 5:
                cout << "Exiting Program... Goodbye!\n";
                break;

            default:
                cout << "Invalid selection! Please enter a number from 1 to 5.\n";
        }
    } while (choice != 5);
//do while here
    return 0;
}
