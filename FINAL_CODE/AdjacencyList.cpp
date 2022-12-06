#include "AdjacencyList.h"
#include<bits/stdc++.h>
#include <chrono>

void AdjacencyList::insert(string _firstName, string _lastName, string _university, string _salary, string _gradSchool,
                           string _id, string _numInternships, string _employed, string _major) {
    Student tempStudent;

    // String Data Types
    tempStudent.firstName = _firstName;
    tempStudent.lastName = _lastName;
    tempStudent.university = _university;
    tempStudent.major = _major;

    // Int Data Types
    tempStudent.salary = stoi(_salary);
    tempStudent.numInternships = stoi(_numInternships);
    tempStudent.id = stoi(_id);

    // Bool Data Types
    if (_gradSchool == "TRUE") {
        tempStudent.gradSchool = true;
    }
    else {
        tempStudent.gradSchool = false;
    }
    if (_employed == "TRUE") {
        tempStudent.employed = true;
    }
    else {
        tempStudent.employed = false;
    }
    adjacencyList[_university + _major].push_back(tempStudent);
}

// NOTE: Every function will have two different versions, a BFS approach and DFS approach

// Search ID Functions (Used for BFS / DFS Comparison)
pair<double, Student> AdjacencyList::searchStudentIDBFS(int _id) {

    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    Student returnStudent;

    bool found = false;
    bool moreLeft = true;
    int currentIndex = 0;
    while (moreLeft) {
        moreLeft = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].id == _id) {
                returnStudent = it->second[currentIndex];
                break;
            }
            else if (it->second.size() > currentIndex) {
                moreLeft = true;
            }
        }
        currentIndex++;
    }

    end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    return make_pair(duration.count(), returnStudent);
}

pair<double, Student> AdjacencyList::searchStudentIDDFS(int _id) {

    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    Student returnStudent;

    bool found = false;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].id == _id) {
                returnStudent = it->second[i];
                break;
            }
        }
    }

    end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;

    return make_pair(duration.count(), returnStudent);
}

// Average Salary Functions *********************************************/
int AdjacencyList::getAverageSalary(string _university, string _major) {
    string index = _university + _major;
    long long currentSum = 0;

    if (adjacencyList.find(index) != adjacencyList.end())
    {
        for (int i = 0; i < adjacencyList[index].size(); i++)
        {
            currentSum += adjacencyList[index][i].salary;
        }

        int avgSalary = currentSum / adjacencyList[index].size();
        return avgSalary;
    }
    else {
        return -1.00;
    }

}

int AdjacencyList::getAverageSalaryDFS() {
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            currentSum += it->second[i].salary;
            numCount++;
        }
    }

    if (numCount != 0)
    {
        int avgSalary = currentSum / numCount;
        return avgSalary;
    }
    else {
        return -1;
    }
}

int AdjacencyList::getAverageSalaryBFS() {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex) {
                currentSum += it->second[currentIndex].salary;
                found = true;
                numCount++;
            }
        }
        currentIndex++;
    }

    if (numCount != 0)
    {
        int avgSalary = currentSum / numCount;
        return avgSalary;
    }
    else {
        return -1;
    }

}

int AdjacencyList::getUniversitySalaryDFS(string _university) {
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].university == _university) {
                currentSum += it->second[i].salary;
                numCount++;
            }
        }
    }

    if (numCount != 0)
    {
        int avgSalary = currentSum / numCount;
        return avgSalary;
    }
    else {
        return -1;
    }
}

int AdjacencyList::getUniversitySalaryBFS(string _university) {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].university == _university) {
                currentSum += it->second[currentIndex].salary;
                found = true;
                numCount++;
            }
        }
        currentIndex++;
    }
    if (numCount != 0)
    {
        int avgSalary = currentSum / numCount;
        return avgSalary;
    }
    else {
        return -1;
    }

}

int AdjacencyList::getMajorSalaryDFS(string _major) {
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].major == _major) {
                currentSum += it->second[i].salary;
                numCount++;
            }
        }
    }

    if (numCount != 0)
    {
        int avgSalary = currentSum / numCount;
        return avgSalary;
    }
    else {
        return -1;
    }

}

int AdjacencyList::getMajorSalaryBFS(string _major) {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].major == _major) {
                currentSum += it->second[currentIndex].salary;
                found = true;
                numCount++;
            }
        }
        currentIndex++;
    }
    if (numCount != 0)
    {
        int avgSalary = currentSum / numCount;
        return avgSalary;
    }
    else {
        return -1;
    }

}

