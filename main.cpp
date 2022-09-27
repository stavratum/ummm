#include <windows.h>
#include <time.h>
#include <iostream>
#include <fstream>

using std::string;

string getClipboardText() {
	if (IsClipboardFormatAvailable(CF_TEXT) && OpenClipboard(NULL)) {
		HANDLE data = GetClipboardData(CF_TEXT);
		CloseClipboard();

		return (char*)data;
	}
	return "PNG";
}

void makeFile(string file_name, string content) {
	std::ofstream file;
	file.open(file_name);
	file << content;
	file.close();
}

int main() {
	system("title Mega Hack");
  
  std::cout << "Hiding console in ";
  for (int i = 3; i > 0; i--) {
  		std::cout << i << "... ";
      Sleep(1000);
	}
  ShowWindow(GetConsoleWindow(), SW_HIDE);

	string prev = getClipboardText();

	while (true) {
		string current = getClipboardText();

		if (current != prev && current.find("PNG")) {
			string path = "clipboards/" + std::to_string( time(0) ) + ".txt";
			std::cout << "Wrote at: " << path << "\n";

			makeFile("./" + path, current);
			prev = current;
		}
		
		Sleep(1000);
	}

	return 0;
}
