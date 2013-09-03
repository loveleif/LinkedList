#include "stdafx.h"
#include "CppUnitTest.h"
#include "LinkedList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(PushFront_PopBack)
		{
			LinkedList list = LinkedList();
      list.PushFront(1);
      Assert::AreEqual(list.Size(), 1);
      list.PushFront(2);
      Assert::AreEqual(list.Size(), 2);
      list.PushFront(3);
      Assert::AreEqual(list.Size(), 3);

      Assert::AreEqual(list.PopBack(), 1);
      Assert::AreEqual(list.Size(), 2);
      Assert::AreEqual(list.PopBack(), 2);
      Assert::AreEqual(list.Size(), 1);
      Assert::AreEqual(list.PopBack(), 3);
      Assert::AreEqual(list.Size(), 0);
      Assert::AreEqual(list.PopBack(), NULL);
      Assert::AreEqual(list.Size(), 0);
		}

    TEST_METHOD(PushBack_PopFront)
    {
			LinkedList list = LinkedList();
      list.PushBack(1);
      Assert::AreEqual(list.Size(), 1);
      list.PushBack(2);
      Assert::AreEqual(list.Size(), 2);
      list.PushBack(3);
      Assert::AreEqual(list.Size(), 3);

      Assert::AreEqual(list.PopFront(), 1);
      Assert::AreEqual(list.Size(), 2);
      Assert::AreEqual(list.PopFront(), 2);
      Assert::AreEqual(list.Size(), 1);
      Assert::AreEqual(list.PopFront(), 3);
      Assert::AreEqual(list.Size(), 0);
      Assert::AreEqual(list.PopFront(), NULL);
      Assert::AreEqual(list.Size(), 0);
    }

	};
}