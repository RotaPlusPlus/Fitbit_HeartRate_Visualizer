//
//  CardiogramBackgroundView.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/03.
//

#include "CardiogramBackgroundView.hpp"


void CardiogramBackgroundView::init(){
    myFbo.allocate(1024, 1024);
    myGlitch.setup(&myFbo);
}

void CardiogramBackgroundView::update(){

    myFbo.begin();
    ofClear(0, 0, 0,255);

    ofPushMatrix();

    ofDrawRectangle(50,50,ofGetWidth()-100,ofGetHeight()-100);

    ofBeginShape();
    for(int i = 0 ; i < HeartRate::heart_rates.size(); i++){
        ofVertex(ofMap(i, 0, MacroManager::max_buffer_size, 50+50,ofGetWidth()-100-50),
                 ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50));

        // post_effect処理。高さの８割を閾値に設定して、それを超えるとeffectをtrueにする。
        if (ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, 50+50, ofGetHeight()-100-50) > 0.8 * (ofGetHeight()-100-50) ) {
            //            myGlitch.setFx(OFXPOSTGLITCH_INVERT            , true);
            //            myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , true);
            //            myGlitch.setFx(OFXPOSTGLITCH_GLOW            , true);
        } else {
            //            myGlitch.setFx(OFXPOSTGLITCH_INVERT            , false);
            //            myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , false);
            //            myGlitch.setFx(OFXPOSTGLITCH_GLOW            , false);
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
    myFbo.end();
}

void CardiogramBackgroundView::draw(){

    myGlitch.generateFx();
    ofSetColor(255);
    myFbo.draw(0, 0);
}
