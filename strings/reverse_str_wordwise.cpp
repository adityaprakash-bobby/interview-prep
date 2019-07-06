#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#define fo(i, a ,b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfo(i, a ,b) for(int i = (int)(a); i >= (int)(b); i--)

using namespace std;

/* Function to modify the string to reverse it */
void reverseWordwise(string &A) {

    stringstream str_stream(A);
    vector<string> words;
    string word;

    while(getline(str_stream, word, ' ')) {
        words.push_back(word);
    }

    str_stream.str(string());
    A.clear();

    for (int i = words.size() - 1; i >= 0; i--) {
        if (i != 0) {
            A += words[i] + " ";
        } else {
            A += words[i];
        }
    }

}

/* Driver function to check the above function */
int main(int argc, char const *argv[])
{
    string test = "iwfcqq igjgip myq sn dqmy qfho sswz ouhsuhf kxorifrhubk jsx ulc osdt fwbpudnbrozzifml";
    reverseWordwise(test);
    cout << test << endl;  
    return 0;
}