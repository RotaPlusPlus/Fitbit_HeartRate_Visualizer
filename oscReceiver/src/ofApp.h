#pragma once

#include "ofMain.h"
#include "OSCManager.hpp"
#include "FontManager.hpp"
#include "GlitchManager.hpp"
#include "BackgroundAutoManager.hpp"
#include "BlendmodeManager.hpp"

#include "ElectroCardiogramView.hpp"
#include "CardiogramBackgroundView.hpp"

#include "LogViewModule.hpp"

#include "BloodGlucoseLevel.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    ElectroCardiogramView mElectroCardiogramView;
    CardiogramBackgroundView mCardiogramBackgroundView;
    LogViewModule mLogViewModule;

    BlendmodeManager mBlendmodeManager;
    GlitchManager mGlitchManager;

    ofFbo mFbo;
};
