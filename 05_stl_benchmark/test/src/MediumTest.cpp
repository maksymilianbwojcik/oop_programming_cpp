#include "TestIncludes.h"

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "Medium.h"

TEST(MediumTest, SizeIsOneKiloByte) {

    EXPECT_EQ(1024u, sizeof(Medium));
}

TEST(MediumTest, CreateObject) {

    Medium medium{};
}

TEST(MediumTest, HasLessThenOperator) {

    Medium a{};
    Medium b{};
    a < b;
}

TEST(MediumTest, HasEqualityOperator) {

    Medium a{};
    Medium b{};
    a == b;
}

TEST(MediumTest, CanBeHashed) {

    Medium medium{};
    std::hash<Medium> hash;
    hash(medium);
}

TEST(MediumTest, Collections) {

    Medium medium{};

    std::vector<Medium> vector{};
    vector.push_back(medium);

    std::array<Medium, 1> array{};
    array[0] = medium;

    std::deque<Medium> deque{};
    deque.push_back(medium);

    std::list<Medium> list{};
    list.push_back(medium);

    std::forward_list<Medium> forward_list{};
    forward_list.push_front(medium);

    std::map<Medium, bool> map{};
    map[medium] = true;

    std::set<Medium> set{};
    set.insert(medium);

    std::unordered_map<Medium, bool> unordered_map{};
    unordered_map[medium] = true;

    std::unordered_set<Medium> unordered_set{};
    unordered_set.insert(medium);
}


TEST(MediumTest, Randomize) {

    Medium medium{};
    medium.randomize();

    auto count = 0u;

    for (int i : medium.data) {
        ASSERT_LE(0, i);
        ASSERT_GE(std::numeric_limits<int>::max(), i);

        if (i != 0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(MediumTest, Clear) {

    Medium medium{};
    medium.randomize();
    medium.clear();

    for (int i : medium.data) {
        ASSERT_EQ(0, i);
    }
}

// TODO: Add tests for your operators implementation!

TEST(MediumTest, IsEqual)
{
    Medium a{3,3};
    Medium b{1,5};
    Medium c{3,5};
    Medium d{3,3};
    EXPECT_EQ(a==b, 0);
    EXPECT_EQ(a==c, 0);
    EXPECT_EQ(a==d, 1);
}

TEST(MediumTest, IsLessThan)
{
    Medium a{3,3};
    Medium b{1,5};
    Medium c{5,5};
    Medium d{3,3};
    EXPECT_EQ(a<b, 0);
    EXPECT_EQ(a<c, 1);
    EXPECT_EQ(a<d, 0);
}

TEST(MediumTest, IsKeyEqual)
{
    Medium medium{};
    std::hash<Medium> hash;
    std::size_t key = 0;
    std::size_t h1;
    std::size_t h2;
    for(int i=0; i<medium.SIZE;i++)
    {
        h1 = std::hash<int>{}(i);
        h2 = std::hash<int>{}(medium.data[i]);
        key += h1 ^ (h2<<1);
    }

    EXPECT_EQ(hash(medium), key);
}