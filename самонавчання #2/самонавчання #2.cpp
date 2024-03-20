

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std;


class File
{
 public:
	void virtual display(const char* path)//звичайний
	{
		ifstream file(path);

		if (!file.is_open())
		{
			cerr << "\nError";
		}
		else 
		{
			char character;

			while (file.get(character))
			{
				cout << character;
			}
			file.close();
		}
	}
};

class File1 : public File
{
public:

	void display(const char* path) override //ASCII-кодів символів
	{
		ifstream file(path);
		if (file.is_open()) 
		{
			int ch;
			while ((ch = file.get()) != EOF) 
			{
				std::cout << ch << " ";
			}

			cout << std::endl;
			file.close();
		}
		else
		{
			std::cerr << "Unable to open file: " << path << std::endl;
		}
	}
};

class File2 : public File
{
public:
	void display(const char* path) override//у двійковому вигляді
	{
		ifstream file(path, std::ios::binary);

		if (file.is_open()) 
		{
			vector<char> buffer(istreambuf_iterator<char>(file), {});
			for (char byte : buffer) 
			{
				cout << bitset<8>(byte) << " ";
			}
			cout << std::endl;
			file.close();
		}

		else 
		{
			std::cerr << "Unable to open file: " << path << std::endl;
		}
	}
};

int main()
{
	const char* path = "Text.txt";

	File k;
	File1 l;
	File2 s;

	
	k.display(path);
	cout << endl;
	cout << endl;
	l.display(path);
	cout << endl;
	s.display(path);
	
}


