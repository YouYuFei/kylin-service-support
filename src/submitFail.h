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

private slots:
    void on_pushButton_2_clicked();
    void close_fail_window();
    void resend_feedbackinfo();

protected:
    void paintEvent(QPaintEvent*);

private:

    void UI_init();
    BaseStyle *parentWnd;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton * fail_closeBtn;
    QPushButton * resendBtn;
    QLabel *label_2;
    QLabel *label_3;
};

#endif // SUBMIT_FAIL_H
