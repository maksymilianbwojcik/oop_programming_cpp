#ifndef INC_08_FAKE_MOCK_OR_STUB_OBSERVERIMPL_H
#define INC_08_FAKE_MOCK_OR_STUB_OBSERVERIMPL_H

#include "Observer.h"

class ObserverImpl : public Observer {
public:

    void remember(std::string question, std::string answer);
    std::string answer(std::string question) const;

private:
    std::map<std::string, std::string> answers;
};


#endif //INC_08_FAKE_MOCK_OR_STUB_OBSERVERIMPL_H
