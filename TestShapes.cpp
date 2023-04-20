#include <gtest/gtest.h>

//#include <C:\msys64\mingw64\include\gtest\gtest.h>
//#include <C:\msys64\mingw64\include\gtest\internal\gtest-internal.h>

extern "C" {
#include "shapes.h"
#include "safeinput.h"
#include "calculator.h"
}

class ShapesTest : public testing::Test{
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

TEST_F(ShapesTest,justafirsttest){
    //ARRANGE

    //ACT
    //Withdraw_Status status = atmWithdraw("AAA111223",100);
    int test = rectangle();

    //ASSERT
    ASSERT_EQ(test,  1);
}