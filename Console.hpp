#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <deque>

class Console
{
private:
	static std::deque<std::string> Split(const std::string& s, char delimiter);
	static std::unordered_map <std::string, std::function<void(std::deque<std::string>)>> c0;
	static std::unordered_map <std::string, std::function<void()>> c1;
	static void Process(std::deque<std::string>);
public:
	static void Set(std::string, std::function<void(std::deque<std::string>)>);
	static void Set(std::string, std::function<void()>);
	static void ConsoleCommand(std::string);
};
