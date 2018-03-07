//
//  BlendmodeManager.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#include "BlendmodeManager.hpp"

void BlendmodeManager::init(){
    blendmodeIndex = 0;
}

void BlendmodeManager::nextIndex(){
    blendmodeIndex = (blendmodeIndex+1)%5;
    switch (blendmodeIndex) {
        case 0:
            ofEnableBlendMode(OF_BLENDMODE_ADD);
            cout << "OF_BLENDMODE_ADD" << endl;
            break;
        case 1:
            ofEnableBlendMode(OF_BLENDMODE_ALPHA);
            cout << "OF_BLENDMODE_ALPHA" << endl;
            break;
        case 2:
            ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
            cout << "OF_BLENDMODE_SUBTRACT" << endl;
            break;
        case 3:
            ofEnableBlendMode(OF_BLENDMODE_SCREEN);
            cout << "OF_BLENDMODE_SCREEN" << endl;
            break;
        case 4:
            ofEnableBlendMode(OF_BLENDMODE_DISABLED);
            cout << "OF_BLENDMODE_DISABLED" << endl;
            break;
        default:
            break;
    }
}
