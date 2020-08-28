#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QProcess>


#define DEF_SCRIPT_NAME "./simple.sh"


class BackEnd : public QObject
{
    Q_OBJECT

public:
    explicit BackEnd( QString _scriptName = DEF_SCRIPT_NAME, QObject *parent = 0);

public slots:
    void getText();

signals:
    void textReady( QString text);
    void errorMessage( QString msg);

private:
    QProcess process;
    QString scriptName;
    QString processOutput;

private slots:
    void dealWithProcessError( QProcess::ProcessError err);
    void updateOutput();
    void wrapUp( int exitCode, QProcess::ExitStatus exitStatus);

};

#endif // BACKEND_H
