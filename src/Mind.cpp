/*
 *  Mind.cpp
 *  emptyExample
 *
 *  Created by Paul Paradiso on 2/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Mind.h"

Mind::Mind(Player *_p, Obstacles *_o){
	body = _p;
	obs = _o;
	astar = new Astar(this);
}

void Mind::update(){
	while(checkHeading() < 0){
		int nH = (body->heading + 1) % 360;
		body->heading = nH;
	}
	ofxVec2f futurePos;
	futurePos.x = body->pos.x + (cos(ofDegToRad(body->heading)) * 5);
	futurePos.y = body->pos.y + (sin(ofDegToRad(body->heading)) * 5);
	body->pos = futurePos;
}

int Mind::checkHeading(){
	vector<ofxVec2f>::iterator vecIter;
	for(vecIter = obs->allPoints.begin();vecIter != obs->allPoints.end(); vecIter++){
		ofxVec2f tt = *(vecIter);
		ofxVec2f *newPos;
		newPos = new ofxVec2f((cos(ofDegToRad(body->heading)) * body->length),(sin(ofDegToRad(body->heading) )* body->length));
		float g = newPos->distance(tt);
		cout << "New G = " << g << "New Pos = " << newPos->x << ", " << newPos->y << endl;
		if (g < body->length + obs->edge){
			cout << "COLLISION - " << g << endl;
			return -1;
		}
	}
	ofxVec2f futurePos;
	futurePos.x = body->pos.x + (cos(ofDegToRad(body->heading)) * body->length);
	futurePos.y = body->pos.y + (sin(ofDegToRad(body->heading)) * body->length);
	if(futurePos.x < body->length || futurePos.x > ofGetWidth() - body->length) return -1;
	if(futurePos.y < body->length || futurePos.y > ofGetHeight() - body->length) return -1;
	return 1;
}