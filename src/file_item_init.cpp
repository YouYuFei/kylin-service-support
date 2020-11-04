/************************************************
* 文件描述: 自制文件列表类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "file_item_init.h"
#include <QWidget>
#include "browse_button.h"
/************************************************
* 函数名称：FileItemInit
* 功能描述：构造函数，创建样式，文件名、大小label，删除按钮
* 输入参数：父类指针
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
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
/************************************************
* 函数名称：~FileItemInit
* 功能描述：析构函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
FileItemInit::~FileItemInit()
{

}
