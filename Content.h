#pragma once

#include "header.h"

public class omn::Content {
public:
	int size;
	int contentType; // 0 words 1 language 2 memo
public:
	std::string content;
	std::vector<std::vector<std::string>> contents;
	std::vector<std::string> smallContents;
public:
	std::string SplitContent();
	void SetContent(std::string content);

public:
	// 파일에서 받은 내용 (1줄짜리) 를 받아 content 에 저장시킴
	Content(int type);
};