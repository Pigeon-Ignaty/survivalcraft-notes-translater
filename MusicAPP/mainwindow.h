#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tiny/tinyxml2.h"
#include <QString>
#include <QFile>
#include "QFileDialog"
#include <QMessageBox>
#include "debug.h"
#include "iostream"
#include <QVariant>
#include <sstream>
#include "qtexteditstream.h"
#include <QObject>

using namespace std;
using namespace tinyxml2;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_OpenXmlFile_clicked();
    void on_MenuConsole_triggered(bool checked);

    void on_about_QT_triggered();

    void on_Exit_triggered();

    void on_OpenFile_triggered();

    void on_CloseFile_triggered();

public slots:
    void SlotConsoleClose();
protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void SignalMainWindowClose();
private:
    QTextEditStreamOutput *sout; // Объявление объекта outputStream
    Debug *console;//окно консоли
    Ui::MainWindow *ui;

    //данные из класса  MusicXMLReader
    XMLDocument doc; // файл musicxml
    bool successOpenFile = false; //флаг успешного открытия файла
};
#endif // MAINWINDOW_H
