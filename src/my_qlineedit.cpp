#include "my_qlineedit.h"

MyQTextEdit::MyQTextEdit(QWidget *parent /*= NULL*/) :QTextEdit(parent)
{

}
void MyQTextEdit::focusInEvent(QFocusEvent *e)
{
    QTextEdit::focusInEvent(e);
    emit focusIn();
}

void MyQTextEdit::focusOutEvent(QFocusEvent *e)
{
    QTextEdit::focusOutEvent(e);
    emit focusOut();
}

void MyQTextEdit::showEvent(QShowEvent *event)
{
    setEnabled(true);
    setFocus();
    QTextEdit::showEvent(event);
}
