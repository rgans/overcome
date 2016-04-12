#include "displaymanager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

RRG::DisplayManager::DisplayManager() {
}

RRG::DisplayManager::~DisplayManager() {
}

bool RRG::DisplayManager::Initialize() {
    if (!_initialized) {

        _ogre_root = new Ogre::Root("plugins.cfg", "ogre.cfg", "ogre.log");

        if(!(_ogre_root->restoreConfig() || _ogre_root->showConfigDialog()))
            return false;
        
        _ogre_root->setRenderSystem(_ogre_root->getAvailableRenderers().front());

        Ogre::NameValuePairList params;
        //params["currentGLContext"] = Ogre::String("True");
        //params["externalGLContext"] = Ogre::String("True");
        //params["externalWindowHandle"] = Ogre::StringConverter::toString((unsigned int)0);
        //params["border"] = "none";
        //params["externalGLControl"] = Ogre::StringConverter::toString( (true) );
        //params["externalGLContext"] = Ogre::StringConverter::toString( (myHGLRC) );
        //params["macAPI"] = "cocoa";
        //params.insert(std::make_pair("macAPI", "cocoa"));
        //params.insert(std::make_pair("macAPICocoaUseNSView", "true"));
        
        
        _ogre_root->initialise(false);
        _main_window = _ogre_root->createRenderWindow( "My sub render window", 800, 600, false, &params );
        
        _main_window->setVisible(true);
        
        //_ogre_scene = _ogre_root->createSceneManager(Ogre::ST_GENERIC);
        
        //_ogre_camera = _ogre_scene->createCamera("MainCam");
        //_ogre_camera->setPosition(0, 0, 80);
        //_ogre_camera->lookAt(0, 0, -300);
        //_ogre_camera->setNearClipDistance(5);

        //_ogre_view_port = _main_window->addViewport(_ogre_camera);
        //_ogre_view_port->setClearEveryFrame(true);
        //_ogre_view_port->setOverlaysEnabled(false);

        //_ogre_camera->setAspectRatio(Ogre::Real(_ogre_view_port->getActualWidth()) / Ogre::Real(_ogre_view_port->getActualHeight()));
        
        _initialized = true;
    }

    return _initialized;
}

void RRG::DisplayManager::DrawImage() {
}

void RRG::DisplayManager::DrawText() {
}

void RRG::DisplayManager::DrawLine(const RRG::Frame& frame, const RRG::Color& color) {
}

void RRG::DisplayManager::Draw(const RRG::Frame& frame, const RRG::Color& color) {
}

void RRG::DisplayManager::Clear(const RRG::Color& color) {
    //_ogre_view_port->setBackgroundColour(Ogre::ColourValue::Black);
}

void RRG::DisplayManager::ClearAll(const RRG::Color& color) {
}

bool RRG::DisplayManager::SetMousePosition(const RRG::Point& position) {
    return true;
}
//bool SetMouseCursor(csMouseCursorID iShape);
//bool SetMouseCursor(iImage *image, const csRGBcolor* keycolor = 0, int hotspot_x = 0, int hotspot_y = 0, csRGBcolor fg = csRGBcolor(255, 255, 255), csRGBcolor bg = csRGBcolor(0, 0, 0));

bool RRG::DisplayManager::BeginDraw() {
    Clear(_clear_color);
    return true;
}

void RRG::DisplayManager::FinishDraw() {
    _ogre_root->renderOneFrame();
    //_ogre_view_port->update();
    _main_window->update();
}

void RRG::DisplayManager::Render() {
    //BeginDraw();
    //FinishDraw();
}