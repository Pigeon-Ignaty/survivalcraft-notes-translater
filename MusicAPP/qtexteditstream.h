#ifndef QTextEditStream_H
#define QTextEditStream_H

#include <streambuf>
#include <QTextEdit>
#include <ostream>

class QTextEditStream : public std::basic_streambuf<char> {
public:
    QTextEditStream(QTextEdit *textEdit);
    ~QTextEditStream();

protected:
    virtual int_type overflow(int_type v);
    virtual int sync();

private:
    std::string buffer;
    QTextEdit *textEdit;
};

class QTextEditStreamOutput : public std::ostream {
public:
    QTextEditStreamOutput(QTextEdit *textEdit);
    ~QTextEditStreamOutput();

private:
    QTextEditStream textEditStream;
};

#endif // QTextEditStream_H
