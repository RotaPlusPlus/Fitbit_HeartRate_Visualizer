//
//  BloodGlucoseLevel.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#include "BloodGlucoseLevel.hpp"

vector<int> BloodGlucoseLevel::bgls;

void BloodGlucoseLevel::init(){
    for(int i = 0; i < MacroManager::num_of_bgls ; i++){
        BloodGlucoseLevel::bgls.push_back(ofRandom(MacroManager::bgls_min,MacroManager::bgls_max));
    }
}

void BloodGlucoseLevel::update(){
    // 1000msに一回値更新
    if(int(ofGetElapsedTimeMillis())%1000 < 10){
        BloodGlucoseLevel::bgls.push_back(ofRandom(MacroManager::bgls_min,MacroManager::bgls_max));
        BloodGlucoseLevel::bgls.erase(BloodGlucoseLevel::bgls.begin());
    }
}
