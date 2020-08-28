#include "backend.h"



BackEnd::BackEnd( QString _scriptName, QObject *parent) : QObject( parent), scriptName( _scriptName)
{

    connect( &process, SIGNAL( error( QProcess::ProcessError)), this, \
             SLOT( dealWithProcessError( QProcess::ProcessError)));

    connect( &process, SIGNAL( readyReadStandardOutput()), this, SLOT( updateOutput()));
    connect( &process, SIGNAL( finished( int, QProcess::ExitStatus)), this, \
             SLOT( wrapUp( int, QProcess::ExitStatus)));

}


void BackEnd::getText()
{
    processOutput.clear();
    process.start( scriptName);
}


void BackEnd::updateOutput()
{
    processOutput.append( process.readAllStandardOutput());
}


void BackEnd::wrapUp( int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus != QProcess::NormalExit)
        emit errorMessage( QString( "%1, execution failed").arg( scriptName));
    else
        emit textReady( processOutput);
}


void BackEnd::dealWithProcessError( QProcess::ProcessError err)
{
    QString msg;

    if (err == QProcess::FailedToStart)
        msg = QString( "Cannot execute %1").arg( scriptName);
    else
        msg = QString( "%1, process error; error code = %2").arg( scriptName).arg( err);

    emit errorMessage( msg);
}
