#pragma once

#include "header.h"
#include "Content.h"

using namespace System::Windows::Forms;

class omn::DataGridView {
public:
	DataGridView();

	/* synced data table */
	std::vector<std::vector<std::string>> dataTable;
	/* synced language */
	std::string lang1;
	std::string lang2;
	/* synced memo */
	bool memo_visiblity;
	std::string memo;

	int Row;

public:
	void AddRow();

	void AddItem(System::String^ content, int Yindex, int Xindex);
	void AddItem(Content words);

	void SetLanguage(Content languages);
	void SetLanguage(System::String^ langu1, System::String^ langu2);
	std::vector<std::string> GetLanguage();

	void SetMemo(Content memo);
	std::string GetMemo();

	System::Object^ GetValue(int Row, int Column);

	int GetRowCount();
	void ClearRow();

public:

	// 파일에서 읽은 데이터의 종류
	enum ContentType {
		Words,
		Languages,
		Memo
	};
};