#pragma once

#include "LangChanger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <Windows.h>

#define TRANSLATION_SPE ':'
#define WORDS_SPE '|'
#define FILE_PATH "Setting.txt"
#define EMPTY "~"
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <experimental/filesystem>

using namespace System::Windows::Forms;

namespace fs = std::experimental::filesystem;

namespace MyArea {

	class SaveFile;
	class ProgramFile;
	class Content;
	class DataGridView;

	std::string ToStdString(System::String^ str) {
		return msclr::interop::marshal_as<std::string>(str);
	}

	System::String^ ToSystemString(std::string str) {
		using namespace System;
		System::String^ temp = gcnew String(str.c_str());
		return temp;
	}
	/*
	*  프로세스
	*	1. Programfile 클래스를 이용에 시스템 파일 로드
	*	2. SaveFile 클래스에서 그 파일에서 얻은 경로를 통해 파일 오픈
	*	3. DataRead 함수를 통해 파일내용 읽기
	*	4. 내용들은 각 줄마다 Content 의 인스턴스화
	*	   1. 단어
	*      2. 언어 2개
	*	   3. 메모 (구상중)
	*	5. Content 클래스 인스턴스들 중 Words 타입인 인스턴스를 DataGridView 클래스를 이용하여 화면에 표시
	*/

	// 데이터 관리
	// 문제가 많음
	// 파일에서 나온 데이터를 관리
	public class Content {
	public:
		// ContentType contentType;
		int contentType; // 0 words 1 language 2 memo
	public:
		std::string content;
		std::vector<std::vector<std::string>> contents;
		std::vector<std::string> smallContents;
	public:
		std::string SplitContent();
		void SetContent(std::string content) {
			this->content = content;
		}
	public:
		// 파일에서 받은 내용 (1줄짜리) 를 받아 content 에 저장시킴
		Content(int type) {
			this->contentType = type;
		}
	};

	// data grid view를 관리함
	class DataGridView {
	public:
		int Row;
	public:
		void AddRow();
		void AddItem(System::String^ content, int Yindex, int Xindex);
		void AddItem(Content words);

		void SetLanguage(Content languages);
		void SetLanguage(System::String^ lang1, System::String^ lang2);
		std::vector<std::string> GetLanguage();

		void SetMemo(Content memo);
		std::string GetMemo();

		System::Object^ GetValue(int Row, int Column);

		int GetRowCount();
		void ClearRow();
		void ResetRowCount();

		void ChangeSize(int height, int top);
		void ChangeSize(int height, int top, int down);
	public:
		DataGridView() {
			Row = 0;
		}

		// 파일에서 읽은 데이터의 종류
		enum ContentType {
			Words,
			Languages,
			Memo
		};
	};

	// 파일관리
	// 세이브 파일을 관리
	class SaveFile {
	public:
		std::string currentPath;
		Content* words;
		Content* language;
		Content* memo;
	public:
		std::string MakeDataToSave();
		void DataSave();
		void DataRead();
		void ChangeOpenedFile();
		void SetCurrentPath(std::string str);
	public:
		SaveFile(bool init) {
			currentPath = "";
			words = new MyArea::Content(0);
			language = new MyArea::Content(1);
			memo = new MyArea::Content(2);
		}
	};

	// 프로그램 파일 관리
	class ProgramFile {
	private:
		std::ifstream FileReader;
		//std::string buffer;
	public:
		void MakePFile();
		void MakePFolder();
		void ReadPFile();
		System::String^ GetPathWithDefaultFile();
		std::string GetPPath();
		void UpdateDefaultPath(std::string str); // UpdatePath()
		void ChangePath(System::String^ str);
		void ChangePath();
		void tryagain();
	public:
		ProgramFile() {
			FileReader.open(GetPPath() + FILE_PATH, std::ifstream::in);

			if (FileReader.is_open()) {
				ReadPFile();
			}
			else if(!FileReader.is_open()) {
				if (fs::exists(GetPPath())) {
					MakePFile();
				}
				else {
					MakePFolder();
				}
			}
		}
	};

	ref class Pointers {
	public:
		static MyArea::SaveFile* sf = new MyArea::SaveFile(true);
		static MyArea::DataGridView* dgvptr = new MyArea::DataGridView();
		static MyArea::ProgramFile* programFile = new MyArea::ProgramFile();
		static System::Windows::Forms::DataGridViewTextBoxColumn^ header1;
		static System::Windows::Forms::DataGridViewTextBoxColumn^ header2;
	};
}
