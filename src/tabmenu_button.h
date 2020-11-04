/************************************************
* 文件描述: 主界面按钮特殊类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef TABMENUBUTTON_H
#define TABMENUBUTTON_H
#include <QPushButton>
#include <QStyleOptionButton>
#include <QStylePainter>
#include <QProxyStyle>

class TabMenuButton : public QPushButton
{
    Q_OBJECT
public:
    explicit TabMenuButton(QWidget *parent = nullptr);
    ~TabMenuButton();
    void SendSingal();
protected:
    void enterEvent(QEvent *e); //鼠标进入事件
    void leaveEvent(QEvent *e);//鼠标离开事件
signals:
    void enterButtonSignal();
};

#endif // TABMENUBUTTON_H
