#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Translator.h"
#include "MusicXMLReader.h" // открытие и чтение MusicXML

using namespace std;


int main() {
    setlocale(LC_ALL, "RU");
    MusicXMLReader xml("123.xml");
    xml.MusicPartReader("P2");
    Translator music(v_notes, v_octaves, v_semitone, v_duration, v_league, beats, beat_type, bpm, 0);

    return 0;
}
