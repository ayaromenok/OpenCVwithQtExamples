// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQtExamples/blob/master/LICENSE

#include <QtGui>
#include <QtWidgets>

#include "../cvqt/share.h"

#include "cvwidget.h"
#include "qcvobject.h"


CvWidget::CvWidget(QWidget *parent)
    : QWidget(parent)
{
    CVQT_TIMESTAMP();

    _cvo = new QCvObject(this);
    setWindowTitle("Qt Widget for OpenCV");
    setupLayoutSignalSlot();
}

CvWidget::~CvWidget()
{
    CVQT_TIMESTAMP();    
}

void
CvWidget::setPropValue()
{
    CVQT_TIMESTAMP();
    _cvo->setIntVal(5);
}

void
CvWidget::setInvokeValue()
{
    CVQT_TIMESTAMP();
    _cvo->setIntValInvokable(7);
}

void
CvWidget::setupLayoutSignalSlot()
{
    CVQT_TIMESTAMP();

    _loutMain = new QVBoxLayout;

    QPushButton*    btnProp = new QPushButton("Set Value via Property: 5", this);
    QPushButton*    btnInvoke = new QPushButton("Set Value via Invokable: 7", this);
    QLabel*         lbValueDesc = new QLabel("value is:", this);
    _lbValue = new QLabel("0");

    _loutMain->addWidget(btnProp);
    _loutMain->addWidget(btnInvoke);

    QHBoxLayout*    loutValue = new QHBoxLayout();
    loutValue->addWidget(lbValueDesc);
    loutValue->addWidget(_lbValue);
    _loutMain->addLayout(loutValue);
    this->setLayout(_loutMain);

    connect(btnProp, SIGNAL(clicked()),
            this,SLOT(setPropValue()));
    connect(btnInvoke, SIGNAL(clicked()),
            this,SLOT(setInvokeValue()));
    connect(_cvo,SIGNAL(intValChanged(int)),
            _lbValue, SLOT(setNum(int)));
}
