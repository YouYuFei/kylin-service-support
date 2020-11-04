/************************************************
* 文件描述: 自制文件列表类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
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
