//
//  GlitchManager.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#ifndef GlitchManager_hpp
#define GlitchManager_hpp

#include "ofMain.h"
#include "PostGlitchComponent.hpp"

class GlitchManager{
private:
    PostGlitchComponent mPostGlitchComponent;
public:
    void init();
    void update();
    void begin(const bool &isAuto);
    void end();
    void generateFX();
    void draw();
    void keyPressed(int key);
};

#endif /* GlitchManager_hpp */
