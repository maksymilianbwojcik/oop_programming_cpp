#include "TestIncludes.h"

// TODO: ...

TEST(VectorInt, CreateInitialized) {

    // TODO: ...
    std::vector<int> vector = {1, 2, 3};

ASSERT_EQ(3u, vector.size());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);
}

TEST(VectorDouble, CreateEmptyAndAddValuesAtTheEnd) {

    // TODO: ...
    std::vector<double> vector;

    ASSERT_EQ(0u, vector.size());
    ASSERT_TRUE(vector.empty());

    // TODO: ...
    vector = {11, 13, 17};
    ASSERT_EQ(3u, vector.size());
    EXPECT_DOUBLE_EQ(11, vector[0]);
    EXPECT_DOUBLE_EQ(13, vector[1]);
    EXPECT_DOUBLE_EQ(17, vector[2]);
}

TEST(VectorFloat, CreateUsingInitializerList) {

    // TODO: ...
    std::vector<int> vector = {10,20,30};

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(10, vector[0]);
    EXPECT_FLOAT_EQ(20, vector[1]);
    EXPECT_FLOAT_EQ(30, vector[2]);
}

TEST(VectorInt, SizeShouldBeLessThanOrEqualToCapacity) {

    // TODO: ...
    std::vector<int> vector = {1,2,3};

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);
    EXPECT_EQ(vector.capacity(), vector.size());

    // TODO: ...
    vector = {4,1,2,3};
    ASSERT_EQ(4u, vector.size());
    EXPECT_FLOAT_EQ(4, vector[0]);
    EXPECT_FLOAT_EQ(1, vector[1]);
    EXPECT_FLOAT_EQ(2, vector[2]);
    EXPECT_FLOAT_EQ(3, vector[3]);
    EXPECT_GE(vector.capacity(), vector.size());

    // TODO: ...
    vector = {4,1,2,3};

    ASSERT_EQ(4u, vector.size());
    EXPECT_EQ(vector.capacity(), vector.size());
}

TEST(VectorFloat, CopyToOtherVectorUsingAssign) {

    // TODO: ...
    std::vector<float> input = {1,2,3};
    std::vector<float> output = {};

    ASSERT_EQ(3u, input.size());
    EXPECT_EQ(1, input[0]);
    EXPECT_EQ(2, input[1]);
    EXPECT_EQ(3, input[2]);

    ASSERT_TRUE(output.empty());

    // TODO: ...
    output.assign(input.begin()+1, input.end());
    ASSERT_EQ(2u, output.size());
    EXPECT_EQ(2, output[0]);
    EXPECT_EQ(3, output[1]);

    ASSERT_EQ(3u, input.size());
    EXPECT_EQ(1, input[0]);
    EXPECT_EQ(2, input[1]);
    EXPECT_EQ(3, input[2]);
}
TEST(VectorFloat, EraseFrontValue) {

    // TODO: ...
    std::vector<float> vector = {1,2,3};

    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);

    // TODO: ...
    vector.erase(vector.begin());
    ASSERT_EQ(2u, vector.size());
    EXPECT_FLOAT_EQ(2, vector[0]);
    EXPECT_FLOAT_EQ(3, vector[1]);
}

TEST(VectorVectorVectorFloat, ThreeDimensionalVector) {

    // TODO: ...
    std::vector< std::vector< std::vector<float>>> vector(2, std::vector< std::vector<float>>(2,std::vector<float>(2,0)));

    ASSERT_EQ(2u, vector.size());
    ASSERT_EQ(2u, vector[0].size());
    ASSERT_EQ(2u, vector[1].size());
    ASSERT_EQ(2u, vector[0][0].size());
    ASSERT_EQ(2u, vector[0][1].size());
    ASSERT_EQ(2u, vector[1][0].size());
    ASSERT_EQ(2u, vector[1][1].size());
    int x = 0;
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            for (int k=0;k<2;k++)
            {
                x++;
                vector[i][j][k] = x;
            }
        }
    }

    EXPECT_FLOAT_EQ(1, vector[0][0][0]);
    EXPECT_FLOAT_EQ(2, vector[0][0][1]);
    EXPECT_FLOAT_EQ(3, vector[0][1][0]);
    EXPECT_FLOAT_EQ(4, vector[0][1][1]);
    EXPECT_FLOAT_EQ(5, vector[1][0][0]);
    EXPECT_FLOAT_EQ(6, vector[1][0][1]);
    EXPECT_FLOAT_EQ(7, vector[1][1][0]);
    EXPECT_FLOAT_EQ(8, vector[1][1][1]);
}
/*
TEST(ArrayInt, FillWithTheSameValue) {

    // TODO: ...
   // std::array<int, 3> a = {0};
    for (auto i = 0u; i < 1000; i++) {
        ASSERT_EQ(0, array[i]);
    }

    // TODO: ...

    for (auto i = 0u; i < 1000; i++) {
        ASSERT_EQ(7, array[i]);
    }
}


TEST(ArrayInt, SizeDefinedAtCompileTime) {

    // TODO: ...

    static_assert(array.size() == 4, "Compilation error: wrong array size");

    ASSERT_EQ(1u, array[0]);
    ASSERT_EQ(2u, array[1]);
    ASSERT_EQ(3u, array[2]);
    ASSERT_EQ(4u, array[3]);
}*/

