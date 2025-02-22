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
			
			Assert::AreEqual(0, list.getLength());  
			Assert::AreEqual(0, list.first());      
			Assert::AreEqual(0, list.last());
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = { 9, 8, 7, 6, 5 };
			Assert::AreEqual(5, list.getLength());  
			Assert::AreEqual(9, list.first());      
			Assert::AreEqual(5, list.last());
				
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
			Assert::AreEqual(1, list.first());      
			Assert::AreEqual(1, list.last());      
			Assert::AreEqual(1, list.getLength()); 

			list.pushFront(2);
			Assert::AreEqual(2, list.first());     
			Assert::AreEqual(1, list.last());       
			Assert::AreEqual(2, list.getLength()); 

			list.pushFront(3);
			Assert::AreEqual(3, list.first());      
			Assert::AreEqual(2, *(list.begin()++));  
			Assert::AreEqual(1, list.last());       
			Assert::AreEqual(3, list.getLength());
		}
		
		TEST_METHOD(PopFront)
		{

			List<int> list = { 1, 2, 3 };
			list.popFront();
			
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(2, list.getLength());

			list.popFront();
			Assert::AreEqual(3, list.first());
			Assert::AreEqual(1, list.getLength());

			list.popFront();
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
		}

		TEST_METHOD(PopBack)
		{
			List<int> list = { 1, 2, 3 };
			int value = list.popBack();
			Assert::AreEqual(3, value);            
			Assert::AreEqual(2, list.last());       
			Assert::AreEqual(2, list.getLength());  

			value = list.popBack();
			Assert::AreEqual(2, value);            
			Assert::AreEqual(1, list.last());      
			Assert::AreEqual(1, list.getLength());  

			value = list.popBack();
			Assert::AreEqual(1, value);             
			Assert::AreEqual(0, list.getLength());  
			Assert::AreEqual(0, list.last());       
		}

		TEST_METHOD(Insert)
		{
			List<int> list;

			
			bool success = list.insert(1, 0);
			Assert::IsTrue(success);
			Assert::AreEqual(1, list.getLength());
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(1, list.last());

			success = list.insert(2, 1);
			Assert::IsTrue(success);
			Assert::AreEqual(2, list.getLength());
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(2, list.last());

			
			success = list.insert(3, 1);
			Assert::IsTrue(success);
			Assert::AreEqual(3, list.getLength());
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(3, *(++(list.begin()))); 
			Assert::AreEqual(2, list.last());

			
			success = list.insert(4, 3);
			Assert::IsTrue(success);
			Assert::AreEqual(4, list.getLength());
			Assert::AreEqual(1, list.first());
			Assert::AreEqual(4, list.last());
		}
		TEST_METHOD(Remove)
		{
			List<int> list{};
			Assert::IsNotNull(&list);

			list.pushBack(1);
			list.pushBack(0);
			list.pushBack(1);
			list.pushBack(2);
			list.pushBack(1);
			list.pushBack(3);
			list.pushBack(1);
			Assert::AreEqual(7, list.getLength());
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(1, *iter);

			
			int count = list.remove(1);
			Assert::AreEqual(4, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(*iter, list.first());
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::IsTrue(iter == nullptr);

			
			count = list.remove(5);
			Assert::AreEqual(0, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			
			list = List<int>();
			Assert::IsNotNull(&list);
			list.pushBack(3);
			list.pushBack(3);
			list.pushBack(3);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			list.remove(3);
			count = list.remove(3);
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
		}
		

	};
}
