#include "logincontroller.h"

RRG::LoginController::LoginController() {
    RRG::View* _mainView = GetView();
    //login_button = new RRG::Button();
    login_button.Register<RRG::ControlObserver::MouseOverEvent>([this]() {
        LoginButton_MouseOver(); });
    login_button.Register<RRG::ControlObserver::MouseOutEvent>([this]() {
        LoginButton_MouseOut(); });

    _mainView->AddChild(&login_button);
}

RRG::LoginController::~LoginController() {
}

void RRG::LoginController::LoginButton_MouseOver() {
    RRG::Color over_color = {255, 0, 0, 0};
    login_button.SetBackgroundColor(over_color);
}

void RRG::LoginController::LoginButton_MouseOut() {
    RRG::Color out_color = {0, 255, 0, 0};
    login_button.SetBackgroundColor(out_color);
}
