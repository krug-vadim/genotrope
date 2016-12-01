#include "coord2dinput.h"
#include "ui_coord2dinput.h"

Coord2DInput::Coord2DInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Coord2DInput)
{
	ui->setupUi(this);
}

Coord2DInput::~Coord2DInput()
{
	delete ui;
}

void Coord2DInput::setXText(const QString& text)
{
	ui->lX->setText(text);
}

void Coord2DInput::setYText(const QString& text)
{
	ui->lY->setText(text);
}

int Coord2DInput::x() const
{
	return ui->xSpinBox->value();
}

int Coord2DInput::y() const
{
	return ui->ySpinBox->value();
}

QPoint Coord2DInput::pos() const
{
	return QPoint(ui->xSpinBox->value(), ui->ySpinBox->value());
}

void Coord2DInput::setXLimits(const int min, const int max, const int step)
{
	ui->xSpinBox->setMinimum(min);
	ui->xSpinBox->setMaximum(max);
	ui->xSpinBox->setSingleStep(step);
}

void Coord2DInput::setYLimits(const int min, const int max, const int step)
{
	ui->ySpinBox->setMinimum(min);
	ui->ySpinBox->setMaximum(max);
	ui->ySpinBox->setSingleStep(step);
}
