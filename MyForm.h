#pragma once

#include <iostream>
#include <fstream>
#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>

#define SPE ':'
#define END "__FIN.omn"
#define EXTENSION ".vcb"
#define PATH "D:\Recording\\"
#define FILE_PATH "Setting.txt"
#define File_Path Setting.txt
#define SIGN "vocabella_program_by_ohmona_0.1"
#define DGV Notification::MyForm::dataGridview1;

#define TEST Console::WriteLine("tset");

#ifdef UNICODE
#define GetCurrentDirectory GetCurrentDirectoryW
#else
#define GetCurrentDirectory GetCurrentDirectoryA
#endif

namespace fs = std::experimental::filesystem;

namespace Notification {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	public: void AddItem(DataGridView^ dgv, std::string content, int index);
	public: void ReadFile();
	//public: void ReadFile(System::String^ path);
	public: void SaveFile();
	public: void ProgramFiles();
	public: void AddRow();
	public: void ChangePath();
	public: void UpdatePath(std::string);
	public: System::String^ GetPath();
	public: void ChangePath(System::String^ str);
	public: std::string GetProgramPath();
	public: std::string ToStdString(System::String^ str);
	public: System::String^ ToSystemString(std::string str);

	public:
		int Row = 1;
		bool shouldAddRow = true;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ FileMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ testToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ changeDirectoryCtrlShiftSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ infoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vocByOhmonaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ version01PreleaseToolStripMenuItem;
	public:

	public:
		System::String^ originPath = "";

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			std::cout << GetProgramPath() << std::endl;
			ProgramFiles();
			ReadFile();
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Deutsch;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Korean;




	protected:


	protected:


	protected:


	protected:


	protected:


	protected:


	protected:


	protected:

	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Deutsch = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Korean = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeDirectoryCtrlShiftSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vocByOhmonaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->version01PreleaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			resources->ApplyResources(this->dataGridView1, L"dataGridView1");
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Deutsch,
					this->Korean
			});
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Arrow;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle7;
			this->dataGridView1->RowTemplate->Height = 26;
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellEndEdit);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellValueChanged);
			this->dataGridView1->CurrentCellDirtyStateChanged += gcnew System::EventHandler(this, &MyForm::dataGridView1_CurrentCellDirtyStateChanged);
			this->dataGridView1->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &MyForm::dataGridView1_EditingControlShowing);
			this->dataGridView1->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MyForm::dataGridView1_RowsAdded);
			this->dataGridView1->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &MyForm::dataGridView1_RowsRemoved);
			this->dataGridView1->ControlRemoved += gcnew System::Windows::Forms::ControlEventHandler(this, &MyForm::dataGridView1_ControlRemoved);
			this->dataGridView1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			// 
			// Deutsch
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->Deutsch->DefaultCellStyle = dataGridViewCellStyle3;
			resources->ApplyResources(this->Deutsch, L"Deutsch");
			this->Deutsch->Name = L"Deutsch";
			this->Deutsch->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Korean
			// 
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Korean->DefaultCellStyle = dataGridViewCellStyle4;
			resources->ApplyResources(this->Korean, L"Korean");
			this->Korean->Name = L"Korean";
			this->Korean->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->FileMenu, this->infoToolStripMenuItem });
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// FileMenu
			// 
			this->FileMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->testToolStripMenuItem,
					this->changeDirectoryCtrlShiftSToolStripMenuItem
			});
			this->FileMenu->Name = L"FileMenu";
			resources->ApplyResources(this->FileMenu, L"FileMenu");
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			resources->ApplyResources(this->testToolStripMenuItem, L"testToolStripMenuItem");
			this->testToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::testToolStripMenuItem_Click);
			// 
			// changeDirectoryCtrlShiftSToolStripMenuItem
			// 
			this->changeDirectoryCtrlShiftSToolStripMenuItem->Name = L"changeDirectoryCtrlShiftSToolStripMenuItem";
			resources->ApplyResources(this->changeDirectoryCtrlShiftSToolStripMenuItem, L"changeDirectoryCtrlShiftSToolStripMenuItem");
			this->changeDirectoryCtrlShiftSToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::changeDirectoryCtrlShiftSToolStripMenuItem_Click);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->vocByOhmonaToolStripMenuItem,
					this->version01PreleaseToolStripMenuItem
			});
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			resources->ApplyResources(this->infoToolStripMenuItem, L"infoToolStripMenuItem");
			// 
			// vocByOhmonaToolStripMenuItem
			// 
			this->vocByOhmonaToolStripMenuItem->Name = L"vocByOhmonaToolStripMenuItem";
			resources->ApplyResources(this->vocByOhmonaToolStripMenuItem, L"vocByOhmonaToolStripMenuItem");
			// 
			// version01PreleaseToolStripMenuItem
			// 
			this->version01PreleaseToolStripMenuItem->Name = L"version01PreleaseToolStripMenuItem";
			resources->ApplyResources(this->version01PreleaseToolStripMenuItem, L"version01PreleaseToolStripMenuItem");
			this->version01PreleaseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::version01PreleaseToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Click_Save(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Click_Load(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
}
private: System::Void Click_LoadOnly(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->Control && e->Shift && e->KeyValue == 83) {
		SaveFile();
		ChangePath();
		ReadFile();
	}
	else if (e->Control && e->KeyValue == 83) {
		SaveFile();
		ReadFile();
	}
	else if (e->Control && e->KeyValue == 70) {
		ReadFile();
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void testToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFile();
	ReadFile();
}
private: System::Void loadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ReadFile();
}
private: System::Void changeDirectoryCtrlShiftSToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFile();
	ChangePath();
	ReadFile();
}
private: System::Void dataGridView1_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
	Row++;
}
private: System::Void dataGridView1_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) {
	Row--;
}
private: System::Void version01PreleaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_ControlRemoved(System::Object^ sender, System::Windows::Forms::ControlEventArgs^ e) {
}
private: System::Void dataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void dataGridView1_CurrentCellDirtyStateChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_EditingControlShowing(System::Object^ sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^ e) {
	TEST
}
private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	
}
};
}

namespace MyArea {
	std::string ToStdString(System::String^ str);
	System::String^ ToSystemString(std::string str);
	namespace File {
		// 세이브 파일을 관리
		static class SaveFile {
		public:
			void Save();
			void Read();
			void ChangeOpenedFile();
		};
		// 프로그램 파일 관리
		static class ProgramFile {
		private:
			std::ifstream FileReader; //= FileReader.open(GetPPath() + FILE_PATH, std::ifstream::in); // warning
			std::string buffer;
		public:
			void MakePFile();
			void MakePFolder();
			void ReadPFile();
			void UpdateDefaultPath(); // UpdatePath()
			System::String^ GetPathFromDialog();
			void ChangePath(System::String^ str);
			std::string GetPPath();
		public:
			ProgramFile();
		};
	}

	namespace Data {
		// 파일에서 나온 데이터를 정리
		public class Content {
		public:
			std::string content;
			std::vector<std::string> contents;
		public:
			std::string SplitContent();
		public:
			Content(std::string content);
		};

		// 화면에 있는 dgv
		static class DataGridView {
		public:
			int Row = 0;
		public:
			void AddRow();
			void AddItem(int Yindex, int Xindex);
		};
	}
}

std::string MyArea::ToStdString(System::String^ str) {
	return msclr::interop::marshal_as<std::string>(str);
}

System::String^ MyArea::ToSystemString(std::string str) {
	return gcnew String(str.c_str());
}