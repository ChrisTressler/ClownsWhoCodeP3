#pragma once
#include <unordered_map>
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
    unordered_map<string, vector<Student>> adjacencyList;
public:

    // Insertion Function
    void insert(string _firstName, string _lastName, string _university, string _salary,
                string _gradSchool, string _id, string _numInternships, string _employed, string _major);

    // Salary Functions
    void getAverageSalaryDFS();
    void getAverageSalary(string _university, string _major);
    void getUniversitySalaryDFS(string _university);
    void getMajorSalaryDFS(string _major);

    void getAverageSalaryBFS();
    void getUniversitySalaryBFS(string _university);
    void getMajorSalaryBFS(string _major);


    // Internship Functions
    void getAvgInternshipsDFS();
    void getAvgInternships(string _university, string _major);
    void getUniversityAvgInternshipsDFS(string _university);
    void getMajorAvgInternshipsDFS(string _major);

    void getAvgInternshipsBFS();
    void getUniversityAvgInternshipsBFS(string _university);
    void getMajorAvgInternshipsBFS(string _major);

    // Graduate Admissions Functions
    void getGradStatsDFS();
    void getGradStats(string _university, string _major);
    void getUniversityGradStatsDFS(string _university);
    void getMajorAvgGradStatsDFS(string _major);

    void getGradStatsBFS();
    void getUniversityGradStatsBFS(string _university);
    void getMajorAvgGradStatsBFS(string _major);

    // SEARCH COMPARISON FUNCTIONS
    void searchStudentIDBFS(int _id);
    void searchStudentIDDFS(int _id);

    // General Print Data Testing Function
    void printData();
    void printStudentData(Student _student);
};

