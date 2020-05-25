#ifndef SCREENEXAMPLE_H
#define SCREENEXAMPLE_H

#include <QMainWindow>
#include "../../qswipecheckbox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ScreenExample; }
QT_END_NAMESPACE

class ScreenExample : public QMainWindow
{
    Q_OBJECT

public:
    ScreenExample(QWidget *parent = nullptr);
    ~ScreenExample();

private:
    Ui::ScreenExample *ui;

    QSwipeCheckbox *swipeCheckbox;
};
#endif // SCREENEXAMPLE_H
