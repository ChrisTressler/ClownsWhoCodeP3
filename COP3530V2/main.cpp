#include <iostream>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "AdjacencyList.h"
using namespace std;

void printMenu(string mode) {

    cout << "Current Mode: " << mode << endl;
    cout << "1. Get Salary Data" << endl;
    cout << "2. Get Internship Data" << endl;
    cout << "3. Get Graduate Admissions Data" << endl;
    cout << "4. Switch DFS/BFS Mode" << endl;
    cout << "5. Search an ID" << endl;
    cout << "6. Exit Program" << endl << endl;
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
    string mode = "DFS";

    while (!systemEnd)
    {
        printMenu(mode);
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
                    if (mode == "BFS") {
                        studentList.getAverageSalaryBFS();
                    }
                    else if (mode == "DFS") {
                        studentList.getAverageSalaryDFS();
                    }
                    cout << endl;
                }
                else if (option == "2") {
                    string universityName;
                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << endl;

                    if (mode == "BFS") {
                        studentList.getUniversitySalaryBFS(universityName);
                    }
                    else if (mode == "DFS") {
                        studentList.getUniversitySalaryDFS(universityName);
                    }

                    cout << endl;

                }
                else if (option == "3") {
                    string majorName;
                    cout << "Type A Major:";
                    getline(cin, majorName);
                    cout << endl;

                    if (mode == "BFS") {
                        studentList.getMajorSalaryBFS(majorName);
                    }
                    else if (mode == "DFS") {
                        studentList.getMajorSalaryDFS(majorName);
                    }
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

                    if (mode == "BFS") {
                        studentList.getAverageSalary(universityName, majorName);
                    }
                    else if (mode == "DFS") {
                        studentList.getAverageSalary(universityName, majorName);
                    }

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

                    if (mode == "BFS") {
                        studentList.getAvgInternshipsBFS();
                    }
                    else if (mode == "DFS") {
                        studentList.getAvgInternshipsDFS();
                    }

                    cout << endl;
                }
                else if (option == "2") {
                    string universityName;
                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << endl;

                    if (mode == "BFS") {
                        studentList.getUniversityAvgInternshipsBFS(universityName);
                    }
                    else {
                        studentList.getUniversityAvgInternshipsDFS(universityName);
                    }

                    cout << endl;

                }
                else if (option == "3") {
                    string majorName;
                    cout << "Type A Major:";
                    getline(cin, majorName);
                    cout << endl;

                    if (mode == "BFS") {
                        studentList.getMajorAvgInternshipsBFS(majorName);
                    }
                    else if (mode == "DFS") {
                        studentList.getMajorAvgInternshipsDFS(majorName);
                    }

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

                    if (mode == "BFS") {
                        studentList.getGradStatsBFS();
                    }
                    else if (mode == "DFS") {
                        studentList.getGradStatsDFS();
                    }

                    cout << endl;
                }
                else if (option == "2") {
                    string universityName;
                    cout << "Type A University:";
                    getline(cin, universityName);
                    cout << endl;

                    if (mode == "BFS") {
                        studentList.getUniversityGradStatsBFS(universityName);
                    }
                    else if (mode == "DFS") {
                        studentList.getUniversityGradStatsDFS(universityName);
                    }
                    cout << endl;
                }
                else if (option == "3") {
                    string majorName;
                    cout << "Type A Major:";
                    getline(cin, majorName);
                    cout << endl;

                    if (mode == "BFS") {
                        studentList.getMajorAvgGradStatsBFS(majorName);
                    }
                    else if (mode == "DFS") {
                        studentList.getMajorAvgGradStatsDFS(majorName);
                    }


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
                if (mode == "DFS") {
                    cout << "Mode: BFS" << endl;
                    mode = "BFS";
                }
                else {
                    cout << "Mode: DFS" << endl;
                    mode = "DFS";
                }
                break;

            case 5:
                cout << "Enter A Search ID: ";
                getline(cin, option);
                intOption = stoi(option);
                cout << endl;

                if (mode == "BFS") {
                    studentList.searchStudentIDBFS(intOption);
                }
                else if (mode == "DFS") {
                    studentList.searchStudentIDDFS(intOption);
                }
                break;


            case 6:
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
