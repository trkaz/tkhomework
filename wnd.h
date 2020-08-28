#ifndef WND_H
#define WND_H

#include <QWidget>
#include <QProcess>
#include "backend.h"


namespace Ui {
class Wnd;
}

class Wnd : public QWidget
{
    Q_OBJECT

public:
    explicit Wnd( QWidget *parent = 0);
    ~Wnd();

private slots:
    void clearLabel();
    void updateLabel( QString text);
    void showErrorMessage( QString msg);

private:
    Ui::Wnd *ui;
    BackEnd *bckEnd;

};

#endif // WND_H
