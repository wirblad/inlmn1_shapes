#include <gtest/gtest.h>

//#include <C:\msys64\mingw64\include\gtest\gtest.h>
//#include <C:\msys64\mingw64\include\gtest\internal\gtest-internal.h>

extern "C" {
#include "shapes.h"
//#include "safeinput.h"
#include "calculator.h"
}

class ShapesTest : public testing::Test{
protected:
	void SetUp() override {
	}
};

class CalcTest : public testing::Test{
protected:
	void SetUp() override {
	}
};

TEST_F(ShapesTest,testAreaofRectangle){

    float area = calc_area_rectangle(5, 5);
    ASSERT_EQ(area, 25);
}

TEST_F(ShapesTest,testPerimeterofRectangle){
   
    float perimeter = calc_perimeter_rectangle(5, 5);
    ASSERT_EQ(perimeter, 20);
}

TEST_F(ShapesTest,testAreaofparallelogram){
  
    float area = calc_area_parallelogram(5,6);
    ASSERT_EQ(area, 30);
}

TEST_F(ShapesTest,testPerimeterofparallelogram){
  
    float perimeter = calc_perimeter_parallelogram(7,9);
    ASSERT_EQ(perimeter, 32);
}

TEST_F(ShapesTest,testAreaoftriangle){
  
    float area = calc_area_triangle(4.5, 5.5);
    ASSERT_EQ(area, 12.375);
}

TEST_F(ShapesTest,testPerimeteroftriangle){
  
    float perimeter = calc_perimeter_triangle(4.5, 6.5, 3.5);
    ASSERT_EQ(perimeter, 14.5);
}

TEST_F(ShapesTest,testAreaofCircle){
  
    double area = calc_area_circle(6.0);
    ASSERT_EQ(area, 18.84);
}

TEST_F(ShapesTest,testPerimeterofCircle){
  
    double perimeter = calc_perimeter_circle(6.0);
    ASSERT_EQ(perimeter, 37.68);
}

TEST_F(CalcTest,testaddition){
  
    float sum = add(13.5,15.5);
    ASSERT_EQ(sum, 29);
}

TEST_F(CalcTest,testsubtraction){
  
    float sum = subtraction(13.5,15.5);
    ASSERT_EQ(sum, -2);
}

TEST_F(CalcTest,testmultiplie){
  
    double sum = multiplie(4.5,4.5);
    ASSERT_EQ(sum, 20.25);
}

TEST_F(CalcTest,testdivision){
  
    double sum = division(4.5,16);
    ASSERT_EQ(sum, 0.28125);
}

TEST_F(CalcTest,testmodulus){
  
    int remainder = modulus(7,3);
    ASSERT_EQ(remainder, 1);
}