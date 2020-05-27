#include "screenexample.h"
#include "ui_screenexample.h"
#include <QDateTime>

ScreenExample::ScreenExample(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ScreenExample)
{
    ui->setupUi(this);

    QDateTime UTC(QDateTime::currentDateTimeUtc());
    QDateTime local(UTC.toLocalTime());
    QFont font = QFont("SF Pro Display",14,QFont::Normal);
    QFont tinyFont = QFont("SF Pro Display", 12, QFont::Normal);
    QFont blueFont = QFont("SF Pro Display", 15, QFont::Normal);
    QFont boldFont = QFont("SF Pro Display", 16, QFont::DemiBold);
    QFont buttonFont = QFont("SF Pro Display",14,QFont::DemiBold);
    ui->localTimeLabel->setFont(font);
    ui->localTimeLabel->setText(QString("%1:%2").arg(local.time().hour()).arg(QString::number(local.time().minute()).rightJustified(2, '0')));
    ui->exampleText->setFont(font);
    ui->backLabel->setFont(blueFont);
    ui->backLabel->setStyleSheet(ui->backLabel->styleSheet()+="color: #087dff");
    ui->exampleLabel->setFont(boldFont);
    ui->quitButton->setFont(buttonFont);
    ui->upperInfoLabel->setFont(tinyFont);
    ui->lowerInfoLabel->setFont(tinyFont);

    this->connect(ui->quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));



    swipeCheckbox = new QSwipeCheckbox(this);
    swipeCheckbox->setGeometry(318,232,78,46);
    swipeCheckbox->setBackgroundColors(QColor("#49E845"), QColor("#E3E3E3"));
    swipeCheckbox->setBorderColors(QColor("#49E845"), QColor("#E3E3E3"));
    swipeCheckbox->setSwitchKnobColors(QColor("#FFFFFF"), QColor("#FFFFFF"));
    swipeCheckbox->setBorderWidth(3);
    swipeCheckbox->setAnimationSpeed(200);
    swipeCheckbox->setDisplayStyle(QSwipeCheckbox::DisplayStyle::iOS);
    swipeCheckbox->setClickableArea(QSwipeCheckbox::ClickableArea::Handle);
    swipeCheckbox->setShadowEnabled(true);
    swipeCheckbox->setShadowAngle(45);
    swipeCheckbox->setShadowSize(2);
    swipeCheckbox->setShadowColor(QColor("#999999"));
    swipeCheckbox->setShadowOpacity(40);
    swipeCheckbox->setEnabled(true);
    swipeCheckbox->setChecked(false);



}

ScreenExample::~ScreenExample()
{
    delete ui;
}

