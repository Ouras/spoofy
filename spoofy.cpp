#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstddef>
using namespace std;

void parse(string str, unsigned long long int* count, string* date);

int main()
{
    unsigned long long int msCount = 0;
    unsigned int minsListened= 0;
    string startDate = "";
    string endDate = "";

    ifstream jsonFile("StreamingHistory.json");
    ofstream outputFile("results.txt");

    //Perform one parsing operation to get the start date
    while (jsonFile.good())
    {
        string str;
        getline(jsonFile, str);
        
        size_t index;
        index = str.find("endTime");

        if (index != string::npos)
        {
            istringstream inSS(str);

            inSS.ignore(16, '"');
            inSS.ignore(16, '"');
            inSS.ignore(16, '"');

            inSS >> startDate;

            break;
        }
    }

    //Parse file line-by-line and total up the ms listened
    while (jsonFile.good())
    {
        string str;
        
        getline(jsonFile, str);
        
        parse(str, &msCount, &endDate);
    }

    //Calculate minutes listened
    minsListened = msCount / 60000;

    //Output
    outputFile << minsListened << " minutes listened between " << startDate << " and " << endDate;

    cout << minsListened << " minutes listened between " << startDate << " and " << endDate;
}

void parse(string str, unsigned long long int* count, string* date)
{
    //Look for endTime and parse
    size_t index;
    index = str.find("endTime");

    if (index != string::npos)
    {
        istringstream inSS(str);

        inSS.ignore(16, '"');
        inSS.ignore(16, '"');
        inSS.ignore(16, '"');

        inSS >> *date;

        return;
    }

    //Look for msPlayed and parse
    index = str.find("msPlayed");

    if (index != string::npos)
    {
        istringstream inSS(str);

        inSS.ignore(16, '"');
        inSS.ignore(16, '"');
        inSS.ignore(16, ':');

        unsigned int tmp;
        inSS >> tmp;

        *count += tmp;

        return;
    }
}