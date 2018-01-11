#include "BinaryNode.h"
#include <stdexcept>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

class BinarySearchTree {
private:
    int node_num; 	// total nodes in the tree
    BinaryNode *root;
    BinaryNode *insert(int x, BinaryNode *t, int& search_cost);
    BinaryNode *findMin(BinaryNode *t);
    BinaryNode *removeMin (BinaryNode *t);
    BinaryNode *remove(int x, BinaryNode *t);
   
    void inOrderTraversal( BinaryNode *t, int& total_sch_cost);
    void preOrderTraversal( BinaryNode *t, int& total_sch_cost);
    void postOrderTraversal( BinaryNode *t, int& total_sch_cost);
	void resetCost(BinaryNode* t, int i);
public:
    // constructor
    BinarySearchTree() { root = NULL; node_num=0; }
    bool isEmpty(){return root == NULL;}
    void remove(int x){ root = remove(x, root); }
    void insert(int x) {
        int search_cost=0;
        root=insert(x, root, search_cost);
    }
    int inOrderTraversal(){
        int total_sch_cost = 0;
        inOrderTraversal(root, total_sch_cost);
        cout<<endl;
        return total_sch_cost;
    }
    int preOrderTraversal(){
        int total_sch_cost = 0;
        preOrderTraversal(root, total_sch_cost);
        cout<<endl;
        return total_sch_cost;
    }
    int postOrderTraversal(){
        int total_sch_cost = 0;
        postOrderTraversal(root, total_sch_cost);
        cout<<endl;
        return total_sch_cost;
    }
    int getNodeNum(){return node_num;}
    
    void OutputTreeLevelByLevel();
    void OutputText(string filename);
};