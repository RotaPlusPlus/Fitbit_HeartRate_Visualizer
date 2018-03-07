//
//  PostGlitchComponent.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#ifndef PostGlitchComponent_hpp
#define PostGlitchComponent_hpp

#include "ofMain.h"
#include "ofxPostGlitch.h"

class PostGlitchComponent{
private:
    ofFbo            myFbo;
    ofxPostGlitch    myGlitch;
    int shaderIndex;
    bool shaderSwitch[6];
public:
    void init();
    void begin(const bool &isAuto);
    void end();
    void keyPressed(int key);
    void draw(const float &x,const float &y,const float &w,const float &h);
    void generateFx();
};

#endif /* PostGlitchComponent_hpp */
