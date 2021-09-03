#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args) {

#ifndef _DEBUG
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Notification::MyForm form;
	Application::Run(% form);
}

void Notification::MyForm::AddItem(DataGridView^ dgv, std::string content, int index) {

	String^ str = gcnew String(content.c_str());

	array<String^>^ arr = str->Split(SPE);

	// Console::WriteLine(str);

	for (int i = 0; i < 16; i++) {
		if (i < arr->Length) {
			//Console::WriteLine("arr 길이 : " + arr->Length);
			//Console::WriteLine((i + 1) + " 번쨰 인덱스 : " + arr[i]);
			if (i == 0) {
				dgv->Rows[index]->Cells[0]->Value = arr[i];
			}
			else if (i == 1) {
				dgv->Rows[index]->Cells[1]->Value = arr[i];
			}
		}
		else {
			break;
		}
	}
}

void Notification::MyForm::ReadFile() {
	UpdatePath(msclr::interop::marshal_as<std::string>(originPath->ToString()));
	System::String^ path = originPath;//s + richTextBox1->Text + EXTENSION;
	std::ifstream readFile;
	readFile.open(msclr::interop::marshal_as<std::string>(path));;

	DataGridView^ dgv = dataGridView1;

	std::string content;

	if (readFile.is_open()) {
		std::cout << "파일이 열렸습니다 : inputStream" << std::endl;
		std::cout << "경로 : " << msclr::interop::marshal_as<std::string>(path) << std::endl;
		Row = 1;
		int index = 0;
		dgv->Rows->Clear();
		while (true) {
			getline(readFile, content);
			if (readFile.eof()) {
				break;
			}
			AddRow();
			// std::cout << index << ".) " << content << std::endl;
			AddItem(dgv, content, index);
			index++;
		}
	}
	else {
		Console::WriteLine(path);
		std::cout << "파일을 열 수 없거나, 찾을 수 없습니다!" << std::endl;
		std::cout << "파일을 생성합니다" << std::endl;
		SaveFile();
	}
	Row = dgv->Rows->Count;
	readFile.close();
}

void Notification::MyForm::AddRow() {
	DataGridView^ dgv = dataGridView1;
	dgv->Rows->Add();
	Row++;
	// Console::WriteLine("Row added : " + Row);
}

//void Notification::MyForm::ReadFile(System::String^ path) {
//	System::String^ original = richTextBox1->Text;
//	richTextBox1->Text = path;
//	ReadFile();
//	richTextBox1->Text = original;
//}

void Notification::MyForm::SaveFile() {
	System::String^ path = originPath;
	std::ofstream out(msclr::interop::marshal_as<std::string>(path));

	if (out.is_open()) {
		std::cout << "파일이 열렸습니다 : outputStream" << std::endl;
		std::cout << "경로 : " << msclr::interop::marshal_as<std::string>(path) << std::endl;
		for (int i = 0; i < Row; i++) {
			// 파일이 없으면 여기까지 접근 안됌

			System::String^ first;
			System::String^ second;
			std::string str1 = "";
			std::string str2 = "";
			bool succeed = false;
			if (dataGridView1->Rows[i]->Cells[0]->Value) {
				first = dataGridView1->Rows[i]->Cells[0]->Value->ToString();
				str1 = msclr::interop::marshal_as<std::string>(first);
				// Console::WriteLine("first succeed");
				succeed = true;
			}
			if (dataGridView1->Rows[i]->Cells[1]->Value) {
				second = dataGridView1->Rows[i]->Cells[1]->Value->ToString();
				str2 = msclr::interop::marshal_as<std::string>(second);
				// Console::WriteLine("second succeed");
				succeed = true;
			}
			if (succeed) {
				// dgv에 있는 모든 컨텐츠들을 :로 나눠서 보관
				std::string save = str1
					+ SPE
					+ str2
					+ "\n";
				out << save;
			}
		}
		System::String^ message = "File successfully saved in \n" + originPath;
		MessageBox::Show(message,"Congratulations!");
		Console::WriteLine(path + "에 저장돼었습니다.");
	}
	else {
		std::cout << "경로를 찾을 수 없습니다!" << std::endl;
	}
	out.close();
}

void Notification::MyForm::ProgramFiles()
{
	std::ifstream readFile;
	readFile.open(FILE_PATH);
	std::string content;

	if (readFile.is_open()) {
		// 시스템 파일 읽기
		while (!readFile.eof()) {
			getline(readFile, content);
			std::cout << "내용 : " << content << std::endl;
			ChangePath(gcnew String(content.c_str()));
		}
	}
	else {
		// 시스템 파일이 없을 경우, 기본값 적용
		std::ofstream creator;
		creator.open(FILE_PATH);
		creator << "";
		if (creator.is_open()) {
			creator << msclr::interop::marshal_as<std::string>(GetPath());
			// Path
			// number?
		}
		else {
			Console::WriteLine("THIS IS ERROR");
		}
		creator.close();
	}
}

void Notification::MyForm::UpdatePath(std::string str) {
	std::ofstream creator;
	creator.open(FILE_PATH);

	creator << str;
}

void Notification::MyForm::ChangePath() {

	// 폴더 선택 다이얼로그
	OpenFileDialog^ Picker;//(strInitPath, OFN_FILEMUSTEXIST, NULL, 0);
	Picker = gcnew System::Windows::Forms::OpenFileDialog;
	Picker->Filter = "txt files (*.txt)|*.txt|vcb files(*.vcb) | *.vcb";
	Picker->FilterIndex = 2;

	System::Windows::Forms::DialogResult result = Picker->ShowDialog();
	if (result == ::DialogResult::OK) {
		originPath = Picker->FileName;
		MyForm::Text = originPath;
		Console::WriteLine("Path : " + originPath);
	}
}

System::String^ Notification::MyForm::GetPath() {
	FolderBrowserDialog^ Picker;
	Picker = gcnew System::Windows::Forms::FolderBrowserDialog;

	System::Windows::Forms::DialogResult result = Picker->ShowDialog();
	if (result == ::DialogResult::OK) {
		std::ofstream output;
		output << "";
		System::String^ returnVal = Picker->SelectedPath + "\\words.vcb";
		MyForm::Text = returnVal;
		originPath = returnVal;
		return returnVal;
	}
}

void Notification::MyForm::ChangePath(System::String^ str)
{
	originPath = str;
	MyForm::Text = originPath;
}
