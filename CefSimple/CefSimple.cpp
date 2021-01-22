// CefSimple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace System;
using namespace System::Windows::Forms;

void OnClick(System::Object^ sender, System::EventArgs^ e);

[STAThreadAttribute]
int main()
{
	Form f;
	f.Size = System::Drawing::Size(800, 800);
	MenuStrip ms;
	ToolStripMenuItem item("Load Url From Clipboard");
	item.Click += gcnew System::EventHandler(&OnClick);
	ms.Items->Add(% item);
	f.MainMenuStrip = % ms;
	String^ url = "https://google.com";
	CefSharp::WinForms::ChromiumWebBrowser cr(url);
	item.Tag = %cr;
	f.Controls->Add(% cr);
	f.Controls->Add(% ms);
	f.ShowDialog();
}


void OnClick(System::Object^ sender, System::EventArgs^ e)
{
	ToolStripMenuItem^ item = (ToolStripMenuItem^)sender;
	CefSharp::WinForms::ChromiumWebBrowser^ cr = (CefSharp::WinForms::ChromiumWebBrowser^)item->Tag;
	String^ url;
	try
	{
		url = Clipboard::GetText();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
		return;
	}
	cr->Load(url);
}
