#include "pch.h"
#include "CppUnitTest.h"
#include "../ArrayList/ArrayList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayListTests
{
	TEST_CLASS(ArrayListTests)
	{
	public:
		
		TEST_METHOD(Part1_01Add)
		{
			// Empty list with capacity 8.
			ArrayList<double> list { 0, 8 };

			double init[8] = { 1.0, 1.5, 2.0, 2.5, 3.5, 4.0, 4.5, 5.0 };

			// Add elements to the list.
			for (unsigned int i = 0; i < 8; i++)
			{
				list.add(init[i]);

				// Check the list's size.
				Assert::AreEqual(i + 1, list.getSize(), L"Size");

				for (unsigned int j = 0; j <= i; j++)
				{
					// Check each element of the list.
					Assert::AreEqual(init[j], list[j], (L"Element at index " + std::to_wstring(j)).c_str());
				}
			}
		}

		TEST_METHOD(Part1_02Remove)
		{
			// List with 8 default-initialized elements.
			ArrayList<double> list { 8, 0 };

			// Remove elements from the list.
			for (unsigned int i = 8; i > 0; i--)
			{
				list.remove();

				// Check the list's size.
				Assert::AreEqual(i - 1, list.getSize(), L"Size");
			}
		}

		TEST_METHOD(Part1_03RemoveException)
		{
			// Empty list with capacity 8.
			ArrayList<double> list { 0, 8 };

			// Expect some sort of std::logic_error when attempting to remove from an empty list.
			Assert::ExpectException<std::logic_error>([&] { list.remove(); }, L"Removing from an empty list.");

			// Check the list's size.
			Assert::AreEqual(0u, list.getSize(), L"Size");
		}

		TEST_METHOD(Part1_04AddRemove)
		{
			// Empty list with capacity 8.
			ArrayList<double> list { 0, 8 };

			double init[8] = { 1.0, 1.5, 2.0, 2.5, 3.5, 4.0, 4.5, 5.0 };

			// Add elements to the list.
			for (unsigned int i = 0; i < 8; i++)
			{
				list.add(init[i]);

				// Check the list's size.
				Assert::AreEqual(i + 1, list.getSize(), L"Size");

				for (unsigned int j = 0; j < i + 1; j++)
				{
					// Check each element of the list.
					Assert::AreEqual(init[j], list[j], (L"Element at index " + std::to_wstring(j)).c_str());
				}
			}

			// Remove elements from the list.
			for (unsigned int i = 8; i > 0; i--)
			{
				list.remove();

				// Check the list's size.
				Assert::AreEqual(i - 1, list.getSize(), L"Size");

				for (unsigned int j = 0; j < i - 1; j++)
				{
					// Check each element of the list.
					Assert::AreEqual(init[j], list[j], (L"Element at index " + std::to_wstring(j)).c_str());
				}
			}
		}

		TEST_METHOD(Part1_05AddRemoveAdd)
		{
			// Empty list with capacity 8.
			ArrayList<double> list { 0, 8 };

			double init[8] = { 1.0, 1.5, 2.0, 2.5, 3.5, 4.0, 4.5, 5.0 };
			
			// Add elements to the list.
			for (unsigned int i = 0; i < 8; i++)
			{
				list.add(init[i]);

				// Check the list's size.
				Assert::AreEqual(i + 1, list.getSize(), L"Size");

				for (unsigned int j = 0; j < i + 1; j++)
				{
					// Check each element of the list.
					Assert::AreEqual(init[j], list[j], (L"Element at index " + std::to_wstring(j)).c_str());
				}
			}

			// Remove elements from the list.
			for (unsigned int i = 8; i > 0; i--)
			{
				list.remove();

				// Check the list's size.
				Assert::AreEqual(i - 1, list.getSize(), L"Size");

				for (unsigned int j = 0; j < i - 1; j++)
				{
					// Check each element of the list.
					Assert::AreEqual(init[j], list[j], (L"Element at index " + std::to_wstring(j)).c_str());
				}
			}

			// Add elements to the list.
			for (unsigned int i = 0; i < 8; i++)
			{
				list.add(init[8 - i - 1]);

				// Check the list's size.
				Assert::AreEqual(i + 1, list.getSize(), L"Size");

				for (unsigned int j = 0; j < i + 1; j++)
				{
					// Check each element of the list.
					Assert::AreEqual(init[8 - j - 1], list[j], (L"Element at index " + std::to_wstring(j)).c_str());
				}
			}
		}

		TEST_METHOD(Part1_06CopyConstructor)
		{
			// Empty list with capacity 8.
			ArrayList<double> list { 0, 8 };

			double init[8] = { 1.0, 1.5, 2.0, 2.5, 3.5, 4.0, 4.5, 5.0 };

			// Add elements to the list.
			for (unsigned int i = 0; i < 8; i++)
			{
				list.add(init[i]);

				// Check the list's size.
				Assert::AreEqual(i + 1, list.getSize(), L"Size");

				for (unsigned int j = 0; j < i + 1; j++)
				{
					// Check each element of the list.
					Assert::AreEqual(init[j], list[j], (L"Element at index " + std::to_wstring(j)).c_str());
				}
			}

			// Make a copy
			ArrayList<double> copy { list };

			// Check the list's size.
			Assert::AreEqual(8u, copy.getSize(), L"Size");

			for (unsigned int j = 0; j < 8; j++)
			{
				// Check each element of the list.
				Assert::AreEqual(init[j], copy[j], (L"Element at index " + std::to_wstring(j)).c_str());
			}
		}

		TEST_METHOD(Part1_07CopyAssignment)
		{
			// Empty list with capacity 8.
			ArrayList<double> list { 0, 8 };

			double init[8] = { 1.0, 1.5, 2.0, 2.5, 3.5, 4.0, 4.5, 5.0 };

			// Add elements to the list.
			for (unsigned int i = 0; i < 8; i++)
			{
				list.add(init[i]);

				// Check the list's size.
				Assert::AreEqual(i + 1, list.getSize(), L"Size");

				for (unsigned int j = 0; j < i + 1; j++)
				{
					// Check each element of the list.
					Assert::AreEqual(init[j], list[j], (L"Element at index " + std::to_wstring(j)).c_str());
				}
			}

			// Make a copy
			ArrayList<double> copy { 0, 4 };
			copy = list;

			// Check the list's size.
			Assert::AreEqual(8u, copy.getSize(), L"Size");

			for (unsigned int j = 0; j < 8; j++)
			{
				// Check each element of the list.
				Assert::AreEqual(init[j], copy[j], (L"Element at index " + std::to_wstring(j)).c_str());
			}
		}

		TEST_METHOD(Part2_Resizing)
		{
			ArrayList<int> list { 0, 1 };

			const unsigned int MAX_SIZE { 1000 };

			for (unsigned int i { 0 }; i < MAX_SIZE; i++)
			{
				list.add(i * i); // fill list with squares of numbers for testing

				Assert::AreEqual(i + 1, list.getSize());
				for (int j { 0 }; j <= i; j++)
				{
					Assert::AreEqual(j * j, list[j]);
				}
			}
		}
	};
}
