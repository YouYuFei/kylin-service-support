#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H
#include <QTabWidget>
#include <QTabBar>
#include <QLabel>

class MyTabWidget : public QTabWidget
{
public:
    explicit MyTabWidget(QWidget *parent = nullptr);

    void updateselect();                          //用来设置一开始选中的状态
    //int addTab(QWidget *widget, const QString &);
    //int addTab(QWidget *widget, const QIcon& icon, const QString &label);
    int addTab(QWidget *widget, const QString &); //重载(不是虚函数)

signals:

public slots:
    void slotSetLabelColor(int color);            //自定义槽(响应tabBar点击事件)
};

#endif // MYTABWIDGET_H
