#include "qssfile.h"

namespace Frost {
/////////////////////////////////////////////////////////
/// Construction and Destruction
/////////////////////////////////////////////////////////

QSSFile::QSSFile(QString filename) {
    _file = new QFile(filename);
    receiveContents();
}
QSSFile::~QSSFile() {
    delete _file;
}

/////////////////////////////////////////////////////////
/// Implementation
/////////////////////////////////////////////////////////

void QSSFile::receiveContents() {
    _file->open(QFile::ReadOnly);
    _contents = QString(_file->readAll());
    _file->close();
}

QString QSSFile::toString() const{
    return _contents;
}
}

