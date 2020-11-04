#ifndef SYSTEMINFOBUTTON_H
#define SYSTEMINFOBUTTON_H

#include<QPushButton>
#include<QEvent>

class MessagePage;

class systemInfoButton :public QPushButton
{
    Q_OBJECT;
public:
    systemInfoButton(QWidget *parent = 0);
    ~systemInfoButton();
public:
    void enterEvent(QEvent *e); //鼠标进入事件
    void leaveEvent(QEvent *e);//鼠标离开事件
    void setFeedBack(MessagePage *p);
    MessagePage* pBaseWindow;
};
#endif // SYSTEMINFOBUTTON_H
