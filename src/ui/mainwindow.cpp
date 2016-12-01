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

	connect(ui->settingsWidget, SIGNAL(offsetChanged(const QPoint)),
	        ui->gridImageWidget, SLOT(setOffset(const QPoint)));
	connect(ui->settingsWidget, SIGNAL(gridChanged(const QSize)),
	        ui->gridImageWidget, SLOT(setGrid(const QSize)));
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
