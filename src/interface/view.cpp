#include "view.h"

RRG::View::View() {
}

RRG::View::~View() {
}

void RRG::View::Render() {
    Resize();
    Draw();

    for (int i = 0; i < _child.size(); i++) {
        RRG::View* child = _child.at(i);
        child->Render();
    }
}

void RRG::View::Show() {
    _visible = true;
}

void RRG::View::Hide() {
    _visible = false;
}

void RRG::View::Resize() {
}

void RRG::View::Draw() {
    _displayManager.Draw(_frame, _background_color);
}

bool RRG::View::IsInside(const RRG::Point* point) {
    if (!point)
        return false;

    return point->x >= _frame.position.x &&
            point->x <= _frame.size.width &&
            point->y >= _frame.position.y &&
            point->y <= _frame.size.height;
}