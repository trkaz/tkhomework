#include "wnd.h"
#include "ui_wnd.h"

#include <QMessageBox>



Wnd::Wnd( QWidget *parent) : QWidget( parent), ui( new Ui::Wnd)
{
    ui->setupUi( this);

    QStringList args = QCoreApplication::arguments();

    if (args.size() > 1)
        bckEnd = new BackEnd( args.at( 1));
    else
        bckEnd = new BackEnd;

    clearLabel();

    connect( ui->btnGetText, SIGNAL( clicked()), this, SLOT( clearLabel()));
    connect( ui->btnGetText, SIGNAL( clicked()), bckEnd, SLOT( getText()));
    connect( bckEnd, SIGNAL( textReady( QString)), this, SLOT( updateLabel( QString)));
    connect( bckEnd, SIGNAL( errorMessage( QString)), this, SLOT( showErrorMessage( QString)));
}


Wnd::~Wnd()
{
    delete bckEnd;
    delete ui;
}


void Wnd::clearLabel()
{
    ui->label->clear();
}


void Wnd::updateLabel( QString text)
{
    ui->label->setText( text);
}


void Wnd::showErrorMessage( QString msg)
{
    QMessageBox::critical( this, "Error", msg);
}
