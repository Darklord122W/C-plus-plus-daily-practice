#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
/* Use of & signifies Call by Reference. What it means in short is whatever you change for these variables in the function is
 reflected back to the calling function. So, you need not return values */
bool getInt(ifstream&, bool&, int&, string&);
int getFileSize(ifstream&);

int main ()
{
	int intData;
	string junkData;
	bool valueIsGood = false;
	string fileName = "";
	cout << "Enter the input filename: ";
	cin >> fileName;
	cout <<endl;
	ofstream foutInt("intVals.txt");
	ofstream foutJunk("junkVals.txt");
	//Open the file in read mode with the ifstream object fin
	ifstream fin;
	fin.open(fileName,ios::in);
	//Check if the file opened successfully. If not, exit the program
	if (fin.is_open())
		{
			std::cout << "file opened successfully\n";
		}
		else
		{
			std::cout << "Error opening file";
			return 0;
		}
	//Print the size of the file
	cout << "File Size: " << getFileSize(fin)<<endl; 

	//Get the line number of the file
	
	fin.clear();
	fin.seekg(0, ios::beg);

	int lineCount = 0;
	char ch;

	while (fin.get(ch)) {
		if (ch == '\n') {
			lineCount++;
		}
	}
	// If file is not empty and doesn't end with '\n', count the last line  
	fin.clear();  
	fin.seekg(0, ios::beg);  
	if (fin.peek() != EOF) {  
		bool endsWithNewline = false;  
		fin.seekg(-1, ios::end);  
		char lastChar;  
		fin.get(lastChar);  
		endsWithNewline = (lastChar == '\n');  
		fin.clear();  
		fin.seekg(0, ios::beg);  
		if (!endsWithNewline) {  
			lineCount++;  
		}  
	}
	cout<<"The number of line we have is: "<<lineCount<<endl;
	fin.clear();
	fin.seekg(0, ios::beg);
	while (getInt(fin, valueIsGood, intData, junkData)) {
		if (valueIsGood) {
			foutInt << intData << endl;
		} else {
			foutJunk << junkData << endl;
		}
	}
	// Close the files
	foutInt.close();
	foutJunk.close();
	fin.close();
		cout <<"You can now open intVals.txt and junkVals.txt to see the output!"<<endl;
		return 0;
	}

int getFileSize(ifstream& fin){
	int fileSize = 0; //For our case, fileSize will not exceed integer's limit so we do not need long
	//Write the logic to print the file size (in bytes)
	streampos opos = fin.tellg();
    cout << "original position: " << opos << endl;
	fin.clear();
	fin.seekg(0, ios::end);
	fileSize = static_cast<int>(fin.tellg());
	// Restore original position
    fin.seekg(opos, ios::beg);
	return fileSize;
}

// Function returns False if you cannot continue reading the file i.e. either the EOF or the Bad flag got set
bool getInt(ifstream& fin, bool& goodFlag, int& intData, string& junkData){
    string token;
	// Code the logic here
	// Try to read the next whitespace-separated token
    if (!(fin >> token)) {
        return false; // EOF or stream failed
    }

    // Use strtol to test if token is a pure integer
    char* endPtr = nullptr;
    long val = strtol(token.c_str(), &endPtr, 10);

    // Valid integer only if we consumed the entire token
    if (endPtr != nullptr && *endPtr == '\0') {

        // Optional range check for 32-bit int without extra headers
        if (val < -2147483648L || val > 2147483647L) {
            goodFlag = false;
            junkData = token;
        } else {
            goodFlag = true;
            intData = static_cast<int>(val);
        }

    } else {
        goodFlag = false;
        junkData = token;
    }

	return true;
}



