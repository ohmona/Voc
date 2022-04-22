#pragma once

#include "header.h"

/*
*	load latest opened path,
*   whether memo section should be opened
*/
class omn::ProgramFile {
public:
	ProgramFile();

public:
	std::string last_opened_path;
	std::string current_path;

	bool should_open_memo;

private:
	std::ifstream FileReader;
	//std::string buffer;

public:
	void MakePFile();
	void MakePFolder();
	void ReadPFile();
	System::String^ GetPathWithDefaultFile();
	static std::string GetPPath();
	void UpdateDefaultPath(std::string str); // UpdatePath()
	void UpdateMemoInfo();

	void ChangePath(System::String^ str);
	void ChangePath();
	void tryagain();
};