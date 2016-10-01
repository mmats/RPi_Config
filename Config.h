#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <vector>
#include <initializer_list>

class Config
{
public:
	Config(std::string filename);

	        int translate2Int(std::string name);
	     double translate2Double(std::string name);
	std::string translate2String(std::string name);

private:
	std::string loadFromVector(std::string varname);
	void getLineContent( std::string text, std::string* variable, std::string* value );

	std::vector<std::pair<std::string, std::string>> entries{};
};

#endif /* CONFIG_H_ */
