/************************************************
* 文件描述: 显示系统信息的定制按钮类
* 待完善:  变量未修改
* 待优化:  尚未读懂代码
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
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
