#pragma once

namespace Vocabella {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// LangChanger�� ���� ����Դϴ�.
	/// </summary>
	public ref class LangChanger : public System::Windows::Forms::Form
	{
	private:
		static System::String^ lang1;
		static System::String^ lang2;
		static int count = 0;
	public:
		void ButtonClick();
	public:
		LangChanger(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			Console::WriteLine("new");
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~LangChanger()
		{
			Console::WriteLine("delete");
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"���� ���", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(260, 29);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &LangChanger::textBox1_TextChanged);
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &LangChanger::textBox1_KeyUp);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"���� ���", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(195, 71);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Change";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LangChanger::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"���� ���", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"please type your first language";
			// 
			// LangChanger
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 116);
			this->ControlBox = false;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LangChanger";
			this->Text = L"Voc";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &LangChanger::LangChanger_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ButtonClick();
	}
	private: System::Void LangChanger_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	}
private: System::Void textBox1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == 13) {
		ButtonClick();
	}
	// TODO enter �������� �Ѿ�°Ŷ� â ������ �����ϴ°� ����, �������ᳪ �ٸ� ������� ��������� ������� ���׼���
}
	};
}
