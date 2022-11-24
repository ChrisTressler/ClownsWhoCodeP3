#include <iostream>
#include <fstream>
#include "AdjacencyList.h"
using namespace std;

void printMenu() {

    cout << "1. Get Salary Data" << endl;
    cout << "2. Get Internship Data" << endl;
    cout << "3. Get Graduate Admissions Data" << endl;
    cout << "4. Exit Program" << endl << endl;
    cout << "Please Select an Option: ";

}

void printSalaryMenu() {

    cout << "1. Get Salary Average Among All Graduates" << endl;
    cout << "2. Get Salary Average For A Specific College" << endl;
    cout << "3. Get Salary Average For A Specific Major" << endl;
    cout << "4. Get Salary Average For A Specific Major & University" << endl;
    cout << "5. Go Back" << endl << endl;
    cout << "Please Select an Option: ";

}

void printInternshipMenu() {
    cout << "1. Get Average Internship Count Among All Graduates" << endl;
    cout << "2. Get Average Internship Count For A Specific College" << endl;
    cout << "3. Get Average Internship Count For A Specific Major" << endl;
    cout << "4. Get Average Internship Count For A Specific Major & University" << endl;
    cout << "5. Go Back" << endl << endl;
    cout << "Please Select an Option: ";
}

void printGraduateMenu() {
    cout << "1. Get Graduate School Admissions Rate Among All Graduates" << endl;
    cout << "2. Get Graduate School Admissions Rate For A Specific College" << endl;
    cout << "3. Get Graduate School Admissions Rate For A Specific Major" << endl;
    cout << "4. Get Graduate School Admissions Rate For A Specific Major & University" << endl;
    cout << "5. Go Back" << endl << endl;
    cout << "Please Select an Option: ";
}

int main()
{

    AdjacencyList studentList;
    string firstName;
    string lastName;
    string university;
    string salary;
    string gradSchool;
    string id;
    string numInternships;
    string employed;
    string major;
    string buffer;

    fstream input("UniStudentData.csv");

    getline(input, buffer);

    while (!input.eof()) {
        getline(input, firstName, ',');
        getline(input, lastName, ',');
        getline(input, university, ',');
        getline(input, salary, ',');
        getline(input, gradSchool, ',');
        getline(input, id, ',');
        getline(input, numInternships, ',');
        getline(input, employed, ',');
        getline(input, major);

        studentList.insert(firstName, lastName, university, salary, gradSchool, id, numInternships, employed, major);

    }

    string option;
    int intOption;
    bool systemEnd = false;

    while (!systemEnd)
    {
        printMenu();
        getline(cin, option);
        cout << endl;

        try
        {
            intOption = stoi(option);
        }
        catch(exception &e)
        {
            cout << "That is not an option!" << endl << endl;
            continue;
        }


        switch (intOption) {
            case 1:
                printSalaryMenu();
                getline(cin, option);
                cout << endl;

                if (option == "1") {
                    studentList.getAverageSalary();
                    cout << endl;
                }
                else if (option == "2") {
                    string universityName;
                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << endl;

                    studentList.getUniversitySalary(universityName);
                    cout << endl;

                }
                else if (option == "3") {
                    string majorName;
                    cout << "Type A Major:";
                    getline(cin, majorName);
                    cout << endl;

                    studentList.getMajorSalary(majorName);
                    cout << endl;
                }
                else if (option == "4") {

                    string universityName;
                    string majorName;

                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << "Choose a Major: ";
                    getline(cin, majorName);
                    cout << endl;

                    studentList.getAverageSalary(universityName, majorName);
                    cout << endl;

                }
                else if (option == "5") {
                    continue;
                }
                else {
                    cout << "That is not an option!" << endl << endl;
                }
                break;

            case 2:
                printInternshipMenu();
                getline(cin, option);
                cout << endl;

                if (option == "1") {
                    studentList.getAvgInternships();
                    cout << endl;
                }
                else if (option == "2") {
                    string universityName;
                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << endl;

                    studentList.getUniversityAvgInternships(universityName);
                    cout << endl;

                }
                else if (option == "3") {
                    string majorName;
                    cout << "Type A Major:";
                    getline(cin, majorName);
                    cout << endl;

                    studentList.getMajorAvgInternships(majorName);
                    cout << endl;
                }
                else if (option == "4") {

                    string universityName;
                    string majorName;

                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << "Choose a Major: ";
                    getline(cin, majorName);
                    cout << endl;

                    studentList.getAvgInternships(universityName, majorName);
                    cout << endl;

                }
                else if (option == "5") {
                    continue;
                }
                else {
                    cout << "That is not an option!" << endl << endl;
                }
                break;

            case 3:
                printGraduateMenu();
                getline(cin, option);
                cout << endl;

                if (option == "1") {
                    studentList.getGradStats();
                    cout << endl;
                }
                else if (option == "2") {
                    string universityName;
                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << endl;

                    studentList.getUniversityGradStats(universityName);
                    cout << endl;
                }
                else if (option == "3") {
                    string majorName;
                    cout << "Type A Major:";
                    getline(cin, majorName);
                    cout << endl;

                    studentList.getMajorAvgGradStats(majorName);
                    cout << endl;
                }
                else if (option == "4") {
                    string universityName;
                    string majorName;

                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << "Choose a Major: ";
                    getline(cin, majorName);
                    cout << endl;

                    studentList.getGradStats(universityName, majorName);
                    cout << endl;
                }
                else if (option == "5") {
                    continue;
                }
                else {
                    cout << "That is not an option!" << endl << endl;
                }
                break;

            case 4:
                systemEnd = true;
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "That is not an option!" << endl << endl;
                continue;
        }
    }
    return 0;
}
