//
//  PostGlitchComponent.cpp
//  oscReceiver
//
//  Created by HirokiNaganuma on 2018/03/07.
//

#include "PostGlitchComponent.hpp"

void PostGlitchComponent::init(){
    myFbo.allocate(ofGetWidth(), ofGetHeight());
    myGlitch.setup(&myFbo);
    for(int i = 0 ;i<=5 ;i++){
        shaderSwitch[i] = false;
    }
}

void PostGlitchComponent::begin(const bool &isAuto){
    myFbo.begin();
    if(isAuto){
        ofClear(0, 255);
    }else{
    }
}

void PostGlitchComponent::end(){
    myFbo.end();
    shaderIndex=ofRandom(0,7);
    if(shaderSwitch[2] == true){
        myGlitch.setFx(OFXPOSTGLITCH_GLOW            , true);
    }else{
        myGlitch.setFx(OFXPOSTGLITCH_GLOW            , false);
    }

    if(shaderSwitch[5] == true){
        myGlitch.setFx(OFXPOSTGLITCH_SUPER_GLOW        , true);
    }else{
        myGlitch.setFx(OFXPOSTGLITCH_SUPER_GLOW        , false);
    }

    if(ofGetElapsedTimeMillis()%1000<300){

        if(shaderSwitch[1]==true){
            if (shaderIndex == 1) myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE      ,true);
            if (shaderIndex == 3) myGlitch.setFx(OFXPOSTGLITCH_SHAKER           ,true);
            if (shaderIndex == 4) myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST  ,true);
        }else{
            myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , false);
            myGlitch.setFx(OFXPOSTGLITCH_SHAKER         , false);
            myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
        }

        if(shaderSwitch[3] ==true){
            if (shaderIndex == 5)myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , true);
            if (shaderIndex == 6)myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN        , true);
        }else{
            myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , false);
            myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN        , false);
        }
        if(shaderSwitch[4] ==true){
            myGlitch.setFx(OFXPOSTGLITCH_INVERT            , true);
        }else{
            myGlitch.setFx(OFXPOSTGLITCH_INVERT            , false);
        }
    }else{
        if (shaderIndex == 1) myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , false);
        if (shaderIndex == 3) myGlitch.setFx(OFXPOSTGLITCH_SHAKER        , false);
        if (shaderIndex == 4) myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
        if (shaderIndex == 5)myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , false);
        if (shaderIndex == 6)myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN        , false);
        if (shaderIndex >6)myGlitch.setFx(OFXPOSTGLITCH_INVERT            , false);
    }

}

void PostGlitchComponent::generateFx(){
    myGlitch.generateFx();
}

void PostGlitchComponent::draw(const float &x,const float &y,const float &w,const float &h){
    glColor3f( 1.0, 1.0, 1.0 );
    myFbo.draw(x,y,w,h);
}

void PostGlitchComponent::keyPressed(int key){

    if(key == '1'){ //色の分離
        shaderSwitch[1] = !shaderSwitch[1];
    }

    if(key == '2'){ //常にglow
        shaderSwitch[2] = !shaderSwitch[2];
    }

    if(key == '3'){ //CutSliderも込み
        shaderSwitch[3] = !shaderSwitch[3];
    }

    if(key == '4'){ //Invert込み
        shaderSwitch[4] = !shaderSwitch[4];
    }

    if(key == '5'){ //Super Glow
        shaderSwitch[5] = !shaderSwitch[5];
    }

    if(key == '0'){ //Glitchなし
        for(int i = 0 ;i<5 ;i++){
            shaderSwitch[i] = false;
        }
    }


    if(key == 't'){
        myFbo.begin();
        ofClear(0,255);
        myFbo.end();
    }
}

