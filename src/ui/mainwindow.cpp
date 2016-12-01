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
