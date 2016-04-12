#include "viewcontroller.h"

RRG::ViewController::ViewController() {
    //_view = new RRG::View();
}

RRG::ViewController::~ViewController() {
}

void RRG::ViewController::Render() {
    _view.Render();
}
