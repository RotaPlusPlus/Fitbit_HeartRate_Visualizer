//
//  BloodGlucoseLevel.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#ifndef BloodGlucoseLevel_hpp
#define BloodGlucoseLevel_hpp

#include "ofMain.h"
#include "MacroManager.hpp"

class BloodGlucoseLevel{
public:
    BloodGlucoseLevel(){};
    static vector<int> bgls;
    static void init();
    static void update();
};

#endif /* BloodGlucoseLevel_hpp */
