#include "header.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args) {

#ifdef _DEBUG
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Notification::MyForm form;
	Application::Run(% form);
}

void MyArea::DataGridView::AddRow() {
	Row++;
	Notification::MyForm::form->AddRow();
}

void MyArea::DataGridView::AddItem(System::String^ content, int Yindex, int Xindex) {
	Notification::MyForm::form->dataGridView1->Rows[Yindex]->Cells[Xindex]->Value = content;
}

void MyArea::DataGridView::AddItem(Content words) {
	for (int i = 0; i < words.contents.size(); i++) {
		AddRow();
		Notification::MyForm::form->dataGridView1->Rows[i]->Cells[0]->Value = ToSystemString(words.contents[i][0]);
		Notification::MyForm::form->dataGridView1->Rows[i]->Cells[1]->Value = ToSystemString(words.contents[i][1]);
	}
}

int MyArea::DataGridView::GetRowCount() {
	return Row;
}

void MyArea::DataGridView::ClearRow() {
	Row = 1;
	Notification::MyForm::form->dataGridView1->Rows->Clear();
}

void MyArea::DataGridView::ResetRowCount() {
	Row = Notification::MyForm::form->dataGridView1->Rows->Count;
}

System::Object^ MyArea::DataGridView::GetValue(int Row, int Column) {
	return Notification::MyForm::form->dataGridView1->Rows[Row]->Cells[Column]->Value;
}

std::string MyArea::Content::SplitContent() {
	// �ܾ� ����
	switch (contentType) {
	case 0:
		if (contentType == 0) {
			// word:�ܾ�|world:����|sand:��
			System::String^ str;
			str = ToSystemString(content);
			array<System::String^>^ wordArr;
			wordArr = str->Split(WORDS_SPE);
			std::vector<std::vector<std::string>> transArr;
			for (int i = 0; i < wordArr->Length - 1; i++) {
				array<System::String^>^ temp = wordArr[i]->Split(TRANSLATION_SPE);

				const int newsize = transArr.size() + 1;
				transArr.resize(newsize);
				transArr[i].resize(2);
				transArr[i][0] = ToStdString(temp[0]);
				transArr[i][1] = ToStdString(temp[1]);
			}
			//��1�� �� ���ٶ����� 30�о�;;
			contents.resize(transArr.size());
			contents = transArr;
		}
		break;
	case 1:
		// deutsch:�ѱ���
		break;

	case 2:
		// hello world
		break;

	default:
		break;
	}
	return "";
}

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>

using namespace System::Windows::Forms;

namespace fs = std::experimental::filesystem;

void MyArea::ProgramFile::MakePFile() {
	System::Console::WriteLine("FOLDER EXSIST!");
	std::ofstream creator;
	creator.open(GetPPath() + FILE_PATH, std::ofstream::out);
	creator << "";
	if (creator.is_open()) {
		creator << ToStdString(GetPathWithDefaultFile());
	}
	else {
		System::Console::WriteLine("THIS SHOULD NOT HAPPEN SOMETHING WENT WRONG");
	}
	creator.close();
}

void MyArea::ProgramFile::MakePFolder() {
	System::Console::WriteLine("FOLDER NOT EXSIST! CREATE A FOLDER");
	fs::create_directory(GetPPath());
	tryagain();
}

void MyArea::ProgramFile::tryagain() {
	FileReader.open(GetPPath() + FILE_PATH, std::ifstream::in);

	if (FileReader.is_open()) {
		ReadPFile();
	}
	else {
		if (fs::exists(GetPPath())) {
			MakePFile();
		}
		else {
			MakePFolder();
		}
	}
}

void MyArea::ProgramFile::ReadPFile() {
	std::string buffer;
	while (!FileReader.eof()) {
		getline(FileReader, buffer);
		std::cout << "���� : " << buffer << std::endl;
		ChangePath(ToSystemString(buffer));
	}
}

System::String^ MyArea::ProgramFile::GetPathWithDefaultFile() {
	System::Windows::Forms::FolderBrowserDialog^ Picker;
	Picker = gcnew System::Windows::Forms::FolderBrowserDialog;

	System::Windows::Forms::DialogResult result = Picker->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK) {
		std::ofstream output;
		output << "";
		System::String^ returnVal = Picker->SelectedPath + "\\words.vcb";
		//Notification::MyForm::Text = returnVal;
		return returnVal;

	}
}

std::string MyArea::ProgramFile::GetPPath() {
	System::String^ path = gcnew System::String(getenv("APPDATA")) + "\\Voc\\";
	return ToStdString(path);
}

void MyArea::ProgramFile::UpdateDefaultPath(std::string str) {
	std::ofstream creator;
	creator.open(GetPPath() + FILE_PATH, std::ofstream::out);
	creator << str;
}

