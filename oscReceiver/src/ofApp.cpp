#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    OSCManager::setup();
    FontManager::init();

    BackgroundAutoManager::init();
    mFbo.allocate(ofGetWidth(), ofGetHeight());
    mGlitchManager.init();
    mBlendmodeManager.init();

    HeartRate::init();
    BloodGlucoseLevel::init();

    mLogViewModule.init();
    mCardiogramBackgroundView.init();
    mElectroCardiogramView.init();
}

//--------------------------------------------------------------
void ofApp::update(){
    OSCManager::update();
    BloodGlucoseLevel::update();

    mCardiogramBackgroundView.update();
    mElectroCardiogramView.update();
    mGlitchManager.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    OSCManager::draw();
    mFbo.begin();
    BackgroundAutoManager::begin();
    mGlitchManager.begin(BackgroundAutoManager::isBackAuto);

    mCardiogramBackgroundView.draw();
    mElectroCardiogramView.draw();

    mGlitchManager.end();
    mGlitchManager.draw();
    mFbo.end();

    mFbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    mGlitchManager.keyPressed(key);
    if(key == ' '){
        BackgroundAutoManager::keyPressed(key);
        ofClear(0,255);
    }
    if(key == OF_KEY_LEFT_SHIFT){
        mBlendmodeManager.nextIndex();
    }
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
