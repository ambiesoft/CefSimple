// CefSimple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace System;
using namespace System::Windows::Forms;

int main()
{
	Form f;
	f.Size = System::Drawing::Size(600, 800);
	String^ url = "https://google.com";
	CefSharp::WinForms::ChromiumWebBrowser cr(url);
	cr.Dock = DockStyle::Fill;
	f.Controls->Add(% cr);
	f.ShowDialog();
}

