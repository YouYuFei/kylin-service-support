#ifndef MYQLINEEDIT_H
#define MYQLINEEDIT_H

#include <QTextEdit>
class MyQTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    MyQTextEdit(QWidget *parent = NULL);
protected:
    virtual void focusInEvent(QFocusEvent *e);
    virtual void focusOutEvent(QFocusEvent *e);
    virtual void showEvent(QShowEvent *event);
private:
signals :
    void focusOut();
    void focusIn();
};

#endif // MYQLINEEDIT_H
