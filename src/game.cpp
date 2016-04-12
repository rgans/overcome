#include "game.h"

//#define TIME_PER_FRAME = 1.f/60.f;

RRG::Game::Game() {

}

RRG::Game::~Game() {
}

bool RRG::Game::Initialize()
{
    if (!_eventManager.Initialize() || !_displayManager.Initialize() || !_gameManager.Initialize())
        return false;
    
    _eventManager.Register<RRG::EventObserver::CloseEvent>([this](bool force_close) {
        _quit = OnClose(force_close); });
    _eventManager.Register<RRG::EventObserver::MouseMoveEvent>([this](RRG::MouseMoveEventArg arg) {
        OnMouseMove(arg); });

    return true;
}

int RRG::Game::Run(int argc, char* args[]) {
    
    if(!Initialize())
        return 1;
    
    RRG::FrameRate fps;
    RRG::Interval interval;
    RRG::Interval tempo;
    int sec = 0;
    int re = 0;
    unsigned long long rate = (1.f / 60.f)*1000;
    while (!_quit) {
        _eventManager.DispatchEvent();
        
        if (interval.value() > rate) {
            if (_displayManager.BeginDraw())
                _gameManager.Update();
            //            _displayManager.DrawText(std::to_string(fps.Get()));
            _displayManager.FinishDraw();
            interval = RRG::Interval();
            re++;
            fps.Update();
        }
        
        //std::cout<<"Fps: "<<fps.Get()<<'\n';
        if (tempo.value() > 1000) {
            sec++;
            std::cout << "Secs: " << sec << '\n';
            std::cout << "Renders: " << re << '\n';
            std::cout << "Fps: " << fps.Get() << '\n';
            tempo = RRG::Interval();
            re = 0;
        }
    }
    
    return 0;
}

void RRG::Game::OnMouseMove(RRG::MouseMoveEventArg arg) {
}

bool RRG::Game::OnClose(bool force_close) {
    bool can_close = true;
    const bool closing{force_close || can_close};
    if (closing) {
        // Actually close the window.
        // ...
    }
    return closing;
}








//#if OGRE_PLATFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WIN32
//#define WIN32_LEAN_AND_MEAN
//#include "windows.h"

//|||||||||||||||||||||||||||||||||||||||||||||||

//INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
//#else
//int main(int argc, char **argv)
//    int result = 0;

//#endif
//{
//#if defined(OGRE_IS_IOS)
//    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
//    int retVal = UIApplicationMain(argc, argv, @"UIApplication", @"AppDelegate");
//    [pool release];
//    return retVal;
//#elif (OGRE_PLATFORM == OGRE_PLATFORM_APPLE) && __LP64__
//    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    
//    mAppDelegate = [[AppDelegate alloc] init];
//    [[NSApplication sharedApplication] setDelegate:mAppDelegate];
//    int retVal = NSApplicationMain(argc, (const char **) argv);
    
//    [pool release];
    
//    return retVal;
//#else
    
//    try
//    {
//        RRG::Game game;
//        result = game.Run(argc, args);
//    }
//    catch(std::exception& ex)
//    {
//        std::cerr << "Unexpected error, aborting.\n\r\t" << ex.what() << std::endl;
//        result = 1;
//#if OGRE_PLATFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WIN32
//        MessageBoxA(NULL, e.what(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
//#else
//        fprintf(stderr, "An exception has occurred: %s\n", e.what());
//#endif
//    }
    
//#endif
//    return result;
//}


int main(int argc, char* args[]) {
    
    int result = 0;
    
    try{
        RRG::Game game;
        result = game.Run(argc, args);
    }catch(const std::exception& ex){
        std::cerr << "Unexpected error, aborting.\n\r\t" << ex.what() << std::endl;
        result = 1;
    }
    
    return result;
}