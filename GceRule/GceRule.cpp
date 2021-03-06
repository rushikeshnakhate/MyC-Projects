
#include<gtest/gtest.h>
#include <iostream>
#include "GceRule.h"
#include <fstream>
#include<boost/algorithm/string.hpp>
bool GceRule::isRuleMapEmpty() {
	if (m_ruleMap.empty()) return true;
	else return false;
}

bool GceRule::bIsFileExists(std::string & fileName, std::ifstream & fd)
{
	fd.open(fileName);
	if (!fd) {
		return false;
	}
	return true;
}
bool GceRule::pushToRuleMap() {
	if (m_ruleDataVec.empty())  return false;
	std::vector<std::string>::iterator itr;
	for (itr = m_ruleDataVec.begin(); itr != m_ruleDataVec.end(); ++itr) {
		std::vector<std::string>lineVec;
		boost::split(lineVec, *itr, boost::is_any_of("^"));
		if (lineVec.size() < 2) return false;
		std::string key = lineVec[0];
		std::string value = lineVec[1];
		m_ruleMap.insert(std::pair<std::string, std::string>(key, value));
	}
	return true;
}

bool GceRule::bIsHasData(std::string & fileName, std::ifstream & fd) {
	std::string line;
	int count = 0;
	while (fd >> line) {
		count++;
		m_ruleDataVec.push_back(line);
	}
	if (count < 1) return false;
	else 	return true;
}

bool GceRule::loadRuleFile(std::string & fileName) {
	if (fileName.empty())
		return false;
	std::ifstream fd;
	if (!bIsFileExists(fileName, fd))  return false;
	if (!bIsHasData(fileName, fd)) return false;
	if (!pushToRuleMap()) return false;
	return true;
}
std::string  GceRule::getRule(std::string & first, std::string & second, std::string & third, std::string & forth, std::string & fifth) {
	std::map<std::string, std::string>::iterator  itr;

	std::string value = "DEFAULT_RULE";
	for (itr = m_ruleMap.begin(); itr != m_ruleMap.end(); ++itr) {
		std::string key = itr->first;
		std::vector<std::string>ruleKeyVec;
		boost::split(ruleKeyVec, key, boost::is_any_of(","));
		bool bFirst(false);
		bool bSecond(false);
		bool bthird(false);
		bool bForth(false);
		bool bFifth(false);

		if (ruleKeyVec[0] == "*")
			bFirst = true;
		else if (first == ruleKeyVec[0])
			bFirst = true;

		if (ruleKeyVec[1] == "*")
			bSecond = true;
		else if (second == ruleKeyVec[1])
			bSecond = true;

		if (ruleKeyVec[2] == "*")
			bthird = true;
		else if (third == ruleKeyVec[2])
			bthird = true;

		if (ruleKeyVec[3] == "*")
			bForth = true;
		else if (forth == ruleKeyVec[3])
			bForth = true;

		if (ruleKeyVec[4] == "*")
			bFifth = true;
		else if (fifth == ruleKeyVec[4])
			bFifth = true;

		if (bFirst && bSecond && bthird && bForth && bFifth) 
			value = itr->second;
	}
	return value;

}

int main(int argc , char **argv )
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

