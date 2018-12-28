#include "LinkList.h"
#include <gtest/gtest.h>

TEST(add,when_add_then_verify_size_incremented) {
	LinkList obj;
	int element = -1;
	obj.add(10);
	obj.getLastElement(element);
	EXPECT_EQ(element,10);
}


TEST(add,when_updated_then_size_is_correct) {
	LinkList obj;
	EXPECT_EQ(obj.getSize(), 0);
	bool ret = obj.add(1);
	EXPECT_EQ(obj.getSize(), 1);
	ret = obj.add(2);
	EXPECT_EQ(obj.getSize(), 2);
}

TEST(add, when_element_append_then_element_is_added_at_end) {
	LinkList obj;
	bool ret = obj.add(10);
	ret = obj.add(20);
	ret = obj.add(30);
	int element=-1;
	obj.getLastElement(element);
	EXPECT_EQ(element, 30);
}

TEST(validateListSize, when_validateListSize_called_then_matches_to_List_size) {
	LinkList obj;
	bool ret = obj.add(55);
	obj.add(99);
	obj.add(33);
	EXPECT_EQ(obj.validateListSize(), obj.getSize());
}