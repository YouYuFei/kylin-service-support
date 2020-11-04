#include "browse_button.h"

BrowseButton::BrowseButton(QWidget* parent) :QPushButton(parent)
{

}

BrowseButton::~BrowseButton()
{

}

void BrowseButton::enterEvent(QEvent *e)
{
    Q_UNUSED(e);

    QFont font;
    font.setUnderline(true);
    setFont(font);

}
void BrowseButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e);

    QFont font;
    font.setUnderline(false);
    setFont(font);

}
