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

#include "Large.h"

TEST(LargeTest, SizeIsOneMegabyte) {

    EXPECT_EQ(1024u*1024u, sizeof(Large));
}

TEST(LargeTest, CreateObject) {

    Large large{};
}

TEST(LargeTest, HasLessThenOperator) {

    Large a{};
    Large b{};

    a < b;
}

TEST(LargeTest, HasEqualityOperator) {

    Large a{};
    Large b{};

    a == b;
}

TEST(LargeTest, CanBeHashed) {

    Large large{};
    std::hash<Large> hash;

    hash(large);
}

TEST(LargeTest, Collections) {

    Large large{};

    std::vector<Large> vector{};
    vector.push_back(large);

    std::array<Large, 1> array{};
    array[0] = large;

    std::deque<Large> deque{};
    deque.push_back(large);

    std::list<Large> list{};
    list.push_back(large);

    std::forward_list<Large> forward_list{};
    forward_list.push_front(large);

    std::map<Large, bool> map{};
    map[large] = true;

    std::set<Large> set{};
    set.insert(large);

    std::unordered_map<Large, bool> unordered_map{};
    unordered_map[large] = true;

    std::unordered_set<Large> unordered_set{};
    unordered_set.insert(large);
}

TEST(LargeTest, Randomize) {

    Large large{};
    large.randomize();

    auto count = 0u;

    for (double i : large.data) {

        ASSERT_LE(0.0, i);
        ASSERT_GE(1.0, i);

        if (i != 0.0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(LargeTest, Clear) {

    Large large{};
    large.randomize();
    large.clear();

    for (double i : large.data) {
        ASSERT_DOUBLE_EQ(0.0, i);
    }
}


// TODO: Add tests for your operators implementation!

TEST(LargeTest, IsEqual)
{
    Large a{3.2,3};
    Large b{1,5};
    Large c{3.2,5};
    Large d{3.2,3};
    EXPECT_EQ(a==b, 0);
    EXPECT_EQ(a==c, 0);
    EXPECT_EQ(a==d, 1);
}

TEST(LargeTest, IsLessThan)
{
    Large a{3,3};
    Large b{1,5};
    Large c{5,5};
    Large d{3,3};
    EXPECT_EQ(a<b, 0);
    EXPECT_EQ(a<c, 1);
    EXPECT_EQ(a<d, 0);
}

TEST(LargeTest, IsKeyEqual)
{
    Large large{};
    std::hash<Large> hash;
    std::size_t key = 0;
    std::size_t h1;
    std::size_t h2;
    for(int i=0; i<large.SIZE;i++)
    {
        h1 = std::hash<int>{}(i);
        h2 = std::hash<double>{}(large.data[i]);
        key += h1 ^ (h2<<1);
    }

    EXPECT_EQ(hash(large), key);
}