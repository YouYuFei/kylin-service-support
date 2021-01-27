/************************************************
* 文件描述: 提交失败的处理
* 待完善:  变量未修改
* 待优化:  尚未读懂代码
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "submitFail.h"
#include "base_style.h"
#include "browse_button.h"
#include "xatom-helper.h"
#include <QPainterPath>

extern void qt_blurImage(QImage &blurImage, qreal radius, bool quality, int transposed);

submit_fail::submit_fail(QWidget *parent) :
    QDialog(parent)
{
    parentWnd = static_cast< BaseStyle * >(parent);//(BaseStyle *)parent;
    UI_init();
}

void submit_fail::UI_init()
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("submit_fail"));
    this->setAttribute(Qt::WA_ShowModal, true);
    this->setFixedSize(236,60);

    label = new QLabel(this);
    label->adjustSize();
    label->setText(tr("Submit Failed!"));//反馈信息发送失败!"));
    label->setObjectName(QString::fromUtf8("label"));
    label->setFixedSize(134,22);
    label->setStyleSheet(QString::fromUtf8("font: 16px;\n"));


    label_2 = new QLabel(this);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setFixedSize(24,24);
    label_2->setStyleSheet("border-image:url(:/data/fail.png);border:0px;");

    QHBoxLayout *hlt_menu=new QHBoxLayout;//窗体内部，水平布局
    hlt_menu->setMargin(0);
    hlt_menu->setSpacing(0);
    hlt_menu->addSpacing(35);
    hlt_menu->addWidget(label_2, 1);
    hlt_menu->addSpacing(8);
    hlt_menu->addWidget(label, 1);
    hlt_menu->addStretch(99);

    QVBoxLayout *vlt_menu=new QVBoxLayout;//窗体内部，水平布局
    vlt_menu->setMargin(0);
    vlt_menu->setSpacing(0);
    vlt_menu->addSpacing(18);
    vlt_menu->addLayout(hlt_menu, 1);
    vlt_menu->addSpacing(18);
//    vlt_menu->addStretch(99);

    body = new QWidget;//窗体
    body->setFixedSize(236,60);
    body->setObjectName("body");
    body->setLayout(vlt_menu);
    body->setStyleSheet("QWidget{background-color:rgba(61, 61, 65, 1);}");


    QHBoxLayout *hlt_fail=new QHBoxLayout;//窗体内部，水平布局
    hlt_fail->setMargin(0);
    hlt_fail->setSpacing(0);
    hlt_fail->addSpacing(0);
    hlt_fail->addWidget(body, 1);
    hlt_fail->addSpacing(0);
    QVBoxLayout *vlt_fail=new QVBoxLayout;//窗体内部，水平布局
    vlt_fail->setMargin(0);
    vlt_fail->setSpacing(0);
    vlt_fail->addSpacing(0);
    vlt_fail->addLayout(hlt_fail, 1);
    vlt_fail->addSpacing(0);

    this->setLayout(vlt_fail);

    // 添加窗管协议
    MotifWmHints hints;
    hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
    hints.functions = MWM_FUNC_ALL;
    hints.decorations = MWM_DECOR_BORDER;
    XAtomHelper::getInstance()->setWindowMotifHint(this->winId(), hints);
}


void submit_fail::pageChangeForTheme(const QString& str)
{
    qDebug() << "提交失败框的颜色设置！";
    nowTheme = str;
    if("ukui-dark" == str || "ukui-black" == str)
    {
        body->setStyleSheet("QWidget{background-color:rgba(61, 61, 65, 1);}");
        label->setStyleSheet(QString::fromUtf8("color:rgba(192, 196, 204, 1);font: 16px;\n"));
    }
    else
    {
        body->setStyleSheet("QWidget{background-color:rgba(255, 255, 255, 1);}");
        label->setStyleSheet(QString::fromUtf8("color:rgba(48, 49, 51, 1);font: 16px;\n"));
    }
}

void submit_fail::show_faillinfo(int error_code)
{
    switch (error_code) {
    case 1:
        qWarning() << (tr("远程服务器拒绝连接"));
        break;
    case 2:
        qWarning() << (tr("服务器关闭"));
        break;
    case 3:
        qWarning() << (tr("找不到远程主机名（无效主机名）"));
        break;
    case 4:
        qWarning() << (tr("与远程服务器的连接超时"));
        break;
    case 99:
        qWarning() << (tr("网络未连接"));
        break;
    case 403:
        qWarning() << (tr("服务器不可用"));
        break;
    default:
        qWarning() << (tr("未知错误"));
        break;
    }
}
submit_fail::~submit_fail()
{
}

void submit_fail::on_pushButton_2_clicked()
{
    //    this->hide();
    //    parentWnd->window_close();
    //parentWnd->pushButton_2->setEnabled(true);
    close();

}