// Average Internship Functions *********************************************/
double AdjacencyList::getAvgInternships(string _university, string _major) {
    string index = _university + _major;
    long long currentSum = 0;

    if (adjacencyList.find(index) != adjacencyList.end())
    {
        for (int i = 0; i < adjacencyList[index].size(); i++)
        {
            currentSum += adjacencyList[index][i].numInternships;
        }

        double avgNumInternships = (double) currentSum / adjacencyList[index].size();
        return avgNumInternships;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getAvgInternshipsDFS()
{
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            currentSum += it->second[i].numInternships;
            numCount++;
        }
    }

    if (numCount != 0)
    {
        double avgNumInternships = (double) currentSum / numCount;
        return avgNumInternships;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getAvgInternshipsBFS() {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex) {
                currentSum += it->second[currentIndex].numInternships;
                found = true;
                numCount++;
            }
        }
        currentIndex++;
    }

    if (numCount != 0)
    {
        double avgNumInternships = (double) currentSum / numCount;
        return avgNumInternships;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getUniversityAvgInternshipsDFS(string _university) {
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].university == _university) {
                currentSum += it->second[i].numInternships;
                numCount++;
            }
        }
    }

    if (numCount != 0)
    {
        double avgNumInternships = (double) currentSum / numCount;
        return avgNumInternships;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getUniversityAvgInternshipsBFS(string _university) {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].university == _university) {
                currentSum += it->second[currentIndex].numInternships;
                found = true;
                numCount++;
            }
        }
        currentIndex++;
    }

    if (numCount != 0)
    {
        double avgNumInternships = (double) currentSum / numCount;
        return avgNumInternships;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getMajorAvgInternshipsDFS(string _major) {
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].major == _major) {
                currentSum += it->second[i].numInternships;
                numCount++;
            }

        }
    }

    if (numCount != 0)
    {
        double avgNumInternships = (double) currentSum / numCount;
        return avgNumInternships;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getMajorAvgInternshipsBFS(string _major) {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].major == _major) {
                currentSum += it->second[currentIndex].numInternships;
                found = true;
                numCount++;
            }
        }
        currentIndex++;
    }

    if (numCount != 0)
    {
        double avgNumInternships = (double) currentSum / numCount;
        return avgNumInternships;
    }
    else {
        return -1.00;
    }
}

// Graduate Statistic Functions *********************************************/
double AdjacencyList::getGradStatsDFS() {
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].gradSchool) {
                currentSum++;
            }
            numCount++;
        }
    }

    if (numCount != 0)
    {
        double avgGradChance = (double) currentSum / numCount;
        return avgGradChance;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getGradStatsBFS() {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].gradSchool) {
                currentSum++;
                numCount++;
                found = true;
            }
            else if (it->second.size() > currentIndex) {
                numCount++;
                found = true;
            }
        }
        currentIndex++;
    }

    if (numCount != 0)
    {
        double avgGradChance = (double) currentSum / numCount;
        return avgGradChance;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getGradStats(string _university, string _major) {
    string index = _university + _major;
    long long currentSum = 0;

    if (adjacencyList.find(index) != adjacencyList.end())
    {
        for (int i = 0; i < adjacencyList[index].size(); i++)
        {
            if (adjacencyList[index][i].gradSchool) {
                currentSum++;
            }
        }

        double avgGradStats = (double) currentSum / adjacencyList[index].size();
        return avgGradStats;
    }
    else {
        return -1.00;
    }

}

double AdjacencyList::getUniversityGradStatsDFS(string _university) {
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].gradSchool && it->second[i].university == _university) {
                currentSum++;
                numCount++;
            }
            else if (it->second[i].university == _university) {
                numCount++;
            }
        }
    }

    if (numCount != 0)
    {
        double avgGradStats = (double) currentSum / numCount;
        return avgGradStats;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getUniversityGradStatsBFS(string _university) {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].university == _university) {
                if (it->second[currentIndex].gradSchool) {
                    currentSum += 1;
                }
                numCount++;
                found = true;

            }
        }
        currentIndex++;
    }

    if (numCount != 0)
    {
        double avgGradChance = (double) currentSum / numCount;
        return avgGradChance;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getMajorAvgGradStatsDFS(string _major) {
    long long currentSum = 0;
    long numCount = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].gradSchool && it->second[i].major == _major) {
                currentSum++;
                numCount++;
            }
            else if (it->second[i].major == _major) {
                numCount++;
            }
        }
    }

    if (numCount != 0)
    {
        double avgGradStats = (double) currentSum / numCount;
        return avgGradStats;
    }
    else {
        return -1.00;
    }
}

double AdjacencyList::getMajorAvgGradStatsBFS(string _major) {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].major == _major) {
                if (it->second[currentIndex].gradSchool) {
                    currentSum += 1;
                }
                numCount++;
                found = true;
            }
        }
        currentIndex++;
    }

    if (numCount != 0)
    {
        double avgGradChance = (double) currentSum / numCount;
        return avgGradChance;
    }
    else {
        return -1.00;
    }
}