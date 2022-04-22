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
*  프로세스
*	1. Programfile 클래스를 이용에 시스템 파일 로드
*	2. SaveFile 클래스에서 그 파일에서 얻은 경로를 통해 파일 오픈
*	3. DataRead 함수를 통해 파일내용 읽기
*	4. 내용들은 각 줄마다 Content 의 인스턴스화
*	   1. 단어
*      2. 언어 2개
*	   3. 메모
*	5. Content 클래스 인스턴스들 중 Words 타입인 인스턴스를 DataGridView 클래스를 이용하여 화면에 표시
*/

struct SetupData {
std::string last_opened_path;
int should_open_memo;
};