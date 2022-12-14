#include <bits/stdc++.h>

using namespace std;

string getCurrentFileName(int currentFileIdx){
	return ("output_" + to_string(currentFileIdx) + ".txt");
}

void readInput(string &filename, int &numberOfFiles){
	cout << "Enter the name of the file to be split: ";
	cin >> filename;

	cout << "Enter the number of files to be split into: ";
	cin >> numberOfFiles;
}
 
int getTotalNumberOfLines(string filename){
	ifstream file(filename);
	int numberOfLines = 0;
	string line;
	while(getline(file, line)){
		numberOfLines++;
	}
	return numberOfLines;
}

int main(){
	string filename, line;
	int numberOfFiles, currentFileIdx = 1, lineCount = 0;

	readInput(filename, numberOfFiles);

	ifstream file(filename);
	ofstream currentOutputFile;
	currentOutputFile.open(getCurrentFileName(currentFileIdx));

	if(!file){
		std::cerr << "Failed to open file\n";
		return EXIT_FAILURE;
	}

	int totalNumberOfLines = getTotalNumberOfLines(filename);			

	while(getline(file, line)){
		currentOutputFile << line << '\n';
		lineCount++;
		
		if(currentFileIdx == numberOfFiles) continue;
		
		if(lineCount % (totalNumberOfLines / numberOfFiles) == 0){
			currentOutputFile.close();
			currentOutputFile.open(getCurrentFileName(++currentFileIdx));
		}
	}	

	return 0;
}
