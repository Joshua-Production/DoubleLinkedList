#include "pch.h"
#include "CppUnitTest.h"
#include "../DoubleLinkedList/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListTests
{
	TEST_CLASS(DoubleLinkedListTests)
	{
	public:
		
		TEST_METHOD(DefualtConstructor)
		{
			List<int> list;
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(list.last(), 0);
			Assert::AreEqual(list.getLength(), 0);
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = { 9, 8, 7, 6, 5 };
			Assert::AreEqual(list.first(), 9);
			Assert::AreEqual(list.last(), 5);
			Assert::AreEqual(list.getLength(), 5);
				
			Iterator<int> iter = list.begin();
			Assert::AreEqual(9, *iter);
			iter++;
			Assert::AreEqual(8, *iter);
			iter++;
			Assert::AreEqual(7, *iter);
			iter++;
			Assert::AreEqual(6, *iter);
			iter++;
			Assert::AreEqual(5, *iter);
			Assert::AreEqual(list.getLength(), 5);
		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			list.pushFront(1);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 1);

			list.pushFront(2);
			Assert::AreEqual(list.first(), 2);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 2);

			list.pushFront(3);
			Assert::AreEqual(list.first(), 3);
			Assert::AreEqual(*(list.begin()++), 2);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 3);
		}
		TEST_METHOD(PushBack)
		{
			List<int> list;
			list.pushBack(1);  
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 1);

			list.pushBack(2);  
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 2);
			Assert::AreEqual(list.getLength(), 2);

			list.pushBack(3);  
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 3);
			Assert::AreEqual(*(list.end()--), 2);  
			Assert::AreEqual(list.getLength(), 3);
		}
	};
}
