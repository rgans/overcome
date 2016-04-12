#ifndef RRG_CONTROL_H
#define RRG_CONTROL_H

#include "view.h"
#include "../common/eventmanager.h"

namespace RRG {

    struct ControlObserver {

        enum {
            MouseOverEvent, MouseOutEvent, MouseClickEvent
        };
        using ObserverTable = std::tuple<
                Observer<void()>, //MouseOverEvent
        Observer<void()> //MouseOutEvent
        >;
    };

    class Control : public View, public Observable<ControlObserver> {
    public:
        Control();
        ~Control();

        inline bool IsEnabled() {
            return _enabled;
        };

        inline void SetEnabled(bool enabled) {
            _enabled = enabled;
        };

    private:
        bool _enabled = true;
        bool _mouseover = false;

        void OnMouseMove(MouseMoveEventArg arg);

    protected:
    };

}

#endif