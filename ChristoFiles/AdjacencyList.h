#pragma once
#include <map>
#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    string university;
    int salary;
    bool gradSchool;
    int id;
    int numInternships;
    bool employed;
    string major;
};

class AdjacencyList
{
private:
    map<string, vector<Student>> adjacencyList;
public:

    // Insertion Function
    void insert(string _firstName, string _lastName, string _university, string _salary,
                string _gradSchool, string _id, string _numInternships, string _employed, string _major);

    // Salary Functions
    void getAverageSalary();
    void getAverageSalary(string _university, string _major);
    void getUniversitySalary(string _university);
    void getMajorSalary(string _major);


    // Internship Functions
    void getAvgInternships();
    void getAvgInternships(string _university, string _major);
    void getUniversityAvgInternships(string _university);
    void getMajorAvgInternships(string _major);

    // Graduate Admissions Functions
    void getGradStats();
    void getGradStats(string _university, string _major);
    void getUniversityGradStats(string _university);
    void getMajorAvgGradStats(string _major);

    // General Print Data Testing Function
    void printData();
};

