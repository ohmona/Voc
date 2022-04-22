#pragma once

#include "header.h"
#include "Content.h"

class omn::SaveFile {
public:
	std::string currentPath;
	omn::Content* words;
	omn::Content* language;
	omn::Content* memo;

	omn::DataGridView* dgvptr;
public:
	std::string MakeDataToSave();
	void DataSave();
	void DataRead();
	//void ChangeOpenedFile();
	void SetCurrentPath(std::string str);
public:
	SaveFile();
};
