//
//  LogViewModule.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/03.
//

#include "LogViewModule.hpp"

void LogViewModule::init(){
    bool logToConsole = true;
    bool logToScreen = true;

    //Log to console on screen, write log to data / log folder
    ofSetLoggerChannel(ofxSuperLog::getLogger(logToConsole,   logToScreen, "logs"));

    //Display on screen
    ofxSuperLog::getLogger()->setMaximized(true);
}

void LogViewModule::update(){
    
}

void LogViewModule::draw(){

}
