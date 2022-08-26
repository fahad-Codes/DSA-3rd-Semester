#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {

	int a;

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	$safeprojectname$::MyForm^ form = gcnew $safeprojectname$::MyForm(); // Create the instance and keep a pointer to it
	Application::Run(form); // Display the Form
	System::String^ name = form->getUsername();

}