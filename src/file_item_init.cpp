#include "file_item_init.h"
#include <QWidget>
#include "browse_button.h"

FileItemInit::FileItemInit(QWidget *parent) :
    QWidget(parent)
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("fileitem_init"));
    deletebtn0 = new BrowseButton(this);
    filename_label0 = new QLabel(this);
    filesize_label0 = new QLabel(this);

    //item_widget->setFixedHeight(17);
    deletebtn0->setFixedHeight(21);
    filename_label0->setFixedHeight(21);
    filesize_label0->setFixedHeight(21);
}

FileItemInit::~FileItemInit()
{

}
