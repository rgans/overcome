#ifndef RRG_FRAMERATE_H
#define RRG_FRAMERATE_H

#include "interval.h"

namespace RRG {

    class FrameRate {
    public:
        FrameRate();
        virtual ~FrameRate();

        void Update() {
            // increase the counter by one
            m_fpscount++;

            // one second elapsed? (= 1000 milliseconds)
            if (m_fpsinterval.value() > 1000) {
                // save the current counter value to m_fps
                m_fps = m_fpscount;

                // reset the counter and the interval
                m_fpscount = 0;
                m_fpsinterval = Interval();
            }
        }

        unsigned int Get() const {
            return m_fps;
        }

    private:

    protected:
        unsigned int m_fps;
        unsigned int m_fpscount;
        Interval m_fpsinterval;
    };

}

#endif

