#include<cstddef>
// to define NULL


using namespace std;

class BinaryNode {
private:
    friend class BinarySearchTree;
    int element;
    int SearchCost;
    BinaryNode *left, *right;
public:
    BinaryNode(int el = 0, int search_cost=0, BinaryNode *lt = NULL, BinaryNode *rt = NULL) ://constructor
		element(el),SearchCost(search_cost), left(lt), right(rt){}// functions
    BinaryNode *getLeft() {return left; }
    BinaryNode *getRight() {return right; }
};