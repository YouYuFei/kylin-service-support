/************************************************
* 文件描述: 提交成功的处理
* 待完善:  变量未修改
* 待优化:  尚未读懂代码
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef SUBMIT_SUCCESS_H
#define SUBMIT_SUCCESS_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include "stylewidgetattribute.h"
#include "stylewidgetshadow.h"

class BaseStyle;


class submit_success : public QDialog
{
    Q_OBJECT

public:
    explicit submit_success(QWidget *parent = nullptr);
    ~submit_success();
    void pageChangeForTheme(const QString& str);
    StyleWidgetShadow *swshadow;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void succ_close_window();


protected:
//    void paintEvent(QPaintEvent*);


private:
    BaseStyle *parentWnd;

    void UI_init();

    QLabel *label;
    QPushButton * succ_closeBtn;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QWidget *body  = nullptr;//窗体
};

#endif // SUBMIT_SUCCESS_H
