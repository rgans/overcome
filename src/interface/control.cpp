#include "control.h"

RRG::Control::Control() {
    RRG::InputManager& _inputManager = RRG::InputManager::Instance();

    _inputManager.Register<RRG::InputObserver::MouseMoveEvent>([this](RRG::MouseMoveEventArg arg) {
        OnMouseMove(arg); });
}

RRG::Control::~Control() {
}

void RRG::Control::OnMouseMove(RRG::MouseMoveEventArg arg) {
    RRG::Point _point = {arg.x, arg.y};
    if (IsInside(&_point)) {
        Notify<RRG::ControlObserver::MouseOverEvent>();
        _mouseover = true;
    } else if (_mouseover) {
        Notify<RRG::ControlObserver::MouseOutEvent>();
        _mouseover = false;
    }
}