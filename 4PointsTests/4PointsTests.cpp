
#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" {
	#include "../PolygonChecker/rectangle.c"
	#include "../PolygonChecker/rectangle.h"
	RECTANGLE createRectangle(double pointsX[], double pointsY[]);
	bool isRectangle(RECTANGLE);
	double getArea(RECTANGLE);
	double getPerimeter(RECTANGLE);
}
namespace My4PointsTests
{
	TEST_CLASS(My4PointsTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double pointsX[4] = { 0,3,3,0 };
			double pointsY[4] = { 0,0,4,4 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			bool expected = true;

			Assert::AreEqual(expected, isRectangle(rect));
		}
	};
}
