#include "Graph.h"
#include "disjointset.h"
#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <algorithm>

using namespace std;

//Runtime: O(n)
void Graph::buildGraph() {
  if((n<0) || (e<0)){
    throw GraphException("either row or column is negative!");
  }
  //implement your code here
	//resize vertices
	AdjacencyList.resize(n);
	//resize edges
	EdgeList.resize(e);
	for(int i = 0; i < AdjacencyList.size(); ++i){
		//create new node with key same as index and value same vertex
		DListNode<Vertex>* tempNode = new DListNode<Vertex>(i, Vertex(i)); 
		//set index of vector equal to new node	
		AdjacencyList[i] = tempNode;
		//set trailer to itself
		AdjacencyList[i]->setTrailer(AdjacencyList[i]);
	}
}

//Runtime: O(1)
void Graph::insertEdge(int i, int j, double w) {
  if(curEdges >= e){
    throw GraphException("edge number is not correct!");
  }
  //implement your code here
  //set next node to be a new node with vertex of j and same for i
  AdjacencyList[i]->getTrailer()->setNext(new DListNode<Vertex>(j, Vertex(j)));
  AdjacencyList[j]->getTrailer()->setNext(new DListNode<Vertex>(i, Vertex(i)));
  //set new trailer to the new node
  AdjacencyList[i]->setTrailer(AdjacencyList[i]->getTrailer()->getNext());
  AdjacencyList[j]->setTrailer(AdjacencyList[j]->getTrailer()->getNext());
  
  //create a new edge and push it into EdgeList
  Edge* tempEdge = new Edge(i,j,w);
  EdgeList.push_back(tempEdge);
  //set the edge of the vertex value equal to the new edge
  AdjacencyList[i]->getTrailer()->getElemt().edge = tempEdge;
  AdjacencyList[j]->getTrailer()->getElemt().edge = tempEdge;
  
  curEdges = curEdges + 1; 
  
  return;
}

//Runtime: O(max(adj(v)))
double Graph::getWeight(int i, int j) {
  //implement your code here
  DListNode<Vertex>* tempNode = AdjacencyList[i];
  //Compare and retrieve weight of edge between vertices
  while(tempNode != NULL){
	if(tempNode -> getElemt().index == j){
		if(tempNode -> getElemt().edge != NULL)
			return tempNode->getElemt().edge->weight;
	}
	tempNode = tempNode->getNext();
  }
  return 0.0;
}

//Runtime: O(n log n)
void Graph::sortEdge() {
  //implement your code here
  sort(EdgeList.begin(), EdgeList.end(),	//sorts weights in ascending order
  [](const Edge *a, const Edge *b) {
	//Account for memory leaks caused by null edges
	if (b==NULL)
		return true;
	if (a==NULL)
		return false;
	return a->weight < b->weight;
  });

}

//Runtime: O(m log n)
double Graph::MSTAlgo() {
  //implement your code here
  double totalWeight = 0;
  DisjointSet<Vertex> VertSet(AdjacencyList.size());  //VertSet = DisjointSet
  for (int i = 0; i < AdjacencyList.size(); i++){
	VertSet.MakeSet(i, AdjacencyList[i]->getElemt());
  }
  sortEdge();  //sort edges in EdgeList by weight, ascending
  for (int i = 0; i < EdgeList.size(); i++){  //for each edge in EdgeList:
  
	if (EdgeList[i]==NULL)	//accounts for empty edges to avoid segmentation fault
		continue;
	
	DListNode<Vertex> NodeA = *VertSet.FindSet(EdgeList[i]->vertex_i);
	DListNode<Vertex> NodeB = *VertSet.FindSet(EdgeList[i]->vertex_j);
	
	if ((VertSet.FindSet(EdgeList[i]->vertex_i)) != (VertSet.FindSet(EdgeList[i]->vertex_j))){
		MST.push_back(EdgeList[i]);	//adds edge between vertices i and j to MST
		totalWeight += EdgeList[i]->weight;
		VertSet.Union(NodeA, NodeB);
	}
  }
  return totalWeight;
}


  