#ifndef COORD2FINPUT_H
#define COORD2FINPUT_H

#include <QWidget>

namespace Ui
{
class Coord2FInput;
}

class Coord2FInput : public QWidget
{
	Q_OBJECT

	public:
		explicit Coord2FInput(QWidget *parent = 0);
		~Coord2FInput();

		void setXText(const QString &text);
		void setYText(const QString &text);

		double x() const;
		double y() const;
		QPointF pos() const;

		void setX(const double x);
		void setY(const double y);
		void setPos(const double x, const double y);
		void setPos(const QPointF &pos);

		void setXLimits(const double min, const double max, const double step);
		void setYLimits(const double min, const double max, const double step);

	signals:
		void xChanged(double value);
		void yChanged(double value);

	private:
		Ui::Coord2FInput *ui;
};

#endif // COORD2FINPUT_H
