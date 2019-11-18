#pragma once

#include <random>

struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<int> dis{};

        for (int &i : data)
            i = dis(gen);
    }

    bool operator<(const Medium &rhs) const {

        // TODO: Implement me!
        for (int i=0;i<SIZE;i++)
        {
            if(data[i]<rhs.data[i]) return true;
            else if (data[i]==rhs.data[i]) continue;
            return false;
        }
        return false;
    }

    bool operator==(const Medium &rhs) const {

        // TODO: Implement me!
        for (int i=0;i<SIZE;i++)
        {
            if(data[i]==rhs.data[i]) continue;
            return false;
        }
        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {

            // TODO: Implement me!
            std::size_t sum = std::hash<int>{}(d.data[0]);
            for (int i=1;i<d.SIZE;i++)
            {
                sum= std::hash<int>{}(d.data[i]);
            }
            return sum;
        }
    };
}