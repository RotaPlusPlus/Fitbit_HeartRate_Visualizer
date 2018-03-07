//
//  GlitchManager.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#include "GlitchManager.hpp"

void GlitchManager::init(){
    mPostGlitchComponent.init();
}

void GlitchManager::update(){
}

void GlitchManager::begin(const bool &isAuto){
    mPostGlitchComponent.begin(isAuto);
}

void GlitchManager::end(){
    ofPushStyle();
    mPostGlitchComponent.end();
    mPostGlitchComponent.generateFx();
    ofPopStyle();
}

void GlitchManager::draw(){
    ofPushStyle();
    mPostGlitchComponent.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
}

void GlitchManager::generateFX(){

}

void GlitchManager::keyPressed(int key){
    mPostGlitchComponent.keyPressed(key);
}
