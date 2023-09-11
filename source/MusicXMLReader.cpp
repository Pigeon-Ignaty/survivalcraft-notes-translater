#include "MusicXMLReader.h"

MusicXMLReader::MusicXMLReader(const char* name) {
    std::locale utf8_locale("en_US.UTF-8");
    std::locale::global(utf8_locale);

    doc.LoadFile(name);
    if (doc.Error()) {
        cout << doc.ErrorLineNum();       
        throw runtime_error("��������� ������, ���� �������� ������"); // ���� ���� �������� ������
    }
        XMLElement* pRootElement = doc.RootElement(); // �������� �������
        if (NULL != pRootElement) { // ���� �� ������
            XMLElement* credit = pRootElement->FirstChildElement("credit"); // ���������� � credit
            while (credit) {
                XMLElement* credit_type_tag = credit->FirstChildElement("credit-type"); // � ����� ����������� ���
                XMLElement* credit_words_tag = credit->FirstChildElement("credit-words"); // � ����� ����������� ��� ����

                if (NULL != credit_type_tag && credit_words_tag != NULL) { // ���� �� ������
                    cout << credit_type_tag->GetText() << ": " << credit_words_tag->GetText() << "\t"; // ����� ������ � ��������
                }
                cout << endl;
                credit = credit->NextSiblingElement("credit"); //���� �������
            }
            cout << u8"����� ��������� ������ � ����������� ����������: " << endl;
            int scorePartCount = 0;
            XMLElement* part_list = pRootElement->FirstChildElement("part-list");
            if (part_list != NULL) {
                for (XMLElement* score_part = part_list->FirstChildElement("score-part");
                    score_part != NULL; score_part = score_part->NextSiblingElement("score-part"))
                {
                    
                    cout << "ID: " << score_part->Attribute("id") << "\t";
                    musical_parts.push_back(score_part->Attribute("id"));
                    XMLElement* part_name = score_part->FirstChildElement("part-name");
                    if (part_name != NULL) {
                        cout << u8"�������� ������: " << string(part_name->GetText()) << endl;
                    }
                    scorePartCount++;
                }
            }
            cout << "scorePartCount: " << scorePartCount << endl;
        }



        
}

