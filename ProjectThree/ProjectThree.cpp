// Jarrale Butts
// Febauary 19th 2023
// The purpose of this application is to 

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;


class SomeClass {
      public:
      private:
};

int main() {

   ifstream readFS;     // Input file stream
   ofstream writeFS;    // Output file stream
   string userInput;         // Data value for string in file
   int wordFreq = 0;
   string currWord;

//    cout << "Opening file CS210_Project_Three_Input_File.txt" << endl;     // Message to the user
   readFS.open("CS210_Project_Three_Input_File.txt");
   if (!readFS.is_open()) {                                      // If the input file can't be opened display a message to the user
      cout << "Couldn't open CS210_Project_Three_Input_File.txt" << endl;
      return 1;                                                  // 1 indicates error
   }

//    cout << "Opening file frequency.dat.txt" << endl;       // Message to the user
   writeFS.open("frequency.dat.txt");                       // Opening output file
   if (!writeFS.is_open()) {                                     // If the output file can't be opened display a message to the user
      cout << "Couldn't open frequency.dat.txt" << endl;
      return 1;                                                  // 1 indicates error
   }

   cout << "Input item or word: ";                     // Word to be found
   cin >> userInput;

   while (!readFS.eof()) {
      readFS >> currWord;
      if (!readFS.fail()) {
         if(currWord == userInput) {
            ++wordFreq;
         }
      }
   }

   cout << userInput << " " << wordFreq << endl;
   writeFS << userInput << " " << wordFreq << endl;     // Write the results of the search and frequency to a seperate file
    

//    cout << "Closing file frequency.dat.txt" << endl;       // Close output file
   writeFS.close();

//    cout << "Closing file CS210_Project_Three_Input_File.txt" << endl << endl;       // Close input file
   readFS.close();

   return 0;
}
