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
