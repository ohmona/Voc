#include "header.h"
#include "MyForm.h"
#include "Langchanger.h"

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

void MyArea::DataGridView::SetLanguage(Content languages) {
	MyArea::Pointers::header1->HeaderText = ToSystemString(languages.smallContents[0]);
	MyArea::Pointers::header2->HeaderText = ToSystemString(languages.smallContents[1]);
}

void MyArea::DataGridView::SetLanguage(System::String^ lang1, System::String^ lang2) {
	MyArea::Pointers::header1->HeaderText = lang1;
	MyArea::Pointers::header2->HeaderText = lang2;
}

std::vector<std::string> MyArea::DataGridView::GetLanguage() {
	std::vector<std::string> langs;
	langs.push_back(ToStdString(MyArea::Pointers::header1->HeaderText));
	langs.push_back(ToStdString(MyArea::Pointers::header2->HeaderText));
	return langs;
}

void MyArea::DataGridView::SetMemo(Content memo) {
	Notification::MyForm::form->memoBox->Text = ToSystemString(memo.content);
}

std::string MyArea::DataGridView::GetMemo() {
	return ToStdString(Notification::MyForm::form->memoBox->Text);
}

int MyArea::DataGridView::GetRowCount() {
	return Row;
}

void MyArea::DataGridView::ClearRow() {
	Row = 1;
	Notification::MyForm::form->dataGridView1->Rows->Clear();
}

void MyArea::DataGridView::ResetRowCount() {
	Notification::MyForm::form->dataGridView1->Rows->Count;
}

System::Object^ MyArea::DataGridView::GetValue(int Row, int Column) {
	return Notification::MyForm::form->dataGridView1->Rows[Row]->Cells[Column]->Value;
}

void MyArea::DataGridView::ChangeSize(int height, int top) {
	Notification::MyForm::form->dataGridView1->Height = height;
	Notification::MyForm::form->dataGridView1->Top = top;
} 

void MyArea::DataGridView::ChangeSize(int height, int top, int down) {
	ChangeSize(height, top);
	Notification::MyForm::form->dataGridView1->Top = down * (-1);
}

