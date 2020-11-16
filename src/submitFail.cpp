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
#include <QPainterPath>

extern void qt_blurImage(QImage &blurImage, qreal radius, bool quality, int transposed);

submit_fail::submit_fail(QWidget *parent) :
    QDialog(parent)
{
    parentWnd = (BaseStyle *)parent;
    UI_init();
}

void submit_fail::UI_init()
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("submit_fail"));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);//窗体透明
    this->setFixedSize(248,72);
    setWindowTitle(tr("提交失败"));



    WidgetParameterClass shadowParameter(236 ,60,1,6,6,0.16,0,0,0,0,0);

    swshadow = new StyleWidgetShadow(shadowParameter);


    label = new QLabel(this);
    label->setText(tr("反馈信息发送失败!"));
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
    body->setStyleSheet("QWidget{background-color:rgba(61, 61, 65, 1);border-radius:6px;}");


    QHBoxLayout *hlt_fail=new QHBoxLayout;//窗体内部，水平布局
    hlt_fail->setMargin(0);
    hlt_fail->setSpacing(0);
    hlt_fail->addSpacing(6);
    hlt_fail->addWidget(body, 1);
    hlt_fail->addSpacing(6);
    QVBoxLayout *vlt_fail=new QVBoxLayout;//窗体内部，水平布局
    vlt_fail->setMargin(0);
    vlt_fail->setSpacing(0);
    vlt_fail->addSpacing(6);
    vlt_fail->addLayout(hlt_fail, 1);
    vlt_fail->addSpacing(6);


    this->setLayout(vlt_fail);
    //this->setStyleSheet("submit_fail{background-color:rgba(61, 61, 65, 1);border-radius:6px;}");

    //设置阴影
    QHBoxLayout *hblayout=new QHBoxLayout(swshadow);
    hblayout->setMargin(0);//控件间距
    hblayout->setSpacing(0);//控件间距
    hblayout->addWidget(this);
    swshadow->show();
    //this->show();

}


void submit_fail::pageChangeForTheme(QString str)
{
    qDebug() << "提交失败框的颜色设置！";
    nowTheme = str;
    if("ukui-dark" == str || "ukui-black" == str)
    {
        body->setStyleSheet("QWidget{background-color:rgba(61, 61, 65, 1);border-radius:6px;}");
        label->setStyleSheet(QString::fromUtf8("color:rgba(192, 196, 204, 1);font: 16px;\n"));
    }
    else
    {
        body->setStyleSheet("QWidget{background-color:rgba(255, 255, 255, 1);border-radius:6px;}");
        label->setStyleSheet(QString::fromUtf8("color:rgba(48, 49, 51, 1);font: 16px;\n"));
    }
}

//void submit_fail::show_faillinfo(int error_code)
//{
//    switch (error_code) {
//    case 1:
//        label_3->setText(tr("远程服务器拒绝连接"));
//        break;
//    case 2:
//        label_3->setText(tr("服务器关闭"));
//        break;
//    case 3:
//        label_3->setText(tr("找不到远程主机名（无效主机名）"));
//        break;
//    case 4:
//        label_3->setText(tr("与远程服务器的连接超时"));
//        break;
//    case 99:
//        label_3->setText(tr("网络未连接"));
//        break;
//    case 403:
//        label_3->setText(tr("服务器不可用"));
//        break;
//    default:
//        label_3->setText(tr("未知错误"));
//        break;
//    }
//}
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
void submit_fail::close_fail_window()
{
    //this->hide();
}
void submit_fail::resend_feedbackinfo()
{
    close();
    //parentWnd->resend_info_when_sendfail();

}
//void submit_fail::paintEvent(QPaintEvent *e)
//{
//    Q_UNUSED(e);


//    QPainter p(this);
//    p.setRenderHint(QPainter::Antialiasing);
//    QPainterPath rectPath;
//    rectPath.addRoundedRect(this->rect().adjusted(10, 10, -10, -10), 5, 5);

//    QPixmap pixmap(this->rect().size());
//    pixmap.fill(Qt::transparent);
//    QPainter pixmapPainter(&pixmap);
//    pixmapPainter.setRenderHint(QPainter::Antialiasing);
//    pixmapPainter.setPen(Qt::transparent);
//    pixmapPainter.setBrush(Qt::black);
//    pixmapPainter.drawPath(rectPath);
//    pixmapPainter.end();

//    QImage img = pixmap.toImage();
//    qt_blurImage(img, 10, false, false);


//    pixmap = QPixmap::fromImage(img);
//    QPainter pixmapPainter2(&pixmap);
//    pixmapPainter2.setRenderHint(QPainter::Antialiasing);
//    pixmapPainter2.setCompositionMode(QPainter::CompositionMode_Clear);
//    pixmapPainter2.setPen(Qt::transparent);
//    pixmapPainter2.setBrush(Qt::transparent);
//    pixmapPainter2.drawPath(rectPath);

//    p.drawPixmap(this->rect(), pixmap, pixmap.rect());
//    QStyleOption *option = new QStyleOption();
//    p.save();
//    p.fillPath(rectPath, option->palette.color(QPalette::Base));
//    p.restore();
//}

//void submit_fail::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;

//    QRect rect = this->rect();
//    rect.setWidth(rect.width()-1);
//    rect.setHeight(rect.height()-1);
//    painter.drawRoundedRect(rect, 6, 6);

//    QWidget::paintEvent(event);
//}
