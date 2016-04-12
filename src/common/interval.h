#ifndef RRG_INTERVAL_H
#define RRG_INTERVAL_H

#include <chrono>

namespace RRG {

    class Interval {
    public:
        Interval();
        virtual ~Interval();

        inline unsigned long long value() const {
            return GetTickCount() - initial_;
        }

        static unsigned long long
        GetTickCount() {
            return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
        }

    private:
        unsigned long long initial_;

    };

}

#endif

