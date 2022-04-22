#include "MyForm.h"
#include "DataGridView.h"
#include "ProgramFile.h"
#include "SaveFile.h"
#include "header.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ argv) {

#ifdef _DEBUG
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Vocabella::MyForm app;

	Application::Run(% app);
}

#define FORM Vocabella::MyForm::form
#define PTR MyArea::Pointers

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>

using namespace System::Windows::Forms;

namespace fs = std::experimental::filesystem;

using namespace Vocabella;

MyForm::MyForm(void)
{
	InitializeComponent();
	//
	//TODO: 생성자 코드를 여기에 추가합니다.
	//
	const float version(0.5);
	UpdateVersionInfo(version);

	programF = new omn::ProgramFile();
	this->Text = toSystemStr(programF->current_path);

	saveF = new omn::SaveFile();
	saveF->currentPath = programF->current_path;

	dgv = new omn::DataGridView();

	std::cout << omn::ProgramFile::GetPPath() << std::endl;
	programF->UpdateDefaultPath(programF->current_path);
	dgv->ClearRow();
	saveF->dgvptr = dgv;
	saveF->DataRead();

	Convert();
	SetLanguage();
	SetMemo();
}

/* convert dataTable vector into real datagridview */
void MyForm::Convert() { // TODO
	// set row
	// add item loop
}

void Vocabella::MyForm::SetLanguage()
{
	Deutsch->HeaderText = toSystemStr(dgv->lang1);
	Korean->HeaderText = toSystemStr(dgv->lang2);
}

void Vocabella::MyForm::SetMemo()
{
	dgv->memo_visiblity = programF->should_open_memo;
	if (dgv->memo_visiblity) {
		ChangeSize(528, 62);
		programF->UpdateMemoInfo();
	}
	else {
		showMemoToolStripMenuItem->Checked = false;
		memoBox->Visible = false;
		ChangeSize(563, 27);
		programF->UpdateMemoInfo();
	}
}

void Vocabella::MyForm::ShowMemo()
{
	ChangeSize(528, 62);
	programF->UpdateMemoInfo();
	dgv->memo_visiblity = true;
}

void Vocabella::MyForm::HideMemo()
{
	showMemoToolStripMenuItem->Checked = false;
	memoBox->Visible = false;
	ChangeSize(563, 27);
	programF->UpdateMemoInfo();
	dgv->memo_visiblity = false;
}

void Vocabella::MyForm::ChangeSize(int height, int top)
{
	dataGridView1->Height = height;
	dataGridView1->Top = top;
}

void Vocabella::MyForm::ChangeSize(int height, int top, int down)
{
	ChangeSize(height, top);
	dataGridView1->Top = down * (-1);
}

void Vocabella::LangChanger::ButtonClick() { // TODO
	if (textBox1->Text != " ") {
		count++;
		if (count == 1) {
			lang1 = textBox1->Text;
			this->label1->Text = L"please type your second language";
			this->textBox1->Text = "";
			this->textBox1->Select();
		}
		else if (count == 2) {
			lang2 = textBox1->Text;
			count = 0;
			PTR::dgvptr->SetLanguage(lang1, lang2);
			this->label1->Text = L"please type your first language";
			this->textBox1->Text = "";
			delete this;
		}
	}
	else {
		System::String^ message = "Please type your language in textbox";
		System::Windows::Forms::MessageBox::Show(message, "Warning");
	}
}