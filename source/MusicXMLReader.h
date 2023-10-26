#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <numeric>
#include <set>
#include <locale>
#include <codecvt>
#include <map>

#include "Z:\VS\MidiApp\MidiAPP\tiny\tinyxml2.h"
using namespace std;
using namespace tinyxml2;

class MusicXMLReader
{

    vector <string> musical_parts; // id ���� ����������� ������ � ������������
    XMLDocument doc; // ���� musicxml 

    vector<char> v_notes; // ������ � ������      | r - rest �����|
    vector<string> v_octaves;//������ � ��������    | n - null ��� rest � notes|
    vector<int> v_semitone; // ������ � ����������
    vector<string> v_voices;// ������ � ��������
    vector<int> v_league; // ������ � ������������ ���
    vector<float> v_duration; // ������ � ��������������
    vector<string> v_instruments;// ������ � �������� �������������

    vector<int> part_list; // ����� �������, ������������ ��� ������
    int divisions = 1; //���������� ��� ����������� ������� ���� ������������� � ������
    //���� ��� �����������, �� �� ��������� ����� 1

    map<string, int> PercussionSurvivalcraftMap{ // �������� �������� � ��� ����������� � Survivalcraft
        {"Acoustic Bass Drum",1},
        {"Bass Drum 1",1},
        {"Side Stick",9}, //�������� 2,3
        {"Acoustic Snare",0},
        {"Electric Snare",0},
        {"Low Floor Tom",5},
        {"Closed Hi-Hat",2},
        {"High Floor Tom",5},
        {"Pedal Hi-Hat",3},
        {"Low Tom",5},
        {"Open Hi-Hat",8}, //����� �� 4, �� ������ �������� 8
        {"Low-Mid Tom",6},
        {"Hi-Mid Tom",6},
        {"Crash Cymbal 1",7},
        {"High Tom",6},
        {"Ride Cymbal 1",8},
        {"Chinese Cymbal",7},
        {"Ride Bell",8},
        {"Tambourine",3},
        {"Splash Cymbal",4}, //�������� 4 � 7
        {"Cowbell",3},
        {"Crash Cymbal 2",7},
        {"Ride Cymbal 2",8},
        {"Open Hi Conga",6},
        {"Low Conga",5},
        {"Cabasa",3},
        {"Castanets",2},
        {"Hand Clap",9},
        {"F",15}
    };
    map<string, string> PercussionPartInstruments; //������ id ����������� � ��� �������� �� ������

    //������� � ����������������� �������
    vector <int> converted_notes;
    vector <int> converted_notes_sequence;
    vector <int> converted_octaves;
    vector <int> converted_octaves_sequence;
    void type_instrument(int instrument); //���-��� ��� ����������� ������� � ������ ������� �����


    //�������� ���������� ��� ������ � �������
    int fifths = 0; // ����� ��� �����
    int beats = 0; // ���������� ����� � ��������� ��������� �������
    int beat_type = 0; //���������� ����� � ����������� ��������� �������
    int line = 0; //������������ ��� ������.2 ��� ����� G (���������� ����), 4 ��� ����� F (������� ����) � 3 ��� ����� C (�������� ����).
    int bpm = 0; // beat per minute
    int count_measure = 1; //������� ������ � 1
    int duration = 0; //������� ������ � 1
    //int voice = 0; //������
    int step = 0; // ��� ��� pitch
    int octave = 0; // ������
    int alter = 0; //���������� ������� �� ����, ���� �� ���� �� �����
    int chromatic = 0; // ���������� ����� ��� �������� �� ����������� � ��������� ����
    string sign; // ������ �����
    string bpm_unit; //����������� bmp ��� ��������
    string accidental; // ���� �� ����: sharp - ����, natural - �����,flat - ������  
    string rest; // �����
    string tied; //���� start, stop
    int accidental_code(string s);
    int minimal_duration; //����������� ������������ �� ��� ������������

    int high_octave; //�������  ������
    int low_octave; //������ ������

    //������, ������ Translation()
    void notes_f(vector<char>& notes, vector<int>& semitone, int chromatic);
    void octaves_f(vector<int>& converted_notes, vector<string>& octaves, int instrument);
    void convert_to_sequence(vector<int>&, vector<float>&, vector<int>&, int t);//����� ������ ��� � �����
    void convert_to_sequence_percussion(vector <string>&, vector<float>&);
    void show_information_about_composition(vector<float>& duration, int fraction_numerator, int denominator_fraction, int bpm);
    void show_notes(vector <int>& converted_notes);
    void show_octaves(vector <int>& converted_octaves);
    int switch_hex_notes(char ch, int semitone);
    void print_amount(int note, int duration, int league, vector <int>& notes_or_octaves); //������������ ������������������ ��� ��� ����� � ������ ������������ � ���
    void calculation_duration(int min_duration_note);
    void FindMinimalDuration(const char* );
    void WriteScoreInstrument(); //����� ������������ �������� ������� ������������
public:
    MusicXMLReader(const char*); //����������� ����������� musicxml � ����������� ������
    void ReadVoice(const char*); //�����, ����������� ���������� ������� � ������ ��� ������������ ������
    void MusicPartWriter(const char*, const char*); //�����, ������� ���������� ��� ���������� �� ������ � ������ � �������
    void OutputToConsole(); //����� �������� � �������
    int Translation(int instrument); // �������, ������� �������� ������ ������� ��� ��������
};
