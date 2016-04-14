#include "displaymanager.h"

RRG::DisplayManager::DisplayManager() {
}

RRG::DisplayManager::~DisplayManager() {
    Ogre::WindowEventUtilities::removeWindowEventListener(_main_window, this);
    OGRE_DELETE _ogre_root;
}

bool RRG::DisplayManager::Initialize() {
    if (!_initialized) {

        _ogre_root = new Ogre::Root("/Users/rgans/Library/Developer/Xcode/DerivedData/overcome-dyotnmirvseavogkwftioindfaco/Build/Products/Debug/overcome.app/Contents/Resources/plugins.cfg", "ogre.cfg", "ogre.log");

        if(!(_ogre_root->restoreConfig() || _ogre_root->showConfigDialog()))
            return false;
        
        _ogre_root->setRenderSystem(_ogre_root->getAvailableRenderers().front());
        _ogre_root->addFrameListener(this);

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
        
        
        _main_window = _ogre_root->initialise(true, "Teste");
        //_main_window = _ogre_root->createRenderWindow( "My sub render window", 800, 600, false, &params );
        Ogre::WindowEventUtilities::addWindowEventListener(_main_window, this);
        
        _ogre_scene = _ogre_root->createSceneManager(Ogre::ST_GENERIC);
        
        _ogre_camera = _ogre_scene->createCamera("MainCam");
        _ogre_camera->setPosition(0, 0, 80);
        _ogre_camera->lookAt(0, 0, -300);
        _ogre_camera->setNearClipDistance(5);

        _ogre_view_port = _main_window->addViewport(_ogre_camera);
        _ogre_view_port->setClearEveryFrame(true);
        _ogre_view_port->setOverlaysEnabled(false);

        _ogre_camera->setAspectRatio(Ogre::Real(_ogre_view_port->getActualWidth()) / Ogre::Real(_ogre_view_port->getActualHeight()));
        
//        _ogre_root->addFrameListener(this);
//        _ogre_root->startRendering();
        
        
        
        
        /*
        OIS::ParamList pl;
        size_t windowHnd = 0;
        std::ostringstream windowHndStr;
        
        _main_window->getCustomAttribute("WINDOW", &windowHnd);
        windowHndStr << windowHnd;
        pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
        
        mInputManager = OIS::InputManager::createInputSystem( pl );
        mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, false ));
        mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, false ));
        */
        
        
        _initialized = true;
    }

    return _initialized;
}

void RRG::DisplayManager::DrawImage() {
    Ogre::WindowEventUtilities::messagePump();

}

void RRG::DisplayManager::DrawText(const std::string& text) {
}

void RRG::DisplayManager::DrawLine(const RRG::Frame& frame, const RRG::Color& color) {
}

void RRG::DisplayManager::Draw(const RRG::Frame& frame, const RRG::Color& color) {
}

void RRG::DisplayManager::Clear(const RRG::Color& color) {
    _ogre_view_port->setBackgroundColour(Ogre::ColourValue::Black);
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
    //_ogre_root->renderOneFrame();
    //_ogre_view_port->update();
    //_main_window->update();
}

void RRG::DisplayManager::Render() {
    _ogre_root->startRendering();
    //_ogre_root->renderOneFrame();
    //_ogre_view_port->update();
    //_main_window->update();
}

void RRG::DisplayManager::DispatchEvent() {
    Ogre::WindowEventUtilities::messagePump();

    if(_main_window->isClosed())
        Notify<DisplayObserver::WindowClosedEvent>(true);

}

bool RRG::DisplayManager::IsActive() {
    return _main_window->isActive();
}

void RRG::DisplayManager::windowResized(Ogre::RenderWindow* rw){
    
}
void RRG::DisplayManager::windowClosed(Ogre::RenderWindow* rw){
    
}