#ifndef RRG_FRAMEMANAGER_H
#define RRG_FRAMEMANAGER_H

#include "util/observer.h"
#include <Ogre/Ogre.h>

namespace RRG {

    struct FrameObserver {

        enum {
            MouseMoveEvent, MouseClickEvent, KeyDownEvent, KeyUpEvent, KeyPressEvent
        };
        using ObserverTable = std::tuple<
                Observer<void()> //MouseMoveEvent
        >;
    };

    class FrameManager : public Observable<FrameObserver> {
    public:

        static FrameManager& Instance() {
            static FrameManager _instance;
            return _instance;
        }

        FrameManager(FrameManager const&) = delete;
        void operator=(FrameManager const&) = delete;
        
        bool Initialize();
        
        double GetTime();
        
    private:
        FrameManager();
        ~FrameManager();
        
        bool _initialized = false;

        Ogre::Timer* _timer;
    };

}

#endif