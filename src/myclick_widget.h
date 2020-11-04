#ifndef MYCLICKWIDGET_H
#define MYCLICKWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>

class MyClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyClickWidget(QWidget *parent = nullptr);

protected:
    virtual void mouseReleaseEvent(QMouseEvent * ev);  // 声明鼠标左键点击事件
    void paintEvent(QPaintEvent *);
signals:
    void clicked(void); // 声明鼠标左击中信号

};

#endif // MYCLICKWIDGET_H
