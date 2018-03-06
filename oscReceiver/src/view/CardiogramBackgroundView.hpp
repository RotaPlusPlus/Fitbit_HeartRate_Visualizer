//
//  CardiogramBackgroundView.hpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/03.
//

#ifndef CardiogramBackgroundView_hpp
#define CardiogramBackgroundView_hpp

#include "ofMain.h"
#include "HeartRate.hpp"

class CardiogramBackgroundView{
public:
    CardiogramBackgroundView(){};

    void init();
    void update();
    void draw();
    void post_effects();

};

#endif /* CardiogramBackgroundView_hpp */