TEST(ArrayInt, Sort) {

    // TODO: ...
    std::array<int, 5> array = {5,3,4,1,2};
    EXPECT_EQ(5, array[0]);
    EXPECT_EQ(3, array[1]);
    EXPECT_EQ(4, array[2]);
    EXPECT_EQ(1, array[3]);
    EXPECT_EQ(2, array[4]);

    // TODO: ...
    std::sort(array.begin(), array.end());
    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(2, array[1]);
    EXPECT_EQ(3, array[2]);
    EXPECT_EQ(4, array[3]);
    EXPECT_EQ(5, array[4]);
}
/*
TEST(ArrayChar, CreateCopy) {

    // TODO: ...

    ASSERT_EQ(5u, arrayIn.size());
    ASSERT_EQ('a', arrayIn[0]);
    ASSERT_EQ('b', arrayIn[1]);
    ASSERT_EQ('c', arrayIn[2]);
    ASSERT_EQ('d', arrayIn[3]);
    ASSERT_EQ('\0', arrayIn[4]);
    EXPECT_STREQ("abcd", arrayIn.data());

    // TODO: ...

    ASSERT_EQ(5u, arrayIn.size());
    EXPECT_STREQ("abcd", arrayIn.data());
    ASSERT_EQ(5u, arrayOut.size());
    EXPECT_STREQ("abcd", arrayOut.data());
}

TEST(ListFloat, Sort) {

    // TODO: ...

    ASSERT_EQ(1000, list.size());
    EXPECT_FALSE(std::is_sorted(list.begin(), list.end()));

    // TODO: ...

    ASSERT_EQ(1000, list.size());
    EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(ListInt, MergeSortedLists) {

    // TODO: ...

    auto iter = a.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(5, *(iter++));
    EXPECT_EQ(a.end(), iter);
    iter = b.begin();
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(6, *(iter++));
    EXPECT_EQ(b.end(), iter);

    // TODO: ...

    EXPECT_EQ(0, b.size());
    EXPECT_EQ(6, a.size());
    iter = a.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(5, *(iter++));
    EXPECT_EQ(6, *(iter++));
    EXPECT_EQ(a.end(), iter);
}
*/
TEST(ForwardListFloat, InsertElementAfterIndex) {

    // TODO: ...
    std::forward_list<float> forwardList {1,2,3,4};
    auto iter = forwardList.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(forwardList.end(), iter);

    // TODO: ...
    auto costam = forwardList.begin();
    ++costam;
    forwardList.insert_after(costam, 10);
    iter = forwardList.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(10, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(forwardList.end(), iter);
}

/*
TEST(DequeInt, RemoveFirstElement) {

    // TODO: ...

    ASSERT_EQ(3u, deque.size());
    EXPECT_FLOAT_EQ(1, deque[0]);
    EXPECT_FLOAT_EQ(2, deque[1]);
    EXPECT_FLOAT_EQ(3, deque[2]);

    // TODO: ...

    ASSERT_EQ(2u, deque.size());
    EXPECT_FLOAT_EQ(2, deque[0]);
    EXPECT_FLOAT_EQ(3, deque[1]);
}


TEST(StackInt, PushAndPop) {

    // TODO: ...

    EXPECT_TRUE(stack.empty());

    // TODO: ...

    ASSERT_EQ(2u, stack.size());
    EXPECT_EQ(2, stack.top());

    // TODO: ...

    ASSERT_EQ(1u, stack.size());
    EXPECT_EQ(1, stack.top());

    // TODO: ...

    ASSERT_EQ(0u, stack.size());
}

TEST(PriorityQueueChar, PushAndPop) {

    // TODO: ...

    ASSERT_TRUE(priority_queue.empty());

    // TODO: ...

    ASSERT_EQ(2u, priority_queue.size());
    EXPECT_EQ(3, priority_queue.top());

    // TODO: ...

    ASSERT_EQ(4u, priority_queue.size());
    EXPECT_EQ(4, priority_queue.top());

    // TODO: ...

    ASSERT_EQ(3u, priority_queue.size());
    EXPECT_EQ(3, priority_queue.top());

    // TODO: ...

    ASSERT_EQ(2u, priority_queue.size());
    EXPECT_EQ(2, priority_queue.top());

    // TODO: ...

    ASSERT_EQ(1u, priority_queue.size());
    EXPECT_EQ(1, priority_queue.top());

    // TODO: ...

    ASSERT_TRUE(priority_queue.empty());
}
*/