int MusicXMLReader::accidental_code(string s) {
    if (s == "sharp") return 1;
    if (s == "natural") return 0;
    if (s == "natural") return -1;
    return 0;
}
void MusicXMLReader::MusicPartWriter(const char* NamePart, const char* voice) {
    // ����������� ������ measure

    XMLElement* pRootElement = doc.RootElement(); // �������� �������
    if (NULL != pRootElement) { // ���� �� ������
        //----------------------
        XMLElement* part_id_tag = pRootElement->FirstChildElement("part");
        XMLElement* measure_tag = nullptr;
        while (part_id_tag) {
            const char* partId = part_id_tag->Attribute("id");
            if (partId && std::string(partId) == NamePart) {
                measure_tag = part_id_tag->FirstChildElement("measure");

                while (measure_tag) { // ���� �� ������
                    XMLElement* attributes_tag = nullptr;
                    XMLElement* divisions_tag = nullptr;
                    XMLElement* key_tag = nullptr;
                    XMLElement* fifths_tag = nullptr;
                    XMLElement* time_tag = nullptr;
                    XMLElement* beats_tag = nullptr;
                    XMLElement* beat_type_tag = nullptr;
                    XMLElement* clef_tag = nullptr;
                    XMLElement* sign_tag = nullptr;
                    XMLElement* line_tage = nullptr;
                    XMLElement* transpose_tag = nullptr;
                    XMLElement* chromatic_tag = nullptr;
                    XMLElement* direction_tag = nullptr;
                    XMLElement* direction_type_tag = nullptr;
                    XMLElement* metronome_tag = nullptr;
                    XMLElement* beat_unit_tag = nullptr;
                    XMLElement* per_minute_tag = nullptr;

                    if (measure_tag->FirstChildElement("attributes") != NULL) {
                        attributes_tag = measure_tag->FirstChildElement("attributes");
                        if (attributes_tag->FirstChildElement("divisions") != NULL) {
                            divisions_tag = attributes_tag->FirstChildElement("divisions");
                            divisions = atoi(divisions_tag->GetText());
                        }
                        if (attributes_tag->FirstChildElement("key") != NULL) {
                            key_tag = attributes_tag->FirstChildElement("key");
                            if (key_tag->FirstChildElement("fifths") != NULL) {
                                fifths_tag = key_tag->FirstChildElement("fifths");
                            }
                        }
                        if (attributes_tag->FirstChildElement("time") != NULL) {
                            time_tag = attributes_tag->FirstChildElement("time");
                            if (time_tag->FirstChildElement("beats") != NULL) {
                                beats_tag = time_tag->FirstChildElement("beats");
                            }
                            if (time_tag->FirstChildElement("beat-type") != NULL) {
                                beat_type_tag = time_tag->FirstChildElement("beat-type");
                            }
                        }
                        if (attributes_tag->FirstChildElement("clef") != NULL) {
                            clef_tag = attributes_tag->FirstChildElement("clef");
                            if (clef_tag->FirstChildElement("sign") != NULL) {
                                sign_tag = clef_tag->FirstChildElement("sign");
                            }
                            if (clef_tag->FirstChildElement("line") != NULL) {
                                line_tage = clef_tag->FirstChildElement("line");
                            }
                        }
                        if (attributes_tag->FirstChildElement("transpose") != NULL) {
                            transpose_tag = attributes_tag->FirstChildElement("transpose");
                            if (transpose_tag->FirstChildElement("chromatic") != NULL) {
                                chromatic = atoi(transpose_tag->FirstChildElement("chromatic")->GetText());
                            }
                        }
                    }
                    if (measure_tag->FirstChildElement("direction") != NULL) {
                        direction_tag = measure_tag->FirstChildElement("direction");
                        if (direction_tag->FirstChildElement("direction-type") != NULL) {
                            direction_type_tag = direction_tag->FirstChildElement("direction-type");
                            if (direction_type_tag->FirstChildElement("metronome") != NULL) {
                                metronome_tag = direction_type_tag->FirstChildElement("metronome");
                                if (metronome_tag->FirstChildElement("beat-unit") != NULL) {
                                    beat_unit_tag = metronome_tag->FirstChildElement("beat-unit");
                                }
                                if (metronome_tag->FirstChildElement("per-minute") != NULL) {
                                    per_minute_tag = metronome_tag->FirstChildElement("per-minute");
                                    bpm = atoi(per_minute_tag->GetText());
                                }
                            }
                        }
                    }


                    cout << u8"Measure (����): " << count_measure << endl;
                    if (fifths_tag != NULL) {
                        fifths = atoi(fifths_tag->GetText());
                        cout << u8"\t�����: " << fifths << endl;
                    }

                    if (beats_tag != NULL) {
                        beats = atoi(beats_tag->GetText());
                        cout << u8"\t����� � ��������� ��������� �������: " << beats_tag->GetText() << endl;
                    }

                    if (beat_type_tag != NULL) {
                        beat_type = atoi(beat_type_tag->GetText());
                        cout << u8"\t ����� � ����������� ��������� �������: " << beat_type_tag->GetText() << endl;
                    }

                    if (sign_tag != NULL) {
                        sign = string(sign_tag->GetText());
                        cout << u8"\tsign (����): " << sign << endl;
                    }

                    if (line_tage != NULL) {
                        line = atoi(line_tage->GetText());
                        cout << u8"\tline (����� ��� �����): " << line << endl;
                    }

                    //////������ ����
                    XMLElement* note_tag = measure_tag->FirstChildElement("note");
                    XMLElement* voice_tag = note_tag->FirstChildElement("voice");
                    string current_voice = voice_tag->GetText();
                    while (note_tag) { // ���� ��  ����� � measure
                        if(current_voice == voice){
                            if (note_tag->FirstChildElement("pitch") != NULL) { //���� ����, �� ������� ���� � ������
                                XMLElement* step_tag = note_tag->FirstChildElement("pitch")->FirstChildElement("step"); //����
                                XMLElement* alter_tag = note_tag->FirstChildElement("pitch")->FirstChildElement("alter"); //���������� �� �������
                                XMLElement* octave_tag = note_tag->FirstChildElement("pitch")->FirstChildElement("octave"); //������
                                XMLElement* notations = nullptr;

                                if (step_tag != NULL) {
                                    cout << "v_notes " << v_notes.size() - 1 << "\t"; // ��� �������
                                    cout << "\tstep: " << step_tag->GetText() << endl; // ����
                                    v_notes.push_back(step_tag->GetText()[0]);
                                    v_league.push_back(0);
                                }
                                if (alter_tag != NULL) {
                                    alter = atoi(alter_tag->GetText());
                                    cout << "v_semitone " << v_semitone.size() - 1 << "\t";

                                    cout << "\talter: " << alter_tag->GetText() << endl;
                                    v_semitone.push_back(atoi(alter_tag->GetText()));

                                }
                                else { //���� ��� alter
                                    cout << "v_semitone " << v_semitone.size() - 1 << "\t";

                                    v_semitone.push_back(0);

                                }
                                if (octave_tag != NULL) {
                                    octave = atoi(octave_tag->GetText());
                                    cout << "\toctave: " << octave_tag->GetText() << endl;
                                    v_octaves.push_back(octave_tag->GetText());

                                }
                            }
                            XMLElement* rest_tag = note_tag->FirstChildElement("rest"); //����������� �����
                            if (rest_tag != NULL) {
                                rest = rest_tag->Name();
                                cout << "\t" << rest_tag->Name() << endl;
                                v_notes.push_back('r');
                                v_octaves.push_back("n");
                                v_semitone.push_back(0);
                                v_league.push_back(0);

                                cout << "v_semitone " << v_semitone.size() - 1 << "\t";
                                cout << "v_notes " << v_notes.size() - 1 << "\t";

                            }
                            XMLElement* duration_tag = note_tag->FirstChildElement("duration"); //����������� ������������
                            if (duration_tag != NULL) {//������������
                                duration = atoi(duration_tag->GetText());
                                cout << "\tduration: " << duration_tag->GetText() << endl;
                                v_duration.push_back(duration);
                            }

                            if (note_tag->FirstChildElement("notations") != NULL) {
                                if (note_tag->FirstChildElement("notations")->FirstChildElement("tied") != NULL) {
                                    if (note_tag->FirstChildElement("notations")->FirstChildElement("tied")->Attribute("type") != NULL) {
                                        XMLElement* tied_tag = note_tag->FirstChildElement("notations")->FirstChildElement("tied");
                                        //tied = tied_tag->Attribute("type");
                                        int count_tied = 0;
                                        while (tied_tag) {
                                            if (string(tied_tag->Attribute("type")) == "stop") count_tied++;
                                            //cout << "Attribute " << tied_tag->Attribute("type") << endl;
                                            if (string(tied_tag->Attribute("type")) == "start") count_tied += 2;
                                            //cout << "\ttied: " << count_tied << endl;

                                            tied_tag = tied_tag->NextSiblingElement("tied");//���� ������� �� tied

                                        }
                                        v_league[v_league.size() - 1] = count_tied;

                                        count_tied = 0;

                                    }


                                }
                            }
                            cout << "v_league " << v_league.size() - 1 << "\t";

                                //XMLElement* voice_tag = note_tag->FirstChildElement("voice"); //����������� ������
                                //if (voice_tag != NULL) {//�������� �����
                                //    voice = atoi(voice_tag->GetText());
                                //    cout << "\tvoice: " << voice_tag->GetText() << endl;
                                //}


                            //XMLElement* accidental_tag = note_tag->FirstChildElement("accidental"); //����������� ��������
                            //if (accidental_tag != NULL) {//�������� �����
                            //    accidental = atoi(accidental_tag->GetText());
                            //    v_semitone[v_semitone.size() - 1] = accidental_code(accidental_tag->GetText());
                            //    cout << "v_semitone " << v_semitone.size() - 1 << "\t";
                            //    cout << "\taccidental: " << accidental_tag->GetText() << endl;
                            //}
                            
                            
                            cout << endl;
                            }
                        note_tag = note_tag->NextSiblingElement("note");//���� ������� �� �����
                        if (note_tag != NULL) {
                            voice_tag = note_tag->FirstChildElement("voice"); //������ ������ ������ � ���� ����
                            current_voice = voice_tag->GetText();
                        }
                    }
                    measure_tag = measure_tag->NextSiblingElement("measure");//���� ������� �� measure
                    count_measure++;
                }

                // ������� � ���������� �������� <part>

                XMLElement* measure_tag = pRootElement->FirstChildElement("part")->FirstChildElement("measure");
                break;
            }
            part_id_tag = part_id_tag->NextSiblingElement("part");
       
        //----------------

        
        }

        }
 }

