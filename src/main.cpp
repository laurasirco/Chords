#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.hpp"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;

    settings.setSize(512, 512);
    settings.setPosition(glm::vec2(0,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

    settings.setSize(900, 300);
    settings.setPosition(glm::vec2(0,512));
    settings.resizable = false;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<GuiApp> guiApp(new GuiApp);
    mainApp->guiApp = guiApp;
    
    ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();

}
