/*
 *  Search.h
 *  emptyExample
 *
 *  Created by Paul Paradiso on 2/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _SEARCH_H_
#define _SEARCH_H_

#include "ofxVectorMath.h"
#include "Obstacles.h"
#include "Mind.h"

class Node{
public:
	Node();
	Node* getParent();
	void setParent(Node *_p);
	int getF();
	int getG();
	int getH();
	void setF(int _f);
	void setG(int _g);
	void setH(int _h);
	void setPos(ofxVec2f _pos);
	ofxVec2f getPos();
	float getX();
	float getY();
	Node *parent;
	Node *child;
	ofxVec2f pos;
	int f,g,h;
};



class Astar{
public:
	Astar();
	ofxVec2f getNextMove();
	ofxVec2f findBest();
	void calculateG(Node *_node);
	void calculateH(Node *_node, ofxVec2f *_goal);
	void addToOpenedNodes(Node *_node);
	void addToClosedNodes(Node *_node);
	void removeFromOpenedNodes(Node *_node);
	void removeFromClosedNodes(Node *_node);
	Node *openedNodes;
	Node *closedNodes;
	Node *currOpenedNode;
	Node *currClosedNode;
	Node *path;
	ofxVec2f currPos;
	int edge;
	double minCost;
	double alpha;
};

#endif
