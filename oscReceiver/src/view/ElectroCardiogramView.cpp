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
    ofSetVerticalSync(true);

    frame_margin = 50;
    frame_height1 = (ofGetHeight() - frame_margin*3)/5*2;
    frame_height2 = (ofGetHeight() - frame_margin*3)/5*2;
    frame_width = ofGetWidth()-frame_margin*2;

    tmp_heart_rate1 = 0;
    tmp_heart_rate2 = 0;

    setupWaveform();

    // ===============
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
    // ===============

    heartRateView.init(ofVec2f(ofGetWidth()/7*5,ofGetHeight()/7*2));
    bglsView.init(ofVec2f(ofGetWidth()/7*5,ofGetHeight()/7*4));
}

void ElectroCardiogramView::update(){

    // Adjust Positions Array num of element
    if(positions.size()!=HeartRate::heart_rates.size()){
        for(int i = 0 ; i < HeartRate::heart_rates.size(); i++){
            if(positions.size() < i)
                positions.push_back(ofVec2f());
        }
    }

    frame_height1 = (ofGetHeight() - frame_margin*3)/5*2;
    frame_height2 = (ofGetHeight() - frame_margin*3)/5*2;
    frame_width = ofGetWidth()-frame_margin*2;
    updateWaveform();

    // Update Cardigogram Elements Position
    for(int i = 0 ; i < positions.size(); i++){
        positions.at(i) = ofVec2f(ofMap(i, 0, MacroManager::max_buffer_size, frame_margin*2,ofGetWidth()-frame_margin*3),
                                  ofMap(HeartRate::heart_rates.at(i), MacroManager::heart_rate_max, MacroManager::heart_rate_min, frame_margin*2, frame_height1-frame_margin));
    }
}

void ElectroCardiogramView::draw(){

    // ======================
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
    // ======================

    ofSetColor(255);
    ofPushMatrix();
    ofDrawRectangle(frame_margin, frame_margin, frame_width, frame_height1);

    ofBeginShape();

    for(int i = 0 ; i < positions.size(); i++){
        ofVertex(positions.at(i).x,positions.at(i).y);
    }
    ofEndShape();


    for(int i = 0 ; i < positions.size(); i++){
        ofDrawCircle(positions.at(i).x, positions.at(i).y, 5);
        FontManager::drawBigString(ofToString(HeartRate::heart_rates.at(i)),
                           positions.at(i).x,
                           positions.at(i).y);
    }

    ofPopMatrix();
    drawWaveform();

    if(HeartRate::heart_rates.size() > 0){
        if(HeartRate::heart_rates.back()>=100){
            heartRateView.draw3dig(ofToString(HeartRate::heart_rates.back()));
        }else{
            heartRateView.draw2dig(ofToString(HeartRate::heart_rates.back()));
        }
    }else{
        heartRateView.drawNaN("NaN");
    }

    if(BloodGlucoseLevel::bgls.back()>0){
        if(BloodGlucoseLevel::bgls.back()>=100){
            bglsView.draw3dig(ofToString(BloodGlucoseLevel::bgls.back()));
        }else{
            bglsView.draw2dig(ofToString(BloodGlucoseLevel::bgls.back()));
        }
    }else{
        bglsView.drawNaN("NaN");
    }
}

//--------------------------------------------------------------
void ElectroCardiogramView::setupWaveform(){


    originX = frame_margin;
    originY = frame_margin*2 + frame_height1;
    float stripWidth    = frame_width;
    float stripHeight    = frame_height2;
    float yMargin        = 5;
    float stripXPos        = originX;
    float stripYPos        = originY;
    float noiseStep        = 0.1; // 0.001

    noiseDataStrip.x = stripXPos;
    noiseDataStrip.y = stripYPos;
    noiseDataStrip.width = stripWidth;
    noiseDataStrip.height = stripHeight;
    noiseDataStrip.noiseStep = noiseStep;
    for (int j=0; j< NOISE_DATA_STRIP_LENGTH; j++){
        noiseDataStrip.data[j] = 0.1;
    }
    stripYPos += stripHeight + yMargin;
}

//--------------------------------------------------------------
void ElectroCardiogramView::updateWaveform(){

    noiseDataStrip.width = frame_width;
    noiseDataStrip.height = frame_height2;


    float *data = (float *)noiseDataStrip.data;
    for (int j=(NOISE_DATA_STRIP_LENGTH-1); j>0; j--){
        data[j] = data[j-1];
    }

    // ノイズ
    float noiseStep = noiseDataStrip.noiseStep;
    float t = ofGetElapsedTimeMillis()*2 * noiseStep/10.0; // パーリンノイズを荒くしたい 50
    data[0] = ofNoise(t) * 0.1;
    //        data[0] = ofRandom(0.1);
    if (HeartRate::heart_rates.size() > 0){
        float begin_heart_rate = HeartRate::heart_rates.at(0);
        float current_heart_rate = HeartRate::heart_rates.at(HeartRate::heart_rates.size()-1);

        if (tmp_heart_rate1 != begin_heart_rate || tmp_heart_rate2 != current_heart_rate){
            data[0] -= ofMap(current_heart_rate, 80, 100, 0, 1.0);
            cout << "heart rate : " <<  current_heart_rate << endl;

            tmp_heart_rate1 = begin_heart_rate;
            tmp_heart_rate2 = current_heart_rate;
        }
    }
}


//--------------------------------------------------------------
void ElectroCardiogramView::drawWaveform(){

    float stackBottom = 0;

    float x = noiseDataStrip.x;
    float y = noiseDataStrip.y;
    float w = noiseDataStrip.width;
    float h = noiseDataStrip.height;
    stackBottom = y+h;

    float noiseStep = noiseDataStrip.noiseStep;
    float *data = (float *) (noiseDataStrip.data);
    drawNoise (x,y, w,h, noiseStep, data);

    ofSetColor(255);

}


//--------------------------------------------------------------
void ElectroCardiogramView::drawNoise (float x, float y, float width, float height, float dt, float *data){

    ofSetColor(255);

    ofPushMatrix();
    ofDisableSmoothing();
    ofEnableAlphaBlending();
    ofTranslate(x, y, 0);

    ofEnableSmoothing();

    // 波形を描く
    ofNoFill();
    ofBeginShape();
    for (int i=0; i<NOISE_DATA_STRIP_LENGTH; i++){
        float px = ofMap(i, 0,(NOISE_DATA_STRIP_LENGTH-1), width, 0);
        float py = height * (data[i]+0.8);
        ofVertex(px, py+frame_margin);
    }
    ofEndShape(false);

    // 外枠を描く
    ofDisableSmoothing();
    ofNoFill();
    ofDrawRectangle(0,0, width, height+100);

    ofPopMatrix();
}


