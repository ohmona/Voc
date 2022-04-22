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
	// ���Ͽ��� ���� ���� (1��¥��) �� �޾� content �� �����Ŵ
	Content(int type);
};