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
    UI_init();
    parentWnd = (BaseStyle *)parent;
    setAttribute(Qt::WA_TranslucentBackground);
}

void submit_fail::UI_init()
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("submit_fail"));
    setWindowTitle(tr("submit fail"));

    this->resize(350, 230);

    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    //----- ------------------------


    label = new QLabel(this);
    label->setText(tr("问题提交失败"));
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(111, 70, 168, 31));
    QFont font;
    font.setPixelSize(24);
    label->setFont(font);



    QPalette palette;
    QColor ColorPlaceholderText(255,255,255,0);
    QBrush brush;
    brush.setColor(ColorPlaceholderText);
    palette.setBrush(QPalette::Button, brush);
    palette.setBrush(QPalette::ButtonText, brush);

    fail_closeBtn = new QPushButton(this);
    fail_closeBtn->setGeometry(QRect(310, 15, 30, 30));
    fail_closeBtn->setIcon(QIcon::fromTheme("window-close-symbolic"));
    fail_closeBtn->setPalette(palette);
    fail_closeBtn->setProperty("useIconHighlightEffect", true);
    fail_closeBtn->setProperty("iconHighlightEffectMode", 1);




    connect(fail_closeBtn,SIGNAL(clicked()),this,SLOT(close_fail_window()));

    resendBtn = new QPushButton(this);
    resendBtn->setGeometry(QRect(130, 160, 60, 26));
    resendBtn->setText(tr("重新发送"));
    resendBtn->setFlat(false);
    resendBtn->hide();
    resendBtn->setStyleSheet(QString::fromUtf8("QPushButton{color: rgb(61, 107, 229);background-color:rgb(255,255,255)}"
                                               "QPushButton:hover {color: rgb(255,255,255);background-color:rgb(107,142,235)}"
                                               ""));
    connect(resendBtn,SIGNAL(clicked()),this,SLOT(resend_feedbackinfo()));

    pushButton_2 = new QPushButton(this);
    pushButton_2->setText(tr("确定"));
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(249, 180, 80, 30));
    pushButton_2->setFlat(false);


    label_2 = new QLabel(this);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(71, 71, 30, 30));
    label_2->setPixmap(QPixmap(":/image/failed.png"));
    label_3 = new QLabel(this);
    label_3->setGeometry(QRect(71,111, 224, 19));


    connect(pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
}
void submit_fail::show_faillinfo(int error_code)
{
    switch (error_code) {
    case 1:
        label_3->setText(tr("远程服务器拒绝连接"));
        break;
    case 2:
        label_3->setText(tr("服务器关闭"));
        break;
    case 3:
        label_3->setText(tr("找不到远程主机名（无效主机名）"));
        break;
    case 4:
        label_3->setText(tr("与远程服务器的连接超时"));
        break;
    case 99:
        label_3->setText(tr("网络未连接"));
        break;
    case 403:
        label_3->setText(tr("服务器不可用"));
        break;
    default:
        label_3->setText(tr("未知错误"));
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
void submit_fail::close_fail_window()
{
    this->hide();
}
void submit_fail::resend_feedbackinfo()
{
    close();
    //parentWnd->resend_info_when_sendfail();

}
void submit_fail::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);


    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QPainterPath rectPath;
    rectPath.addRoundedRect(this->rect().adjusted(10, 10, -10, -10), 5, 5);

    QPixmap pixmap(this->rect().size());
    pixmap.fill(Qt::transparent);
    QPainter pixmapPainter(&pixmap);
    pixmapPainter.setRenderHint(QPainter::Antialiasing);
    pixmapPainter.setPen(Qt::transparent);
    pixmapPainter.setBrush(Qt::black);
    pixmapPainter.drawPath(rectPath);
    pixmapPainter.end();

    QImage img = pixmap.toImage();
    qt_blurImage(img, 10, false, false);


    pixmap = QPixmap::fromImage(img);
    QPainter pixmapPainter2(&pixmap);
    pixmapPainter2.setRenderHint(QPainter::Antialiasing);
    pixmapPainter2.setCompositionMode(QPainter::CompositionMode_Clear);
    pixmapPainter2.setPen(Qt::transparent);
    pixmapPainter2.setBrush(Qt::transparent);
    pixmapPainter2.drawPath(rectPath);

    p.drawPixmap(this->rect(), pixmap, pixmap.rect());
    QStyleOption *option = new QStyleOption();
    p.save();
    p.fillPath(rectPath, option->palette.color(QPalette::Base));
    p.restore();
}
