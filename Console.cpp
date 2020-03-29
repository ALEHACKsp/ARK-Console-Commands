#include "Console.hpp"

std::unordered_map <std::string, std::function<void(std::deque<std::string>)>> Console::c0{};
std::unordered_map <std::string, std::function<void()>> Console::c1{};

std::deque<std::string> Console::Split(const std::string& s, char delimiter)
{
    std::deque<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void Console::Set(std::string cmd, std::function<void(std::deque<std::string>)> func)
{
	std::pair<std::string, std::function<void(std::deque<std::string>)>> ins(cmd, func);
	c0.insert(ins);
}

void Console::Set(std::string cmd, std::function<void()> func)
{
    std::pair<std::string, std::function<void()>> ins(cmd, func);
    c1.insert(ins);
}

void Console::ConsoleCommand(std::string cmd)
{
    auto Args = Split(cmd, ' ');
    Process(Args);
}

void Console::Process(std::deque<std::string> args)
{
    if (args.size() > 1)
    {
        if (c0.find(args[0]) != c0.end())
        {
            auto cmd = args[0];
            args.pop_front();
            c0[cmd](args);
        }
    }
    else
    {
        if (c1.find(args[0]) != c1.end())
        {
            c1[args[0]]();
        }
    }
}
