/*
 *  Player.cpp
 *  emptyExample
 *
 *  Created by Paul Paradiso on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Player.h"

Player::Player(Obstacles *_o){
	setPos(50,ofGetHeight()/2);
	setColor(255,0,0);
	setSize(20);
	setHeading(0);
	width = 40;
	length = 40;
	setShape();
	obs = _o;
	mind = new Mind(this,obs);
}

void Player::draw(){
	mind->update();
	ofSetColor(color.x, color.y, color.z);
	ofFill();
	ofCircle(pos.x, pos.y, 10);
	setShape();
	//ofLine(pos.x,pos.y,pos.x + (cos(ofDegToRad(heading)) * length), pos.y + (sin(ofDegToRad(heading)) * length));
	//ofLine(leftHand.x,leftHand.y,rightHand.x,rightHand.y);
	ofNoFill();
	ofTriangle(head.x,head.y, rightHand.x,rightHand.y,leftHand.x,leftHand.y);
}

void Player::setShape(){
	head.set(pos.x + (cos(ofDegToRad(heading)) * length), pos.y + (sin(ofDegToRad(heading)) * length));
	rightHand.set(pos.x + (cos(ofDegToRad(heading + 90)) * width/2), pos.y + (sin(ofDegToRad(heading +90)) * width/2));
	leftHand.set(pos.x + (cos(ofDegToRad(heading + 270)) * width/2), pos.y + (sin(ofDegToRad(heading +270)) * width/2));
}

void Player::setPos(float _x, float _y){
	pos.set(_x,_y);
}

ofxVec2f * Player::getPos(){
	return &pos;
}

void Player::setColor(float _r, float _g, float _b){
	color.set(_r,_g,_g);
}

void Player::setSize(int _s){
	size = _s;
}

ofxVec2f Player::getPos(){
	return pos;
}

void Player::setHeading(ofSerial *_ser){
	string newAngle;
	unsigned char newByte = 0;
	_ser->writeByte('e');
	ofSleepMillis(100);
	while(newByte != '\n'){
		newByte = _ser->readByte();
		if(newByte != 0xff){
			newAngle.append((char *)&newByte,1);
		}
	}
	istringstream stream(newAngle);
	stream >> angle;
	newAngle.clear();
}

int Player::getHeading(){
	return heading;
}

int Player::getWidth(){
	return width;
}

int Player::getLength(){
	return length;
}
