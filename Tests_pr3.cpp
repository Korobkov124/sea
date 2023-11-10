#include <sstream>

#include "pch.h"
#include "CppUnitTest.h"

#include "..\sea\Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testspr3
{
	TEST_CLASS(Testspr3)
	{
	public:
		
		TEST_METHOD(valid_read_fishes)
		{
			std::stringstream sin{ "abv abc adf" };
			const auto fishes = sea::read_fish(sin);
			Assert::IsTrue(fishes.size() == 3);
		}

		TEST_METHOD(valid_name_read_names_of_seas)
		{
			std::stringstream sin{ "\"Abc Bcd\"" };
			const auto seas_name = sea::read_name_of_sea(sin);
			Assert::IsTrue(seas_name == "Abc Bcd");
		}

		TEST_METHOD(valid_name_read_fullnames_of_seas)
		{
			std::stringstream sin{ "\"AbcBcd\"" };
			const auto seas_name = sea::read_name_of_sea(sin);
			Assert::IsTrue(seas_name == "AbcBcd");
		}

		TEST_METHOD(valid_init_name_depth_salinity_fishes)
		{
			std::stringstream sin{ "\"Abcde\" 515.0 717.5" };
			const auto vector = sea::read_sea(sin);
			Assert::IsTrue(vector[0].name == "Abcde");
			Assert::IsTrue(vector[0].depth == 515.0);
			Assert::IsTrue(vector[0].salinity == 717.5);
		}

		TEST_METHOD(invalid_read_fishes)
		{
			std::stringstream sin{ "abv abc adf" };
			const auto fishes = sea::read_fish(sin);
			Assert::IsFalse(fishes.size() != 3);
		}
		
		TEST_METHOD(invalid_name_read_fullnames_of_seas)
		{
			std::stringstream sin{ "\"AbcBcd\"" };
			const auto seas_name = sea::read_name_of_sea(sin);
			Assert::IsFalse(seas_name != "AbcBcd");
		}

		TEST_METHOD(invalid_name_read_names_of_seas)
		{
			std::stringstream sin{ "\"Abc Bcd\"" };
			const auto seas_name = sea::read_name_of_sea(sin);
			Assert::IsFalse(seas_name != "Abc Bcd");
		}

		TEST_METHOD(invalid_init_depth_is_double)
		{
			std::stringstream sin{ "\"Abcde\" 515.2 717.5" };
			const auto vector = sea::read_sea(sin);
			Assert::IsFalse(vector[0].depth == 515);
		}

		TEST_METHOD(invalid_init_salinity_is_double)
		{
			std::stringstream sin{ "\"Abcde\" 515.0 717.5" };
			const auto vector = sea::read_sea(sin);
			Assert::IsFalse(vector[0].salinity == 717);
		}

		TEST_METHOD(invalid_init_depth)
		{
			std::stringstream sin{ "\"Abcde\" 515.2 717.5" };
			const auto vector = sea::read_sea(sin);
			Assert::IsFalse(vector[0].depth != 515.2);
		}

		TEST_METHOD(invalid_init_salinity)
		{
			std::stringstream sin{ "\"Abcde\" 515.2 717.5" };
			const auto vector = sea::read_sea(sin);
			Assert::IsFalse(vector[0].salinity != 717.5);
		}
	};
}
