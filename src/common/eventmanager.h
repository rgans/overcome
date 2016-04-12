#ifndef RRG_EVENTMANAGER_H
#define RRG_EVENTMANAGER_H

#include "util/observer.h"

namespace RRG {

    typedef struct MouseMoveEventArg {
        float x;
        float y;

        MouseMoveEventArg(float x_, float y_) : x(x_), y(y_) {
        };
    } MouseMoveEventArg;

    struct EventObserver {

        enum {
            CloseEvent, MouseMoveEvent, MouseClickEvent, KeyDownEvent, KeyUpEvent, KeyPressEvent
        };
        using ObserverTable = std::tuple<
                Observer<void(bool force_close)>, //CloseEvent
        Observer<void(MouseMoveEventArg arg)> //MouseMoveEvent
        >;
    };

    class EventManager : public Observable<EventObserver> {
    public:

        static EventManager& Instance() {
            static EventManager _instance;
            return _instance;
        }

        EventManager(EventManager const&) = delete;
        void operator=(EventManager const&) = delete;

        bool Initialize();
        void DispatchEvent();

    private:
        EventManager();
        ~EventManager();

        void HandleClose();
        void HandleMouseEvent();
        void HandleKeyboardEvent();

        bool _initialized;
    };

}

#endif