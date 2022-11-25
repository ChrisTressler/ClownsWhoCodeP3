//
// Created by kusha on 11/23/2022.
//
#include "redblack.h"
#include <bits/stdc++.h>
#include "string"
using namespace std;

Node::Node(string firstName, string lastName, string university, string salary, string gradSchool, string id, string numInternships, string employed, string major) {
    this->lastName = lastName;
    this->university = university;
    this->salary = salary;
    this->gradSchool = gradSchool;
    this->id = id;
    this->numInternships = numInternships;
    this->employed = employed;
    this->major = major;
    this->color = red;
    left = right = p = nullptr;
}

redblack::redblack() {
    root = nullptr;
}

int redblack::getColor(Node *&node) {
    if (node == nullptr)
        return black;

    return node->color;
}

void redblack::setColor(Node *&node, int color) {
    if (node == nullptr)
        return;
    node->color = color;
}

Node* redblack::insertBST(Node *&root, Node *&ptr) {
    if (root == nullptr)
        return ptr;
    if (ptr->id < root->id) {
        root->left = insertBST(root->left, ptr);
        root->left->p = root;
    } else if (ptr->id > root->id) {
        root->right = insertBST(root->right, ptr);
        root->right->p = root;
    }
    return root;
}

void redblack::insertValue(string firstName, string lastName, string university, string salary, string gradSchool, string id, string numInternships, string employed, string major) {
    Node *node = new Node(firstName, lastName, university, salary, gradSchool, id, numInternships, employed, major);
    root = insertBST(root, node);
    fixInsertRBTree(node);
}

Node* redblack::rotateLeft(Node *&ptr) {
    Node *rchild = ptr->right;
    ptr->right = rchild->left;
    if (ptr->right != nullptr)
        ptr->right->p = ptr;
    rchild->p = ptr->p;
    if (ptr->p == nullptr)
        root = rchild;
    else if (ptr == ptr->p->left)
        ptr->p->left = rchild;
    else
        ptr->p->right = rchild;
    rchild->left = ptr;
    ptr->p = rchild;
    return ptr;
    /*
        TreeNode* rotateLeft(TreeNode *root)
     {
         TreeNode* rightChild = root->right;
         root->right = rightChild->left;
         rightChild->left = root;
         return rightChild;
     }
     */
}

Node* redblack::rotateRight(Node *&ptr) {
    Node *lchild = ptr->left;
    ptr->left = lchild->right;

    if (ptr->left != nullptr)
        ptr->left->p = ptr;

    lchild->p = ptr->p;

    if (ptr->p == nullptr)
        root = lchild;
    else if (ptr == ptr->p->left)
        ptr->p->left = lchild;
    else
        ptr->p->right = lchild;

    lchild->right = ptr;
    ptr->p = lchild;
    return ptr;
    /*
        TreeNode* rotateRight(TreeNode *root)
     {
         TreeNode* leftChild = root->left;
         root->left = leftChild->right;
         leftChild->right = root;
         return leftChild;
     }
     */
}

Node* redblack::fixInsertRBTree(Node *&ptr) {
    Node *p = nullptr;
    Node *gp = nullptr;
    while (ptr != root && getColor(ptr) == red && getColor(ptr->p) == red) {
        p = ptr->p;
        gp = p->p;
        if (p == gp->left) {
            Node *uc = gp->right;
            if (getColor(uc) == red) {
                setColor(uc, black);
                setColor(p, black);
                setColor(gp, red);
                ptr = gp;
            } else {
                if (ptr == p->right) {
                    rotateLeft(p);
                    ptr = p;
                    p = ptr->p;
                }
                rotateRight(gp);
                swap(p->color, gp->color);
                ptr = p;
            }
        } else {
            Node *uc = gp->left;
            if (getColor(uc) == red) {
                setColor(uc, black);
                setColor(p, black);
                setColor(gp, red);
                ptr = gp;
            } else {
                if (ptr == p->left) {
                    rotateRight(p);
                    ptr = p;
                    p = ptr->p;
                }
                rotateLeft(gp);
                swap(p->color, gp->color);
                ptr = p;
            }
        }
    }
    setColor(root, black);
    return ptr;
}

void redblack::inorderBST(Node *&ptr) {
    if (ptr == nullptr){
        return;
    }
    inorderBST(ptr->left);
    cout << ptr->id << " " << ptr->color << endl; // 1 is black and 0 is red i think something strange happened here
    inorderBST(ptr->right);
}

void redblack::inorder() {
    inorderBST(root);
}
void SearchMajorwrap(string key, Node* root){
    vector<string> tlist;
    vector<string> searchedNames = SearchMajor(root, key, tlist); //tried figuring out what was wrong with it
                                                                  //but lowkey only spent like 5 seconds on it since chris put me on a time crunch atm

    if(searchedNames.size() == 0){
        cout << "unsuccessful" << endl;
    }
    else{
        for(int i = 0; i < searchedNames.size(); i++){
            cout << searchedNames[i] << endl;
        }
    }
}

vector<string> SearchMajor(Node* root, string key, vector<string> &listname){
    if(root == nullptr){
        return listname;
    }
    else{
        if(root->major == key){
            string bit = root->major;
            listname.push_back(bit);
        }
        SearchMajor(root->left, key, listname);
        SearchMajor(root->right, key, listname);
    }
    return listname;
}