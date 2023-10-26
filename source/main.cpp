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

    MusicXMLReader xml("Z:\\VS\\Survivalcraft-notes-translator\\survivalcraft-notes-translater\\TEMP\\4.musicxml");

    xml.ReadVoice("P1");
    system("pause");

    xml.MusicPartWriter("P1","2");//номер партии и голос
    //xml.OutputToConsole(); //вывод доп информации
    xml.Translation(4);//тип инструмента

    return 0;
}
