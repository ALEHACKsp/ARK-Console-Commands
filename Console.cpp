#include "Console.hpp"

std::unordered_map <std::string, std::function<void(std::vector<std::string>)>> Console::Commands{};

std::vector<std::string> Console::Split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void Console::Set(std::string cmd, std::function<void(std::vector<std::string>)> func)
{
	std::pair<std::string, std::function<void(std::vector<std::string>)>> ins(cmd, func);
	Commands.insert(ins);
}

void Console::ToString()
{
	for (auto i : Commands)
	{
		std::cout << &i.second << " " << i.first << std::endl;
	}
}

void Console::ConsoleCommand(std::string cmd)
{
    auto Args = Split(cmd, ' ');
    Process(Args);
}

void Console::Process(std::vector<std::string> args)
{
    if (args.size() > 0)
    {
        if (Commands.find(args[0]) != Commands.end())
        {
            Commands[args[0]](args);
        }
    }
}
