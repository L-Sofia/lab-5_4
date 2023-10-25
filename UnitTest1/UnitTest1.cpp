#include "pch.h"
#include "CppUnitTest.h"
#include "../Project5_4 corr/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t;
			t = P2(9, 10, 10);
			Assert::AreEqual(t, 42.7282, 0.00001);

		}
	};
}
