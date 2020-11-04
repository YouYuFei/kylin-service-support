#ifndef SUBMIT_SUCCESS_H
#define SUBMIT_SUCCESS_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>


class BaseStyle;


class submit_success : public QDialog
{
    Q_OBJECT

public:
    explicit submit_success(QWidget *parent = nullptr);
    ~submit_success();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void succ_close_window();


protected:
    void paintEvent(QPaintEvent*);


private:
    BaseStyle *parentWnd;

    void UI_init();

    QLabel *label;
    QPushButton * succ_closeBtn;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;

};

#endif // SUBMIT_SUCCESS_H
