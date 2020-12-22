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

    //增加下拉框阴影
    WidgetParameterClass shadowParameter(206,120,1,4,4,0.16,0,0,0,0,0);

    shadowWidget = new StyleWidgetShadow(shadowParameter);
    shadowWidget->setWindowFlag(Qt::FramelessWindowHint);  // 无边框
    shadowWidget->setAttribute(Qt::WA_TransparentForMouseEvents, true);;


    listWidget=new QListWidget;
    listWidget->setWindowFlag(Qt::FramelessWindowHint);  // 无边框
    listWidget->setAttribute(Qt::WA_TranslucentBackground);

    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //关闭水平滚动条
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //关闭水平滚动条

    connect(listWidget,&QListWidget::itemClicked,this,&MyComboBox::clickComboboxList);

    //设置阴影
    QHBoxLayout *hblayout=new QHBoxLayout(shadowWidget);
    hblayout->setMargin(0);//控件间距
    hblayout->setSpacing(0);//控件间距
    hblayout->addWidget(listWidget);


    QFont ft;
    ft.setPixelSize(14);
    listWidget->setFont(ft);
    text->setFont(ft);
}

void MyComboBox::addItem(QString lable)
{
    QListWidgetItem *item=new QListWidgetItem;
    item->setText(lable);

    item->setSizeHint(QSize(pushButton->width(),ITEMHIGHT));
    if(text->text().isEmpty())
    {
        clickComboboxList(item);
    }

    listWidget->addItem(item);
}

void MyComboBox::clickComboboxList(QListWidgetItem *item)
{
    qDebug() << "clickComboboxList";
    text->setText("    " + item->text());

    //增加选项被选中后颜色
    if(LIGHTTHEME == themeStatus)
    {
        text->setStyleSheet("color:rgba(112, 149, 255, 1);border:0px;");
    }
    else if(DARKTHEME == themeStatus)
    {
        text->setStyleSheet("color:rgba(112, 149, 255, 1);border:0px;");
    }
    closeListWidget();
    emit buttonTextChanged();
}

void MyComboBox::on_comboboxButton_click()
{
    qDebug() << "on_comboboxButton_click()";
    if(!isListOpen)
    {
        closeListWidget();
        int listWidgetHeight=120;
        listWidget->setFixedHeight(listWidgetHeight);
        listWidget->setFixedWidth(LISTWIDGETWIDTH);

        //设置阴影

        QPoint point= pushButton->mapToGlobal(QPoint(0,0));

        icon->setStyleSheet("border-image:url(:/data/comboboxIcon_d.png);border:0px;");
        if(LIGHTTHEME == themeStatus)
        {
            pushButton->setStyleSheet(".QPushButton{background-color:rgba(143, 147, 153, 0.08);border:0px;border-radius:6px;}");
            listWidget->setStyleSheet("QListWidget{color:rgba(48, 49, 51, 1);border-radius:4px;border:0px;border-radius:4px;}"
                                      "QListWidget::Item{background-color:rgba(255,255,255,1);border-radius:2px;padding-left:20px;color:rgba(48, 49, 51, 1);border-radius:0px;}"
                                      "QListWidget::Item:hover{background-color: rgba(247, 247, 247, 1) ;border-radius:0px;}");
        }
        else if(DARKTHEME == themeStatus)
        {
            pushButton->setStyleSheet(".QPushButton{background-color:rgba(49, 50, 52, 1);border:0px;border-radius:6px;}");
            listWidget->setStyleSheet("QListWidget{color:rgba(31, 32, 34, 1);border-radius:4px;border:0px;border-radius:4px;}"
                                      "QListWidget::Item{background-color:rgba(61, 61, 65, 1);border-radius:2px;color:rgba(249,249,249,1);padding-left:20px;border-radius:0px;}"
                                      "QListWidget::Item:hover{background-color:rgba(72, 72, 76, 1);color:rgba(249,249,249,1);border-radius:0px;}");
        }
//        listWidget->move(point.rx(),point.ry()+pushButton->height()+ SHADOW);
        shadowWidget->move(point.rx()-SHADOW,point.ry()+pushButton->height());

        shadowWidget->show();
        listWidget->show();
        isListOpen = true;
    }
    else
    {
        //isListOpen = false;
        closeListWidget();
    }
}

void MyComboBox::closeListWidget()
{
    qDebug() << "closeListWidget()";
    isListOpen = false;
    icon->setStyleSheet("border-image:url(:/data/comboboxIcon_d.png);border:0px;");

    shadowWidget->hide();
    listWidget->close();

    if(LIGHTTHEME == themeStatus)
    {
        pushButton->setStyleSheet(".QPushButton{background-color:rgba(143, 147, 153, 0.08);border:0px;border-radius:6px;}"
                              ".QPushButton:hover{background-color:rgba(143, 147, 153, 0.08);border:0px;border-radius:6px;}");
    }
    else if(DARKTHEME == themeStatus)
    {
        pushButton->setStyleSheet(".QPushButton{background-color:rgba(49, 50, 52, 1);border:0px;border-radius:6px;}"
                              ".QPushButton:hover{background-color:rgba(49, 50, 52, 1);border:0px;border-radius:6px;}");
    }
}

void MyComboBox::setThemeDark()
{
    themeStatus = DARKTHEME;
    text->setStyleSheet("color:rgba(143, 147, 153, 1);border:0px;");
    listWidget->setStyleSheet("QListWidget{color:rgba(61,61,65,1);border-radius:4px;border:0px;border-radius:4px;}"
                              "QListWidget::Item{background-color:rgba(61,61,65,1);color:rgba(249,249,249,1);padding-left:10px;border-radius:0px;}"
                              "QListWidget::Item:hover{background-color:rgba(72, 72, 76, 1);border:0px;border-radius:0px;};");
    icon->setStyleSheet("border-image:url(:/data/comboboxIcon_d.png);border:0px;");
    pushButton->setStyleSheet(".QPushButton{background-color:rgba(49, 50, 52, 1);border:0px;border-radius:6px;}");
}

void MyComboBox::setThemeLight()
{
    themeStatus = LIGHTTHEME;
    text->setStyleSheet("color:rgba(143, 147, 153, 1);border:0px;");
    listWidget->setStyleSheet("QListWidget{color:rgba(61,61,65,1);border-radius:4px;border:0px;border-radius:4px;}"
                              "QListWidget::Item{background-color:rgba(255,255,255,1);color:rgba(48, 49, 51, 1);padding-left:10px;border-radius:0px;}"
                              "QListWidget::Item:hover{background-color:(246,246,246,1);border:0px;border-radius:0px;};");
    icon->setStyleSheet("border-image:url(:/data/comboboxIcon_d.png);border:0px;");
    pushButton->setStyleSheet(".QPushButton{background-color:rgba(143, 147, 153, 0.08);border:0px;border-radius:6px;}");
}

QString MyComboBox::getCurrentText()
{

    return (text->text().right(text->text().length()-4));
}

void MyComboBox::setCurrentText(QString str)
{
    text->setText(str);
}
