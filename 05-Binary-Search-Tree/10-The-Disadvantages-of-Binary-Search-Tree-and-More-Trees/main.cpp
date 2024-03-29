#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include "BST.h"
#include "SequenceST.h"
#include "FileOps.h"

using namespace std;

int main() {
    
    string filename = "communist.txt";
    vector<string> words;

    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        time_t startTime = clock();
        BST<string, int> *bst = new BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst).search(*iter);
            if (res == NULL)
                (*bst).insert(*iter, 1);
            else
                (*res)++;
        }

        if( bst->contain("unite") )
            cout << "'unite' : " << *(*bst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete bst;


        startTime = clock();
        SequenceST<string, int> *sst = new SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*sst).search(*iter);
            if (res == NULL)
                (*sst).insert(*iter, 1);
            else
                (*res)++;
        }

        if( sst->contain("unite") )
            cout << "'unite' : " << *(*sst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete sst;


        startTime = clock();
        BST<string, int> *bst2 = new BST<string, int>();

        sort( words.begin() , words.end() );
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst2).search(*iter);
            if (res == NULL)
                (*bst2).insert(*iter, 1);
            else
                (*res)++;
        }

        cout << "'unite' : " << *(*bst2).search("unite") << endl;
        endTime = clock();

        cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete bst2;
    }

    return 0;
}