#include "gridsettingswidget.h"
#include "ui_gridsettingswidget.h"

GridSettingsWidget::GridSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridSettingsWidget)
{
	ui->setupUi(this);

	// offset
	connect(ui->offsetInput, SIGNAL(xChanged(int)),
	        this, SLOT(offsetUpdate()));
	connect(ui->offsetInput, SIGNAL(yChanged(int)),
	        this, SLOT(offsetUpdate()));

	// grid
	connect(ui->gridSizeInput, SIGNAL(xChanged(int)),
	        this, SLOT(gridUpdate()));
	connect(ui->gridSizeInput, SIGNAL(yChanged(int)),
	        this, SLOT(gridUpdate()));

	// spacing
	connect(ui->spacingInput, SIGNAL(xChanged(int)),
	        this, SLOT(spacingUpdate()));
	connect(ui->spacingInput, SIGNAL(yChanged(int)),
	        this, SLOT(spacingUpdate()));
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

void GridSettingsWidget::setSpacing(const QSize &spacing)
{
	ui->spacingInput->setPos(spacing.width(), spacing.height());
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

void GridSettingsWidget::spacingUpdate()
{
	QPoint pos = ui->spacingInput->pos();
	emit spacingChanged( QSize(pos.x(), pos.y()) );
}
