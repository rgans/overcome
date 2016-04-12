#ifndef RRG_VIEWCONTROLLER_H
#define RRG_VIEWCONTROLLER_H

#include "interface/view.h"

namespace RRG {

    class ViewController {
    public:
        ViewController();
        virtual ~ViewController();
        virtual void Render();

    protected:

        View* GetView() {
            return &_view;
        };

    private:
        View _view;

    };

}

#endif