// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQtExamples/blob/master/LICENSE

#ifndef CVWIDGET_H
#define CVWIDGET_H

#include <QWidget>

class QVBoxLayout;
class QLayout;
class QLabel;
class QPushButton;

class QCvObject;

class CvWidget : public QWidget
{
    Q_OBJECT

public:
    CvWidget(QWidget *parent = 0);
    ~CvWidget();
signals:

private slots:
    void  setPropValue();
    void  setInvokeValue();
private:
    void setupLayoutSignalSlot();
    QVBoxLayout       *_loutMain;
    QCvObject         *_cvo;
    QLabel            *_lbValue;
};

#endif // CVWIDGET_H
