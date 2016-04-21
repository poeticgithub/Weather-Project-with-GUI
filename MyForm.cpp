/*Nujoma Halls, Maaz, Giovanni
This GUI will show the user information about monthly temps from the year 1869 to 2012.
This program accepts command line arguments specifiying the file name and the starting year.
*/

#include "MyForm.h"
using namespace System;
#include "Wheader.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
#include <msclr\marshal_cppstd.h>  
using namespace msclr::interop;



using namespace System::Windows::Forms;

//[STAThreadAttribute]

[STAThread]

int Main(array<System::String ^> ^args)

{
	String ^ firstArg = args[0]; // first command line arg
	String ^ secondArg = args[1]; //second command line arg

	string filename = marshal_as<string>(firstArg);
	int startYear=0;
	Int32::TryParse(secondArg, startYear);
	int * startYearPointer = &startYear; //puts the address of startYear into the pointer called startYearPointer 
	                                  //in order to send  over the second command line arg to Myform.h
	
	// Enabling Windows XP visual effects before any controls are created

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	//Namespace of the project create the form

	//Name of the form example MyForm

	Application::Run(gcnew GUI_demo::MyForm(filename, startYearPointer));

	return 0;

}

