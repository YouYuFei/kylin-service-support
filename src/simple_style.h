#ifndef SIMPLESTYLE_H
#define SIMPLESTYLE_H

#include <QObject>
#include <QWidget>
#include <QWidget>
#include <QStackedWidget>
#include <QGraphicsDropShadowEffect>
#include <QPalette>
#include <QApplication>
#include <QScreen>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
//读取本地字体
#include <QFontDatabase>
//鼠标拖动事件
#include <QMouseEvent>
#include <QPoint>

#include <QPainter>
#include <QProxyStyle>

#include "widget_parameter_class.h"
#include "message_page.h"

class SimpleStyle : public QWidget
{
    Q_OBJECT
public:
    explicit SimpleStyle(const WidgetParameterClass& basicParameter, const QString& dialogTitleText);

signals:

private:
    WidgetParameterClass local_basicParameter;

};

#endif // SIMPLESTYLE_H
