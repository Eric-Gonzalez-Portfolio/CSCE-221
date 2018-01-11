#include "Graph.h"
#include "TemplateDoublyLinkedList.h"
#include <iostream>

using namespace std;

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
  