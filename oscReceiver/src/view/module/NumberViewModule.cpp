//
//  NumberViewModule.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#include "NumberViewModule.hpp"

void NumberViewModule::init(ofVec2f pos){
    this->position = pos;
    ofSetCircleResolution(64);
}

void NumberViewModule::update(){
    
}

void NumberViewModule::draw3dig(string arg){
    ofPushMatrix();
    ofTranslate(position);
    ofDrawCircle(-50, -50, 100);
    FontManager::drawString(ofToString(arg),-145,-7);
    ofPopMatrix();
}

void NumberViewModule::draw2dig(string arg){
    ofPushMatrix();
    ofTranslate(position);
    ofDrawCircle(-50, -50, 100);
    FontManager::drawString(ofToString(arg),-128,-7);
    ofPopMatrix();
}

void NumberViewModule::drawNaN(string arg){
    ofPushMatrix();
    ofTranslate(position);
    ofDrawCircle(-50, -50, 100);
    FontManager::drawGuiString(ofToString(arg),-145,-15);
    ofPopMatrix();
}
