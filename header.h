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

namespace omn 
{
	class DataGridView;
	class Content;
	class SaveFile;
	class ProgramFile;
}

std::string toStdStr(System::String^ str) {
	return msclr::interop::marshal_as<std::string>(str);
}

System::String^ toSystemStr(std::string str) {
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
*	   3. �޸�
*	5. Content Ŭ���� �ν��Ͻ��� �� Words Ÿ���� �ν��Ͻ��� DataGridView Ŭ������ �̿��Ͽ� ȭ�鿡 ǥ��
*/

struct SetupData {
std::string last_opened_path;
int should_open_memo;
};