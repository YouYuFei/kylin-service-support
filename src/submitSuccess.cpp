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
    this->setWindowFlags(Qt::FramelessWindowHint);

    this->showNormal();
    this->setAttribute(Qt::WA_TranslucentBackground, true);//窗体透明
    this->setFixedSize(248,72);

    WidgetParameterClass shadowParameter(236 ,60,1,6,6,0.16,0,0,0,0,0);

    swshadow = new StyleWidgetShadow(shadowParameter);
        swshadow->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

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
    body->setStyleSheet("QWidget{background-color:rgba(61, 61, 65, 1);border-radius:6px;}");


    QHBoxLayout *hlt_suc=new QHBoxLayout;//窗体内部，水平布局
    hlt_suc->setMargin(0);
    hlt_suc->setSpacing(0);
    hlt_suc->addSpacing(6);
    hlt_suc->addWidget(body, 1);
    hlt_suc->addSpacing(6);
    QVBoxLayout *vlt_suc=new QVBoxLayout;//窗体内部，水平布局
    vlt_suc->setMargin(0);
    vlt_suc->setSpacing(0);
    vlt_suc->addSpacing(6);
    vlt_suc->addLayout(hlt_suc, 1);
    vlt_suc->addSpacing(6);

    this->setLayout(vlt_suc);
    //设置阴影
    QHBoxLayout *hblayout=new QHBoxLayout(swshadow);
    hblayout->setMargin(0);//控件间距
    hblayout->setSpacing(0);//控件间距
    hblayout->addWidget(this);
    swshadow->show();
}
submit_success::~submit_success()
{

}

void submit_success::pageChangeForTheme(const QString& str)
{
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

void submit_success::on_pushButton_2_clicked()
{
    this->close();
    swshadow->close();
    //parentWnd->window_close();
}

void submit_success::on_pushButton_clicked()
{
    //parentWnd ->feedback_info_init();
    close();
}
void submit_success::succ_close_window()
{
    this->close();
}
//void submit_success::paintEvent(QPaintEvent *e)
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

//void submit_success::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
//    painter.setBrush(QBrush(Qt::red));
//    painter.setPen(Qt::transparent);
//    QRect rect = this->rect();
//    rect.setWidth(rect.width() - 1);
//    rect.setHeight(rect.height() - 1);
//    painter.drawRoundedRect(rect, 6, 6);

//    QWidget::paintEvent(event);
//}

