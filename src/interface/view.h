#ifndef RRG_VIEW_H
#define RRG_VIEW_H

#include "../common/displaymanager.h"
#include <iostream>

namespace RRG {

    class View {
    public:
        View();
        virtual ~View();

        inline View* GetParent() {
            return _parent;
        };

        inline const Frame& GetFrame() {
            return _frame;
        };

        inline void SetFrame(const Frame& frame) {
            _frame.position.x = frame.position.x;
            _frame.position.y = frame.position.y;
            _frame.size.width = frame.size.width;
            _frame.size.height = frame.size.height;
        };

        inline const Color& GetBackgroundColor() {
            return _background_color;
        };

        inline void SetBackgroundColor(const Color& color) {
            _background_color.r = color.r;
            _background_color.g = color.g;
            _background_color.b = color.b;
            _background_color.a = color.a;
        };

        inline bool IsVisible() {
            return _visible && (!_parent || _parent->IsVisible());
        }

        inline void SetVisibility(bool visible) {
            if (visible) Show();
            else Hide();
        }

        inline void AddChild(View* view) {
            if (!view)
                return;

            _child.push_back(view);

            view->SetParent(this);
        }

        inline void RemoveChild(View* view) {
            if (!view)
                return;

            //_child.erase(&view);

            view->SetParent(nullptr);
        }



        virtual void Render();

    private:
        View* _parent = nullptr;
        std::vector<View*> _child;
        bool _need_layout = false;
        bool _visible = true;
        Color _background_color = {0, 0, 0, 0};
        Frame _frame = {0.f, 0.f, 100.f, 100.f};
        DisplayManager& _displayManager = DisplayManager::Instance();

    protected:

        inline void SetParent(View* parent) {
            _parent = parent;
        };

        virtual void Show();
        virtual void Hide();
        virtual void Resize();
        virtual void Draw();

        bool IsInside(const Point* point);
    };

}

#endif