void MusicXMLReader::ReadVoice(const char* NamePart) {
    set <string> voices; //��� ������ � ������

    XMLElement* measure_tag = nullptr;

    XMLElement* pRootElement = doc.RootElement(); // �������� �������
    if (NULL != pRootElement) { // ���� �� ������
        //----------------------
        XMLElement* part_id_tag = pRootElement->FirstChildElement("part");
        if (part_id_tag) {
            const char* partId = part_id_tag->Attribute("id");
            measure_tag = part_id_tag->FirstChildElement("measure");
            if (measure_tag != NULL) {
                if (partId && std::string(partId) == NamePart) {
                    while (measure_tag) {
                        XMLElement* note_tag = measure_tag->FirstChildElement("note");
                        if (note_tag != NULL) {
                            
                            while (note_tag) {
                                XMLElement* voice_tag = note_tag->FirstChildElement("voice");
                                if (voice_tag != NULL)
                                    voices.insert(voice_tag->GetText());

                                note_tag = note_tag->NextSiblingElement("note");

                            }


                            
                        }
                        measure_tag = measure_tag->NextSiblingElement("measure");

                    }
                }
            }

        }

    }
    cout << u8"������, ������������ � ������" << std::endl;
    for (const string& v : voices) {
        cout << v << endl;
    }
}

 void MusicXMLReader::OutputToConsole() {

     cout << u8"�����, ����, ������, ������������,�������� " << endl;
     cout << v_notes.size() << endl;
     cout << v_octaves.size() << endl;
     cout << v_duration.size() << endl;
     cout << v_semitone.size() << endl;
     cout << v_league.size() << endl;
     for (int i = 0; i < v_semitone.size(); i++) {
         cout << i << " " << v_notes[i] << " " << v_octaves[i] << " " << v_duration[i] << " " << v_semitone[i] << endl;
     }
     cout << endl;
     cout << u8"���� � v_notes" << endl;
     for (int i = 0; i < v_notes.size(); i++) {
         cout << v_notes[i] << "";
     }
     cout << endl;
     cout << u8"������ � v_octaves" << endl;

     for (int i = 0; i < v_octaves.size(); i++) {
         cout << v_octaves[i] << "";
     }
     cout << endl;
     cout << u8"������������ � v_duration" << endl;

     for (int i = 0; i < v_duration.size(); i++) {
         cout << v_duration[i] << " ";
     }
     cout << endl;
     cout << "chromatic: " << chromatic << endl;
 }

 int MusicXMLReader::Translation(int instrument) {

     //type_instrument = 2; // ��� �����������
     notes_f(v_notes, v_semitone, chromatic);//������� �� ��� CDEFGAB � hex ������������� � survivalcraft
     octaves_f(converted_notes, v_octaves, instrument); //������� ������ � ������ survivalcraft, � ��� ����� ������� �� �������
     calculation_duration();//��������� ���������� ������������ ���
     convert_to_sequence(converted_notes, v_duration, v_league, 0);// ������� � ������������������ ��� � ����������� �� ������������
     convert_to_sequence(converted_octaves, v_duration, v_league, 1);//������� � ������������������ ����� � ����������� �� ������������
     show_information_about_composition(v_duration, beats, beat_type, bpm);//������������� ������� ����������, �� �������� ���������
     show_notes(converted_notes_sequence); //����� ��� � �������� �� ������ ������ 256 ��������
     show_octaves(converted_octaves_sequence);//����� ����� � �������� �� ������ ������ 256 ��������
     return 0;

 }

 void MusicXMLReader::notes_f(vector<char>& notes, vector<int>& semitone, int chromatic) {
     if (notes.size() != semitone.size()) {
         cout << "Error: vectors have different sizes" << endl;
     }
     cout << u8"���� � notes_f:" << endl;
     for (int i = 0; i < semitone.size(); i++) {
         semitone[i] = semitone[i] + chromatic;
         int hex_notes = switch_hex_notes(notes[i], semitone[i]);
         if (hex_notes < 0) { //??
             converted_notes.push_back(12 + hex_notes);
         }
         else {
             converted_notes.push_back(hex_notes);

         }
         cout << hex << uppercase << hex_notes;
     }
     cout << endl;
 }

 int MusicXMLReader::switch_hex_notes(char ch, int semitone) {
     switch (ch) {
     case 'C': return 0 + semitone; //��
     case 'D': return 2 + semitone; //��
     case 'E': return 4 + semitone; //��
     case 'F': return 5 + semitone; //��
     case 'G': return 7 + semitone; //����
     case 'A': return 9 + semitone; //��
     case 'B': return 11 + semitone;//��
     default: return 15; //�����
     }
 }

 void MusicXMLReader::octaves_f(vector<int>& converted_notes, vector<string>& octaves, int instrument) {
     type_instrument(instrument);

     for (int i = 0; i < octaves.size(); i++) {
         int number = 0;
         if (octaves[i] == "n") {
             converted_octaves.push_back(15);
             //cout << hex << uppercase << 15;
         }
         else {
             try {
                 number = stoi(octaves[i]);
                 if (number == 3) {
                     int l = 0;
                 }
                 if (number > high_octave && converted_notes[i] == 0) {
                     number = high_octave + 1;//high_octave + 1;
                 }
                 else {
                     if (number < low_octave) {
                         number = low_octave;
                     }
                     else if (number > high_octave) {
                         number = high_octave;
                     }
                 }
                 if (instrument == 1) {//���� �����������, �� ������� �� ������ �����, ����� �������� ������� ������
                     converted_octaves.push_back(number - low_octave + 1);

                 }
                 else {
                     converted_octaves.push_back(number - low_octave);

                 }

                 //cout << hex << uppercase << number;
             }
             catch (const exception& ex) {
                 cout << ex.what() << endl;
             }
         }


     }
 }

 void MusicXMLReader::type_instrument(int instrument) {
     if (instrument == 1) { // ����������� - ������� 2 ������  
         high_octave = 4;
         low_octave = 3;
     }
     if (instrument == 2|| instrument == 3 || instrument == 6) { // �����, 8 ���, ��������� ��  
         high_octave = 5;
         low_octave = 3;
     }
     else if (instrument == 4 || instrument == 5) {//�������� ����������, �����
         high_octave = 4;
         low_octave = 2;
     }

     else if (instrument == 7 || instrument == 8) {//��� �������
         high_octave = 5;
         low_octave = 2;
     }
 }
 void MusicXMLReader::convert_to_sequence(vector<int>& converted, vector<float>& duration, vector<int>& league, int t) {

     if (converted.size() != duration.size()) {
         cout << "Error: vectors have different sizes" << endl;
     }
     

     try {
         if (!t) {//���� ����
             for (int i = 0; i < duration.size(); i++) {
                 (print_amount(converted[i], duration[i], league[i], converted_notes_sequence));
             }
         }
         else { // ���� ������
             for (int i = 0; i < duration.size(); i++) {
                 (print_amount(converted[i], duration[i], league[i], converted_octaves_sequence));
             }
         }

     }
     catch (const exception& ex) {
         cout << ex.what() << endl;
     }
 }


 void MusicXMLReader::print_amount(int object, int duration, int league, vector <int>& converted_notes_sequence) {
     for (int i = 0; i < duration; i++) {
         if (league) {
             if (league == 2) converted_notes_sequence.push_back(object);//cout <<hex<< object;
             else if (league == 1 || league == 3)  converted_notes_sequence.push_back(15);//cout << hex << "F";
             league = 0;
         }
         else {
             if (i == 0) converted_notes_sequence.push_back(object);//cout << hex << object;
             else converted_notes_sequence.push_back(15);//cout << hex << "F";
         }

     }


 }

 void MusicXMLReader::show_information_about_composition(vector<float>& duration, int fraction_numerator, int denominator_fraction, int bpm) {
     float min_duration = *min_element(duration.begin(), duration.end());
     float max_duration = *max_element(duration.begin(), duration.end());
     float relationship_bpm;
     float quarter_time;
     float time_min_duration;
     try {
         relationship_bpm = float(60) / float(bpm); //���������
         quarter_time = relationship_bpm * float(fraction_numerator); //������������ �����
         time_min_duration = quarter_time / max_duration;
     }
     catch (const exception& ex) {
         cout << ex.what() << endl;
     }
     cout << u8"����� ����������� ������������/����� ��� ���������� " << round(time_min_duration * 100) / 100 << endl;
     cout << u8"����������� ������������ " << max_duration << endl;

 }

 void MusicXMLReader::show_notes(vector <int>& converted_notes_sequence) {
     cout << u8"����" << endl;
     int count = 0;
     for (int& i : converted_notes_sequence) {
         if (count == 256) {
             cout << endl;
             count = 0;
         }
         cout << hex << uppercase << i;
         count++;
     }
     while (count != 256) {
         cout << "F";
         count++;
     }
     cout << endl;
 }

 void MusicXMLReader::show_octaves(vector <int>& converted_octaves_sequence) {
     cout << u8"������" << endl;
     int count = 0;
     for (int& i : converted_octaves_sequence) {
         if (count == 256) {
             cout << endl;
             count = 0;
         }
         cout << hex << uppercase << i;
         count++;
     }
     while (count != 256) {
         cout << "F";
         count++;
     }
     cout << endl;
 }

 void MusicXMLReader::calculation_duration() {
     int s = 0;
     for (int i = 0; i < v_duration.size(); i++) {
         if (static_cast<int>(v_duration[i]) % 2) {
             s = 1;
         }
     }

         if (divisions != 1 && s != 1) { //���� �� 1, ����� ��� ������
         for (int i = 0; i < v_duration.size(); i++) { //����� ������ ������� �� divisions
             
             v_duration[i] = v_duration[i] / divisions;
             //cout << v_duration[i] << " ";
         }
         cout << endl;
         auto minElement = min_element(v_duration.begin(), v_duration.end()); //������� ����������� �������
         float min = *minElement;
         float reverse = 1/ min; //���� �������� �����

         for (int i = 0; i < v_duration.size(); i++) { // �������� ������ ������� �� ��������, ����� ����������� �������� ���� 1

             v_duration[i] = v_duration[i] * reverse;
             //cout << v_duration[i] << " ";
         }
         cout << endl;
        
     }
     
 }

