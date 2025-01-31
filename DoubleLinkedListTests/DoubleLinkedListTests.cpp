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
		TEST_METHOD(PushBack)
		{
			List<int> list;
			list.pushBack(1);
			Assert::AreEqual(1, list.first());      
			Assert::AreEqual(1, list.last());     
			Assert::AreEqual(1, list.getLength());  

			list.pushBack(2);
			Assert::AreEqual(1, list.first());      
			Assert::AreEqual(2, list.last());       
			Assert::AreEqual(2, list.getLength()); 

			list.pushBack(3);
			Assert::AreEqual(1, list.first());      
			Assert::AreEqual(3, list.last());     
			Assert::AreEqual(2, *(list.end()--));    
			Assert::AreEqual(3, list.getLength());
		}
		TEST_METHOD(PopFront)
		{

			List<int> list = { 1, 2, 3 };
			int value = list.popFront();
			Assert::AreEqual(1, value);
			Assert::AreEqual(2, list.first());
			Assert::AreEqual(2, list.getLength());

			value = list.popFront();
			Assert::AreEqual(2, value);
			Assert::AreEqual(3, list.first());
			Assert::AreEqual(1, list.getLength());

			value = list.popFront();
			Assert::AreEqual(3, value);
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


	};
}
