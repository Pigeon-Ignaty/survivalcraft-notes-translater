#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
//#include "Translator.h"
#include "MusicXMLReader.h" // открытие и чтение MusicXML

using namespace std;


int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите имя файла с расширением, либо путь до него." << endl;
    cout << "Пример: Minecraft_OST.musicxml или D:\\MIDI\\Minecraft_OST.musicxml"  << endl;

    MusicXMLReader xml("Scatman_ski_ba_bop_dop_bop4.musicxml");

    xml.ReadVoice("P6");
    system("pause");

    xml.MusicPartWriter("P8","1");
    //xml.OutputToConsole(); //вывод доп информации
    xml.Translation(8);//3, 6

    return 0;
}
