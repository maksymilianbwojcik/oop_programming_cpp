#ifndef INC_08_FAKE_MOCK_OR_STUB_TIMEIMPL_H
#define INC_08_FAKE_MOCK_OR_STUB_TIMEIMPL_H

#include "Time.h"

class TimeImpl : public Time {
public:

    void create(bool endless);
    long long now() const;
    void flow();

private:
    long long year;
    bool endless;
};


#endif //INC_08_FAKE_MOCK_OR_STUB_TIMEIMPL_H
