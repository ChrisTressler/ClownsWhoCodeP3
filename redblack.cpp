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

Node* redblack::insertBST(Node *&root, Node *&head) {
    if (root == nullptr)
        return head;
    if (head->id < root->id) {
        root->left = insertBST(root->left, head);
        root->left->p = root;
    } else if (head->id > root->id) {
        root->right = insertBST(root->right, head);
        root->right->p = root;
    }
    return root;
    /*
     if (head == nullptr)
         {
             cout<< "successful"<< endl;
             return new TreeNode(name, id);
         }
         else if(id == head->id){
             cout << "unsuccessful" << endl;
             return 0;
         }
         else if (id < (head->id))
         {
             head->left = inserthelp(head->left, name, id);
             head->height = height(head);
         }
         else
         {
             head->right = inserthelp(head->right, name, id);
             head->height = height(head);
         }
     */
}

void redblack::insertValue(string firstName, string lastName, string university, string salary, string gradSchool, string id, string numInternships, string employed, string major) {
    Node *node = new Node(firstName, lastName, university, salary, gradSchool, id, numInternships, employed, major);
    root = insertBST(root, node);
    realInsert(node);
}

Node* redblack::rotateLeft(Node *&head) {
    Node *rchild = head->right;
    head->right = rchild->left;
    if (head->right != nullptr)
        head->right->p = head;
    rchild->p = head->p;
    if (head->p == nullptr)
        root = rchild;
    else if (head == head->p->left)
        head->p->left = rchild;
    else
        head->p->right = rchild;
    rchild->left = head;
    head->p = rchild;
    return head;
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

Node* redblack::rotateRight(Node *&head) {
    Node *lchild = head->left;
    head->left = lchild->right;

    if (head->left != nullptr)
        head->left->p = head;

    lchild->p = head->p;

    if (head->p == nullptr)
        root = lchild;
    else if (head == head->p->left)
        head->p->left = lchild;
    else
        head->p->right = lchild;

    lchild->right = head;
    head->p = lchild;
    return head;
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

Node* redblack::realInsert(Node *&head) {
    Node *p = nullptr;
    Node *gp = nullptr;
    while (head != root && getColor(head) == red && getColor(head->p) == red) {
        p = head->p;
        gp = p->p;
        if (p == gp->left) {
            Node *uc = gp->right;
            if (getColor(uc) == red) {
                setColor(uc, black);
                setColor(p, black);
                setColor(gp, red);
                head = gp;
            } else {
                if (head == p->right) {
                    rotateLeft(p);
                    head = p;
                    p = head->p;
                }
                rotateRight(gp);
                swap(p->color, gp->color);
                head = p;
            }
        } else {
            Node *uc = gp->left;
            if (getColor(uc) == red) {
                setColor(uc, black);
                setColor(p, black);
                setColor(gp, red);
                head = gp;
            } else {
                if (head == p->left) {
                    rotateRight(p);
                    head = p;
                    p = head->p;
                }
                rotateLeft(gp);
                swap(p->color, gp->color);
                head = p;
            }
        }
    }
    setColor(root, black);
    return root;
}

void redblack::inorder(Node *&head) {
    if (head == nullptr){
        return;
    }
    inorder(head->left);
    cout << head->id << " " << head->color << endl; // 1 is black and 0 is red i think something strange happened here
    inorder(head->right);
}

void redblack::inorder() {
    inorder(root);
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