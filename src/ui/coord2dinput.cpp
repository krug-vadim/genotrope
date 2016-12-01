#include "coord2dinput.h"
#include "ui_coord2dinput.h"

Coord2DInput::Coord2DInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Coord2DInput)
{
	ui->setupUi(this);

	connect(ui->xSpinBox, SIGNAL(valueChanged(int)),
	        this, SIGNAL(xChanged(int)));
	connect(ui->ySpinBox, SIGNAL(valueChanged(int)),
	        this, SIGNAL(yChanged(int)));
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

void Coord2DInput::setX(const int x)
{
	ui->xSpinBox->setValue(x);
}

void Coord2DInput::setY(const int y)
{
	ui->ySpinBox->setValue(y);
}

void Coord2DInput::setPos(const int x, const int y)
{
	ui->xSpinBox->setValue(x);
	ui->ySpinBox->setValue(y);
}

void Coord2DInput::setPos(const QPoint &pos)
{
	ui->xSpinBox->setValue(pos.x());
	ui->ySpinBox->setValue(pos.y());
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
