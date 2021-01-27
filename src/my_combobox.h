#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#define LISTWIDGETWIDTH (206)
#define DARKTHEME ("dark")
#define LIGHTTHEME ("light")
#define ITEMHIGHT (30)
#define SHADOW (4)

#include <QtMath>
#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QListWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

class MyComboBox : public QWidget
{
    Q_OBJECT
public:
    explicit MyComboBox();
    QListWidget *listWidget = nullptr;//combobox列表列表部分

    void addItem(QString lable);//添加到列表
    void closeListWidget();
    void setThemeDark(); //深色模式
    void setThemeLight(); //浅色模式

    QString getCurrentText();
    void setCurrentText(QString str);

public slots:
    void clickComboboxList(QListWidgetItem *item); //将值传递到按键

signals:
    void buttonTextChanged();//点击下拉列表，内容发生变化

private:
    QPushButton *pushButton = nullptr;//点击按钮
    void on_comboboxButton_click();   //下拉栏点击事件

    bool isListOpen = false;

    QLabel *text=nullptr;   // 下拉框按钮中的文字
    QLabel *icon=nullptr;   // 下拉框按钮中的图标
    QString themeStatus = LIGHTTHEME; //主题状态标识
};

#endif // MYCOMBOBOX_H
