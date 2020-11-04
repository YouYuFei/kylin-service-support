#ifndef BROWSEBUTTON_H
#define BROWSEBUTTON_H
#include<QPushButton>
#include<QEvent>

class BrowseButton : public QPushButton
{
    Q_OBJECT;
public:
    BrowseButton(QWidget *parent = 0);
    ~BrowseButton();
public:
    void enterEvent(QEvent *e); //鼠标进入事件
    void leaveEvent(QEvent *e);//鼠标离开事件
};

#endif // BROWSEBUTTON_H
