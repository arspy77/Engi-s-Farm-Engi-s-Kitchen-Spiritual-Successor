#include "LinkedList.h"
#include <gtest/gtest.h>


TEST(LinkedListTest, EmptyConstructor) {
	LinkedList<int> l{};
	EXPECT_TRUE(l.isEmpty());
	EXPECT_EQ(0, l.len());
}

TEST(LinkedListTest, ListConstructor) {
	LinkedList<int> l{1,2,5,7};
	EXPECT_FALSE(l.isEmpty());
	EXPECT_EQ(4, l.len());
	EXPECT_EQ(1, l.get(0));
	EXPECT_EQ(2, l.get(1));
	EXPECT_EQ(5, l[2]);
	EXPECT_EQ(7, l[3]);
}

TEST(LinkedListTest, CopyConstructor) {
	LinkedList<int> l{2,7,5,3};
	LinkedList<int> k{l};
	EXPECT_FALSE(k.isEmpty());
	EXPECT_EQ(4, k.len());
	EXPECT_EQ(2, k.get(0));
	EXPECT_EQ(7, k.get(1));
	EXPECT_EQ(5, k[2]);
	EXPECT_EQ(3, k[3]);
}

TEST(LinkedListTest, OperatorEq) {
	LinkedList<int> l{2,7,5,3};
	LinkedList<int> k{};
	k = l;
	EXPECT_FALSE(k.isEmpty());
	EXPECT_EQ(4, k.len());
	EXPECT_EQ(2, k.get(0));
	EXPECT_EQ(7, k.get(1));
	EXPECT_EQ(5, k[2]);
	EXPECT_EQ(3, k[3]);
}

TEST(LinkedListTest, AddRemove) {
	LinkedList<char> l{};
	l.add('a');
	EXPECT_EQ(1, l.len());
	EXPECT_EQ('a', l[0]);
	l.add('b');
	l.add('c');
	EXPECT_EQ(3, l.len());
	EXPECT_EQ('b', l[1]);
	EXPECT_EQ('c', l[2]);
	l.remove('b');
	EXPECT_EQ(2, l.len());
	EXPECT_EQ('a', l[0]);
	EXPECT_EQ('c', l[1]);
	l.removeIdx(1);
	EXPECT_EQ(1, l.len());
	try {
		l.removeIdx(2);
		FAIL() << "Expected \"Index out of range\"";
	} catch (const char* s) {
		EXPECT_EQ(s, "Index out of range");
	} catch (...) {
		FAIL() << "Wrong Throw Type";
	}
	try {
		++l[3];
		FAIL() << "Expected \"Index out of range\"";
	} catch (const char* s) {
		EXPECT_EQ(s, "Index out of range");
	} catch (...) {
		FAIL() << "Wrong Throw Type";
	}
}

TEST(LinkedListTest, Find) {
	LinkedList<int*> l{};
	l.add(new int{2});
	l.add(new int{3});
	int* p = new int{4};
	EXPECT_EQ(-1, l.find(p));
	l.add(p);
	EXPECT_EQ(2, l.find(p));
	l.remove(p);
	l.add(new int{4});
	EXPECT_EQ(2, l.findPointer(p));
	delete p;
	delete l[2];
	delete l[1];
	delete l[0];
}