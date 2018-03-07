//
//  BackgroundAutoManager.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#ifndef BackgroundAutoManager_hpp
#define BackgroundAutoManager_hpp

#include "ofMain.h"

class BackgroundAutoManager{
private:

public:
    static bool isBackAuto;
    static void init();
    static void begin();
    static void keyPressed(int key);
};

#endif /* BackgroundAutoManager_hpp */
