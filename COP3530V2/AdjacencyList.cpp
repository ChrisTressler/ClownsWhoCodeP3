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

void AdjacencyList::printStudentData(Student _student) {
    cout << "First Name: " << _student.firstName << endl;
    cout << "Last Name: " << _student.lastName << endl;
    cout << "University: " << _student.university << endl;
    cout << "Salary: " << _student.salary << endl;
    cout << "Accepted To Grad School: " << _student.gradSchool << endl;
    cout << "ID #: " << _student.id << endl;
    cout << "Internship Count: " << _student.numInternships << endl;
    cout << "Employed: " << _student.employed << endl;
    cout << "Major: " << _student.major << endl << endl;
}

void AdjacencyList::searchStudentIDBFS(int _id) {

    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    bool found = false;
    bool moreLeft = true;
    int currentIndex = 0;
    while (moreLeft) {
        moreLeft = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].id == _id) {
                printStudentData(it->second[currentIndex]);
                found = true;
                break;
                moreLeft = true;
            }
            else if (it->second.size() > currentIndex) {
                moreLeft = true;
            }
        }
        currentIndex++;
    }
    if (!found) {
        cout << "Student w/ ID # " << _id << " Not Found!" << endl << endl;
    }

    end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "BFS Search Time: " << fixed << setprecision(2) << duration.count() * 1000 << "ms" << endl << endl;
}

void AdjacencyList::searchStudentIDDFS(int _id) {

    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    bool found = false;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].id == _id) {
                printStudentData(it->second[i]);
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "Student w/ ID # " << _id << " Not Found!" << endl << endl;
    }

    end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "DFS Search Time: " << fixed << setprecision(2) << duration.count() * 1000 << "ms" << endl << endl;
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

void AdjacencyList::getAverageSalaryDFS() {
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

void AdjacencyList::getAverageSalaryBFS() {
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
        cout << "Average Salary: " << avgSalary << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }

}

void AdjacencyList::getUniversitySalaryDFS(string _university) {
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

void AdjacencyList::getUniversitySalaryBFS(string _university) {
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
        cout << "Average Salary: " << avgSalary << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }

}

void AdjacencyList::getMajorSalaryDFS(string _major) {
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

void AdjacencyList::getMajorSalaryBFS(string _major) {
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
        cout << "Average Salary: " << avgSalary << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
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

void AdjacencyList::getAvgInternshipsDFS()
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

void AdjacencyList::getAvgInternshipsBFS() {
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
        cout << "Average # Internships: " << fixed << setprecision(2) << avgNumInternships << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }
}

void AdjacencyList::getUniversityAvgInternshipsDFS(string _university) {
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

void AdjacencyList::getUniversityAvgInternshipsBFS(string _university) {
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
        cout << "Average # Internships: " << fixed << setprecision(2) << avgNumInternships << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }
}

void AdjacencyList::getMajorAvgInternshipsDFS(string _major) {
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

void AdjacencyList::getMajorAvgInternshipsBFS(string _major) {
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
        cout << "Average # Internships: " << fixed << setprecision(2) << avgNumInternships << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }
}

void AdjacencyList::getGradStatsDFS() {
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

void AdjacencyList::getGradStatsBFS() {
    long long currentSum = 0;
    long numCount = 0;

    bool found = true;
    int currentIndex = 0;
    while (found) {
        found = false;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (it->second.size() > currentIndex && it->second[currentIndex].gradSchool) {
                currentSum += 1;
                found = true;
                numCount++;
            }
        }
        currentIndex++;
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

void AdjacencyList::getUniversityGradStatsDFS(string _university) {
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

void AdjacencyList::getUniversityGradStatsBFS(string _university) {
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
        cout << "Graduate Admissions Rate: " << fixed << setprecision(2) << avgGradChance << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }
}

void AdjacencyList::getMajorAvgGradStatsDFS(string _major) {
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

void AdjacencyList::getMajorAvgGradStatsBFS(string _major) {
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
        cout << "Graduate Admissions Rate: " << fixed << setprecision(2) << avgGradChance << endl;
    }
    else {
        cout << "Error! Data Not Found! Check your CSV!" << endl;
    }
}