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
    parentWnd = (BaseStyle *)parent;
    UI_init();
}
void submit_success::UI_init()
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("submit_success"));
    this->resize(350, 230);
    setWindowTitle(tr("问题提交成功"));
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    //----- ------------------------

    label = new QLabel(this);
    label->setText(tr("问题提交成功"));
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(111, 70, 168, 31));
    label->setStyleSheet(QString::fromUtf8("font: 24px;\n"));

    QPalette palette;
    QColor ColorPlaceholderText(255,255,255,0);
    QBrush brush;
    brush.setColor(ColorPlaceholderText);
    palette.setBrush(QPalette::Button, brush);
    palette.setBrush(QPalette::ButtonText, brush);

    succ_closeBtn = new QPushButton(this);
    succ_closeBtn->setGeometry(QRect(310, 15, 30, 30));
    succ_closeBtn->setIcon(QIcon::fromTheme("window-close-symbolic"));
    succ_closeBtn->setPalette(palette);
    succ_closeBtn->setProperty("useIconHighlightEffect", true);
    succ_closeBtn->setProperty("iconHighlightEffectMode", 1);

    connect(succ_closeBtn,SIGNAL(clicked()),this,SLOT(succ_close_window()));

    pushButton = new QPushButton(this);
    pushButton->setText(tr("继续反馈问题"));
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(110, 165, 131, 26));
    pushButton->setFlat(false);
    pushButton->hide();




    pushButton_2 = new QPushButton(this);
    pushButton_2->setText(tr("确认"));
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(249, 180, 80, 30));

    label_2 = new QLabel(this);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(71, 71, 30, 30));
    label_2->setPixmap(QPixmap(":/image/success.png"));


//    connect(pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    qDebug()<<"submit_success::UI_init()";
    this->show();
}
submit_success::~submit_success()
{

}

void submit_success::on_pushButton_2_clicked()
{
    this->close();
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
void submit_success::paintEvent(QPaintEvent *e)
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
