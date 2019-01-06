#include<gtest/gtest.h>
#include "GceRule.h"

TEST(loadRuleFile, when_filename_Empty_then_no_rule) {
	GceRule obj;
	std::string fileName;
	EXPECT_FALSE(obj.loadRuleFile(fileName));
}

TEST(loadRuleFile, when_file_not_exists_then_no_rule) {
	GceRule obj;
	std::string fileName = "rushi1.rule";
	EXPECT_FALSE(obj.loadRuleFile(fileName));
}

TEST(loadRuleFile, when_filename_Empty_then_no_rule_Test) {
	GceRule obj;
	std::string fileName = "Emptyfile.rule";
	EXPECT_FALSE(obj.loadRuleFile(fileName));
}
TEST(pushToRuleMap, when_empty_line_then_no_rule) {
	GceRule obj;
	EXPECT_FALSE(obj.pushToRuleMap());
}

TEST(pushToRuleMap, when_rule_passed_then_loaded_to_map) {
	GceRule obj;
	std::string fileName = "rushi.rule";
	obj.loadRuleFile(fileName);
	obj.pushToRuleMap();
	EXPECT_FALSE(obj.isRuleMapEmpty());
}

TEST(getRule, when_first_rule_matched_then_rule_fetched) {
	GceRule obj;
	std::string fileName = "rushi.rule";
	obj.loadRuleFile(fileName);
	obj.pushToRuleMap();
	std::string first = "FIRST";
	std::string second = "SECOND";
	std::string third = "THIRD";
	std::string forth, fifth;
	EXPECT_EQ(obj.getRule(first, second, third, forth, fifth), "FIRST_RULE");
}

TEST(getRule, when_second_rule_matched_then_rule_fetched) {
	GceRule obj;
	std::string fileName = "rushi.rule";
	obj.loadRuleFile(fileName);
	obj.pushToRuleMap();
	std::string first = "FIRST";
	std::string second = "SECOND";
	std::string third;
	std::string forth = "FORTH";
	std::string fifth ;
	std::string value = obj.getRule(first, second, third, forth, fifth);
	EXPECT_EQ(value, "SECOND_RULE");
}
