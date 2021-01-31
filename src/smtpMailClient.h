#ifndef SMTPMAILCLIENT_H
#define SMTPMAILCLIENT_H

#include <QObject>
#include<QByteArray>
#include<QString>
#include<QTcpSocket>

typedef struct
{
    QString askTitle;
    QString questionDescription;
    QString customerEMail;
    QString OSVersion;
    QString desktopVersion;
    QString systemLanguage;
}mailContent;

enum class SmtpErrType : int
{
    SmtpOpSucc = 0,
    SmtpConnectOverTime,
    SmtpFeedBackOverTime,
    MailServerNotReady,
    MailLoginFailed,
    SendMailConfigFeedBackOverTime,
};

class SmtpMailClient : public QObject
{
    Q_OBJECT
public:
    explicit SmtpMailClient(QObject *parent);
    ~SmtpMailClient();

    int connectToHost();

    int sendMail(const mailContent& mailData);

signals:

private:
    const QByteArray userName;
    const QByteArray passWD;

    QTcpSocket *mailSocket = nullptr;

    mailContent mailStruct;

};

#endif // SMTPMAILCLIENT_H
