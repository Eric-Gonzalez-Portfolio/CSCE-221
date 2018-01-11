#pragma once

#include "TemplateDoublyLinkedList.h"
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Disjoint Set
template <typename T>
class DisjointSet {
private:
	vector<DListNode<T>*> nodeLocator;
public:
	DListNode<T>* FindSet(DListNode<T> node) { return node.getRepresentative(); }	//Worst Runtime: O(n), Best Runtime: O(1)
	DListNode<T>* FindSet(int nodeKey) { return nodeLocator[nodeKey-1]->getRepresentative(); }	//Worst Runtime: O(n), Best Runtime: O(1)
	
//Constructor
DisjointSet(int n){
	nodeLocator.resize(n);
	for(int i = 0; i<nodeLocator.size(); i++)
		nodeLocator[i] = NULL;
}

//Returns the value of the vector nodeLocator
vector<DListNode<T>*> getNodeLocator() const{
	return nodeLocator;
}

//Forms a new set of values
//Best & Worst Runtime: O(1)
DListNode<T>* MakeSet(int key, T node){
	DListNode<T>* newNode = new DListNode<T>(key, node);
	newNode->setRepresentative(newNode);
	newNode->setTrailer(newNode);
	nodeLocator[key-1] = newNode;
	return newNode;
}

//Combines the values of two separate sets
//Worst Runtime: O(n)
//Best Runtime: O(log n)
DListNode<T>* Union(DListNode<T> nodeI, DListNode<T> nodeJ){
	DListNode<T>* Node1 = FindSet(nodeI);
	DListNode<T>* Node2 = FindSet(nodeJ);

	if(nodeI.getListSize() > nodeJ.getListSize()){
		Node1->getTrailer()->setNext(Node2);
		Node2->setPrevious(Node1->getTrailer());
		Node1->setTrailer(Node2->getTrailer());
		Node2->setTrailer(NULL);
		while(Node2 != NULL){
			Node2->setRepresentative(Node1);
			Node2 = Node2->getNext();
		}
		Node1->setListSize(nodeI.getListSize() + nodeJ.getListSize());
	}
	
	else if(nodeI.getListSize() < nodeJ.getListSize()){
		Node2->getTrailer()->setNext(Node1);
		Node1->setPrevious(Node2->getTrailer());
		Node2->setTrailer(Node1->getTrailer());
		Node1->setTrailer(NULL);
		while(Node1 != NULL){
			Node1->setRepresentative(Node2);
			Node1 = Node1->getNext();
		}
		Node2->setListSize(nodeI.getListSize() + nodeJ.getListSize());
	}
	
	else{
		if (Node1->getKey() < Node2->getKey()){
			Node1->getTrailer()->setNext(Node2);
			Node2->setPrevious(Node1->getTrailer());
			Node1->setTrailer(Node2->getTrailer());
			Node2->setTrailer(NULL);
			while(Node2 != NULL){
				Node2->setRepresentative(Node1);
				Node2 = Node2->getNext();
			}
			Node1->setListSize(nodeI.getListSize() + nodeJ.getListSize());
		}
	}
	
}

//Destructor
~DisjointSet(){
	for (auto i = 0; i < nodeLocator.size(); i++)
		delete nodeLocator[i];
}
};

//Overloaded << operator to allow proper output
template <typename T>
ostream& operator<<(ostream& out, const DisjointSet<T>& ds) {
	for(int i=0; i<ds.getNodeLocator().size(); i++){
		DListNode<T>* node = ds.getNodeLocator()[i];
		if (node -> getKey() == node->getRepresentative()->getKey()){
			out << "Set " << i << " { rep=" << node->getRepresentative()->getElemt() << ", trail=" << node->getTrailer()->getElemt() << ", size=" << node->getListSize() << " } " << "{ ";
			while(node!=NULL){
				out << node->getElemt() << " ";
				node = node->getNext();
			}
			out << "}";
			cout << endl;
		}
	}
	return out;
}