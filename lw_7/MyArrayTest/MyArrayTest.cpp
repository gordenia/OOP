#include "stdafx.h"
#include "iostream"
#include "../MyArray/MyArray.h"

struct ArrayItem
{
	ArrayItem(int value = 0) : value(value)
	{}
	int value;
};


TEST_CASE("initially the size is zero")
{
	CMyArray<ArrayItem> arr;
	CHECK(arr.GetSize() == 0);
};

TEST_CASE("initially the capacity is zero")
{
	CMyArray<ArrayItem> arr;
	CHECK(arr.GetCapacity() == 0);
};

TEST_CASE("increases the size and capacity after adding an element")
{
	CMyArray<ArrayItem> arr;

	arr.Append(ArrayItem());
	CHECK(arr.GetSize() == 1);
	CHECK(arr.GetCapacity() == 1);

	arr.Append(ArrayItem());
	CHECK(arr.GetSize() == 2);
	CHECK(arr.GetCapacity() == 2);

	arr.Append(ArrayItem());
	CHECK(arr.GetSize() == 3);
	CHECK(arr.GetCapacity() == 4);

	arr.Append(ArrayItem());
	CHECK(arr.GetSize() == 4);
	CHECK(arr.GetCapacity() == 4);
}

TEST_CASE("after copy has size capacity equal to size of original array")
{
	CMyArray<ArrayItem> arr;

	for (auto i = 0; i < 6; ++i)
	{
		arr.Append(i);
	}

	auto copy(arr);
	CHECK(copy.GetSize() == arr.GetSize());
	CHECK(copy.GetCapacity() == arr.GetSize());
}

TEST_CASE("can not access an item outside the range")
{
	CMyArray<ArrayItem> arr;

	arr.Append(1);
	CHECK_THROWS_AS(arr[1], std::out_of_range);
}

TEST_CASE("can access items from the range")
{
	CMyArray<int> arr;

	arr.Append(1);
	arr.Append(2);

	CHECK(arr[0] == 1);
	CHECK(arr[1] == 2);
}

TEST_CASE("can change the data within the range")
{
	CMyArray<int> arr;

	arr.Append(1);
	arr[0] = 3;
	CHECK(arr[0] == 3);
}

TEST_CASE("can make the size of the array smaller")
{
	CMyArray<int> arr;

	arr.Append(1);
	arr.Append(22);
	arr.Append(3);
	arr.Append(4);
	arr.Append(35);
	CHECK(arr.GetSize() == 5);
	CHECK(arr.GetCapacity() == 8);

	arr.Resize(3);
	CHECK(arr.GetSize() == 3);
	CHECK(arr.GetCapacity() == 8);
	CHECK(arr[0] == 1);
	CHECK(arr[1] == 22);
	CHECK(arr[2] == 3);
	CHECK_THROWS_AS(arr[3], std::out_of_range);
}

TEST_CASE("can make the size of the array larger")
{
	CMyArray<int> arr;

	arr.Append(1);
	arr.Append(22);
	arr.Append(3);
	CHECK(arr.GetSize() == 3);
	CHECK(arr.GetCapacity() == 4);

	arr.Resize(4);

	CHECK(arr.GetSize() == 4);
	CHECK(arr.GetCapacity() == 4);

	arr.Resize(6);

	CHECK(arr[0] == 1);
	CHECK(arr[1] == 22);
	CHECK(arr[2] == 3);
	CHECK(arr[3] == 0);
	CHECK(arr[4] == 0);
	CHECK(arr[5] == 0);
	CHECK_THROWS_AS(arr[6], std::out_of_range);
}

TEST_CASE("array can be cleared")
{
	CMyArray<int> arr;

	arr.Append(1);
	arr.Append(22);
	arr.Clear();
	CHECK(arr.GetSize() == 0);
	CHECK(arr.GetCapacity() == 2);
	CHECK_THROWS_AS(arr[0], std::out_of_range);
}

TEST_CASE("array can be copied")
{
	CMyArray<int> arr;

	arr.Append(1);
	arr.Append(22);

	CMyArray<int> newArr;

	newArr = arr;

	CHECK(newArr.GetSize() == arr.GetSize());
	CHECK(newArr[0] == arr[0]);
	CHECK(newArr[1] == arr[1]);
	CHECK_THROWS_AS(newArr[3], std::out_of_range);
}

TEST_CASE("array can be moved")
{
	CMyArray<int> arr;

	arr.Append(1);
	arr.Append(2);
	arr.Append(3);

	CMyArray<int> arrNew(std::move(arr));

	CHECK(arr.GetSize() == 0);
	CHECK(arrNew.GetSize() == 3);
	CHECK(arrNew[0] == 1);
	CHECK(arrNew[1] == 2);
	CHECK(arrNew[2] == 3);
	CHECK_THROWS_AS(arrNew[3], std::out_of_range);

	CMyArray<int> arrNew1;
	arrNew1 = std::move(arrNew);

	CHECK(arrNew.GetSize() == 0);
	CHECK(arrNew1.GetSize() == 3);
	CHECK(arrNew1[0] == 1);
	CHECK(arrNew1[1] == 2);
	CHECK(arrNew1[2] == 3);
	CHECK_THROWS_AS(arrNew1[3], std::out_of_range);
}

TEST_CASE("has a method begin()")
{
	CMyArray<int> arr;
	arr.Append(1);
	arr.Append(2);
	auto it = arr.begin();
	CHECK(*it == 1);
}


TEST_CASE("has iterators for iterating through elements")
{
	CMyArray<int> arr;
	arr.Append(1);
	arr.Append(2);
	arr.Append(3);
	CMyArray<int>::CMyIterator<int> it;
	CHECK(it == nullptr);
	it = arr.begin();
	CHECK(*it == 1);
	++it;
	CHECK(*it == 2);
	++it;
	CHECK(*it == 3);
	--it;
	CHECK(*it == 2);
	--it;
	CHECK(*it == 1);
}

TEST_CASE("has a method end()")
{
	CMyArray<int> arr;
	arr.Append(1);
	arr.Append(2);
	arr.Append(3);
	auto it = arr.end();
	--it;
	CHECK(*it == 3);
}

TEST_CASE("has a method rbegin()")
{
	CMyArray<int> arr;
	arr.Append(1);
	arr.Append(2);
	arr.Append(3);
	auto it = arr.rbegin();
	CHECK(*it == 3);
}

TEST_CASE("has a method rend()")
{
	CMyArray<int> arr;
	arr.Append(1);
	arr.Append(2);
	arr.Append(3);
	auto it = arr.rend();
	--it;
	CHECK(*it == 1);
}
