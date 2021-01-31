#include <QDateTime>
#include "smtpMailClient.h"

SmtpMailClient::SmtpMailClient(QObject *parent)
    : QObject(parent),userName("kylin-service-support-01@kylinos.cn"),passWD("kylin123")
{

}

SmtpMailClient::~SmtpMailClient()
{

}

int SmtpMailClient::connectToHost()
{
    mailSocket = new QTcpSocket();

    mailSocket->connectToHost("smtp.kylinos.cn",25,QTcpSocket::ReadWrite);

    if (!mailSocket->waitForConnected(1000))
    {
        qFatal("connection failed!");
        return int(SmtpErrType::SmtpConnectOverTime);
    }

    if (!mailSocket->waitForReadyRead(1000))
    {
        qFatal("connection failed!");
        return int(SmtpErrType::SmtpFeedBackOverTime);
    }
    QByteArray returnData;
    returnData = mailSocket->readAll();
    qDebug() << returnData;

    if(returnData.contains("ready"))
    {
        QByteArray serverName = "EHLO kylin-service-support-01@kylinos.cn\r\n";
        mailSocket->write(serverName);
        if (!mailSocket->waitForReadyRead(1000))
        {
            qFatal("connection failed!");
            return int(SmtpErrType::SmtpFeedBackOverTime);
        }

        QString tempuserName = userName;

        QString temppassWD = passWD;



        mailSocket->write("AUTH LOGIN\r\n");
        if(mailSocket->waitForReadyRead(10000))
        {
            returnData = mailSocket->readAll();
            qDebug() << returnData;

            if(!returnData.contains("334"))
            {
                return int(SmtpErrType::MailLoginFailed);
            }
            else
            {
                mailSocket->write(QByteArray().append(tempuserName).toBase64() + "\r\n");
                if(mailSocket->waitForReadyRead(10000))
                {
                    returnData = mailSocket->readAll();
                    qDebug() << returnData;

                    if(!returnData.contains("334"))
                    {
                        return int(SmtpErrType::MailLoginFailed);
                    }
                    else
                    {
                        mailSocket->write(QByteArray().append(temppassWD).toBase64() + "\r\n");

                        if(mailSocket->waitForReadyRead(10000))
                        {
                            returnData = mailSocket->readAll();
                            qDebug() << returnData;

                            if(!returnData.contains("235"))
                            {
                                return int(SmtpErrType::MailLoginFailed);
                            }
                            else
                            {
                                return int(SmtpErrType::SmtpOpSucc);
                            }
                        }
                        else
                        {
                            return int(SmtpErrType::SmtpFeedBackOverTime);
                        }
                    }
                }
                else
                {
                    return int(SmtpErrType::SmtpFeedBackOverTime);
                }
            }
        }
    }
    else
    {
        return int(SmtpErrType::MailServerNotReady);
    }
}

int SmtpMailClient::sendMail(const mailContent& mailData)
{
    qDebug() << "开始发信";
    QByteArray returnData;

    mailStruct = mailData;

    QByteArray mailfrom = "MAIL FROM:<";
    QString tempName1 = "kylin-service-support-01@kylinos.cn";
    mailfrom.append(tempName1.toUtf8().append(">\r\n"));
    mailSocket->write(mailfrom);

    if (!mailSocket->waitForReadyRead(10000)) {
        return int(SmtpErrType::SendMailConfigFeedBackOverTime);
    }
    else
    {
        returnData = mailSocket->readAll();
        qDebug() << returnData;
    }

    QByteArray rcptto = "rcpt to:<";
    QString tempName2 = "kylin-service-support-01@kylinos.cn";
    rcptto.append(tempName2.toUtf8().append(">\r\n"));
    mailSocket->write(rcptto);

    if (!mailSocket->waitForReadyRead(10000)) {
        return int(SmtpErrType::SendMailConfigFeedBackOverTime);
    }
    else
    {
        mailSocket->write("DATA\r\n");

        mailSocket->waitForReadyRead(1000);

        returnData = mailSocket->readAll();
        qDebug() << returnData;
    }

    qDebug() << "填写邮件内容";
    QByteArray tempSender = "From: ";
    QString sender = userName;
    tempSender.append(sender.toUtf8().append("\r\n"));

    QByteArray tempRecv = "To: ";
    QString receivers = "kylin-service-support-01@kylinos.cn";
    tempRecv.append(receivers.toUtf8().append("\r\n"));

    QByteArray tempsubject = "Subject: ";
    QString subject = "【麒麟服务与支持】";
    tempsubject.append(subject.toUtf8().append("\r\n"));

    mailSocket->write(tempSender);

    mailSocket->write(tempRecv);

    mailSocket->write(tempsubject);


    mailSocket->write(QByteArrayLiteral("MIME-Version: 1.0\r\n"));

    QByteArray mailHeaders;
    QByteArray contentType = QByteArrayLiteral("multipart/mixed");
    QByteArray contentCharset = QByteArrayLiteral("utf-8");
    QByteArray contentBoundary = QByteArrayLiteral("myBoundary");


    mailHeaders.append("Content-Type: " + contentType);
    mailHeaders.append("; boundary=" + contentBoundary + "\r\n\r\n");
    mailSocket->write(mailHeaders);

    QByteArray mailText = "";
    mailText += ("--" + contentBoundary);
    mailText.append("\r\n\r\n");
    mailSocket->write(mailText);

    QByteArray mailText1 = "";
    QByteArray htmlType = QByteArrayLiteral("text/html");
    mailText1.append("Content-Type: " + htmlType);
    mailText1.append("; boundary=" + contentCharset + "\r\n");
    mailSocket->write(mailText1);

    QByteArray mailText2 = "";
    mailText2.append(QByteArrayLiteral("Content-Transfer-Encoding: quoted-printable"));
    mailText2.append("\r\n\r\n");
    mailSocket->write(mailText2);

    QByteArray mailText3 = "";
    mailText3.append("【用户通过服务与支持反馈邮件】<br\>");
    mailText3.append("<br\>用户邮件地址：");
    mailText3.append(mailStruct.customerEMail + "<br\>");
    mailText3.append("反馈问题类型：");
    mailText3.append(mailStruct.askTitle + "<br\>");
    mailText3.append("反馈内容：");
    mailText3.append(mailStruct.questionDescription + "<br\>");
    mailText3.append("系统版本：");
    mailText3.append(mailStruct.OSVersion + "<br\>");
    mailText3.append("桌面版本：");
    mailText3.append(mailStruct.desktopVersion + "<br\>");
    mailText3.append("语言环境：");
    mailText3.append(mailStruct.systemLanguage + "<br\>");
    mailSocket->write(mailText3);
    mailSocket->write("\r\n\r\n");

    QByteArray mailText4 = "";
    mailText3 += "--" + contentBoundary + "--\r\n\r\n";
    mailSocket->write(mailText4);


    mailSocket->write(QByteArrayLiteral("\r\n.\r\n"));

    mailSocket->waitForReadyRead(10000);


    returnData = mailSocket->readAll();

    qDebug()<<returnData;

    mailSocket->write("quit\r\n");

    mailSocket->waitForReadyRead(1000);

    returnData = mailSocket->readAll();

    qDebug()<<returnData;
    return int(SmtpErrType::SmtpOpSucc);
}
