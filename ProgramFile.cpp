#include "ProgramFile.h"

using namespace omn;

ProgramFile::ProgramFile() {
	/* open the program file at specific path */
	FileReader.open(GetPPath() + FILE_PATH, std::ifstream::in);

	/* if file exists, read program file */
	if (FileReader.is_open()) {
		ReadPFile(); // 1
	}
	else if (!FileReader.is_open()) {
		/* if path exists, create program file */
		if (fs::exists(GetPPath())) {
			MakePFile();
		}
		/* unless, create folder */
		else {
			MakePFolder();
		}
	}
}

void ProgramFile::MakePFile() {
	System::Console::WriteLine("FOLDER EXSIST!");
	std::ofstream creator;
	creator.open(GetPPath() + FILE_PATH, std::ofstream::out);
	creator << "";
	if (creator.is_open()) {
		creator << toStdStr(GetPathWithDefaultFile());
	}
	else {
		System::Console::WriteLine("THIS SHOULD NOT HAPPEN SOMETHING WENT WRONG");
	}
	creator.close();
}

void ProgramFile::MakePFolder() {
	System::Console::WriteLine("FOLDER NOT EXSIST! CREATE A FOLDER");
	fs::create_directory(GetPPath());
	tryagain();
}

void ProgramFile::tryagain() {
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

void ProgramFile::ReadPFile() {
	std::string buffer;
	int line = 1;

	/* read file line by line */
	while (!FileReader.eof()) {
		getline(FileReader, buffer);
		std::cout << line << " 번쨰 내용 : " << buffer << std::endl;

		/* run code after setting */
		switch (line) {
		/* open latest opened file */
		case 1: {
			ChangePath(toSystemStr(buffer)); // 1.1
			last_opened_path = buffer;
			break;
		}
		/* open or hide Memo section */
		case 2: {
			if (buffer == "1") {
				should_open_memo = true;
			}
			else if (buffer == "0") {
				std::cout << buffer << std::endl;
				should_open_memo = false;
			}
			break;
		}
		}
		line++;
	}
}

System::String^ ProgramFile::GetPathWithDefaultFile() {
	System::Windows::Forms::FolderBrowserDialog^ Picker;
	Picker = gcnew System::Windows::Forms::FolderBrowserDialog;

	System::Windows::Forms::DialogResult result = Picker->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK) {
		std::ofstream output;
		output << "";
		System::String^ returnVal = Picker->SelectedPath + "\\words.vcb";
		return returnVal;
	}
}

std::string ProgramFile::GetPPath() {
	System::String^ path = gcnew System::String(getenv("APPDATA")) + "\\Voc\\";
	return toStdStr(path);
}

// 프로그램 파일에 경로를 저장함
void ProgramFile::UpdateDefaultPath(std::string str) {
	std::ofstream creator;
	creator.open(GetPPath() + FILE_PATH, std::ofstream::out);
	System::Console::WriteLine("update");

	creator << str << std::endl;
	creator << toStdStr(should_open_memo.ToString());
	last_opened_path = str;
	creator.close();
}

void ProgramFile::UpdateMemoInfo() {
	System::Console::WriteLine("memo update");
	std::ofstream creator;

	creator.open(GetPPath() + FILE_PATH, std::ofstream::out);
	creator << last_opened_path + "\n";
	std::cout << last_opened_path << std::endl;
	creator << toStdStr(should_open_memo.ToString());
	creator.close();
}

// Change current path using input
void ProgramFile::ChangePath(System::String^ str) {
	//PTR::sf->SetCurrentPath(toStdStr(str)); // error! 당연하지;; 아직 만들어지지도 않았는데;;
	current_path = toStdStr(str);
}

// should call after this savefile::SetCurrentPath!!! //
// should call after this form->changeText!!! //
void ProgramFile::ChangePath() {
	OpenFileDialog^ Picker;
	Picker = gcnew System::Windows::Forms::OpenFileDialog;
	Picker->Filter = "txt files (*.txt)|*.txt|vcb files(*.vcb)|*.vcb";
	Picker->FilterIndex = 2;

	DialogResult result = Picker->ShowDialog();
	if (result == DialogResult::OK) {
		current_path = toStdStr(Picker->FileName);
		std::cout << "Selected Path : " << current_path << std::endl;
	}
}