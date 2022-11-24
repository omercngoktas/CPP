#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void tokenize(string s, string del = " ")
{
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        cout << s.substr(start, end - start) << endl;
    } while (end != -1);
}

int main() {
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("coktan-secmeli-sorular.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
    // Output the text from the file
        //tokenize(myText, "\t");
        //cout << endl;
        for(int i = 0; i < myText.size(); i++) {
            if(myText[i] == '\t'){ 
                i++;
                cout << "-";
            }
            cout << myText[i];
        }
    }
    cout << endl;
    // Close the file
    MyReadFile.close();

    return 0;
}