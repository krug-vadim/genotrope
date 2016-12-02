#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->actionFileOpen, SIGNAL(triggered()),
	        this, SLOT(openImage()));

	// grid & pos settings
	ui->settingsWidget->setOffset(ui->gridImageWidget->offset());
	ui->settingsWidget->setGrid(ui->gridImageWidget->grid());
	ui->settingsWidget->setSpacing(ui->gridImageWidget->spacing());

	connect(ui->settingsWidget, SIGNAL(offsetChanged(const QPoint)),
	        ui->gridImageWidget, SLOT(setOffset(const QPoint)));
	connect(ui->settingsWidget, SIGNAL(gridChanged(const QSize)),
	        ui->gridImageWidget, SLOT(setGrid(const QSize)));
	connect(ui->settingsWidget, SIGNAL(spacingChanged(const QSize)),
	        ui->gridImageWidget, SLOT(setSpacing(const QSize)));

	// color
	ui->settingsWidget->setColor(ui->gridImageWidget->color());
	connect(ui->settingsWidget, SIGNAL(colorChanged(const QColor)),
	        ui->gridImageWidget, SLOT(setColor(const QColor)));

	// scale
	ui->settingsWidget->setScale(ui->gridImageWidget->scale());
	connect(ui->settingsWidget, SIGNAL(scaleChanged(const QPointF)),
	        ui->gridImageWidget, SLOT(setScale(const QPointF)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::openImage()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
	                                                "",
	                                                tr("Images (*.png *.xpm *.jpg)"));

	if ( fileName.isEmpty() )
		return;

	ui->gridImageWidget->load(fileName);
}
