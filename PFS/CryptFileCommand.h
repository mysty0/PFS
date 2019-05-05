#pragma once
#include "CommandHandler.h"
#include "AsymmetricCryptedFile.h"

class CryptFileCommand :
	public CommandHandler
{
public:
	CryptFileCommand(FileSystem* file_system);
	~CryptFileCommand();

	// Inherited via CommandHandler
	virtual bool handle_command(std::string command, std::vector<std::string> args, std::ostream& stream) override;
};

