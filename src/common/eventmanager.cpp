#include "EventManager.h"

RRG::EventManager::EventManager() {
    _initialized = false;
}

RRG::EventManager::~EventManager() {
}

bool RRG::EventManager::Initialize() {
    if (!_initialized) {
        _initialized = true;
    }

    return _initialized;
}

void RRG::EventManager::DispatchEvent() {
}

void RRG::EventManager::HandleClose() {
    Notify<RRG::EventObserver::CloseEvent>(false);
}

void RRG::EventManager::HandleMouseEvent() {

}

void RRG::EventManager::HandleKeyboardEvent() {
    //Notify<CEventObserver::KeyPressEvent>();
}