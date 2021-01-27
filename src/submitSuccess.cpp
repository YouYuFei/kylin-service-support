/************************************************
* 文件描述: 提交成功的处理
* 待完善:  变量未修改
* 待优化:  尚未读懂代码
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "submitSuccess.h"
#include "base_style.h"
#include "browse_button.h"
#include "xatom-helper.h"
#include <QPainterPath>
extern void qt_blurImage(QImage &blurImage, qreal radius, bool quality, int transposed);
submit_success::submit_success(QWidget *parent) :
    QDialog(parent)
{
    parentWnd = static_cast<BaseStyle *>(parent);
    UI_init();
}
void submit_success::UI_init()
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("submit_success"));
    this->setAttribute(Qt::WA_ShowModal, true);
    this->setFixedSize(236,60);

    label = new QLabel(this);
    label->adjustSize();
    label->setText(tr("Submit Successed!"));//反馈信息已发送!"));
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(75, 19, 118, 22));
    label->setStyleSheet(QString::fromUtf8("font: 16px;\n"));

    label_2 = new QLabel(this);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(43, 18, 24, 24));
    label_2->setStyleSheet("border-image:url(:/data/finish.png);border:0px;");

    label_2->setFixedSize(24,24);

    QHBoxLayout *hlt_menu=new QHBoxLayout;//窗体内部，水平布局
    hlt_menu->setMargin(0);
    hlt_menu->setSpacing(0);
    hlt_menu->addSpacing(43);
    hlt_menu->addWidget(label_2, 1);
    hlt_menu->addSpacing(8);
    hlt_menu->addWidget(label, 1);
    hlt_menu->addStretch(99);

    QVBoxLayout *vlt_menu=new QVBoxLayout;//窗体内部，水平布局
    vlt_menu->setMargin(0);
    vlt_menu->setSpacing(0);
    vlt_menu->addSpacing(18);
    vlt_menu->addLayout(hlt_menu, 1);
    vlt_menu->addStretch(99);

    body = new QWidget;//窗体
    body->setFixedSize(236,60);
    body->setObjectName("body");
    body->setLayout(vlt_menu);
//    body->setStyleSheet("QWidget{background-color:rgba(61, 61, 65, 1);}");


    QHBoxLayout *hlt_suc=new QHBoxLayout;//窗体内部，水平布局
    hlt_suc->setMargin(0);
    hlt_suc->setSpacing(0);
    hlt_suc->addSpacing(0);
    hlt_suc->addWidget(body, 1);
    hlt_suc->addSpacing(0);
    QVBoxLayout *vlt_suc=new QVBoxLayout;//窗体内部，水平布局
    vlt_suc->setMargin(0);
    vlt_suc->setSpacing(0);
    vlt_suc->addSpacing(0);
    vlt_suc->addLayout(hlt_suc, 1);
    vlt_suc->addSpacing(0);

    this->setLayout(vlt_suc);

    // 添加窗管协议
    MotifWmHints hints;
    hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
    hints.functions = MWM_FUNC_ALL;
    hints.decorations = MWM_DECOR_BORDER;
    XAtomHelper::getInstance()->setWindowMotifHint(this->winId(), hints);
}
submit_success::~submit_success()
{

}

void submit_success::pageChangeForTheme(const QString& str)
{
    if("ukui-dark" == str || "ukui-black" == str)
    {
        body->setStyleSheet("QWidget{background-color:rgba(61, 61, 65, 1);}");
//        label->setStyleSheet(QString::fromUtf8("color:rgba(192, 196, 204, 1);font: 16px;\n"));
    }
    else
    {
        body->setStyleSheet("QWidget{background-color:rgba(255, 255, 255, 1);}");
//        label->setStyleSheet(QString::fromUtf8("color:rgba(48, 49, 51, 1);font: 16px;\n"));
    }
}

void submit_success::on_pushButton_2_clicked()
{
    this->close();
    //parentWnd->window_close();
}
