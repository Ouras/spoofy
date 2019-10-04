/*
    Random StreamingHistory generator:
    Generates a random Spotify StreamingHistory.json file for
    a year of streams for testing purposes based on two parameters:
    number of songs and number of streams. Number of streams is used
    as the maximum number of streams total;

    Accepts one or no arguments:
        If no arguments are given, number of songs and number of
        streams is select randomly
        If any argument is provided (e.g., "r"), prompts the user to
        enter number of songs and number of stream

    Written by: Ouras
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define MAX_SONGS 256
#define MAX_STREAMS 8196

class Song;

int main(int argc, char *argv[])
{
    unsigned int numSongs = 0;
    unsigned int numStreams = 0;

    vector<string> artists;
    vector<Song> songs;
    vector<Song> streams;

    srand(time(0));

    //Validate command-line arguments
    if (argc = 1)
    {
        numSongs = (rand() % MAX_SONGS) + 1;
        numStreams = (rand() % MAX_STREAMS) + 1;
    } else
    {
        cout << "Number of songs: ";
        cin >> numSongs;

        while (cin.bad() || numSongs < 1)
        {
            cin.clear();
            cin >> numSongs;
        }

        cout << "Number of songs: ";
        cin >> numStreams;

        while (cin.bad() || numStreams < 1)
        {
            cin.clear();
            cin >> numStreams;
        }
    }

    //Open output file
    ifstream inFS;
    inFS.open("StreamingHistory.json");

    if (!inFS.is_open())
    {
        cout << "Failed to open output file" << endl;

        return 1;
    }

    //Generate artists
    for (int i = 0; i < numSongs / 3; i++)
    {
        int n;
        string adj;
        string noun;
        ostringstream nameStream;

        //Generate name
        n = (rand() % 8) + 1;
        
        switch (n) {
            case 1: adj = "Unusual";
                break;
            case 2: adj = "Happy";
                break;
            case 3: adj = "Angry";
                break;
            case 4: adj = "Blue";
                break;
            case 5: adj = "Pink";
                break;
            case 6: adj = "Arrogant";
                break;
            case 7: adj = "Living";
                break;
            case 8: adj = "Secret";
                break;
        }

        n = (rand() % 8) + 1;

        switch (n) {
            case 1: noun = "Advantage";
                break;
            case 2: noun = "Stranger";
                break;
            case 3: noun = "Player";
                break;
            case 4: noun = "Funk";
                break;
            case 5: noun = "Hotel";
                break;
            case 6: noun = "Sound";
                break;
            case 7: noun = "Feature";
                break;
            case 8: noun = "Stone";
                break;
        }

        n = (rand() % 8) + 1;

        if (n % 2 == 0)
        {
            nameStream << "The ";
        }

        n = (rand() % 8) + 1;

        if (n % 2 == 0)
        {
            nameStream << adj << " ";
        } else
        {
            nameStream << noun << "s";
        }

        //Add name to artists vector
        artists.resize(i + 1);
        artists.at(i) = nameStream.str();
    }

    //Generate numSongs songs
    for (int i = 0; i < numSongs; i++)
    {
        int n;
        int artistIndex;
        string adj = "";
        string noun = "";
        istringstream nameStream;

        //Generate song name
        n = (rand() % 8) + 1;
        
        switch (n) {
            case 1: adj = "Unusual";
                break;
            case 2: adj = "Happy";
                break;
            case 3: adj = "Angry";
                break;
            case 4: adj = "Blue";
                break;
            case 5: adj = "Pink";
                break;
            case 6: adj = "Arrogant";
                break;
            case 7: adj = "Living";
                break;
            case 8: adj = "Secret";
                break;
        }

        n = (rand() % 8) + 1;

        switch (n) {
            case 1: noun = "Advantage";
                break;
            case 2: noun = "Stranger";
                break;
            case 3: noun = "Player";
                break;
            case 4: noun = "Funk";
                break;
            case 5: noun = "Hotel";
                break;
            case 6: noun = "Sound";
                break;
            case 7: noun = "Feature";
                break;
            case 8: noun = "Stone";
                break;
        }

        nameStream << adj << " " << noun;

        //Pick artist
        artistIndex = rand() % artists.size();

        //Create Song object
        songs.resize(i + 1);
        songs.at(i) = Song::Song(nameStream.str(), artists.at(artistIndex))
    }

    //Generate numStreams streams and output to file
    inFS << "[" << endl;
    
    for (int i = 1; i <= 365; i++)
    {
        int n;
        n = numStreams / 365;
        n = (rand() % n);
        n = (int) (n * 1.2);

        for (int j = 0; j < n; j++)
        {
            int tmp = rand() % songs.size();

            inFS << "  {" << endl;

            inFS << "    \"endTime\" : " << "2018-";
            
            //Generate date
            if (i <= 1 && i <= 31)
            {
                inFS << "01-" << setfill('0') << setw(2) << i; 
            } else if (i <= 32 && i <= 59)
            {
                inFS << "02-" << setfill('0') << setw(2) << i % 31;
            } else if (i <= 60 && i <= 90)
            {
                inFS << "03-" << setfill('0') << setw(2) << i % 59;
            } else if (i <= 91 && i <= 120)
            {
                inFS << "04-" << setfill('0') << setw(2) << i % 90;
            } else if (i <= 121 && i <= 151)
            {
                inFS << "05-" << setfill('0') << setw(2) << i % 120;
            } else if (i <= 152 && i <= 181)
            {
                inFS << "06-" << setfill('0') << setw(2) << i % 151;
            } else if (i <= 182 && i <= 212)
            {
                inFS << "07-" << setfill('0') << setw(2) << i % 181;
            } else if (i <= 213 && i <= 243)
            {
                inFS << "08-" << setfill('0') << setw(2) << i % 212;
            } else if (i <= 244 && i <= 273)
            {
                inFS << "09-" << setfill('0') << setw(2) << i % 243;
            } else if (i <= 274 && i <= 304)
            {
                inFS << "10-" << setfill('0') << setw(2) << i % 273;
            } else if (i <= 305 && i <= 334)
            {
                inFS << "11-" << setfill('0') << setw(2) << i % 304;
            } else if (i <= 335 && i <= 365)
            {
                inFS << "12-" << setfill('0') << setw(2) << i % 334;
            }

            inFS << " 12:00\"," << endl;

            inFS << "    \"artistName\" : \"" << songs.at(tmp).getArtist() << "\"," << endl;

            inFS << "    \"trackName\" : \"" << songs.at(tmp).getTitle() << "\"," << endl;

            tmp = rand() % 270000;

            inFS << "    \"msPlayed\" : " << tmp << endl;

            inFS << "  }," << endl;
        }
    }

    inFS << "]";
}

class Song
{
    private:
        string title;
        string artist;
    public:
        void setTitle(string title) { this->title = title; }
        void setArtist(string title) { this->artist = artist; }
        string getTitle() { return title; }
        string getArtist() { return artist; }
        Song()
        {
            title = "";
            artist = "";
        }
        Song(string title, string artist)
        {
            this->title = title;
            this->artist = artist;
        }
};