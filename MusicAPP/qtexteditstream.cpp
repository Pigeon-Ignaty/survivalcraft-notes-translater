#include "QTextEditStream.h"

QTextEditStream::QTextEditStream(QTextEdit *textEdit) : textEdit(textEdit) {}

QTextEditStream::~QTextEditStream() {
    sync();
}

std::streambuf::int_type QTextEditStream::overflow(std::streambuf::int_type v) {
    if (v == '\n') {
        textEdit->append(buffer.c_str());
        buffer.clear();
    } else {
        buffer.push_back(v);
    }
    return v;
}

int QTextEditStream::sync() {
    if (!buffer.empty()) {
        textEdit->append(buffer.c_str());
        buffer.clear();
    }
    return 0;
}

QTextEditStreamOutput::QTextEditStreamOutput(QTextEdit *textEdit) : textEditStream(textEdit) {
    rdbuf(&textEditStream);
}

QTextEditStreamOutput::~QTextEditStreamOutput() {
    // Not needed, as textEditStream will be destroyed automatically
}
