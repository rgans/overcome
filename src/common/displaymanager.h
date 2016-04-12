#ifndef RRG_DISPLAYMANAGER_H
#define RRG_DISPLAYMANAGER_H

#include "util/observer.h"
#include <Ogre/Ogre.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

namespace RRG {

    typedef struct Color {
        unsigned r;
        unsigned g;
        unsigned b;
        unsigned a;
    } Color;

    typedef struct Size {
        float width;
        float height;
    } Size;

    typedef struct Point {
        float x;
        float y;
    } Point;

    typedef struct Frame {
        Size size;
        Point position;
    } Frame;

    struct DisplayObserver {

        enum {
            MouseMoveEvent, MouseClickEvent, KeyDownEvent, KeyUpEvent, KeyPressEvent
        };
        using ObserverTable = std::tuple<
                Observer<void()> //MouseMoveEvent
        >;
    };

    class DisplayManager : public Observable<DisplayObserver> {
    public:

        static DisplayManager& Instance() {
            static DisplayManager _instance;
            return _instance;
        }

        DisplayManager(DisplayManager const&) = delete;
        void operator=(DisplayManager const&) = delete;

        bool Initialize();

        void DrawImage();
        void DrawText();
        void DrawLine(const Frame& frame, const Color& color);
        void Draw(const Frame& frame, const Color& color);
        void Clear(const Color& color);
        void ClearAll(const Color& color);
        bool SetMousePosition(const Point& position);
        //bool SetMouseCursor(csMouseCursorID iShape);
        //bool SetMouseCursor(iImage *image, const csRGBcolor* keycolor = 0, int hotspot_x = 0, int hotspot_y = 0, csRGBcolor fg = csRGBcolor(255, 255, 255), csRGBcolor bg = csRGBcolor(0, 0, 0));

        void Render();
        bool BeginDraw();
        void FinishDraw();

    private:
        DisplayManager();
        ~DisplayManager();

        inline unsigned long createRGBA1(int r, int g, int b, int a) {
            return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (a & 0xff);
        }

        inline unsigned long createRGBA(const Color& color) {
            return createRGBA1(color.r, color.g, color.b, color.a);
        }

        bool _initialized = false;
        Color _clear_color = {255, 255, 255, 255};
        
        Ogre::Root* _ogre_root;
        Ogre::RenderWindow* _main_window;
        Ogre::SceneManager* _ogre_scene;
        Ogre::Camera* _ogre_camera;
        Ogre::Viewport* _ogre_view_port;
    };

}

#endif