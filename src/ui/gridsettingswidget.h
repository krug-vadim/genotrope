#ifndef GRIDSETTINGSWIDGET_H
#define GRIDSETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class GridSettingsWidget;
}

class GridSettingsWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit GridSettingsWidget(QWidget *parent = 0);
		~GridSettingsWidget();

	private:
		Ui::GridSettingsWidget *ui;
};

#endif // GRIDSETTINGSWIDGET_H
