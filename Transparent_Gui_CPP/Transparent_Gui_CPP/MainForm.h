#pragma once

namespace TransparentGuiCPP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	//To make the Form moveable---------Start
	private: bool dragging;
	private: Point offset;
	//THX TO (Source): www.codeproject.com/articles/Making-a-Borderless-Form-Movable-in-C#comments-section
	//To make the Form moveable---------End



	private: System::Windows::Forms::Panel^ panelTaskbar;
	protected:
	private: System::Windows::Forms::Panel^ panelMainBody;
	private: System::Windows::Forms::Button^ buttonCloseMainForm;
	private: System::Windows::Forms::PictureBox^ pictureBoxTheme1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panelTaskbar = (gcnew System::Windows::Forms::Panel());
			this->buttonCloseMainForm = (gcnew System::Windows::Forms::Button());
			this->panelMainBody = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxTheme1 = (gcnew System::Windows::Forms::PictureBox());
			this->panelTaskbar->SuspendLayout();
			this->panelMainBody->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxTheme1))->BeginInit();
			this->SuspendLayout();
			// 
			// panelTaskbar
			// 
			this->panelTaskbar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panelTaskbar->Controls->Add(this->buttonCloseMainForm);
			this->panelTaskbar->Location = System::Drawing::Point(12, 12);
			this->panelTaskbar->Name = L"panelTaskbar";
			this->panelTaskbar->Size = System::Drawing::Size(976, 24);
			this->panelTaskbar->TabIndex = 0;
			this->panelTaskbar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panelTaskbar_Paint);
			this->panelTaskbar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panelTaskbar_MouseDown);
			this->panelTaskbar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panelTaskbar_MouseMove);
			this->panelTaskbar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panelTaskbar_MouseUp);
			// 
			// buttonCloseMainForm
			// 
			this->buttonCloseMainForm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCloseMainForm->ForeColor = System::Drawing::Color::Red;
			this->buttonCloseMainForm->Location = System::Drawing::Point(953, 0);
			this->buttonCloseMainForm->Name = L"buttonCloseMainForm";
			this->buttonCloseMainForm->Size = System::Drawing::Size(22, 22);
			this->buttonCloseMainForm->TabIndex = 0;
			this->buttonCloseMainForm->Text = L"X";
			this->buttonCloseMainForm->UseVisualStyleBackColor = true;
			this->buttonCloseMainForm->Click += gcnew System::EventHandler(this, &MainForm::buttonCloseMainForm_Click);
			// 
			// panelMainBody
			// 
			this->panelMainBody->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panelMainBody->Controls->Add(this->pictureBoxTheme1);
			this->panelMainBody->Location = System::Drawing::Point(12, 42);
			this->panelMainBody->Name = L"panelMainBody";
			this->panelMainBody->Size = System::Drawing::Size(976, 396);
			this->panelMainBody->TabIndex = 1;
			// 
			// pictureBoxTheme1
			// 
			this->pictureBoxTheme1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxTheme1.Image")));
			this->pictureBoxTheme1->Location = System::Drawing::Point(3, 3);
			this->pictureBoxTheme1->Name = L"pictureBoxTheme1";
			this->pictureBoxTheme1->Size = System::Drawing::Size(15, 390);
			this->pictureBoxTheme1->TabIndex = 0;
			this->pictureBoxTheme1->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Green;
			this->ClientSize = System::Drawing::Size(1000, 450);
			this->Controls->Add(this->panelMainBody);
			this->Controls->Add(this->panelTaskbar);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->TransparencyKey = System::Drawing::Color::Green;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panelTaskbar->ResumeLayout(false);
			this->panelMainBody->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxTheme1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonCloseMainForm_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void panelTaskbar_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//Make sure it isn't moving when we open the form.
		this->dragging = false;
	}
private: System::Void panelTaskbar_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//tell the form its gonna be draggin'
	this->dragging = true;
	this->offset = Point(e->X, e->Y);
}
private: System::Void panelTaskbar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->dragging){ //Move, soldier, MOVE!
    Point currentScreenPos = PointToScreen(e->Location);
    Location = Point(currentScreenPos.X - this->offset.X, 
                     currentScreenPos.Y - this->offset.Y);
}
}
private: System::Void panelTaskbar_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = false; //this bool is awesome
}
};
}