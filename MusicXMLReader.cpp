#include "MusicXMLReader.h"

MusicXMLReader::MusicXMLReader(const char* name) {
    setlocale(LC_ALL, "RU");
    doc.LoadFile(name);
    if (doc.Error()) {
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
            cout << "����� ��������� ������ � ����������� ����������: " << endl;
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
                        cout << "�������� ������: " << string(part_name->GetText()) << endl;
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
void MusicXMLReader::MusicPartReader(const char* NamePart) {
    // ����������� ������ measure

    XMLElement* pRootElement = doc.RootElement(); // �������� �������
    if (NULL != pRootElement) { // ���� �� ������
    
        XMLElement* measure_tag = pRootElement->FirstChildElement("part")->FirstChildElement("measure");

        while (measure_tag) { // ���� �� ������
            XMLElement* attributes_tag = nullptr;
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


            cout << "Measure (����): " << count_meaure << endl;
            if (fifths_tag != NULL) {
                fifths = atoi(fifths_tag->GetText());
                cout << "\t�����: " << fifths << endl;
            }

            if (beats_tag != NULL) {
                beats = atoi(beats_tag->GetText());
                cout << "\t����� � ��������� ��������� �������: " << beats_tag->GetText() << endl;
            }

            if (beat_type_tag != NULL) {
                beat_type = atoi(beat_type_tag->GetText());
                cout << "\t ����� � ����������� ��������� �������: " << beat_type_tag->GetText() << endl;
            }

            if (sign_tag != NULL) {
                sign = string(sign_tag->GetText());
                cout << "\tsign (����): " << sign << endl;
            }

            if (line_tage != NULL) {
                line = atoi(line_tage->GetText());
                cout << "\tline (����� ��� �����): " << line << endl;
            }

            //////������ ����
            XMLElement* note_tag = measure_tag->FirstChildElement("note");
            while (note_tag) { // ���� ��  ����� � measure
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

                XMLElement* voice_tag = note_tag->FirstChildElement("voice"); //����������� ������
                if (voice_tag != NULL) {//�������� �����
                    voice = atoi(voice_tag->GetText());
                    cout << "\tvoice: " << voice_tag->GetText() << endl;
                }


                XMLElement* accidental_tag = note_tag->FirstChildElement("accidental"); //����������� ��������
                if (accidental_tag != NULL) {//�������� �����
                    accidental = atoi(accidental_tag->GetText());
                    v_semitone[v_semitone.size() - 1] = accidental_code(accidental_tag->GetText());
                    cout << "v_semitone " << v_semitone.size() - 1 << "\t";
                    cout << "\taccidental: " << accidental_tag->GetText() << endl;
                }
                note_tag = note_tag->NextSiblingElement("note");//���� ������� �� �����
                cout << endl;
            }
            measure_tag = measure_tag->NextSiblingElement("measure");//���� ������� �� measure
            count_meaure++;
        }



        cout << "�����, ����, ������, ������������,�������� " << endl;
        cout << v_notes.size() << endl;
        cout << v_octaves.size() << endl;
        cout << v_duration.size() << endl;
        cout << v_semitone.size() << endl;
        cout << v_league.size() << endl;
        for (int i = 0; i < v_semitone.size(); i++) {
            cout << i << " " << v_notes[i] << " " << v_octaves[i] << " " << v_duration[i] << " " << v_semitone[i] << endl;
        }
        cout << endl;
        cout << "���� � v_notes" << endl;
        for (int i = 0; i < v_notes.size(); i++) {
            cout << v_notes[i] << "";
        }
        cout << endl;
        cout << "������ � v_octaves" << endl;

        for (int i = 0; i < v_octaves.size(); i++) {
            cout << v_octaves[i] << "";
        }
        cout << endl;
        cout << "������������ � v_duration" << endl;

        for (int i = 0; i < v_duration.size(); i++) {
            cout << v_duration[i] << " ";
        }
        cout << endl;
        cout << chromatic << endl;
        }
 }