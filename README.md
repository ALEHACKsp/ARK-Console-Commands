# ARK-Console-Commands
Handles console commands with or without arguments

Example use:

```cpp
typedef sdk::FString* (*tConsoleCommand)(sdk::UConsole*, sdk::FString const&);
static tConsoleCommand rConsoleCommand{ nullptr }; // Fill in offset of function here

// UConsole::ConsoleCommand hook
	sdk::FString* hConsoleCommand(sdk::UConsole* this__, const sdk::FString* Command)
	{
		rConsoleCommand(this__, *Command);
		if (Command->IsValid())
		{ 
			Console::ConsoleCommand(Command->ToString());
		}
	}
```

```cpp
void InitConsoleHooks() {
  // Toggle aimbot and ESP
  Console::Set("aim",			[]() { bAimbot = !bAimbot; });
  Console::Set("esp",		  []() { bESP = !bESP; });
  
  // Get current FOV or set new FOV
  Console::Set("fov",			[]() { ARK->GetFOV(); });
  Console::Set("fov",			[](std::deque<std::string> args) { ARK->SetFOV(args); });
}
```

```cpp
// Definition of functions being called
void GetFOV();
void SetFOV(std::deque<std::string>);

void MyARK::GetFOV()
{
  std::cout << "Current FOV is " << MaxFOV << std::endl;
}

void MyARK::SetFOV(std::deque<std::string> Args)
{
  if (Args.size() > 0)
  {
    MaxFOV = std::stof(Args[0]);
    std::cout << "MaxFOV set to " << MaxFOV << std::endl;
  }
}
```
