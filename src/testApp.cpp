#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	obstacles = new Obstacles();
	obstacles->makeObstacles("/Users/pp/obstacles.txt");
	player = new Player(obstacles);
	serial.setup("/dev/tty.usbserial-A600aimy",115200);
	commandMap.insert(make_pair("left,walk",'k'));
	commandMap.insert(make_pair("right,walk",'l'));
	commandMap.insert(make_pair("up,walk",'m'));
	commandMap.insert(make_pair("down",'f'));
	commandMap.insert(make_pair("shock,walk",'j'));
	//ofSetFrameRate(10);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0,0,255);
	for(int i = 0; i < ofGetWidth(); i += 20){
		//ofLine(i,0,i,ofGetHeight());
		for(int j = 0; j < ofGetHeight(); j += 20){
			ofFill();
			ofEllipse(i + 10, j + 10, 5,5);
		}
	}
	obstacles->draw();
	player->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

