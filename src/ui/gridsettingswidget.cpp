#include "gridsettingswidget.h"
#include "ui_gridsettingswidget.h"

GridSettingsWidget::GridSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GridSettingsWidget)
{
	ui->setupUi(this);
}

GridSettingsWidget::~GridSettingsWidget()
{
	delete ui;
}
