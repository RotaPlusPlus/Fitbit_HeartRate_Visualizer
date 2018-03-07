//
//  BlendmodeManager.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#ifndef BlendmodeManager_hpp
#define BlendmodeManager_hpp

#include "ofMain.h"

class BlendmodeManager{
private:
    int blendmodeIndex;
public:
    void init();
    void nextIndex();
};
#endif /* BlendmodeManager_hpp */
