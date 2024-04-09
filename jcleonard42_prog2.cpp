/*
	Title:  		jcleonard42_prog2.cpp
	Author:			Jonathan Leonard
	Date Created:  	June 13, 2022
	Purpose:  		Brute force string matching algorithm
*/

#include <iostream>
#include <string>
using namespace std;

void stringMatching(string, string);

int main(){
    string text;
	string pattern;

	/*User text input section*/
	cout << "\nEnter a string of characters, called the text.\nTEXT: ";
	getline(cin, text);

	/*Input validation*/
	while(text.length() == 0){
		cout << "Oops!  You must enter in a text greater than zero characters.\nTEXT: ";
		getline(cin, text);
	}

	/*User pattern input section*/
	cout << "\nEnter a search string to find in the text, called the pattern.\n";
	cout << "Your pattern must be less than " << text.length() << " characters long.\nPattern: ";
	getline(cin, pattern);

	/*Input validation*/
	while(pattern.length() == 0 || pattern.length() >= text.length()){

		/*Determines in what way user input was invalid to give appropriate directions*/
		if(pattern.length() == 0){
			cout << "Oops!  You must enter in a text greater than zero characters.\nPattern: ";
		}
		else{
			cout << "Oops! Your pattern must be less than " << text.length() << " characters long.\nPattern: ";
		}

		getline(cin, pattern);
	}

	cout << endl;

	stringMatching(text, pattern);  // String matching function call

}

void stringMatching(string text, string pattern){
	int j;  // Holds iterations of inner loop
	int totalComparisons = 0;  // Total compariosns made in algorithm
	int index = 0;  // Starting index being searched

	for(int i=0; i <= text.length() - pattern.length(); i++){  // Iterates as long as text can still contain pattern

		j = 0;

		while(j < pattern.length() && pattern.at(j) == text.at(i+j)){  // Iterates as long as strings match
			cout << "LETTER MATCHED-" << pattern.at(j) << ", NUMBER OF CHARS MATCHED-" << j+1 << endl;
			j = j+1;
			totalComparisons += 1;
		}

		if(j == pattern.length()){  // Takes appropriate action based on if the pattern was found in the text
			i = text.length() - pattern.length();
		}
		else{
			totalComparisons += 1;
			index += 1;
		}
	}
	/*Final result output section*/
	if(j == pattern.length()){
		cout << "\nPattern was found at index " << index << "!\n";
	}
	else{
		cout << "\nSorry, the pattern was not found in the text.\n";
	}
	cout << "TOTAL COMPARISONS: " << totalComparisons << endl;
}
