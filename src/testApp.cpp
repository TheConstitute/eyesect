#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofHideCursor();

	cam1.listDevices();

	cam1.initGrabber(640, 800);
	cam2.setDeviceID(1);
	cam2.initGrabber(640, 800);

	last_new_frame_cam1 = ofGetElapsedTimef();
	last_new_frame_cam2 = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void testApp::update(){
	cam1.update();
	cam2.update();

	if(cam1.isFrameNew()) last_new_frame_cam1 = ofGetElapsedTimef();

	if(cam2.isFrameNew()) last_new_frame_cam2 = ofGetElapsedTimef();

	// reinitialize the cameras when they haven't received a new frame for 5 seconds
	if(ofGetElapsedTimef() - last_new_frame_cam1 > 5.0){
		ofLog() << "haven't heard from cam1 for more than 5 second. re-initing the grabber now.";
		cam1 = ofVideoGrabber();
		cam1.initGrabber(640, 800);
		last_new_frame_cam1 = ofGetElapsedTimef();
	}
	if(ofGetElapsedTimef() - last_new_frame_cam2 > 5.0){
		ofLog() << "haven't heard from cam2 for more than 5 second. re-initing the grabber now.";
		cam2 = ofVideoGrabber();
		cam2.setDeviceID(1);
		cam2.initGrabber(640, 800);
		last_new_frame_cam2 = ofGetElapsedTimef();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	cam1.draw(0,0);
	cam2.draw(640, 0, 640, 800);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
