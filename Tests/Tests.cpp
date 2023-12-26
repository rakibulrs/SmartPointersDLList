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
			// arrange
			DLList list{ 1, 2, -3, 34, -70 };

			//assert
			Assert::IsTrue(list.to_string() == "[ 1 2 -3 34 -70 ]");
		}

		TEST_METHOD(EqualOperator_ValidData_Success)
		{
			// arrange
			DLList list_1{ 1, 2, -3, 34, -70 };
			DLList list_2{ 1, 2, -3, 34, -70 };

			//assert
			Assert::IsTrue(list_1 == list_2);
		}

		TEST_METHOD(NotEqualOperator_ValidData_Success)
		{
			// arrange
			DLList list_1{ 1, 2, -3, 34, -70 };
			DLList list_2{ 3, 4, 5, 34, -70 };

			//assert
			Assert::IsTrue(list_1 != list_2);
		}

		TEST_METHOD(Clean_ValidData_Success)
		{
			// arrange
			DLList list{ 1, 2, -3, 34, -70 };

			//act
			list.clean();

			//assert
			Assert::IsTrue(list.to_string() == "[ ]");
		}

		TEST_METHOD(PushBack_ValidData_Success)
		{
			// arrange
			DLList list{ 1, 2, -3, 34, -70 };
			DLList expected{ 1, 2, -3, 34, -70, 22 };

			//act
			list.push_back(22);

			//assert
			Assert::IsTrue(list == expected);
		}

		TEST_METHOD(PushForward_ValidData_Success)
		{
			// arrange
			DLList list{ 1, 2, -3, 34, -70 };
			DLList expected{ 22, 1, 2, -3, 34, -70 };

			//act
			list.push_forward(22);

			//assert
			Assert::IsTrue(list == expected);
		}

		TEST_METHOD(PopBack_ValidData_Success)
		{
			// arrange
			DLList list{ 1, 2, -3, 34, -70 };
			DLList expected{ 1, 2, -3, 34 };

			//act
			list.pop_back();

			//assert
			Assert::IsTrue(list == expected);
		}

		TEST_METHOD(PopForward_ValidData_Success)
		{
			// arrange
			DLList<int> list{ 1, 2, -3, 34, -70 };
			DLList<int> expected{ 2, -3, 34, -70 };

			//act
			list.pop_forward();

			//assert
			Assert::IsTrue(list == expected);
		}

		TEST_METHOD(HasElements_ValidData_Success)
		{
			// arrange
			DLList<int> list_1{ 1, 2, -3, 34, -70 };
			DLList<int> list_2;

			//assert
			Assert::IsTrue(list_1.has_elements());
			Assert::IsFalse(list_2.has_elements());
		}

		TEST_METHOD(IsEmpty_ValidData_Success)
		{
			// arrange
			DLList<int> list_1;
			DLList<int> list_2{ 1, 2, -3, 34, -70 };

			//assert
			Assert::IsTrue(list_1.is_empty());
			Assert::IsFalse(list_2.is_empty());
		}

		TEST_METHOD(CopyOperator_ValidData_Success)
		{
			// arrange
			DLList<int> list_1{ 1, 2, 3 };
			DLList<int> list_2;

			//act
			list_2 = list_1;

			//assert
			Assert::IsTrue(list_1 == list_2);
			Assert::IsTrue(list_1.to_string() == "[ 1 2 3 ]");
			Assert::IsTrue(list_2.to_string() == "[ 1 2 3 ]");
		}

		TEST_METHOD(MoveOperator_ValidData_Success)
		{
			// arrange
			DLList list_1{ 1, 2, -3, 34, -70 };
			DLList list_2{ 3, 4, 3213, 22, -33 };
			DLList list_3{ 1, 2, -3, 34, -70 };

			//act
			list_2 = std::move(list_3);

			//assert
			Assert::IsTrue(list_1 == list_2);
		}

		TEST_METHOD(Find_ValidData_Success)
		{
			// arrange
			DLList list_1{ 1, 2, -3, 34, -70 };

			//act
			int result_1 = list_1.find(-3);
			int result_2 = list_1.find(13);

			//assert
			Assert::IsTrue(result_1);
			Assert::IsFalse(result_2);
		}

	};
}
