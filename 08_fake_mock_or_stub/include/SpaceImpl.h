#ifndef INC_08_FAKE_MOCK_OR_STUB_SPACEIMPL_H
#define INC_08_FAKE_MOCK_OR_STUB_SPACEIMPL_H

#include "Space.h"

class SpaceImpl : public Space {
public:

    void create(unsigned int dimensions);
    unsigned int dimensions() const;

private:
    unsigned int dimensionsCount;
    std::vector<Point> points;
};


#endif //INC_08_FAKE_MOCK_OR_STUB_SPACEIMPL_H
