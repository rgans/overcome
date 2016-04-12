#ifndef RRG_LOGINCONTROLLER_H
#define RRG_LOGINCONTROLLER_H

#include "viewcontroller.h"
#include "interface/button.h"

namespace RRG {

    class LoginController : public ViewController {
    public:
        LoginController();
        virtual ~LoginController();
    private:
        Button login_button;
        void LoginButton_MouseOver();
        void LoginButton_MouseOut();

    };

}

#endif
