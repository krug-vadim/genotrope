#ifndef GRIDSETTINGSWIDGET_H
#define GRIDSETTINGSWIDGET_H

#include <QWidget>

namespace Ui
{
class GridSettingsWidget;
}

class GridSettingsWidget : public QWidget
{
	Q_OBJECT

	public:
		explicit GridSettingsWidget(QWidget *parent = 0);
		~GridSettingsWidget();

	public slots:
		void setOffset(const QPoint &pos);
		void setGrid(const QSize &size);
		void setSpacing(const QSize &spacing);

	signals:
		void offsetChanged(const QPoint &pos);
		void gridChanged(const QSize &size);
		void spacingChanged(const QSize &spacing);

	private slots:
		void offsetUpdate();
		void gridUpdate();
		void spacingUpdate();

	private:
		Ui::GridSettingsWidget *ui;
};

#endif // GRIDSETTINGSWIDGET_H
