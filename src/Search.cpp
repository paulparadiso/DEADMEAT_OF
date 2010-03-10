/*
 *  Search.cpp
 *  emptyExample
 *
 *  Created by Paul Paradiso on 2/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Search.h"

Node::Node(ofxVec2f *_pos){
	pos = *_pos;
	parent = NULL;
	child = NULL;
}

Astar::Astar(Mind *_mind){
	minCost = 1.0;
	alpha = 0.5;
	edge = EDGE_SIZE;
	mind = _mind;
}

ofxVec2f getNextMove(){
	Node *target;
	path = openedNodes;
	Node *testNode;
	Node *currentNode;
	while(1){
		target = findLowestF();
		addToClosedList(target);
		for(int x = -1; x < 2; x++){
			for(int y = -1; y < 2; y++){
				if(mind->obs->isWalkable(testNode->getX() + (x * edge), testNode->getY() + (y * edge))){
					if(!isOnClosedList(testNode){
						addToOpenedNodes(testNode);
					} else {
						addToClosedNode(testNode);
				}
			}
		}	
	}
}

void Astar::calculateG(Node *_node){
	_node->setG(1.0 + alpha * (_node->getG() - 1.0));
}

void Astar::calculateH(Node *_node, ofxVec2f *_goal){
	_node->setH(minCost *
		(abs((double)_node->getX() - _goal->x) +
		abs((double)_node->getY() - _goal->y)));
}

Node * Astar::findLowestF(){
	Node *tmp, *solution;
	tmp = solution = openedNodes;
	while(tmp->getChild() != NULL){
		if(tmp->getF() < solution->getF()){
			solution = tmp;
		} 
		tmp = tmp->getChild();
	}
	return solution;
}

void Astar::addToOpenedNodes(Node _node){
	Node *tmp = openedNodes;
	while(tmp->getChild != NULL){
		tmp = tmp->getChild;
	}
	tmp->setChild(_node);
	_node->setParent(tmp);
	_node->setChild(NULL);
}

void Astar::addToClosedNodes(Node _node){
	Node *tmp = closedNodes;
	while(tmp->getChild != NULL){
		tmp = tmp->getChild;
	}
	tmp->setChild(_node);
	_node->setParent(tmp);
	_node->setChild(NULL);
}

void Astar::addToPath(Node _node){
	Node *tmp = path;
	while(tmp->getChild != NULL){
		tmp = tmp->getChild;
	}
	tmp->setChild(_node);
	_node->setParent(tmp);
	_node->setChild(NULL);
}

void Astar::removFromOpenedList(Node *_node){
	Node *tmp
	tmp = _node->getParent();
	tmp->setChild(_node->getChild);
	_node->getChild()->setParent(tmp);
	delete _node;
}
