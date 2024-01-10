#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    console = new Debug;
    connect(console,&Debug::signalConsoleClose,this,&MainWindow::SlotConsoleClose);//закрытие консоли и снятие галочки
    connect(this,&MainWindow::SignalMainWindowClose,console,&Debug::SlotMainWindowClose);//закрытие консоли если закрыли главное окно
    ui->MenuConsole->setCheckable(true);//по умолчанию кнопка bool в menu bar
    ui->MenuConsole->setChecked(true);//по умолчанию она выключена
    ui->CloseFile->setEnabled(false); //кнопка закрытия неактивна после запуска программы
    console->show();
    //для передачи sout в консоль
    QTextEdit* textEdit = console->getTextEdit();
    sout = new QTextEditStreamOutput(textEdit); // Инициализация sout
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenXmlFile_clicked()
{
    on_CloseFile_triggered();
    QFile file;
    QString path_to_file = QFileDialog::getOpenFileName(this,"Выбор .musicxml файла","Z:\\VS\\Survivalcraft-notes-translator gui\\survivalcraft-notes-translator\\MusicAPP\\xml","*.musicxml");
    QByteArray ba = path_to_file.toLocal8Bit(); //преобразование в const char
    const char *path = ba.data();
    doc.LoadFile(path);
    if(doc.Error() && path_to_file.isNull()){//если не выбран файл
        *sout <<"Файл не выбран" << endl;
        return;
    }
    else if (doc.Error()) {//ошибка открытия
        QMessageBox errorMessage;
        errorMessage.setIcon(QMessageBox::Critical); // Установка иконки ошибки
        errorMessage.setText("Пук-среньк!");
        errorMessage.setInformativeText(u8"Произошла ошибка. Файл не найден, либо имеет неправильное расширение, либо содержит ошибку.");
        errorMessage.setWindowTitle("Ошибка");
        errorMessage.exec();
        *sout <<"Ошибка открытия " << doc.Error()<< endl;
        *sout <<path<< endl;
        return;
        }

    else{//если успех
        XMLElement* pRootElement = doc.RootElement(); // корневой каталог
        if (nullptr != pRootElement) { // если не пустой
            XMLElement* credit = pRootElement->FirstChildElement("credit"); // спускаемся в credit
                while (credit) {
                    XMLElement* credit_type_tag = credit->FirstChildElement("credit-type"); // в цикле вытаскиваем тип
                    XMLElement* credit_words_tag = credit->FirstChildElement("credit-words"); // в цикле вытаскиваем имя типа
                    if (nullptr != credit_type_tag && credit_words_tag != nullptr) { // если не пустой
                        //this->setWindowTitle(credit_type_tag->GetText()+ ": " + credit_words_tag->GetText());
                        *sout << credit_type_tag->GetText() << ": " << credit_words_tag->GetText() << "\t"; // вывод автора и названия
                    }
                    credit = credit->NextSiblingElement("credit"); //след элемент
                }
                *sout << u8"Вывод следующих партий в музыкальной композиции: " << endl;
                int scorePartCount = 0;
                XMLElement* part_list = pRootElement->FirstChildElement("part-list");
                if (part_list != nullptr) {
                    for (XMLElement* score_part = part_list->FirstChildElement("score-part");
                        score_part != nullptr; score_part = score_part->NextSiblingElement("score-part"))
                    {
                        *sout << "ID: " << score_part->Attribute("id") << "\t";
                        XMLElement* part_name = score_part->FirstChildElement("part-name");
                        if (part_name != nullptr) {
                            *sout << u8"Название партии: " << string(part_name->GetText()) << endl;
                        }
                        scorePartCount++;
                    }
                }
                *sout << "scorePartCount: " << scorePartCount << endl;
                ui->CloseFile->setEnabled(true);
                successOpenFile = true;
            }
            //FindMinimalDuration(name);//вызов функции, которая будет duration самой быстрой длительности во всём произведении
    }
    delete path;
}

void MainWindow::on_MenuConsole_triggered(bool checked)
{
    if(checked){
        console->show();
    }
    else{
        console->hide();
    }
}

void MainWindow::SlotConsoleClose()
{
    *sout << "console close" << endl;
    ui->MenuConsole->setChecked(false);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit SignalMainWindowClose();
    event->accept();
}


void MainWindow::on_about_QT_triggered()//о версии qt
{
    QMessageBox::aboutQt(nullptr,"О версии QT");
}

void MainWindow::on_Exit_triggered()
{
    this->close();
    emit SignalMainWindowClose();
}

void MainWindow::on_OpenFile_triggered()//открытие через menu bar
{
    on_OpenXmlFile_clicked();
}

void MainWindow::on_CloseFile_triggered()//закрытие через menu bar
{
    ui->OpenFile->setEnabled(true);
    ui->CloseFile->setEnabled(false);
    successOpenFile = false;
}
