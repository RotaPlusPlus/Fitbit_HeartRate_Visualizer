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
    NumberViewModule(){};
    void init();
    void update();
    void draw();
};

#endif /* NumberViewModule_hpp */
