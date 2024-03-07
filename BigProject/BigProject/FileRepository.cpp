#include "FileRepository.h"

void FileRepository::load() {
    ifstream file(filepath);
    if (!file.is_open())
        throw runtime_error("Input file cannot be opened.");
    string line, a, t, ly, lk;
    int d = 0, y = 0;
    while (getline(file, line)) {
        if (line.find("LYRICS=") != string::npos) {
            do {
                if (!line.empty() && line[line.length() - 1] == '\"') {
                    ly = ly + "\n" + line.substr(line.find_first_of("\"") + 1, line.length() - 1);
                    break;
                }
                ly = ly + " " + line.substr(line.find_first_of("\"") + 1, line.length());
            } while (getline(file, line));
        }

        if (line.find("YEAR=") != string::npos)
            y = stoi(line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1));

        if (line.find("DURATION=") != string::npos)
            d = stoi(line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1));

        if (line.find("LINK=") != string::npos)
            lk = line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1);

        if (line.find("TITLE=") != string::npos)
            t = line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1);

        if (line.find("ARTIST=") != string::npos) {
            if (!a.empty()) {
                songs.push_back(Song(a, t, ly, d, lk, y));
                a = "";
                ly = "";
            }
            a = line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1);
        }
    }
    if (!a.empty()) {
        store(Song(a, t, ly, d, lk, y));
    }
    file.close();
}

void FileRepository::save() {
    ofstream file(filepath);
    for (Song& o : songs) {
        file << "ARTIST=" << "\"" << o.getArtist() << "\"" << endl;
        file << "TITLE=" << "\"" << o.getTitle() << "\"" << endl;
        file << "YEAR=" << "\"" << o.getYear() << "\"" << endl;
        file << "DURATION=" << "\"" << o.getDuration() << "\"" << endl;
        file << "LINK=" << "\"" << o.getLink() << "\"" << endl;
        file << "LYRICS=" << "\"" << o.getLyrics() << "\"" << endl;
        file << endl;
    }
    file.close();
}

void FileRepository::store(const Song& s) {
    Repository::store(s);
    save();
}

void FileRepository::remove(const Song& s) {
    Repository::remove(s);
    save();
}
