#include <iostream>
#include <gtest/gtest.h>
#include<gmock/gmock.h>


int main(int agrc, char ** argv )
{
	::testing::InitGoogleTest(&agrc, argv);
		return RUN_ALL_TESTS();
}
