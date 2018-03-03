//
//  ElectroCardiogramView.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#include "ElectroCardiogramView.hpp"


void ElectroCardiogramView::init(){
    ofBackground(0);
    ofNoFill();
    ofSetLineWidth(1.0);
    ofSetColor(255);
}

void ElectroCardiogramView::update(){

    // Adjust Positions Array num of element
    if(positions.size()!=HeartRate::heart_rates.size()){
        for(int i = 0 ; i < HeartRate::heart_rates.size(); i++){
            if(positions.size() < i)
                positions.push_back(ofVec2f());
        }
    }

    // Update Cardigogram Elements Position
    for(int i = 0 ; i < positions.size(); i++){
        positions.at(i) = ofVec2f(ofMap(i, 0, MacroManager::max_buffer_size, 50+50,ofGetWidth()-100-50),
                                  ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50));
    }
}

void ElectroCardiogramView::draw(){
    ofPushMatrix();
    ofDrawRectangle(50,50,ofGetWidth()-100,ofGetHeight()-100);

    ofBeginShape();
    for(int i = 0 ; i < positions.size(); i++){
        ofVertex(positions.at(i).x,positions.at(i).y);
    }
    ofEndShape();

    for(int i = 0 ; i < positions.size(); i++){
        ofDrawCircle(positions.at(i).x, positions.at(i).y, 5);
        ofDrawBitmapString(ofToString(HeartRate::heart_rates.at(i)),
                           positions.at(i).x,
                           positions.at(i).y);
    }
    ofPopMatrix();
}


