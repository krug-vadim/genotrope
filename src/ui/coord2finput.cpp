#include "coord2finput.h"
#include "ui_coord2finput.h"

Coord2FInput::Coord2FInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Coord2FInput)
{
	ui->setupUi(this);

	connect(ui->xSpinBox, SIGNAL(valueChanged(double)),
	        this, SIGNAL(xChanged(double)));
	connect(ui->ySpinBox, SIGNAL(valueChanged(double)),
	        this, SIGNAL(yChanged(double)));
}

Coord2FInput::~Coord2FInput()
{
	delete ui;
}

void Coord2FInput::setXText(const QString& text)
{
	ui->lX->setText(text);
}

void Coord2FInput::setYText(const QString& text)
{
	ui->lY->setText(text);
}

double Coord2FInput::x() const
{
	return ui->xSpinBox->value();
}

double Coord2FInput::y() const
{
	return ui->ySpinBox->value();
}

QPointF Coord2FInput::pos() const
{
	return QPointF(ui->xSpinBox->value(), ui->ySpinBox->value());
}

void Coord2FInput::setX(const double x)
{
	ui->xSpinBox->setValue(x);
}

void Coord2FInput::setY(const double y)
{
	ui->ySpinBox->setValue(y);
}

void Coord2FInput::setPos(const double x, const double y)
{
	ui->xSpinBox->setValue(x);
	ui->ySpinBox->setValue(y);
}

void Coord2FInput::setPos(const QPointF &pos)
{
	ui->xSpinBox->setValue(pos.x());
	ui->ySpinBox->setValue(pos.y());
}

void Coord2FInput::setXLimits(const double min, const double max, const double step)
{
	ui->xSpinBox->setMinimum(min);
	ui->xSpinBox->setMaximum(max);
	ui->xSpinBox->setSingleStep(step);
}

void Coord2FInput::setYLimits(const double min, const double max, const double step)
{
	ui->ySpinBox->setMinimum(min);
	ui->ySpinBox->setMaximum(max);
	ui->ySpinBox->setSingleStep(step);
}
