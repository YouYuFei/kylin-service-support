/************************************************
* 文件描述: 自定义combobox类
* 待完善:
* 待优化:
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*************************************************/
#include "my_combobox.h"
/************************************************
* 函数名称：MyComboBox
* 功能描述：自定义combobox构造函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.09
* 修改内容：
*   创建  HZH
*
*************************************************/
MyComboBox::MyComboBox()
{
    //窗口设置
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);//窗体透明
    this->setFixedSize(206,40);

    pushButton = new QPushButton(this);
    pushButton->setFixedSize(206,40);
    connect(pushButton,&QPushButton::clicked,this,&MyComboBox::on_comboboxButton_click);

    text=new QLabel;
    text->setFixedHeight(16);
    icon=new QLabel;
    icon->setFixedSize(16,16);
    QHBoxLayout *hlt=new QHBoxLayout(pushButton);
    hlt->addWidget(text,9);
    hlt->addWidget(icon);

    listWidget=new QListWidget;
    listWidget->setWindowFlag(Qt::FramelessWindowHint);  // 无边框
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //关闭水平滚动条
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //关闭水平滚动条
    connect(listWidget,&QListWidget::itemClicked,this,&MyComboBox::clickComboboxList);

    QFont ft;
    ft.setPixelSize(14);
    listWidget->setFont(ft);
    ft.setPixelSize(12);
    text->setFont(ft);
}

void MyComboBox::addItem(QString lable)
{
    QListWidgetItem *item=new QListWidgetItem;
    item->setText(lable);

    item->setSizeHint(QSize(pushButton->width()-SHADOW * 2,ITEMHIGHT));
    if(text->text().isEmpty())
    {
        clickComboboxList(item);
    }

    listWidget->addItem(item);
}

void MyComboBox::clickComboboxList(QListWidgetItem *item)
{
    text->setText(item->text());

    closeListWidget();
    emit buttonTextChanged();
}

void MyComboBox::on_comboboxButton_click()
{
    if(!isListOpen)
    {
        closeListWidget();
        int listWidgetHeight=listWidget->count() * ITEMHIGHT + SHADOW;
        listWidget->setFixedHeight(listWidgetHeight);
        listWidget->setFixedWidth(LISTWIDGETWIDTH);

        //设置阴影

        QPoint point= pushButton->mapToGlobal(QPoint(0,0));

        icon->setStyleSheet("border-image:url(:/data/comboboxIcon_d.png);border:0px;");
        if(LIGHTTHEME == themeStatus){
            pushButton->setStyleSheet(".QPushButton{background-color:#fff;border:1px solid rgba(100, 105, 241, 1);}");
            listWidget->setStyleSheet("QListWidget::Item{background-color:rgba(255,255,255,1);border-radius:2px;padding-left:20px;color:rgba(96,98,102,1);}"
                                      "QListWidget::Item:hover{background-color:rgba(246,246,246,1);}");
        }else if(DARKTHEME == themeStatus){
            pushButton->setStyleSheet(".QPushButton{background-color:rgba(31,32,34,1);border:1px solid rgba(100,105,241,1);border-radius:4px;color:rgba(143,417,153,1);}");
            listWidget->setStyleSheet("QListWidget::Item{background-color:rgba(61,61,65,1);border-radius:2px;color:rgba(249,249,249,1);padding-left:20px;}"
                                      "QListWidget::Item:hover{background-color:rgba(72,72,76,1);color:rgba(249,249,249,1);}");
        }
        listWidget->move(point.rx()-SHADOW/2,point.ry()+pushButton->height()+ SHADOW);

        listWidget->show();
        isListOpen = true;
    }
    else
    {
        isListOpen = false;
        closeListWidget();
    }
}

void MyComboBox::closeListWidget()
{
    icon->setStyleSheet("border-image:url(:/data/comboboxIcon_d.png);border:0px;");
    listWidget->close();
    if(LIGHTTHEME == themeStatus){
        pushButton->setStyleSheet(".QPushButton{background-color:#fff;border:1px solid rgba(192, 196,204,1);border-radius:4px;}"
                              ".QPushButton:hover{background-color:#fff;border:1px solid rgba(192,196,204,1);border-radius:4px;}");
    }else if(DARKTHEME == themeStatus){
        pushButton->setStyleSheet(".QPushButton{background-color:rgba(31,32,34,1);border:1px solid rgba(61,61,65,1);border-radius:4px;}"
                              ".QPushButton:hover{background-color:rgba(31,32,34,1);border:1px solid rgba(61,61,65,1);border-radius:4px;}");
    }
}

void MyComboBox::setThemeDark()
{
    themeStatus = DARKTHEME;
    text->setStyleSheet("background-color:rgba(31,32,34,1);color:rgba(143,147,153,1);border:0px;");
    listWidget->setStyleSheet("QListWIdget{color:rgba(61,61,65,1);}"
                "QListWidget::Item{background-color:rgba(61,61,65,1);color:rgba(249,249,249,1);padding-left:10px;}"
                              "QListWidget::Item:hover{background-color:(26,246,246,1);border:1px soild red};");
    icon->setStyleSheet("border-image:url(:/data/comboboxIcon_d.png);border:0px;");
    pushButton->setStyleSheet(".QPushButton{background-color:rgba(31,32,34,1);border:1px solid rgba(61,61,65,1);}");
}

void MyComboBox::setThemeLight()
{
    themeStatus = LIGHTTHEME;
    text->setStyleSheet("color:rgba(96,98,101,1);border:0px;");
    listWidget->setStyleSheet("QListWidget::Item{background-color:rgba(255,255,255,1);color:rgba(96,98,102,1);padding-left:10px;}"
                              "QListWidget::Item:hover{background-color:(246,246,246,1);border:1px soild red};");
    icon->setStyleSheet("border-image:url(:/data/comboboxIcon_d.png);border:0px;");
    pushButton->setStyleSheet(".QPushButton{background-color:#fff;border:1px solid rgba(192, 196,204,1);border-radius:4px;}"
                              ".QPushButton:hover{background-color:#fff;border:1px solid rgba(192,196,204,1);border-radius:4px;}");
}

QString MyComboBox::getCurrentText()
{

    return (text->text());
}

void MyComboBox::setCurrentText(QString str)
{
    text->setText(str);
}
