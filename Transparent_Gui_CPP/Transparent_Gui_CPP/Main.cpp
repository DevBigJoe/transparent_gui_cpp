//STD
#include <iostream>
#include <Windows.h>

//Local
#include "MainForm.h"

[System::STAThreadAttribute]
int main(cli::array<System::String^>^ args)
{
    FreeConsole();
       
    // Windows Forms vorbereiten
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    // MainForm aus dem Namespace erstellen
    System::Windows::Forms::Form^ form = gcnew TransparentGuiCPP::MainForm();
    System::Windows::Forms::Application::Run(form);

    return 0;
}