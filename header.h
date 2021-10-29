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
	*  ���μ���
	*	1. Programfile Ŭ������ �̿뿡 �ý��� ���� �ε�
	*	2. SaveFile Ŭ�������� �� ���Ͽ��� ���� ��θ� ���� ���� ����
	*	3. DataRead �Լ��� ���� ���ϳ��� �б�
	*	4. ������� �� �ٸ��� Content �� �ν��Ͻ�ȭ
	*	   1. �ܾ�
	*      2. ��� 2��
	*	   3. �޸� (������)
	*	5. Content Ŭ���� �ν��Ͻ��� �� Words Ÿ���� �ν��Ͻ��� DataGridView Ŭ������ �̿��Ͽ� ȭ�鿡 ǥ��
	*/

	// ������ ����
	// ������ ����
	// ���Ͽ��� ���� �����͸� ����
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
		// ���Ͽ��� ���� ���� (1��¥��) �� �޾� content �� �����Ŵ
		Content(int type) {
			this->contentType = type;
		}
	};

	// data grid view�� ������
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

		// ���Ͽ��� ���� �������� ����
		enum ContentType {
			Words,
			Languages,
			Memo
		};
	};

	// ���ϰ���
	// ���̺� ������ ����
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

	// ���α׷� ���� ����
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
