#include <iostream>
using namespace std;
int main() {
    //minimal coverage and length to be filtered out
    int minCoverage = 10;
    int minLength = 200;

    string line;
    while (getline(cin, line))
    {
        if (line == "") {
            break;
        }
        if(line.at(0) == '>'){
            //find last position of _ as it preceeds coverage number
            size_t found = line.find_last_of('_');
            //keep the rest of the line in order to extract the length
            string restofline = line.substr(0, found);
            int coverage = stoi(line.substr(found + 1));
            //remove _ separating length value from cov
            found = restofline.find_last_of('_');
            restofline = line.substr(0, found);
            //get seq length
            found = restofline.find_last_of('_');
            int length = stoi(restofline.substr(found + 1));
            //write out the line without > character
            if(coverage < minCoverage || length < minLength){
                cout << line.substr(1) << "\n";
            }
        }
    }
    return 0;
}