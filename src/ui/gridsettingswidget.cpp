#include "gridsettingswidget.h"
#include "ui_gridsettingswidget.h"

GridSettingsWidget::GridSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridSettingsWidget)
{
	ui->setupUi(this);

	connect(ui->offsetInput, SIGNAL(xChanged(int)),
	        this, SLOT(offsetUpdate()));
	connect(ui->offsetInput, SIGNAL(yChanged(int)),
	        this, SLOT(offsetUpdate()));

	connect(ui->gridSizeInput, SIGNAL(xChanged(int)),
	        this, SLOT(gridUpdate()));
	connect(ui->gridSizeInput, SIGNAL(yChanged(int)),
	        this, SLOT(gridUpdate()));
}

GridSettingsWidget::~GridSettingsWidget()
{
	delete ui;
}

void GridSettingsWidget::setOffset(const QPoint &pos)
{
	ui->offsetInput->setPos(pos);
}

void GridSettingsWidget::setGrid(const QSize &size)
{
	ui->gridSizeInput->setPos(size.width(), size.height());
}

void GridSettingsWidget::offsetUpdate()
{
	emit offsetChanged( ui->offsetInput->pos() );
}

void GridSettingsWidget::gridUpdate()
{
	QPoint pos = ui->gridSizeInput->pos();
	emit gridChanged( QSize(pos.x(), pos.y()) );
}
