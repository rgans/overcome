#include "framemanager.h"

RRG::FrameManager::FrameManager() {
}

RRG::FrameManager::~FrameManager() {
    OGRE_DELETE _timer;
}

bool RRG::FrameManager::Initialize() {
    if (!_initialized) {

        _timer = OGRE_NEW Ogre::Timer();
        _timer->reset();
        
        _initialized = true;
    }
    
    return _initialized;
}

double RRG::FrameManager::GetTime() {
    return _timer->getMillisecondsCPU();
}