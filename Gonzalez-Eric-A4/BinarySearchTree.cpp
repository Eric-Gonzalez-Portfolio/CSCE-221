#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>


//insert an element into the tree
BinaryNode *BinarySearchTree::insert(int x, BinaryNode *t, int& search_cost){
    search_cost++;
    if(t == NULL){
        t = new BinaryNode(x);
        t -> SearchCost = search_cost;
        node_num++;
        cout << "Key = " << x << "  SearchCost = " << search_cost << endl; //Key corresponds to element
    }
    else if(x < t->element)
        t->left = insert(x, t->left, search_cost);
    else if(x > t->element)
        t->right = insert(x, t->right, search_cost);
    else
        cerr << "error (insert): Duplicate item." << endl;
    return t;
}


//find the minimum node in the tree
BinaryNode *BinarySearchTree::findMin(BinaryNode *t){
    if(t == NULL)   cerr << "error (findMin): Empty Tree." << endl;
    while(t->left != NULL) t = t->left;
    return t;
}


//remove the minimum node from the tree
BinaryNode *BinarySearchTree::removeMin(BinaryNode *t){
    if(t == NULL)
        cerr << "error (removeMin): Item Not Found." << endl;
    if(t->left != NULL)
        t->left = removeMin(t->left);
    else {
        BinaryNode *node = t;
        t = t->right;
        delete node;
    }
    return t;
}


//remove a node from the tree
BinaryNode *BinarySearchTree::remove(int x, BinaryNode *t){
    if(t == NULL){
        cerr << "error (remove): Item Not Found." << endl;
        return t;
    }
    if(x < t->element)
        t->left = remove(x, t->left);
    else if(x > t->element)
        t->right = remove(x, t->right);
    else if(t->left != NULL && t->right != NULL){
        // item x is found; t has two children
        t->element = findMin(t->right)->element;
        t->right = removeMin(t->right);
        node_num--;
        resetCost(root,1);
    }
    else { //t has only one child
        node_num--;
        BinaryNode *node = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete node;
        //resetCost(root,1);
    }
    return t;
}


// SearchCost = 1 + depth of the node
void BinarySearchTree::resetCost(BinaryNode* t, int i){
    if(t == NULL) 
		return;
    resetCost(t->left, i+1);
    resetCost(t->right, i+1);
    t->SearchCost = i; //  reset
}


// do a in_order traversal and print out the element
void BinarySearchTree::inOrderTraversal( BinaryNode *t, int& total_sch_cost){
    if(t == NULL)
        cerr << "error (inOrderTraversal): Empty Tree." << endl;
    
    if(t->left != NULL)
        inOrderTraversal(t->left,total_sch_cost);
    if (node_num < 17) {
        cout << t->element << "[" << t->SearchCost << "] ";
    }
    total_sch_cost += t->SearchCost;
    if(t->right != NULL)
        inOrderTraversal(t->right, total_sch_cost);
}


// do a pre_order traversal and print out the element
void BinarySearchTree::preOrderTraversal( BinaryNode *t, int& total_sch_cost){
    if(t == NULL)
        cerr << "error (preOrderTraversal): Empty Tree." << endl;
    
    if (node_num <17) {
        cout << t->element << "[" << t->SearchCost << "] ";
    }
    total_sch_cost += t->SearchCost;
    if(t->left != NULL)
        preOrderTraversal(t->left, total_sch_cost);
    if(t->right !=NULL)
        preOrderTraversal(t->right, total_sch_cost);
}


// do a post_order traversal and print out the element
void BinarySearchTree::postOrderTraversal( BinaryNode *t, int& total_sch_cost){
    if(t==NULL)
        cerr << "error (postOrderTraversal): Empty Tree." << endl;
    
    if(t->left != NULL)
        postOrderTraversal(t->left, total_sch_cost);
    if(t->right !=NULL)
        postOrderTraversal(t->right, total_sch_cost);
    if (node_num < 17) {
        cout << t->element << "[" << t->SearchCost << "] ";
    }
    total_sch_cost += t->SearchCost;
}


// output the whole tree level by level
void BinarySearchTree::OutputTreeLevelByLevel() {
    if (!root) 
		return;
    queue<BinaryNode*> nodes_queue;
    int nodesInNextLevel = 0;
	int nodesInCurrLevel = 1;
    nodes_queue.push(root);
    BinaryNode* X_node = new BinaryNode(-1);
    bool marker = true;
    vector<int> vect;
    while (!nodes_queue.empty()) {
        BinaryNode *currNode = nodes_queue.front();
        nodes_queue.pop();
        nodesInCurrLevel--;
        if (currNode) {
            vect.push_back(currNode->element);
            if (currNode->left == NULL) nodes_queue.push(X_node);
            else{
                marker = false;
                nodes_queue.push(currNode->left);
            }
            if (currNode->right == NULL) nodes_queue.push(X_node);
            else{
                marker = false;
                nodes_queue.push(currNode->right);
            }
            nodesInNextLevel += 2;
        }
        if (nodesInCurrLevel == 0) {
            
            for (int i=0; i<vect.size(); i++) {
                if (vect[i] == -1)
                    cout << "X ";
                else
                    cout << vect[i] << " ";
            }
            cout << endl;
            if (marker) {
                return;
            }
            vect.clear();
            marker = true;
            nodesInCurrLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
        }
    }
}

//save the whole tree to a file
void BinarySearchTree::OutputText(string filename){
    ofstream ofs(filename.c_str());
    if (!root) 
		return;
    queue<BinaryNode*> nodes_queue;
    int nodesInNextLevel = 0;
	int nodesInCurrLevel = 1;
    nodes_queue.push(root);
    BinaryNode* X_node = new BinaryNode(-1);
    bool marker = true;
    vector<int> vect;
    while (!nodes_queue.empty()) {
        BinaryNode *currNode = nodes_queue.front();
        nodes_queue.pop();
        nodesInCurrLevel--;
        if (currNode) {
            vect.push_back(currNode->element);
            if (currNode->left == NULL)
				nodes_queue.push(X_node);
            else{
                marker = false;
                nodes_queue.push(currNode->left);
            }
            if (currNode->right == NULL)
				nodes_queue.push(X_node);
            else{
                marker = false;
                nodes_queue.push(currNode->right);
            }
            nodesInNextLevel += 2;
        }
        if (nodesInCurrLevel == 0) {
            for (int i=0; i<vect.size(); i++) {
                if (vect[i] == -1)
                    ofs <<"X ";
                else
                    ofs << vect[i] << " ";
            }
            ofs << endl;
            if (marker) {
                return ;
            }
            vect.clear();
            marker = true;
            nodesInCurrLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
        }
    }
}