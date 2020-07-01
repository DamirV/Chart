#pragma once
#include "TRoot.h"
#include "TPoint.h"
#include "TChart.h"

namespace Chart {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		TPoint *p1, *p2;
		TChart *pFirst;
		Graphics^ gr;
		int xf, yf, xl, yl;
		bool flag;
		int op;
		bool show;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button4;
	public:
	private: System::Windows::Forms::Button^  button1;
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			gr = CreateGraphics();
			pFirst = NULL;
			op = 0;
			show = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(628, 366);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Hide";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(628, 337);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Show";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(141, 366);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Move";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 369);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(59, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"10";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(77, 369);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(58, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"0";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(628, 308);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(94, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Hide fat lines";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(734, 401);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDoubleClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		xf = xl = e->X;
		yf = yl = e->Y;
		flag = true;
	}
	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (flag == true)
		{
			gr->DrawLine(Pens::White, xf, yf, xl, yl);
			xl = e->X;
			yl = e->Y;
			if ((pFirst != NULL) && (op >= 10) && (show == true))
			{
				pFirst->Show(gr);
				op = 0;
			}
			gr->DrawLine(Pens::Black, xf, yf, xl, yl);
			op++;
		}
	}
	private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		flag = false;

		if (pFirst == NULL)
		{
			p1 = new TPoint(xf, yf);
			p2 = new TPoint(xl, yl);
			pFirst = new TChart();

			pFirst->SetFirst(p1);
			pFirst->SetLast(p2);
		}
		else
		{
			TChartLine clf;
			TChartLine cll;
			clf = pFirst->Find(xf, yf);
			cll = pFirst->Find(xl, yl);


			if (clf.tf != NULL || clf.tl != NULL)
			{
				p2 = new TPoint(xl, yl);
				TChart *tmp = new TChart();
				if (clf.tf)
				{
					tmp->SetLast(clf.tf);
					tmp->SetFirst(p2);
					clf.tc->SetFirst(tmp);
				}
				else
				{
					tmp->SetLast(clf.tl);
					tmp->SetFirst(p2);
					clf.tc->SetLast(tmp);
				}
			}

			if (clf.tf == NULL && clf.tl == NULL)
			{
				if (cll.tf != NULL || cll.tl != NULL)
				{
					p2 = new TPoint(xf, yf);
					TChart *tmp = new TChart();
					if (cll.tf)
					{
						tmp->SetLast(cll.tf);
						tmp->SetFirst(p2);
						cll.tc->SetFirst(tmp);
					}
					else
					{
						tmp->SetLast(cll.tl);
						tmp->SetFirst(p2);
						cll.tc->SetLast(tmp);
					}
				}
			}

		}
		gr->DrawLine(Pens::White, xf, yf, xl, yl);

		if (show == true)
			pFirst->Show(gr);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (pFirst != NULL)
		{
			pFirst->Hide(gr);
			show = false;

		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (pFirst != NULL)
		{
			pFirst->Show(gr);
			show = true;

		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox1->Text != "\0" || textBox1->Text != " " || textBox1->Text != "")
		{

			pFirst->Move(gr, Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text));
		}
	}
	private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
	
	}
private: System::Void MyForm_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	if (pFirst != NULL)
		pFirst->Click(gr, e->X, e->Y);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	if (pFirst != NULL)
		pFirst->HideFatLines(gr);
}
};
}
