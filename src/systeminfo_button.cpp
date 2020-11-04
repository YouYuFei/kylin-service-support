#include "systeminfo_button.h"

#include "message_page.h"
#include <QPointF>


systemInfoButton::systemInfoButton(QWidget* parent) :QPushButton(parent)
{

}

systemInfoButton::~systemInfoButton()
{

}

void systemInfoButton::enterEvent(QEvent *e)
{
    QPointF position = QCursor::pos();
    pBaseWindow->systeminfo_show(position);
}

void systemInfoButton::leaveEvent(QEvent *e)
{
    pBaseWindow->systeminfo_hide();
}

//Resource/feedback_en.qm
void systemInfoButton::setFeedBack(MessagePage *p)
{
    pBaseWindow = p;
}
