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
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    bl_shader.load("shaders/blood.vert", "shaders/blood.frag");
    blood.allocate(w, h, GL_RGBA, 8);
    
    blood_mask.allocate(w, h, GL_RGBA, 8);
    blood_mask.begin();
    {
        ofClear(0, 0, 0, 255);
    }
    blood_mask.end();

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
    
    blood.begin();
    //    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    bl_shader.begin();
    bl_shader.setUniform1f("u_time", ofGetElapsedTimef());
    bl_shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    blood_mask.draw(0, 0);
    bl_shader.end();
    blood.end();
    
    blood.draw(0, 0);

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


