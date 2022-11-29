#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" {
#include "../PolygonChecker/triangleSolver.h";
#include "../PolygonChecker/triangleSolver.c"
	char* analyzeTriangle(int side1, int side2, int side3);
	double triAng(int side, int side1, int side2);
}
namespace TriangleTests
{
	TEST_CLASS(TriangleAnalysisTests)
	{
	public:
		
		TEST_METHOD(AnalyzeTriangle1)
		{
			char* expected = "Not a triangle";
			Assert::AreEqual(expected, analyzeTriangle(100, 0, 50));
		}
		TEST_METHOD(AnalyzeTriangle2)
		{
			char* expected = "Equilateral triangle";
			Assert::AreEqual(expected, analyzeTriangle(50, 50, 50));
		}
		TEST_METHOD(AnalyzeTriangle3)
		{
			char* expected = "Isosceles triangle";
			Assert::AreEqual(expected, analyzeTriangle(75, 75, 50));
		}
		TEST_METHOD(AnalyzeTriangle4)
		{
			char* expected = "Scalene triangle";
			Assert::AreEqual(expected, analyzeTriangle(30, 40, 50));
		}
	};

	TEST_CLASS(TriangleInsideAngleTests)
	{
	public:

		TEST_METHOD(TriAng1)
		{
			double expected = 180;
			Assert::AreEqual(expected, triAng(50, 40, 30));
		}
		TEST_METHOD(TriAng2)
		{
			double expected = 180;
			Assert::AreEqual(expected, triAng(50, 50, 50));
		}
		TEST_METHOD(TriAng3)
		{
			double expected = 180;
			Assert::AreEqual(expected, triAng(40, 40, 60));
		}
		TEST_METHOD(TriAng4)
		{
			double expected = 180;
			Assert::AreEqual(expected, triAng(40, 50, 60));
		}
	};
}
