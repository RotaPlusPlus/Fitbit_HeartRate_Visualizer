#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    OSCManager::setup();
    FontManager::init();

    HeartRate::init();
    BloodGlucoseLevel::init();

    mLogViewModule.init();
//    mCardiogramBackgroundView.init();
    mElectroCardiogramView.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    OSCManager::update();
    BloodGlucoseLevel::update();

//    mCardiogramBackgroundView.update();
    mElectroCardiogramView.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    OSCManager::draw();
//    mCardiogramBackgroundView.draw();
    mElectroCardiogramView.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
