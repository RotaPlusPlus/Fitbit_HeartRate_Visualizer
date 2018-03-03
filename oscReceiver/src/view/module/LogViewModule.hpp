//
//  LogViewModule.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/03.
//

#ifndef LogViewModule_hpp
#define LogViewModule_hpp

#include "ofMain.h"
#include "HeartRate.hpp"
#include "ofxSuperlog.h"

class LogViewModule{
public:
    LogViewModule(){};
    void init();
    void update();
    void draw();
};

#endif /* LogViewModule_hpp */
