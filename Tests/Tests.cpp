#include "pch.h"
#include "CppUnitTest.h"
#include "../SmartPointersDLList/DoubleLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(ToString_ValidData_Success)
		{
			DLList list {1, 2, -3, 34, -70};
			Assert::IsTrue(list.to_string() == "[ 1 2 -3 34 -70 ]");
		}

		TEST_METHOD(EqualOperator_ValidData_Success)
		{
			DLList list_1{ 1, 2, -3, 34, -70 };
			DLList list_2{ 1, 2, -3, 34, -70 };
			DLList list_3{ 1, 2, -222, 333, 123 };
			
			Assert::IsTrue(list_1 == list_2 && list_1 != list_3);
		}

		TEST_METHOD(Clean_ValidData_Success)
		{
			DLList list{ 1, 2, -3, 34, -70 };
			list.clean();
			Assert::IsTrue(list.to_string() == "[ ]");
		}

		TEST_METHOD(PushBack_ValidData_Success)
		{
			DLList list{ 1, 2, -3, 34, -70 };
			list.push_back(22);
			DLList expected{ 1, 2, -3, 34, -70, 22 };
			Assert::IsTrue(list == expected);
		}

		TEST_METHOD(PushForward_ValidData_Success)
		{
			DLList list{ 1, 2, -3, 34, -70 };
			list.push_forward(22);
			DLList expected{ 22, 1, 2, -3, 34, -70};
			Assert::IsTrue(list == expected);
		}

		TEST_METHOD(PopBack_ValidData_Success)
		{
			DLList list{ 1, 2, -3, 34, -70 };
			list.pop_back();
			DLList expected{ 1, 2, -3, 34};
			Assert::IsTrue(list == expected);
		}

		TEST_METHOD(PopForward_ValidData_Success)
		{
			DLList list{ 1, 2, -3, 34, -70 };
			list.pop_forward();
			DLList expected{ 2, -3, 34, -70 };
			Assert::IsTrue(list == expected);
		}

		TEST_METHOD(HasElements_ValidData_Success)
		{
			DLList list_1{ 1, 2, -3, 34, -70 };
			DLList<int> list_2{};
			Assert::IsTrue(list_1.has_elements() == true && list_2.has_elements() == false);
		}

		TEST_METHOD(IsEmpty_ValidData_Success)
		{
			DLList list_1{ 1, 2, -3, 34, -70 };
			DLList<int> list_2{};
			Assert::IsTrue(list_1.is_empty() == false && list_2.is_empty() == true);
		}

		TEST_METHOD(CopyOperator_ValidData_Success)
		{
			DLList list_1 { 1, 2, -3, 34, -70 };
			DLList list_2 { 3, 4, 3213, 22, -33 };
			list_1 = list_2;
			bool result_1 = list_1 == list_2;
			list_2.push_back(20);
			bool result_2 = (list_1 != list_2);
			Assert::IsTrue(result_1 && result_2);
		}

		TEST_METHOD(MoveOperator_ValidData_Success)
		{
			DLList list_1 { 1, 2, -3, 34, -70 };
			DLList list_2 { 3, 4, 3213, 22, -33 };
			DLList list_3 { 1, 2, -3, 34, -70 };
			list_2 = std::move(list_3);
			Assert::IsTrue(list_1 == list_2);
		}

	};
}
