/*Nujoma Halls, Maaz, Giovanni
This GUI will show the user information about monthly temps from the year 1869 to 2012.
This program accepts command line arguments specifiying the file name and the starting year.
*/

#pragma once
#include <string>
using namespace std;
#include <msclr\marshal_cppstd.h>  
using namespace msclr::interop;
#include "Wheader.h"
#include <fstream>
#include <iostream>

namespace GUI_demo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	int ROWS = 144;
	int COLS = 12;
	int * startYearPointer;
	Weather myWeather(ROWS, COLS); 


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		MyForm(string file, int * startYear)
		{
			InitializeComponent();
            startYearPointer = startYear; // Now both point to the address of the second command line arg sent over from MyForm.cpp.
			fstream fileIn(file);
			myWeather.read(fileIn); //reads in the values from the file and puts them in the 2d array.
			//
			//TODO: Add the constructor code here
			//
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

		private: System::Windows::Forms::TextBox^  MonthBox;
		private: System::Windows::Forms::TextBox^  YearBox;
		protected:

		protected:

		private: System::Windows::Forms::Label^  Ylabel;
		private: System::Windows::Forms::Label^  Mlabel;


		private: System::Windows::Forms::CheckBox^  AvgYBox;
		private: System::Windows::Forms::CheckBox^  HYBox;
		private: System::Windows::Forms::CheckBox^  LYBox;



		private: System::Windows::Forms::CheckBox^  AvgMBox;

		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::CheckBox^  HMBox;
		private: System::Windows::Forms::CheckBox^  LMBox;
		private: System::Windows::Forms::TextBox^  DisAvgM;
		private: System::Windows::Forms::TextBox^  DisLY;




		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::Label^  label6;
		private: System::Windows::Forms::Label^  label7;
		private: System::Windows::Forms::TextBox^  DisHY;

		private: System::Windows::Forms::TextBox^  DisAvgY;

		private: System::Windows::Forms::TextBox^  DisLM;

		private: System::Windows::Forms::TextBox^  DisHM;

		private: System::Windows::Forms::Label^  label8;
		private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  MonthSearch;
	private: System::Windows::Forms::Button^  YearSearch;




		protected:

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
				this->MonthBox = (gcnew System::Windows::Forms::TextBox());
				this->YearBox = (gcnew System::Windows::Forms::TextBox());
				this->Ylabel = (gcnew System::Windows::Forms::Label());
				this->Mlabel = (gcnew System::Windows::Forms::Label());
				this->AvgYBox = (gcnew System::Windows::Forms::CheckBox());
				this->HYBox = (gcnew System::Windows::Forms::CheckBox());
				this->LYBox = (gcnew System::Windows::Forms::CheckBox());
				this->AvgMBox = (gcnew System::Windows::Forms::CheckBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->HMBox = (gcnew System::Windows::Forms::CheckBox());
				this->LMBox = (gcnew System::Windows::Forms::CheckBox());
				this->DisAvgM = (gcnew System::Windows::Forms::TextBox());
				this->DisLY = (gcnew System::Windows::Forms::TextBox());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->DisHY = (gcnew System::Windows::Forms::TextBox());
				this->DisAvgY = (gcnew System::Windows::Forms::TextBox());
				this->DisLM = (gcnew System::Windows::Forms::TextBox());
				this->DisHM = (gcnew System::Windows::Forms::TextBox());
				this->label8 = (gcnew System::Windows::Forms::Label());
				this->label9 = (gcnew System::Windows::Forms::Label());
				this->MonthSearch = (gcnew System::Windows::Forms::Button());
				this->YearSearch = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// MonthBox
				// 
				this->MonthBox->Location = System::Drawing::Point(56, 25);
				this->MonthBox->Name = L"MonthBox";
				this->MonthBox->Size = System::Drawing::Size(100, 20);
				this->MonthBox->TabIndex = 0;
				this->MonthBox->TextChanged += gcnew System::EventHandler(this, &MyForm::MonthBox_TextChanged);
				// 
				// YearBox
				// 
				this->YearBox->Location = System::Drawing::Point(367, 25);
				this->YearBox->Name = L"YearBox";
				this->YearBox->Size = System::Drawing::Size(100, 20);
				this->YearBox->TabIndex = 1;
				this->YearBox->TextChanged += gcnew System::EventHandler(this, &MyForm::YearBox_TextChanged);
				// 
				// Ylabel
				// 
				this->Ylabel->AutoSize = true;
				this->Ylabel->Location = System::Drawing::Point(325, 25);
				this->Ylabel->Name = L"Ylabel";
				this->Ylabel->Size = System::Drawing::Size(29, 13);
				this->Ylabel->TabIndex = 3;
				this->Ylabel->Text = L"Year";
				// 
				// Mlabel
				// 
				this->Mlabel->AutoSize = true;
				this->Mlabel->Location = System::Drawing::Point(12, 32);
				this->Mlabel->Name = L"Mlabel";
				this->Mlabel->Size = System::Drawing::Size(37, 13);
				this->Mlabel->TabIndex = 4;
				this->Mlabel->Text = L"Month";
				// 
				// AvgYBox
				// 
				this->AvgYBox->AutoSize = true;
				this->AvgYBox->Location = System::Drawing::Point(346, 53);
				this->AvgYBox->Name = L"AvgYBox";
				this->AvgYBox->Size = System::Drawing::Size(121, 17);
				this->AvgYBox->TabIndex = 6;
				this->AvgYBox->Text = L"Average Year Temp";
				this->AvgYBox->UseVisualStyleBackColor = true;
				// 
				// HYBox
				// 
				this->HYBox->AutoSize = true;
				this->HYBox->Location = System::Drawing::Point(346, 76);
				this->HYBox->Name = L"HYBox";
				this->HYBox->Size = System::Drawing::Size(130, 17);
				this->HYBox->TabIndex = 7;
				this->HYBox->Text = L"Highest Temp for year";
				this->HYBox->UseVisualStyleBackColor = true;
				// 
				// LYBox
				// 
				this->LYBox->AutoSize = true;
				this->LYBox->Location = System::Drawing::Point(346, 99);
				this->LYBox->Name = L"LYBox";
				this->LYBox->Size = System::Drawing::Size(128, 17);
				this->LYBox->TabIndex = 8;
				this->LYBox->Text = L"Lowest Temp for year";
				this->LYBox->UseVisualStyleBackColor = true;
				// 
				// AvgMBox
				// 
				this->AvgMBox->AutoSize = true;
				this->AvgMBox->Location = System::Drawing::Point(32, 51);
				this->AvgMBox->Name = L"AvgMBox";
				this->AvgMBox->Size = System::Drawing::Size(124, 17);
				this->AvgMBox->TabIndex = 9;
				this->AvgMBox->Text = L"Average month temp";
				this->AvgMBox->UseVisualStyleBackColor = true;
				this->AvgMBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox4_CheckedChanged);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(159, 0);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(159, 13);
				this->label1->TabIndex = 10;
				this->label1->Text = L"Please enter Month and/or Year";
				// 
				// HMBox
				// 
				this->HMBox->AutoSize = true;
				this->HMBox->Location = System::Drawing::Point(32, 74);
				this->HMBox->Name = L"HMBox";
				this->HMBox->Size = System::Drawing::Size(135, 17);
				this->HMBox->TabIndex = 11;
				this->HMBox->Text = L"Highest temp for month";
				this->HMBox->UseVisualStyleBackColor = true;
				this->HMBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::HMBox_CheckedChanged);
				// 
				// LMBox
				// 
				this->LMBox->AutoSize = true;
				this->LMBox->Location = System::Drawing::Point(32, 97);
				this->LMBox->Name = L"LMBox";
				this->LMBox->Size = System::Drawing::Size(133, 17);
				this->LMBox->TabIndex = 12;
				this->LMBox->Text = L"Lowest temp for month";
				this->LMBox->UseVisualStyleBackColor = true;
				// 
				// DisAvgM
				// 
				this->DisAvgM->Location = System::Drawing::Point(106, 149);
				this->DisAvgM->Name = L"DisAvgM";
				this->DisAvgM->Size = System::Drawing::Size(100, 20);
				this->DisAvgM->TabIndex = 13;
				this->DisAvgM->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
				// 
				// DisLY
				// 
				this->DisLY->Location = System::Drawing::Point(408, 193);
				this->DisLY->Name = L"DisLY";
				this->DisLY->Size = System::Drawing::Size(100, 20);
				this->DisLY->TabIndex = 14;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(12, 152);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(77, 13);
				this->label2->TabIndex = 15;
				this->label2->Text = L"Average Temp";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(325, 174);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(73, 13);
				this->label3->TabIndex = 16;
				this->label3->Text = L"Highest Temp";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(12, 174);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(73, 13);
				this->label4->TabIndex = 17;
				this->label4->Text = L"Highest Temp";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(325, 196);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(71, 13);
				this->label5->TabIndex = 18;
				this->label5->Text = L"Lowest Temp";
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(325, 152);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(77, 13);
				this->label6->TabIndex = 19;
				this->label6->Text = L"Average Temp";
				this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click_1);
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(14, 196);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(71, 13);
				this->label7->TabIndex = 20;
				this->label7->Text = L"Lowest Temp";
				// 
				// DisHY
				// 
				this->DisHY->Location = System::Drawing::Point(408, 171);
				this->DisHY->Name = L"DisHY";
				this->DisHY->Size = System::Drawing::Size(100, 20);
				this->DisHY->TabIndex = 21;
				// 
				// DisAvgY
				// 
				this->DisAvgY->Location = System::Drawing::Point(408, 149);
				this->DisAvgY->Name = L"DisAvgY";
				this->DisAvgY->Size = System::Drawing::Size(100, 20);
				this->DisAvgY->TabIndex = 22;
				// 
				// DisLM
				// 
				this->DisLM->Location = System::Drawing::Point(106, 193);
				this->DisLM->Name = L"DisLM";
				this->DisLM->Size = System::Drawing::Size(100, 20);
				this->DisLM->TabIndex = 23;
				// 
				// DisHM
				// 
				this->DisHM->Location = System::Drawing::Point(106, 171);
				this->DisHM->Name = L"DisHM";
				this->DisHM->Size = System::Drawing::Size(100, 20);
				this->DisHM->TabIndex = 24;
				// 
				// label8
				// 
				this->label8->AutoSize = true;
				this->label8->BackColor = System::Drawing::SystemColors::Highlight;
				this->label8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->label8->Location = System::Drawing::Point(325, 130);
				this->label8->Name = L"label8";
				this->label8->Size = System::Drawing::Size(36, 13);
				this->label8->TabIndex = 25;
				this->label8->Text = L"Yearly";
				this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
				// 
				// label9
				// 
				this->label9->AutoSize = true;
				this->label9->BackColor = System::Drawing::SystemColors::Highlight;
				this->label9->ForeColor = System::Drawing::SystemColors::ButtonFace;
				this->label9->Location = System::Drawing::Point(14, 130);
				this->label9->Name = L"label9";
				this->label9->Size = System::Drawing::Size(44, 13);
				this->label9->TabIndex = 26;
				this->label9->Text = L"Monthly";
				// 
				// MonthSearch
				// 
				this->MonthSearch->Location = System::Drawing::Point(173, 51);
				this->MonthSearch->Name = L"MonthSearch";
				this->MonthSearch->Size = System::Drawing::Size(75, 63);
				this->MonthSearch->TabIndex = 27;
				this->MonthSearch->Text = L"Search ";
				this->MonthSearch->UseVisualStyleBackColor = true;
				this->MonthSearch->Click += gcnew System::EventHandler(this, &MyForm::MonthSearch_Click);
				// 
				// YearSearch
				// 
				this->YearSearch->Location = System::Drawing::Point(494, 51);
				this->YearSearch->Name = L"YearSearch";
				this->YearSearch->Size = System::Drawing::Size(83, 61);
				this->YearSearch->TabIndex = 28;
				this->YearSearch->Text = L"Search";
				this->YearSearch->UseVisualStyleBackColor = true;
				this->YearSearch->Click += gcnew System::EventHandler(this, &MyForm::YearSearch_Click);
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(615, 283);
				this->Controls->Add(this->YearSearch);
				this->Controls->Add(this->MonthSearch);
				this->Controls->Add(this->label9);
				this->Controls->Add(this->label8);
				this->Controls->Add(this->DisHM);
				this->Controls->Add(this->DisLM);
				this->Controls->Add(this->DisAvgY);
				this->Controls->Add(this->DisHY);
				this->Controls->Add(this->label7);
				this->Controls->Add(this->label6);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->DisLY);
				this->Controls->Add(this->DisAvgM);
				this->Controls->Add(this->LMBox);
				this->Controls->Add(this->HMBox);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->AvgMBox);
				this->Controls->Add(this->LYBox);
				this->Controls->Add(this->HYBox);
				this->Controls->Add(this->AvgYBox);
				this->Controls->Add(this->Mlabel);
				this->Controls->Add(this->Ylabel);
				this->Controls->Add(this->YearBox);
				this->Controls->Add(this->MonthBox);
				this->Name = L"MyForm";
				this->Text = L"MyForm";
				this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void textBox1_TextChanged_2(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void HMBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
private: System::Void MonthBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void YearBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MonthSearch_Click(System::Object^  sender, System::EventArgs^  e) {
	int month;
	Int32::TryParse(MonthBox->Text, month);
	if (month < 1 || month > 12){
		MessageBox::Show("Please enter a valid Month. 1 through 12.");
		DisAvgM->Text = " ";
		DisHM->Text = " ";
		DisLM->Text = " ";
	}
	else {
		month--;
		if (AvgMBox->Checked == true){
			float testy = myWeather.avgCol(month);
			DisAvgM->Text = testy.ToString();
		}
		else if (AvgMBox->Checked == false){
			DisAvgM->Text = " ";
		}
		if (HMBox->Checked == true){
			float testy = myWeather.highestForCol(month);
			DisHM->Text = testy.ToString();
		}
		else if (HMBox->Checked == false){
			DisHM->Text = " ";
		}
		if (LMBox->Checked == true){
			float testy = myWeather.lowestForCol(month);
			DisLM->Text = testy.ToString();
		}
		else if (LMBox->Checked == false){
			DisLM->Text = " ";
		}
	}
}
private: System::Void YearSearch_Click(System::Object^  sender, System::EventArgs^  e) {
	int year;
	Int32::TryParse(YearBox->Text, year);
	int startYear = 0;
	startYear = *startYearPointer;
	if (year < startYear || year >(startYear + (ROWS - 1))){
		MessageBox::Show("Please enter a valid year.");
		DisAvgY->Text = " ";
		DisHY->Text = " ";
		DisLY->Text = " ";
	}
	else{
		year -= startYear;
		if (AvgYBox->Checked == true){
			float testy = myWeather.avgRow(year);
			DisAvgY->Text = testy.ToString();
		}
		else if (AvgYBox->Checked == false){
			DisAvgY->Text = " ";
		}
		if (HYBox->Checked == true){
			float testy1 = myWeather.highestForRow(year);
			DisHY->Text = testy1.ToString();
		}
		else if (HYBox->Checked == false){
			DisHY->Text = " ";
		}
		if (LYBox->Checked == true){
			float testy2 = myWeather.lowestForRow(year);
			DisLY->Text = testy2.ToString();
		}
		else if (LYBox->Checked == false){
			DisLY->Text = " ";
		}
	}
}
};
}

