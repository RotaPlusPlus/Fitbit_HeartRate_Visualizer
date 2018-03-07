//
//  BackgroundAutoManager.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#include "BackgroundAutoManager.hpp"

bool BackgroundAutoManager::isBackAuto;


void BackgroundAutoManager::init(){
    isBackAuto = true;
}

void BackgroundAutoManager::begin(){
    if(isBackAuto){
        ofClear(0, 0, 0, 255);
    }
}
void BackgroundAutoManager::keyPressed(int key){
    isBackAuto = !isBackAuto;
    ofSetBackgroundAuto(isBackAuto);
}
