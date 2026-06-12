#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include "Driver.h"
using namespace std;

class BTreeNode {
public:
    vector<int> keys;
    vector<Driver> values;
    vector<BTreeNode*> children;
    bool leaf;
    int t;

    BTreeNode(int degree, bool isLeaf) {
        t = degree;
        leaf = isLeaf;
    }

    Driver* search(int id) {
        int i = 0;

        while (i < keys.size() && id > keys[i]) {
            i++;
        }

        if (i < keys.size() && keys[i] == id) {
            return &values[i];
        }

        if (leaf) {
            return nullptr;
        }

        return children[i]->search(id);
    }

    void traverse(vector<Driver>& result) {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!leaf) {
                children[i]->traverse(result);
            }
            result.push_back(values[i]);
        }

        if (!leaf) {
            children[i]->traverse(result);
        }
    }

    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->t, y->leaf);

        int midKey = y->keys[t - 1];
        Driver midValue = y->values[t - 1];

        for (int j = 0; j < t - 1; j++) {
            z->keys.push_back(y->keys[j + t]);
            z->values.push_back(y->values[j + t]);
        }

        if (!y->leaf) {
            for (int j = 0; j < t; j++) {
                z->children.push_back(y->children[j + t]);
            }
        }

        y->keys.resize(t - 1);
        y->values.resize(t - 1);

        if (!y->leaf) {
            y->children.resize(t);
        }

        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, midKey);
        values.insert(values.begin() + i, midValue);
    }

    void insertNonFull(Driver driver) {
        int i = keys.size() - 1;

        if (leaf) {
            keys.push_back(0);
            values.push_back(driver);

            while (i >= 0 && driver.id < keys[i]) {
                keys[i + 1] = keys[i];
                values[i + 1] = values[i];
                i--;
            }

            keys[i + 1] = driver.id;
            values[i + 1] = driver;
        } else {
            while (i >= 0 && driver.id < keys[i]) {
                i--;
            }

            i++;

            if (children[i]->keys.size() == 2 * t - 1) {
                splitChild(i, children[i]);

                if (driver.id > keys[i]) {
                    i++;
                }
            }

            children[i]->insertNonFull(driver);
        }
    }
};

class BTree {
    BTreeNode* root;
    int t;

public:
    BTree(int degree = 3) {
        root = nullptr;
        t = degree;
    }

    void insertDriver(Driver driver) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys.push_back(driver.id);
            root->values.push_back(driver);
            return;
        }

        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* newRoot = new BTreeNode(t, false);
            newRoot->children.push_back(root);
            newRoot->splitChild(0, root);

            int i = 0;
            if (driver.id > newRoot->keys[0]) {
                i++;
            }

            newRoot->children[i]->insertNonFull(driver);
            root = newRoot;
        } else {
            root->insertNonFull(driver);
        }
    }

    Driver* searchDriver(int id) {
        if (root == nullptr) {
            return nullptr;
        }

        return root->search(id);
    }

    vector<Driver> getAllDrivers() {
        vector<Driver> result;

        if (root != nullptr) {
            root->traverse(result);
        }

        return result;
    }

    void displayDrivers() {
        vector<Driver> drivers = getAllDrivers();

        cout << "\nDriver Directory using B-Tree:\n";

        for (auto d : drivers) {
            cout << "ID: " << d.id
                 << " | Name: " << d.name
                 << " | Location Node: " << d.locationNode
                 << " | Available: " << (d.available ? "Yes" : "No")
                 << endl;
        }
    }
};

#endif