void MyArea::ProgramFile::ChangePath(System::String^ str) {
	Notification::MyForm::form->sf->SetCurrentPath(ToStdString(str)); // error!
	Notification::MyForm::form->ChangeText(str);
}

void MyArea::ProgramFile::ChangePath() {
	OpenFileDialog^ Picker;
	Picker = gcnew System::Windows::Forms::OpenFileDialog;
	Picker->Filter = "txt files (*.txt)|*.txt|vcb files(*.vcb)|*.vcb";
	Picker->FilterIndex = 2;

	DialogResult result = Picker->ShowDialog();
	if (result == DialogResult::OK) {
		Notification::MyForm::form->sf->SetCurrentPath(ToStdString(Picker->FileName));
		Notification::MyForm::form->ChangeText(ToSystemString(Notification::MyForm::form->sf->currentPath));
		std::cout << "Selected Path : " << Notification::MyForm::form->sf->currentPath << std::endl;
	}
}

// dgv ���� ������ ���� �� �� �ٷ� ����
std::string MyArea::SaveFile::MakeDataToSave() {
	int Row = Notification::MyForm::form->dgvptr->GetRowCount();
	std::string saveData;
	for (int i = 0; i < Row; i++) {
		System::String^ first;
		System::String^ second;
		std::string str1 = "";
		std::string str2 = "";
		bool succeed = false;

		if (Notification::MyForm::form->dgvptr->GetValue(i, 0)) {
			first = Notification::MyForm::form->dgvptr->GetValue(i, 0)->ToString();
			str1 = ToStdString(first);
			succeed = true;
		}
		if (Notification::MyForm::form->dgvptr->GetValue(i, 1)) {
			second = Notification::MyForm::form->dgvptr->GetValue(i, 1)->ToString();
			str2 = ToStdString(second);
			succeed = true;
		}
		if (succeed) {
			saveData += (str1 + TRANSLATION_SPE + str2 + WORDS_SPE);
		}
	}
	std::cout << saveData << std::endl;
	return saveData;
}

void MyArea::SaveFile::DataRead() {
	Notification::MyForm::form->programFile->UpdateDefaultPath(currentPath);
	System::String^ tempPath = ToSystemString(currentPath);

	std::ifstream fileReader;
	fileReader.open(ToStdString(tempPath));

	std::string content;

	if (fileReader.is_open()) {
		std::cout << "������ ���Ƚ��ϴ� : inputStream" << std::endl;
		std::cout << "��� : " << ToStdString(tempPath) << std::endl;
		Notification::MyForm::form->dgvptr->ClearRow();

		int index = 0;
		while (!fileReader.eof()) {
			// ToDo save �ȵŴ� ���� ���� + �б���� ����
			getline(fileReader, content);
			switch (index) {
			case 0:
				Console::WriteLine("content section");
				words->SetContent(content);
				words->SplitContent();
				Notification::MyForm::form->dgvptr->AddItem(*words);
				// AddItem
				break;
			case 1:
				language->SetContent(content);
				Console::WriteLine("language section");
				std::cout << content << std::endl;
				// TODO: ���� ���
				// Set Language
				break;
			case 2:
				Console::WriteLine("memo section");
				memo->SetContent(content);
				// SetMemo
				break;
			default:
				std::cout << "���� ������" << std::endl;
			}
			index++;
		}
		index = 0;
	}
	else {
		std::cout << currentPath << std::endl;
		std::cout << "������ �� �� ���ų�, ã�� �� �����ϴ�!" << std::endl;
		std::cout << "������ �����մϴ�" << std::endl;
		DataSave(); // deprecated
	}
	Notification::MyForm::form->dgvptr->ResetRowCount();
	fileReader.close();
}

void MyArea::SaveFile::SetCurrentPath(std::string str) {
	currentPath = str;
}

// Content Ŭ������ ����Ͽ� �����ϴ°� ���߿� ������ �ϴ� �׽�Ʈ�� �ؼ� SaveFile�� �ִ� �Լ� ���
void MyArea::SaveFile::DataSave() {
	System::String^ path = ToSystemString(currentPath);
	std::ofstream out(currentPath);

	if (out.is_open()) {
		std::cout << "������ ���Ƚ��ϴ� : outputStream" << std::endl;
		std::cout << "��� : " << currentPath << std::endl;
		std::string savedata = MyArea::SaveFile::MakeDataToSave();
		std::cout << savedata << std::endl;
		out << savedata;

		System::String^ message = "File successfully saved in \n" + ToSystemString(currentPath);
		System::Windows::Forms::MessageBox::Show(message, "Congratulations!");
		System::Console::WriteLine(path + "�� ����ž����ϴ�.");
	}
	else {
		std::cout << "��θ� ã�� �� �����ϴ�!" << std::endl;
	}
	out.close();
}

void MyArea::SaveFile::ChangeOpenedFile() {
	Notification::MyForm::form->programFile->ChangePath();
}