#ifndef FILEITEMINIT_H
#define FILEITEMINIT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class FileItemInit : public QWidget
{
    Q_OBJECT

public:

    QWidget* item_widget;
    QPushButton * deletebtn0;
    QLabel *  filename_label0;
    QLabel *  filesize_label0;


    explicit FileItemInit(QWidget *parent = nullptr);
    ~FileItemInit();

private:

};

#endif // FILEITEMINIT_H
