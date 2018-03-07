//
//  NumberViewModule.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#ifndef NumberViewModule_hpp
#define NumberViewModule_hpp

#include "ofMain.h"
#include "HeartRate.hpp"
#include "BloodGlucoseLevel.hpp"
#include "FontManager.hpp"

class NumberViewModule{
public:
    ofVec2f position;
    NumberViewModule(){};
    void init(ofVec2f pos);
    void update();
    void draw3dig(string arg, string name);
    void draw2dig(string arg, string name);
    void drawNaN(string arg);
};

#endif /* NumberViewModule_hpp */
