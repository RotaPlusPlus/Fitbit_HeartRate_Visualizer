//
//  ElectroCardiogramView.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/01.
//

#ifndef ElectroCardiogramView_hpp
#define ElectroCardiogramView_hpp

#include "ofMain.h"
#include "HeartRate.hpp"

class ElectroCardiogramView{
public:
    vector <ofVec2f>positions;

    ElectroCardiogramView(){};
    void init();
    void update();
    void draw();

    // this is for blood animation
    ofShader bl_shader;
    ofFbo blood;
    ofFbo blood_mask;
};

#endif /* ElectroCardiogramView_hpp */
