#pragma once
#include<map>
#include<vector>


class GceRule {
	std::map<std::string,std::string>m_ruleMap;
	std::vector<std::string>m_ruleDataVec;

public:
	bool bIsFileExists(std::string & fileName,std::ifstream & fd);
	bool bIsHasData(std::string & fileName,std::ifstream & fd);
	bool loadRuleFile(std::string & fileName);
	bool pushToRuleMap();
	bool isRuleMapEmpty();
	std::string getRule(std::string & first,std::string & second , std::string & third , std::string & forth , std::string & fifth);
};