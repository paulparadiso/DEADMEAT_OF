/*
 *  Mind.h
 *  emptyExample
 *
 *  Created by Paul Paradiso on 2/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _MIND_H_
#define _MIND_H_

#include "Player.h"
#include "Search.h"
#include "Obstacles.h"
#include "ofMain.h"

class Player;

class Mind{
public:
	Mind(Player *_p, Obstacles *_o);
	void update();
	int getHeading();
	int checkHeading();
	Obstacles *obs;
	Player *body;
	Astar *astar;
};

#endif
