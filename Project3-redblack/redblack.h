#include "iostream"
#include "string"
#include <bits/stdc++.h>
using namespace std;
enum Color {red, black};

struct Node
{
    Node( string firstName, string lastName, string university, string salary, string gradSchool, string id,
         string numInternships, string employed, string major);

    string firstName;
    string lastName;
    string university;
    string salary;
    string gradSchool;
    string id;
    string numInternships;
    string employed;
    string major;
    int color;
    Node *left, *right, *p;

};

class redblack
{
private:
    Node *root;
protected:
    Node* rotateLeft(Node *&);
    Node* rotateRight(Node *&);
    Node* fixInsertRBTree(Node *&);
    void inorderBST(Node *&);
    int getColor(Node *&);
    void setColor(Node *&, int);
    Node* insertBST(Node *&, Node *&);

public:
    redblack();
    void insertValue(string firstName, string lastName, string university, string salary, string gradSchool, string id, string numInternships, string employed, string major);
    void inorder();
    void SearchMajorwrap(string key);
    vector<string> SearchMajor(redblack* root, string key, vector<string> &listname);
};


