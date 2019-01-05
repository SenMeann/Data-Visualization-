#ifndef READFILE_H
#define READFILE_H
#include<QString>
#include<QtXml>

class ReadFile
{
public:
    ReadFile();
    void setFileName(const QString &filename);
private:
    void setRow(QDomNode node, int row);
    void setCell(QDomNodeList list, int row);
    void setData(int row, int column);
    void setDataToTable(int row,int column,QString data);
};

#endif // READFILE_H
