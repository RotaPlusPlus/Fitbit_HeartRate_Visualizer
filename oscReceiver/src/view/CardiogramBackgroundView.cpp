//
//  CardiogramBackgroundView.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/03.
//

#include "CardiogramBackgroundView.hpp"


void CardiogramBackgroundView::init(){
    shader.load("shaders/shader.vert", "shaders/shader.frag");
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    maskFbo.allocate(w, h);
    fbo.allocate(w, h);
    
    isRGB = false;
}

void CardiogramBackgroundView::update(){
    
    maskFbo.begin();
    ofClear(0, 0, 0, 255);
    ofPushMatrix();
    
    ofDrawRectangle(50,50,ofGetWidth()-100,ofGetHeight()-100);
    
    ofBeginShape();
    for(int i = 0 ; i < HeartRate::heart_rates.size(); i++){
        ofVertex(ofMap(i, 0, MacroManager::max_buffer_size, 50+50,ofGetWidth()-100-50),
                 ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50));
        
        if (ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50) > 0.8 * (ofGetHeight()-100-50)) {
            isRGB = true;
        } else {
            isRGB = false;
        }
    }
    ofEndShape();
    
    
    for(int i = 0 ; i < HeartRate::heart_rates.size(); i++){
        ofDrawCircle(ofMap(i, 0, MacroManager::max_buffer_size, 50+50,ofGetWidth()-100-50),
                     ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50),
                     5);
        ofDrawBitmapString(ofToString(HeartRate::heart_rates.at(i)),
                           ofMap(i, 0, MacroManager::max_buffer_size, 50+50,ofGetWidth()-100-50),
                           ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50));
    }
    
    ofPopMatrix();
    
    maskFbo.end();

}

void CardiogramBackgroundView::draw(){
    
    fbo.begin();
    ofClear(0, 0, 0, 255);
    shader.begin();
    shader.setUniformTexture("image", maskFbo.getTexture(), 1);
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    maskFbo.draw(0, 0);
    shader.end();
    fbo.end();
    
    ofSetColor(255);
    if (isRGB) {
        fbo.draw(0, 0);
    } else {
        maskFbo.draw(0, 0);
    }

}