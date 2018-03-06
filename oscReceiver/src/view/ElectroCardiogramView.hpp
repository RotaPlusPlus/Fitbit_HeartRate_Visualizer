//
//  ElectroCardiogramView.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#ifndef ElectroCardiogramView_hpp
#define ElectroCardiogramView_hpp

#define NOISE_DATA_STRIP_LENGTH 1000 //256

#include "ofMain.h"
#include "HeartRate.hpp"

struct NoiseDataStrip {
    float data[NOISE_DATA_STRIP_LENGTH];
    float x;
    float y;
    float width;
    float height;
    float noiseStep;
};

class ElectroCardiogramView{
public:
    
    NoiseDataStrip noiseDataStrip;
    vector <ofVec2f>positions;

    ElectroCardiogramView(){};
    void init();
    void update();
    void draw();

    void setupWaveform();
    void drawWaveform();
    void updateWaveform();

    float frame_margin;
    float frame_height1;
    float frame_height2;
    float frame_width;

    float originX;
    float originY;

    void drawNoise (float x, float y, float width, float height, float dt, float *data);
    float summedNoiseData[NOISE_DATA_STRIP_LENGTH];
    float tmp_heart_rate1; // heart_rates の0番目の数値を保存
    float tmp_heart_rate2; // heart_rates のsize()-1番目の数値を保存
};

#endif /* ElectroCardiogramView_hpp */
