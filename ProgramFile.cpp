#include "MyForm.h"

MyArea::File::ProgramFile::ProgramFile() {

}

void MyArea::File::ProgramFile::MakePFile() {

}

void MyArea::File::ProgramFile::MakePFolder() {

}

void MyArea::File::ProgramFile::ReadPFile() {

}

void MyArea::File::ProgramFile::UpdateDefaultPath() {

}

System::String^ MyArea::File::ProgramFile::GetPathFromDialog() {

}

void MyArea::File::ProgramFile::ChangePath(System::String^ str) {

}

std::string MyArea::File::ProgramFile::GetPPath() {
	System::String^ path = gcnew System::String(getenv("APPDATA")) + "\\Voc\\";
	return ToStdString(path);
}