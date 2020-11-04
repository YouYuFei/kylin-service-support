/************************************************
* 文件描述: 自建浏览按钮类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
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
