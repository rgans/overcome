#ifndef RRG_GAME_H
#define RRG_GAME_H

#include "gamemanager.h"
#include "common/displaymanager.h"
#include "common/eventmanager.h"
#include "common/framerate.h"
#include <iostream>

namespace RRG {

    class Game {
    public:
        Game();
        ~Game();

        int Run(int argc, char* args[]);

    private:
        bool Initialize();
        bool Refresh();
        bool Update();
        bool Render();
        void Cleanup();

        void OnMouseMove(MouseMoveEventArg arg);
        bool OnClose(bool force_close = false);

        bool _quit = false;
        
        RRG::EventManager& _eventManager = RRG::EventManager::Instance();
        RRG::DisplayManager& _displayManager = RRG::DisplayManager::Instance();
        RRG::GameManager& _gameManager = RRG::GameManager::Instance();
    };

}

#endif