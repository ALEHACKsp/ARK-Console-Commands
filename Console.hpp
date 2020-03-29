#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <functional>

class Console
{
private:
	static std::vector<std::string> Split(const std::string& s, char delimiter);
  static std::unordered_map <std::string, std::function<void(std::vector<std::string>)>> Commands;
  static void Process(std::vector<std::string>);
public:
	static void Set(std::string, std::function<void(std::vector<std::string>)>);
	static void ConsoleCommand(std::string);
	static void ToString();
};
