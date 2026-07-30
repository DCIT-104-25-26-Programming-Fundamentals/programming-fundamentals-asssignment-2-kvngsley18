// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateStudentAverage(const Student& student) {
    if (student.scores.empty()) return 0.0;

    double total = 0.0;
    for (double score : student.scores) {
        total += score;
    }
    return total / student.scores.size();
}

void displayMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Student name: ";
    getline(cin, newStudent.name);

    if (newStudent.name.empty()) {
        cout << "Error: Student name cannot be empty." << endl;
        return;
    }

    cout << "Student ID: ";
    if (!(cin >> newStudent.id)) {
        cout << "Error: Invalid ID entered." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (const auto& s : students) {
        if (s.id == newStudent.id) {
            cout << "Error: A student with ID " << newStudent.id << " already exists." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    }

    int numScores;
    cout << "How many scores? ";
    if (!(cin >> numScores) || numScores <= 0) {
        cout << "Error: Number of scores must be a positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    newStudent.scores.resize(numScores);
    for (int i = 0; i < numScores; ++i) {
        cout << "Enter score " << (i + 1) << ": ";
        while (!(cin >> newStudent.scores[i]) || newStudent.scores[i] < 0 || newStudent.scores[i] > 100) {
            cout << "Invalid input. Please enter a valid score (0-100): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records found." << endl;
        return;
    }

    cout << "\n-------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for (const auto& student : students) {
        string scoresStr = "[";
        for (size_t i = 0; i < student.scores.size(); ++i) {
            scoresStr += to_string(static_cast<int>(student.scores[i]));
            if (i < student.scores.size() - 1) scoresStr += ", ";
        }
        scoresStr += "]";

        double avg = calculateStudentAverage(student);

        cout << left << setw(20) << student.name 
             << setw(12) << student.id 
             << setw(20) << scoresStr 
             << fixed << setprecision(2) << avg << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
}
void calculateAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records found." << endl;
        return;
    }

    int searchID;
    cout << "Enter student ID: ";
    if (!(cin >> searchID)) {
        cout << "Error: Invalid ID entered." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (const auto& student : students) {
        if (student.id == searchID) {
            double avg = calculateStudentAverage(student);
            cout << student.name << "'s average score: " 
                 << fixed << setprecision(2) << avg << endl;
            return;
        }
    }

    cout << "Error: Student ID " << searchID << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        displayMenu();

        if (!(cin >> choice)) {
            cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverage(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Error: Choice must be between 1 and 4." << endl;
                break;
        }
    }

    return 0;
}