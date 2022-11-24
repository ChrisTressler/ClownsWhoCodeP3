#include "AdjacencyList.h"
#include<bits/stdc++.h>

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

void AdjacencyList::printData() {
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            cout << "First Name: " << it->second[i].firstName << ", ";
            cout << "Last Name: " << it->second[i].lastName << ", ";
            cout << "University: " << it->second[i].university << ", ";
            cout << "Salary: " << it->second[i].salary << ", ";
            cout << "Accepted To Grad School: " << it->second[i].gradSchool << ", ";
            cout << "ID #: " << it->second[i].id << ", ";
            cout << "Internship Count: " << it->second[i].numInternships << ", ";
            cout << "Employed: " << it->second[i].employed << ", ";
            cout << "Major: " << it->second[i].major << endl;
        }
    }
}

void AdjacencyList::getAverageSalary(string _university, string _major) {
    string index = _university + _major;
    long long currentSum = 0;

    if (adjacencyList.find(index) != adjacencyList.end())
    {
        for (int i = 0; i < adjacencyList[index].size(); i++)
        {
            currentSum += adjacencyList[index][i].salary;
        }

        int avgSalary = currentSum / adjacencyList[index].size();
        cout << "University: " << _university << endl;
        cout << "Major: " << _major << endl;
        cout << "Average Post-Graduate Salary: " << avgSalary << endl;
    }
    else {
        cout << "Error! \"" << _university << "\" \"" << _major << "\" Data Not Found!" << endl;
    }

}

void AdjacencyList::getAverageSalary() {
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
        cout << "Average Salary: " << avgSalary << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }

}

void AdjacencyList::getUniversitySalary(string _university) {
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
        cout << "University: " << _university << endl;
        cout << "Average Salary: " << avgSalary << endl;
    }
    else {
        cout << "Error! \"" << _university << "\" Data Not Found!" << endl;
    }
}

void AdjacencyList::getMajorSalary(string _major) {
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
        cout << "Major: " << _major << endl;
        cout << "Average Salary: " << avgSalary << endl;
    }
    else {
        cout << "Error! \"" << _major << "\" Data Not Found!" << endl;
    }

}

void AdjacencyList::getAvgInternships(string _university, string _major) {
    string index = _university + _major;
    long long currentSum = 0;

    if (adjacencyList.find(index) != adjacencyList.end())
    {
        for (int i = 0; i < adjacencyList[index].size(); i++)
        {
            currentSum += adjacencyList[index][i].numInternships;
        }

        double avgNumInternships = (double) currentSum / adjacencyList[index].size();
        cout << "University: " << _university << endl;
        cout << "Major: " << _major << endl;
        cout << "Avg # Internships: " << fixed << setprecision(2) << avgNumInternships << endl;
    }
    else {
        cout << "Error! \"" << _university << "\" \"" << _major << "\" Data Not Found!" << endl;
    }

}

void AdjacencyList::getAvgInternships()
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
        cout << "Average # Internships: " << fixed << setprecision(2) << avgNumInternships << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }

}

void AdjacencyList::getUniversityAvgInternships(string _university) {
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
        cout << "University: " << _university << endl;
        cout << "Average # Internships: " << fixed << setprecision(2) << avgNumInternships << endl;
    }
    else {
        cout << "Error! \"" << _university << "\" Data Not Found!" << endl;
    }
}

void AdjacencyList::getMajorAvgInternships(string _major) {
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
        cout << "Major: " << _major << endl;
        cout << "Average # Internships: " << fixed << setprecision(2) << avgNumInternships << endl;
    }
    else {
        cout << "Error! \"" << _major << "\" Data Not Found!" << endl;
    }

}

void AdjacencyList::getGradStats() {
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
        cout << "Graduate Admissions Rate: " << fixed << setprecision(2) << avgGradChance << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }
}

void AdjacencyList::getGradStats(string _university, string _major) {
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
        cout << "University: " << _university << endl;
        cout << "Major: " << _major << endl;
        cout << "Graduate Admission Rate: " << fixed << setprecision(2) << avgGradStats << endl;
    }
    else {
        cout << "Error! \"" << _university << "\" \"" << _major << "\" Data Not Found!" << endl;
    }

}

void AdjacencyList::getUniversityGradStats(string _university) {
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
        cout << "University: " << _university << endl;
        cout << "Graduate Admissions Rate: " << fixed << setprecision(2) << avgGradStats << endl;
    }
    else {
        cout << "Error! \"" << _university << "\" Data Not Found!" << endl;
    }
}

void AdjacencyList::getMajorAvgGradStats(string _major) {
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
        cout << "Major: " << _major << endl;
        cout << "Graduate Admissions Rate: " << fixed << setprecision(2) << avgGradStats << endl;
    }
    else {
        cout << "Error! \"" << _major << "\" Data Not Found!" << endl;
    }
}