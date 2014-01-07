﻿/*****************************************************************
**				Project:	ShipControl(WOPC)					**
**				Author:		Dong Shengwei						**
**				Library:	BestSea								**
**				Date:		2014-01-04							**
******************************************************************/

//mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QLabel;
class QMenu;
class QScrollArea;
class QSlider;
class QPushButton;
class QTimer;
QT_END_NAMESPACE

class ShipGraph;
class ShipControl;
class ShipParameter;
class OptionDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void about();
    void controlStart();
	void controlStop();
	void updateShip();

private:
    void createActions();
    void createMenus();
    QSlider *createSlider(const char *changedSignal, const char *setterSlot);

    ShipControl *shipCtrl;
    ShipParameter *shipPara;
	OptionDialog *setDialog;

    QWidget *centralWidget;
    QScrollArea *glWidgetArea;
    ShipGraph *shipWidget;

	QTimer *timer;

    QSlider *xSlider;
    QSlider *ySlider;
	QSlider *zSlider;
	QSlider *zoomSlider;

    QPushButton *startButton;
	QPushButton *stopButton;

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *setDialogAct;
    QAction *exitAct;
	QAction *aboutAct;

	//船舶控制是否初次运行
	bool firstRun;
};

#endif // MAINWINDOW_H
