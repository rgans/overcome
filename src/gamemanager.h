#ifndef RRG_GAMEMANAGER_H
#define RRG_GAMEMANAGER_H

#include "common/util/observer.h"
#include "logincontroller.h"

namespace RRG {

    struct GameObserver {

        enum {
            CloseEvent, MouseMoveEvent, MouseClickEvent, KeyDownEvent, KeyUpEvent, KeyPressEvent
        };
        using ObserverTable = std::tuple<
                Observer<void(bool force_close)>
        >;
    };

    class GameManager : public Observable<GameObserver> {
    public:

        static GameManager& Instance() {
            static GameManager _instance;
            return _instance;
        }

        GameManager(GameManager const&) = delete;
        void operator=(GameManager const&) = delete;

        bool Initialize();
        void Update();

    private:
        GameManager();
        ~GameManager();

        bool _initialized = false;
    };

}

#endif