#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
//#include "Translator.h"
#include "MusicXMLReader.h" // открытие и чтение MusicXML

using namespace std;


int main() {
    system("chcp 1251");
    //setlocale(LC_ALL, "RU");
    MusicXMLReader xml("Scatman_ski_ba_bop_dop_bop2.musicxml");

    xml.ReadVoice("P1");
    system("pause");

    xml.MusicPartWriter("P7","1");
    //xml.OutputToConsole(); //вывод доп информации
    xml.Translation(7);//3, 6

    return 0;
}
