#include <qt/veil/tooltipbalance.h>
#include <qt/veil/forms/ui_tooltipbalance.h>

#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QPropertyAnimation>
#include <QTimer>

TooltipBalance::TooltipBalance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TooltipBalance)
{
    ui->setupUi(this);

    // TODO: Load me..
    ui->textZero->setText("25.280 Veil");
    ui->textRing->setText("25.280 Veil");

    QTimer::singleShot(3500, this, SLOT(hide()));

}

void TooltipBalance::showEvent(QShowEvent *event){
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
    a->setDuration(400);
    a->setStartValue(0.1);
    a->setEndValue(1);
    a->setEasingCurve(QEasingCurve::InBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);
}

void TooltipBalance::hideEvent(QHideEvent *event){
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
    a->setDuration(800);
    a->setStartValue(1);
    a->setEndValue(0);
    a->setEasingCurve(QEasingCurve::OutBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    //connect(a,SIGNAL(finished()),this,SLOT(hideThisWidget()));
}

TooltipBalance::~TooltipBalance()
{
    delete ui;
}