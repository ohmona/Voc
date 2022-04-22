#include "DataGridView.h"

omn::DataGridView::DataGridView() {
	Row = 0;
}

void omn::DataGridView::AddRow() {
	Row++;
	//FORM->AddRow();
}

void omn::DataGridView::AddItem(System::String^ content, int Yindex, int Xindex) {
	//FORM->dataGridView1->Rows[Yindex]->Cells[Xindex]->Value = content;
	dataTable[Yindex][Xindex] = toStdStr(content);
}

void omn::DataGridView::AddItem(Content words) {
	for (int i = 0; i < words.contents.size(); i++) {
		AddRow();
		dataTable[i][0] = words.contents[i][0];
		dataTable[i][1] = words.contents[i][1];
	}
}

void omn::DataGridView::SetLanguage(Content languages) {
	lang1 = languages.smallContents[0];
	lang2 = languages.smallContents[1];
}

void omn::DataGridView::SetLanguage(System::String^ langu1, System::String^ langu2) {
	lang1 = toStdStr(langu1);
	lang2 = toStdStr(langu2);
}

std::vector<std::string> omn::DataGridView::GetLanguage() {
	std::vector<std::string> langs;
	langs.push_back(lang1);
	langs.push_back(lang2);
	return langs;
}

void omn::DataGridView::SetMemo(Content memo) {
	this->memo = memo.content;
}

std::string omn::DataGridView::GetMemo() {
	return memo;
}

int omn::DataGridView::GetRowCount() {
	return Row;
}

void omn::DataGridView::ClearRow() {
	Row = 1;
}

System::Object^ omn::DataGridView::GetValue(int Row, int Column) {
	return toSystemStr(dataTable[Row][Column]);
}