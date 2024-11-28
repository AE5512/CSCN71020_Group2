#include "pch.h"
#include "CppUnitTest.h"

extern "C" int triangleType(int* inputSides);
extern "C" void anglePrint(int* input); // the function to print off the angles
extern "C" double findingAngle(int a, int b, int c);
extern "C" int triangleType(int* inputSides);
extern "C" int isValidTriangle(int a, int b, int c);
extern "C" double distanceSquared(int x1, int y1, int x2, int y2);
extern "C" int isRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
extern "C" void checkRectangle();

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(triangleTest)
	{
	public:
		
		TEST_METHOD(isValid)
		{
			int input[3] = {9, 8, 7};
			int result = triangleType(input);

			Assert::AreNotEqual(0, result);

		}
		TEST_METHOD(isEquilateral)
		{
			int input[3] = { 5, 5, 5 };
			int result = triangleType(input);

			Assert::AreEqual(1, result);

		}
		TEST_METHOD(isScalene)
		{
			int input[3] = { 10, 7, 8 };
			int result = triangleType(input);

			Assert::AreEqual(3, result);

		}
		TEST_METHOD(isIsosceles)
		{
			int input[3] = { 10, 10, 9 };
			int result = triangleType(input);

			Assert::AreEqual(2, result);

		}TEST_METHOD(cantClose)
		{
			int input[3] = { 1, 7, 4 };
			int result = triangleType(input);

			Assert::AreEqual(0, result);

		}
		TEST_METHOD(zeros)
		{
			int input[3] = { 0, 0, 1 };
			int result = triangleType(input);

			Assert::AreEqual(0, result);

		}
		TEST_METHOD(negativeNumbers)
		{
			int input[3] = { -10, -7, 8 };
			int result = triangleType(input);

			Assert::AreEqual(0, result);

		}

	};
	TEST_CLASS(angleTest)
	{
	public:
		TEST_METHOD(angelA)
		{
			double result = round(findingAngle(10, 7, 8));
			double compare = 83;

			Assert::AreEqual(compare, result);

		}
		TEST_METHOD(angelB)
		{
			double result = round(findingAngle(7, 8, 10));
			double compare = 44;

			Assert::AreEqual(compare, result);

		}
		TEST_METHOD(AngelC)
		{
			double result = round(findingAngle(8, 10, 7));
			double compare = 53;

			Assert::AreEqual(compare, result);

		}TEST_METHOD(is180)
		{
			double angleA = round(findingAngle(10, 7, 8));
			double angleB = round(findingAngle(7, 8, 10));
			double angleC = round(findingAngle(8, 10, 7));
			double result = angleA + angleB + angleC;
			double compare = 180;

			Assert::AreEqual(compare, result);

		}
	};
	TEST_CLASS(rectangle)
	{
	public:
		TEST_METHOD(checkRectangle)
		{
			int x1 = 0;
			int y1 = 0;
			int x2 = 7;
			int y2 = 3;
			int x3 = 0;
			int y3 = 3;
			int x4 = 7;
			int y4 = 0;
			
			int result = isRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(1, result);

		}
		TEST_METHOD(checkPerimeter)
		{
			int x1 = 0;
			int y1 = 0;
			int x2 = 7;
			int y2 = 3;
			int x3 = 0;
			int y3 = 3;
			int x4 = 7;
			int y4 = 0;

			double side1 = sqrt(distanceSquared(x1, y1, x3, y3));
			double side2 = sqrt(distanceSquared(x2, y2, x3, y3));
			double result = 2 * (side1 + side2);
			double compare = 20;

			Assert::AreEqual(compare, result);

		}	
		TEST_METHOD(checkArea)
		{
			int x1 = 0;
			int y1 = 0;
			int x2 = 7;
			int y2 = 3;
			int x3 = 0;
			int y3 = 3;
			int x4 = 7;
			int y4 = 0;

			double side1 = sqrt(distanceSquared(x1, y1, x3, y3));
			double side2 = sqrt(distanceSquared(x2, y2, x3, y3));
			double result = (side1 * side2);
			double compare = 21;
			Assert::AreEqual(compare, result);

		}
	};
}
