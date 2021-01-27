/************************************************
* 文件描述: 提交失败的处理
* 待完善:  变量未修改
* 待优化:  尚未读懂代码
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef SUBMIT_FAIL_H
#define SUBMIT_FAIL_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

class BaseStyle;

class submit_fail : public QDialog
{
    Q_OBJECT

public:
    explicit submit_fail(QWidget *parent = nullptr);
    ~submit_fail();

    void show_faillinfo(int errorcode);
    void pageChangeForTheme(const QString& str);

private slots:
    void on_pushButton_2_clicked();

protected:

private:

    void UI_init();
    BaseStyle *parentWnd;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton * fail_closeBtn;
    QPushButton * resendBtn;
    QLabel *label_2;
    QLabel *label_3;
    QString nowTheme;
    QWidget *body  = nullptr;//窗体
};

#endif // SUBMIT_FAIL_H
