#include "SaveFile.h"
#include "DataGridView.h"

using namespace omn;

SaveFile::SaveFile() {
	// owo nothing is here everlast ~30%
}

/* compress data */
std::string SaveFile::MakeDataToSave() {
	DataGridView* dgv = dgvptr;
	int Row = dgv->Row;
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
			str1 = toStdStr(first);
			succeed = true;
		}
		if (dgv->GetValue(i, 1)) {
			second = dgv->GetValue(i, 1)->ToString();
			str2 = toStdStr(second);
			succeed = true;
		}
		if (succeed) {
			saveData += (str1 + TRANSLATION_SPE + str2 + WORDS_SPE);
		}
	}
	std::cout << saveData << std::endl;
	return saveData;
}

// load data
void SaveFile::DataRead() {
	System::String^ tempPath = toSystemStr(currentPath);

	std::ifstream fileReader;
	fileReader.open(toStdStr(tempPath));

	std::string content;

	if (fileReader.is_open()) {
		std::cout << "파일이 열렸습니다 : inputStream" << std::endl;
		std::cout << "경로 : " << toStdStr(tempPath) << std::endl;

		int index = 0;
		while (!fileReader.eof()) {
			getline(fileReader, content);
			switch (index) {
			case 0:
				//Console::WriteLine("content section");
				//std::cout << content << std::endl;
				words->SetContent(content);
				words->SplitContent();
				dgvptr->AddItem(*words);
				break;
			case 1:
				language->SetContent(content);
				language->SplitContent();
				//Console::WriteLine("language section");
				//std::cout << content << std::endl;
				dgvptr->SetLanguage(*language);
				break;
			case 2: // !!
				memo->SetContent(content);
				//Console::WriteLine("memo section");
				if (content == EMPTY) std::cout << "memo doesn't exist!" << std::endl;
				else {
					//std::cout << content << std::endl;
					dgvptr->SetMemo(*memo);
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
		DataSave();
	}
	fileReader.close();
}

void SaveFile::SetCurrentPath(std::string str) {
	currentPath = str;
}

// Content 클래스를 사용하여 저장하는건 나중에 만들자 일단 테스트겸 해서 SaveFile에 있는 함수 사용
void SaveFile::DataSave() {
	/* open output stream */
	System::String^ path = toSystemStr(currentPath);
	std::ofstream out(currentPath);

	if (out.is_open()) {
		std::cout << "파일이 열렸습니다 : outputStream" << std::endl;
		std::cout << "경로 : " << currentPath << std::endl;

		/* save compressed string at first line of the file */
		std::string savedata = SaveFile::MakeDataToSave();
		std::cout << savedata << std::endl;
		out << savedata << "\n";

		/* save language data using language vector */
		std::vector<std::string> langs = dgvptr->GetLanguage();
		out << langs[0] << WORDS_SPE << langs[1] << "\n";

		/* save memo data unless it is empty */
		std::string memosavedata = dgvptr->GetMemo();
		if (memosavedata == "") out << EMPTY << "\n";
		else out << memosavedata << "\n";

		/* notify to user the success */
		System::String^ message = "File successfully saved in \n" + toSystemStr(currentPath);
		System::Windows::Forms::MessageBox::Show(message, "Congratulations!");
		System::Console::WriteLine(path + "에 저장돼었습니다.");
	}
	else {
		std::cout << "경로를 찾을 수 없습니다!" << std::endl;
	}
	out.close();
}

//void SaveFile::ChangeOpenedFile() {
//	PTR::programFile->ChangePath();
//}