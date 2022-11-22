
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
		
		TEST_METHOD(RectanlgeCase1)
		{
			double pointsX[4] = { 0,3,3,0 };
			double pointsY[4] = { 0,0,4,4 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			bool expected = true;

			Assert::AreEqual(expected, isRectangle(rect));
		}
		//\left(-2,-6\right),\left(1,-3\right),\left(-1,-1\right)\left(-4,-4\right)
		TEST_METHOD(RectanlgeCase2)
		{
			double pointsX[4] = { -2,1,-1,-4 };
			double pointsY[4] = { -6,-3,-1,-4 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			bool expected = true;

			Assert::AreEqual(expected, isRectangle(rect));
		}
		//\left(1,-3\right),\left(4,-3\right),\left(8,2\right),\left(4,2\right)
		TEST_METHOD(RectanlgeCase3)
		{
			double pointsX[4] = { 1,4,8,5 };
			double pointsY[4] = { -3,-3,2,2 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			bool expected = true;

			Assert::AreEqual(expected, isRectangle(rect));
		}

		TEST_METHOD(NotARectangleCase1)
		{
			double pointsX[4] = { 1,1,1,1 };
			double pointsY[4] = { 2,2,2,2 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			bool expected = false;

			Assert::AreEqual(expected, isRectangle(rect));
		}

		//\left(0,0\right),\left(2,0\right),\left(2,2\right),\left(0,2\right)
		TEST_METHOD(NotARectangleCase2)
		{
			double pointsX[4] = { 0,2,2,0 };
			double pointsY[4] = { 0,0,2,2 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			bool expected = false;

			Assert::AreEqual(expected, isRectangle(rect));
		}
		//\left(0,0\right),\left(4,3\right),\left(5,5\right),\left(1,20\right)
		TEST_METHOD(NotARectangleCase3)
		{
			double pointsX[4] = { 0,4,5,1 };
			double pointsY[4] = { 0,3,5,20 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			bool expected = false;

			Assert::AreEqual(expected, isRectangle(rect));
		}

		TEST_METHOD(RectangleArea1)
		{
			double pointsX[4] = { 0,3,3,0 };
			double pointsY[4] = { 0,0,4,4 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 12;

			Assert::AreEqual(expected, getArea(rect));
		}
		TEST_METHOD(RectangleArea2)
		{
			double pointsX[4] = { -2,1,-1,-4 };
			double pointsY[4] = { -6,-3,-1,-4 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 12;

			Assert::AreEqual(expected, getArea(rect));
		}

		TEST_METHOD(RectangleArea3)
		{
			double pointsX[4] = { 1,4,8,5 };
			double pointsY[4] = { -3,-3,2,2 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 19.2;

			Assert::AreEqual(expected, getArea(rect), 0.001);
		}

		TEST_METHOD(RectanglePerimeter1)
		{
			double pointsX[4] = { 0,3,3,0 };
			double pointsY[4] = { 0,0,4,4 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 14;

			Assert::AreEqual(expected, getPerimeter(rect));
		}

		TEST_METHOD(RectanglePerimeter2)
		{
			double pointsX[4] = { -2,1,-1,-4 };
			double pointsY[4] = { -6,-3,-1,-4 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 14.14;

			Assert::AreEqual(expected, getPerimeter(rect), 0.001);
		}
		TEST_METHOD(RectanglePerimeter3)
		{
			double pointsX[4] = { 1,4,8,5 };
			double pointsY[4] = { -3,-3,2,2 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 18.8;

			Assert::AreEqual(expected, getPerimeter(rect), 0.001);
		}

		TEST_METHOD(NotARectanglePerimeter1)
		{
			double pointsX[4] = { 1,1,1,1 };
			double pointsY[4] = { 2,2,2,2 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 0;

			Assert::AreEqual(expected, getPerimeter(rect));
		}

		TEST_METHOD(NotARectanglePerimeter2)
		{
			double pointsX[4] = { 0,2,2,0 };
			double pointsY[4] = { 0,0,2,2 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 8;

			Assert::AreEqual(expected, getPerimeter(rect), 0.001);
		}
		TEST_METHOD(NotARectanglePerimeter3)
		{
			double pointsX[4] = { 0,4,5,1 };
			double pointsY[4] = { 0,3,5,20 };
			RECTANGLE rect = createRectangle(pointsX, pointsY);
			double expected = 42.78;

			Assert::AreEqual(expected, getPerimeter(rect), 0.001);
		}
	};
}
