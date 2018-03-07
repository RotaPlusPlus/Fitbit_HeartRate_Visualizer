#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofSetupOpenGL(1024,768,OF_WINDOW);            // <-------- setup the GL context

//    ofGLFWWindowSettings settings;
//    settings.glVersionMajor = 2;
//    settings.glVersionMinor = 1;
////    settings.setGLVersion(2,1);
//    settings.width = 1024;
//    settings.height = 768;
//    ofCreateWindow(settings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
