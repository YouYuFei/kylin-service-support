#include "my_tab_widget.h"

MyTabWidget::MyTabWidget(QWidget *parent) : QTabWidget(parent)
{

    connect(this,SIGNAL(tabBarClicked(int)),this,SLOT(slotSetLabelColor(int)));

}

void MyTabWidget::slotSetLabelColor(int index)
{
    for(int i=0;i<this->count();i++)
    {
        this->tabBar()->tabButton(i,QTabBar::ButtonPosition::RightSide)->setStyleSheet("background-color:rgba(255,255,255,0.5);");
    }
    this->tabBar()->tabButton(index,QTabBar::ButtonPosition::RightSide)->setStyleSheet("background-color:rgba(0,0,0,0);color:white;");

}

int MyTabWidget::addTab(QWidget *widget, const QString &label)
{
    int nRetrun=QTabWidget::addTab(widget,"");
    int count=this->count()-1;
    QLabel *labelTab=new QLabel(label,this);
    QFont ft;
    ft.setPointSize(40);
    labelTab->setFont(ft);
    labelTab->setAlignment(Qt::AlignCenter);
    //labelTab->setFixedSize(40,30);
    this->tabBar()->setTabButton(count,QTabBar::ButtonPosition::RightSide,labelTab);
    this->tabBar()->tabButton(count,QTabBar::ButtonPosition::RightSide)->setFixedHeight(100);
    this->tabBar()->setFixedSize(400,300);
    updateselect();
    return nRetrun;

}

void MyTabWidget::updateselect()
{
    for(int i=0;i<this->currentIndex();i++)
    {
        this->tabBar()->tabButton(i,QTabBar::ButtonPosition::RightSide)->setStyleSheet("background-color:rgba(255,0,0,0);color:black;");
    }
    this->tabBar()->tabButton(this->currentIndex(),QTabBar::ButtonPosition::RightSide)->setStyleSheet("background-color:rgba(255,0,0,0);color:white;");

}
