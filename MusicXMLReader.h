#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
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
    vector<int> v_duration; // ������ � ������������ ���
    vector<int> part_list; // ����� �������
    int fifths = 0; // ����� ��� �����
    int beats = 0; // ���������� ����� � ��������� ��������� �������
    int beat_type = 0; //���������� ����� � ����������� ��������� �������
    string sign; // ������ �����
    int line = 0; //������������ ��� ������.2 ��� ����� G (���������� ����), 4 ��� ����� F (������� ����) � 3 ��� ����� C (�������� ����).
    int bpm = 0; // beat per minute
    string bpm_unit; //����������� bmp ��� ��������
    int count_meaure = 1; //������� ������ � 1
    int duration = 0; //������� ������ � 1
    int voice = 0; //������
    int step = 0;
    int octave = 0;
    int alter = 0; //���������� ������� �� ����, ���� �� ���� �� �����
    int chromatic = 0;
    string accidental; // ���� �� ����: sharp - ����, natural - �����,flat - ������  
    string rest; // �����
    string tied; //���� start, stop
    int accidental_code(string s);

    friend class Translator;
public:
    MusicXMLReader(const char*); //����������� ����������� musicxml � ����������� ������
    void MusicPartReader(const char*); //�����, ������� ������� ��� ���������� �� ������ � �������
};
