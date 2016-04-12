#include "gamemanager.h"
#include "logincontroller.h"

RRG::GameManager::GameManager() {
}

RRG::GameManager::~GameManager() {
}

bool RRG::GameManager::Initialize() {
    if (!_initialized) {
        _initialized = true;
    }

    return _initialized;
}

void RRG::GameManager::Update() {
    RRG::LoginController _currentController;
    _currentController.Render();
}