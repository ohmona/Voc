#include "Content.h"
#include "header.h"

#define FORM Vocabella::MyForm::form
#define PTR MyArea::Pointers

using namespace omn;

Content::Content(int type) {
	this->contentType = type;
}

void Content::SetContent(std::string content) {
	this->content = content;
}

std::string Content::SplitContent() {
	// 단어 전용
	switch (contentType) {
	case 0:
		if (contentType == 0) {
			// word:단어|world:세계|sand:모래
			System::String^ str;
			str = toSystemStr(content);
			array<System::String^>^ wordArr;
			wordArr = str->Split(WORDS_SPE);
			std::vector<std::vector<std::string>> transArr;
			for (int i = 0; i < wordArr->Length - 1; i++) {
				array<System::String^>^ temp = wordArr[i]->Split(TRANSLATION_SPE);

				const int newsize = transArr.size() + 1;
				transArr.resize(newsize);
				transArr[i].resize(2);
				transArr[i][0] = toStdStr(temp[0]);
				transArr[i][1] = toStdStr(temp[1]);
			}
			contents.resize(transArr.size());
			contents = transArr;
			//delete transArr;
		}
		break;
	case 1:
		// deutsch:한국어
		System::String ^ str;
		str = toSystemStr(content);
		array<System::String^>^ arr;
		arr = str->Split(WORDS_SPE);
		smallContents.resize(2);
		smallContents[0] = toStdStr(arr[0]);
		smallContents[1] = toStdStr(arr[1]);
		break;

	case 2:
		// hello world
		break;

	default:
		break;
	}
	return "";
}