std::string MyArea::Content::SplitContent() {
	// 단어 전용
	switch (contentType) {
	case 0:
		if (contentType == 0) {
			// word:단어|world:세계|sand:모래
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
			//시1발 이 한줄때문에 30분씀;;
			contents.resize(transArr.size());
			contents = transArr;
		}
		break;
	case 1:
		// deutsch:한국어
		System::String ^ str;
		str = ToSystemString(content);
		array<System::String^>^ arr;
		arr = str->Split(WORDS_SPE);
		smallContents.resize(2);
		smallContents[0] = ToStdString(arr[0]);
		smallContents[1] = ToStdString(arr[1]);
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
		std::cout << "내용 : " << buffer << std::endl;
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
	MyArea::Pointers::sf->SetCurrentPath(ToStdString(str)); // error!
	Notification::MyForm::form->ChangeText(str);
}

void MyArea::ProgramFile::ChangePath() {
	OpenFileDialog^ Picker;
	Picker = gcnew System::Windows::Forms::OpenFileDialog;
	Picker->Filter = "txt files (*.txt)|*.txt|vcb files(*.vcb)|*.vcb";
	Picker->FilterIndex = 2;

	DialogResult result = Picker->ShowDialog();
	if (result == DialogResult::OK) {
		MyArea::Pointers::sf->SetCurrentPath(ToStdString(Picker->FileName));
		Notification::MyForm::form->ChangeText(ToSystemString(MyArea::Pointers::sf->currentPath));
		std::cout << "Selected Path : " << MyArea::Pointers::sf->currentPath << std::endl;
	}
}

// dgv 에서 데이터 수집 후 한 줄로 묶기
std::string MyArea::SaveFile::MakeDataToSave() {
	MyArea::DataGridView* dgv = MyArea::Pointers::dgvptr;
	int Row = dgv->GetRowCount();
	std::string saveData;
	for (int i = 0; i < Row; i++) {
		System::String^ first;
		System::String^ second;
		std::string str1 = "";
		std::string str2 = "";
		bool succeed = false;

		/*
		* 저장 방식 : dgv 에서 매 칸마다에서 값을 불러옴
		* 희망 사항 : dgv가 업데이트 될때마다 SaveFile 클래스에 있는 Content words 인스턴스를 업데이트를 해주면서
		*			 저장할때는 그 인스턴스를 이용하여 저장
		*/

		if (dgv->GetValue(i, 0)) {
			first = dgv->GetValue(i, 0)->ToString();
			str1 = ToStdString(first);
			succeed = true;
		}
		if (dgv->GetValue(i, 1)) {
			second = dgv->GetValue(i, 1)->ToString();
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
	MyArea::Pointers::programFile->UpdateDefaultPath(currentPath);
	System::String^ tempPath = ToSystemString(currentPath);

	std::ifstream fileReader;
	fileReader.open(ToStdString(tempPath));

	std::string content;

	if (fileReader.is_open()) {
		std::cout << "파일이 열렸습니다 : inputStream" << std::endl;
		std::cout << "경료 : " << ToStdString(tempPath) << std::endl;
		MyArea::Pointers::dgvptr->ClearRow();

		int index = 0;
		while (!fileReader.eof()) {
			// ToDo save 안돼는 버그 수정 + 읽기버그 있음
			getline(fileReader, content);
			switch (index) {
			case 0:
				Console::WriteLine("content section");
				words->SetContent(content);
				words->SplitContent();
				MyArea::Pointers::dgvptr->AddItem(*words);
				// AddItem
				break;
			case 1:
				language->SetContent(content);
				language->SplitContent();
				Console::WriteLine("language section");
				std::cout << content << std::endl;
				MyArea::Pointers::dgvptr->SetLanguage(*language);
				// Set Language
				break;
			case 2:
				memo->SetContent(content);
				Console::WriteLine("memo section");
				if(content == EMPTY) std::cout << "memo doesn't exist!" << std::endl;
				else {
					std::cout << content << std::endl;
					MyArea::Pointers::dgvptr->SetMemo(*memo);
				}
				// SetMemo
				break;
			default:
				std::cout << "파일 다읽음" << std::endl;
			}
			index++;
		}
		index = 0;
	}
	else {
		std::cout << currentPath << std::endl;
		std::cout << "파일을 열 수 없거나, 찾을 수 없습니다!" << std::endl;
		std::cout << "파일을 생성합니다" << std::endl;
		DataSave(); // deprecated
	}
	MyArea::Pointers::dgvptr->ResetRowCount();
	fileReader.close();
}

void MyArea::SaveFile::SetCurrentPath(std::string str) {
	currentPath = str;
}

// Content 클래스를 사용하여 저장하는건 나중에 만들자 일단 테스트겸 해서 SaveFile에 있는 함수 사용
void MyArea::SaveFile::DataSave() {
	System::String^ path = ToSystemString(currentPath);
	std::ofstream out(currentPath);

	if (out.is_open()) {
		std::cout << "파일이 열렸습니다 : outputStream" << std::endl;
		std::cout << "경로 : " << currentPath << std::endl;
		// words저장
		std::string savedata = MyArea::SaveFile::MakeDataToSave();
		std::cout << savedata << std::endl;
		out << savedata << "\n";

		// language저장 임시!!
		std::vector<std::string> langs = MyArea::Pointers::dgvptr->GetLanguage();
		out << langs[0] << WORDS_SPE << langs[1] << "\n";

		// memo저장
		std::string memosavedata = MyArea::Pointers::dgvptr->GetMemo();
		if(memosavedata == "") out << EMPTY << "\n";
		else out << memosavedata << "\n";

		System::String^ message = "File successfully saved in \n" + ToSystemString(currentPath);
		System::Windows::Forms::MessageBox::Show(message, "Congratulations!");
		System::Console::WriteLine(path + "에 저장돼었습니다.");
	}
	else {
		std::cout << "경로를 찾을 수 없습니다!" << std::endl;
	}
	out.close();
}

void MyArea::SaveFile::ChangeOpenedFile() {
	MyArea::Pointers::programFile->ChangePath();
}

void Notification::LangChanger::ButtonClick() {
	if (textBox1->Text != " ") {
		count++;
		if (count == 1) {
			lang1 = textBox1->Text;
			this->label1->Text = L"please type your second language";
			this->textBox1->Text = "";
			this->textBox1->Select();
		}
		else if (count == 2) {
			lang2 = textBox1->Text;
			count = 0;
			MyArea::Pointers::dgvptr->SetLanguage(lang1, lang2);
			this->label1->Text = L"please type your first language";
			this->textBox1->Text = "";
			delete this;
		}
	}
	else {
		System::String^ message = "Please type your language in textbox";
		System::Windows::Forms::MessageBox::Show(message, "Warning");
	}
}