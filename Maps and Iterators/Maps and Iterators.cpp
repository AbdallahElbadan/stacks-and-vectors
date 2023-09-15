#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include<map>
#include <iterator>
using namespace std;


int main() {
    unordered_map<string, int> wordCount;
    string lines[200];
    int lineCount = 0;
    ifstream inFile; // create an object inFile of type ifstream
    inFile.open("greenEggsAndHam.txt");
    while (getline(inFile, lines[lineCount])) {
        lineCount++;
    }
    for (int i = 0; i < lineCount;i++) {
        for (int j = 0; j < lines[i].length(); j++) {
            if (lines[i][j] < 'A' || lines[i][j] > 'z' ||
                (lines[i][j] < 'Z' && lines[i][j] > 'a')) {
                lines[i][j] = ' ';//set non-alphabetical to spaces
            }
        }
    }
    for (int i = 0; i < lineCount; i++) {
        //It's possible there are spaces in front so find first non-space
        int start = lines[i].find_first_not_of(" ");
        if (start < 0) continue; //skip this line
        //find first space after start
        int end = lines[i].find_first_of(" ", start);
        if (end <= 0) end = lines[i].length() - 1;
        string word = lines[i].substr(start, end - start);
        //add or increment the value in the map matching the word
        ++wordCount[word];
    }

    //printing out the size of the wordcout, the bucket count as well as the load factor.
    cout << "Number of keys: " << wordCount.size() << endl << endl;

    cout << "Bucket Count: " << wordCount.bucket_count() << endl << endl;

    cout << "Load factor: " << wordCount.load_factor() << endl << endl;


    //creating an iterador for max word and count
    auto itmax = wordCount.begin();

    int maxcount = 0;
    string maxword;

    //making a for loop to go through every word and compare it to the one before
    // and finding the most frequnt one
    for (itmax = wordCount.begin(); itmax != wordCount.end(); itmax++) {

        if (maxcount < itmax->second) {
            maxcount = itmax->second;
            maxword = itmax->first;
        }

    }

    cout << "Word with max frequency is " << maxword << " which is used " << maxcount << endl << endl;





    //creating the iterator
    auto iterator = wordCount.begin();

    cout << "The bucket key " << iterator->first << " : " << iterator->second << endl << endl;

    //make a loop to go through every singel bucket and print it
    for (iterator = wordCount.begin(); iterator != wordCount.end(); iterator++) {
        cout << "Key: " << iterator->first << " Value: " << iterator->second << endl << endl;

    }

    inFile.close();
    return 0;
}