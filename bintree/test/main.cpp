#include "binary_tree.hpp"

#include <thread>
#include <chrono>

#include <gmock/gmock.h>
#include <gtest/gtest.h>


#define SLEEP(n) 	{ \
						auto milliwait = std::chrono::milliseconds(n); \
						std::this_thread::sleep_for(milliwait); \
					}

void insert_hella(BinaryTree<int>* tree, int start=0, int end=100)
{
	for(int i = start; i <= end; i++)
	{
		tree->insert(i);
	}
}

TEST(BinaryTree, ShouldWorkThreaded)
{
	BinaryTree<int> btree;

	auto t1 = std::thread(insert_hella, &btree, 0, 10);
	auto t2 = std::thread(insert_hella, &btree, -8, 2);
	auto t3 = std::thread(insert_hella, &btree, 10, 222);
	auto t4 = std::thread(insert_hella, &btree, 33, 333);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	auto res = btree.search(3);

	ASSERT_EQ(3, res->data);

	ASSERT_EQ(342, btree.getSize());
}

TEST(BinaryTree, ShouldWork)
{
	BinaryTree<int> btree;

	insert_hella(&btree, 0, 100);

	ASSERT_EQ(101, btree.getSize());
}

TEST(BinaryTree, SearchReturnsCorrectNode)
{
	BinaryTree<int> btree;

	insert_hella(&btree);

	ASSERT_EQ(40, btree.search(40)->data);
}

TEST(BinaryTree, RemoveWorks)
{
	BinaryTree<int> btree;

	insert_hella(&btree);

	ASSERT_TRUE(btree.remove(0));

	ASSERT_FALSE(btree.remove(0));

	ASSERT_EQ(100, btree.getSize());
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
