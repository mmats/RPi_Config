#include "Config.h"

#include <unistd.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <iterator>

Config::Config(std::string filename)
{
    std::ifstream file(filename);

    std::string str;
    std::vector<std::string> v1{};
    while (std::getline(file, str))
    {
    	v1.push_back(str);
    }

    std::string var, val;
    for (auto const &n : v1)
    {
    	getLineContent(n,&var,&val);
    	entries.push_back(std::make_pair(var,val));
    }
}

int Config::translate2Int(std::string name)
{
	std::string value = loadFromVector(name);
	if( !value.empty() )
		return std::stoi( value );
	return 0;
}
double Config::translate2Double(std::string name)
{
	std::string value = loadFromVector(name);
	if( !value.empty() )
		return std::stod( value );
	return 0.0;
}
std::string Config::translate2String(std::string name)
{
	std::string value = loadFromVector(name);
	if( !value.empty() )
		return value;
	return "-";
}

std::string Config::loadFromVector(std::string varname)
{
	for (auto const &n : entries)
	{
		if( varname.compare(n.first)==0 )
		{
			return n.second;
		}
	}
	return "";
}
void Config::getLineContent( std::string text, std::string* variable, std::string* value )
{
    std::string strTmp;
    std::size_t signPos = text.find( "=" );

    strTmp = text.substr( 0, signPos );
    if( strTmp == "null" )
    	*variable = "";
    else
    	*variable = strTmp;

    strTmp = text.substr( signPos+1, text.length() );
    if( strTmp == "null" )
    	*value = "";
    else
    	*value = strTmp;
}
