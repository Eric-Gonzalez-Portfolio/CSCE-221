#include "BinarySearchTree.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void read_file(string filename, BinarySearchTree& tree){
    ifstream ist(filename);
    if (ist.is_open()){
        vector<int> input;
        int number;
        auto count = 0;
        cout << "Input data:\n";
        while(ist>>number){
            count++;
            input.push_back(number);
            cout << number << endl;
        }
        cout << "Create a binary search tree:"<<endl;
        for (int i=0; i<input.size(); i++) {
            tree.insert(input[i]);
        }
        cout << "Total number of nodes is " << count << endl;
    }
    else{
        cerr << "Cannot open '"<< filename <<"'."<<endl;
    }   
}

// This part is used with the test_example file.
int main(){
    BinarySearchTree tree;
    cout << "Input a filename: ";
    string filename;
    cin >> filename;
    read_file(filename,tree);

    cout << "In Order Traversal:" << endl;
    int total_sch_cost = tree.inOrderTraversal();
    cout << "Pre Order Traversal:" << endl;
    tree.preOrderTraversal();
    cout << "Post Order Traversal:" << endl;
    tree.postOrderTraversal();
    cout<< "Average search cost is " << (double) total_sch_cost/(double) tree.getNodeNum() <<'\n';
    if (tree.getNodeNum()>16) {
        cout << "Node number great than 16, please check output file."<<endl;
    }
    else{
        tree.OutputText("test_example_output");
        tree.OutputTreeLevelByLevel();
    }

    cout << "Please enter a key to remove: ";
    int num;
    cin >> num;
    tree.remove(num);
    
    if (tree.getNodeNum() > 16) {
        cout << "Node number greater than 16, check output file."<<endl;
    }
    else{
        tree.OutputText("test_example_output");
        tree.OutputTreeLevelByLevel();
    }
    total_sch_cost = tree.inOrderTraversal();
    cout<< "Average search cost is " << (double) total_sch_cost/(double) tree.getNodeNum() << '\n';
    cout << "Total number of nodes is " << tree.getNodeNum() << endl;

//For 1-4 p,l,r files
	cout << "Enter any key to calculate test files and print to screen/files: " << endl;
	string press;
	cin >> press;
    ofstream ofs("output_averages");
    ofs << "File\tAverage Search Cost\n";
    char letter[3] = {'p','r','l'};
    for (int i=0; i<3; i++) {
        for (int j=1; j<13; j++) {
            BinarySearchTree tree;
            string path = "./221-A4-test-files/";
            path = path + to_string(j) + letter[i];
            read_file(path,tree);
            int total_sch_cost = tree.inOrderTraversal();
            ofs << to_string(j) + letter[i] << "\t" <<(double) total_sch_cost/(double) tree.getNodeNum() << endl;
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=1; j<5; j++) {
            BinarySearchTree tree;
            string path = "./221-A4-test-files/";
            path = path + to_string(j) + letter[i];
            read_file(path,tree);
            tree.OutputText(to_string(j) + letter[i] + ".txt");
        }
    }
}