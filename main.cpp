// Driver Program for Red Black Tree
#include "iostream"
#include <bits/stdc++.h>
#include "redblack.h"
#include "fstream"
#include "string"
using namespace std;

int main() {
    redblack redblack1;
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
        redblack1.insertValue(firstName, lastName, university, salary, gradSchool, id, numInternships, employed, major);
    }
        redblack1.inorder();
    return 0;
}