#ifndef DIYSUPPORTPAGE_H
#define DIYSUPPORTPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include "widget_parameter_class.h"
#include "myclick_widget.h"
#include "daemonipcdbus.h"

class DIYSupportPage : public QWidget
{
    Q_OBJECT
public:
    explicit DIYSupportPage(WidgetParameterClass basicParam);
public slots:
    void on_officialWeb_clicked();
    void on_kylinManual_clicked();
signals:
private:
    void pageLocationInit();
    QLabel *m_pKylinPic;
    QLabel *m_pMoreInfoLink;
    QLabel *m_pPageTitle;
    QLabel *m_pOnline;
    QLabel *m_pTelphone;
    QLabel *m_pMail;

    QLabel *m_pKylinOfficialWeb_1;
    QLabel *m_pKylinOfficialWeb_2;
    QLabel *m_pKylinOfficialWeb_3;

    QLabel *m_pKylinManual_1;
    QLabel *m_pKylinManual_2;
    QLabel *m_pKylinManual_3;

    MyClickWidget *officialWeb;
    MyClickWidget *kylinManual;

    WidgetParameterClass diySupportPageBasicParameter;

    DaemonIpcDbus *mDaemonIpcDbus;

};

#endif // DIYSUPPORTPAGE_H
