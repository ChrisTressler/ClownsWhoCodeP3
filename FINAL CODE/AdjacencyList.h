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
    int getAverageSalaryDFS();
    int getAverageSalary(string _university, string _major);
    int getUniversitySalaryDFS(string _university);
    int getMajorSalaryDFS(string _major);

    int getAverageSalaryBFS();
    int getUniversitySalaryBFS(string _university);
    int getMajorSalaryBFS(string _major);


    // Internship Functions
    double getAvgInternshipsDFS();
    double getAvgInternships(string _university, string _major);
    double getUniversityAvgInternshipsDFS(string _university);
    double getMajorAvgInternshipsDFS(string _major);

    double getAvgInternshipsBFS();
    double getUniversityAvgInternshipsBFS(string _university);
    double getMajorAvgInternshipsBFS(string _major);

    // Graduate Admissions Functions
    double getGradStatsDFS();
    double getGradStats(string _university, string _major);
    double getUniversityGradStatsDFS(string _university);
    double getMajorAvgGradStatsDFS(string _major);

    double getGradStatsBFS();
    double getUniversityGradStatsBFS(string _university);
    double getMajorAvgGradStatsBFS(string _major);

    // SEARCH COMPARISON FUNCTIONS
    pair<double, Student> searchStudentIDBFS(int _id);
    pair<double, Student> searchStudentIDDFS(int _id);

};

