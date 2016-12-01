#ifndef COORD2DINPUT_H
#define COORD2DINPUT_H

#include <QWidget>

namespace Ui
{
class Coord2DInput;
}

class Coord2DInput : public QWidget
{
		Q_OBJECT

	public:
		explicit Coord2DInput(QWidget *parent = 0);
		~Coord2DInput();

		void setXText(const QString &text);
		void setYText(const QString &text);

		int x() const;
		int y() const;
		QPoint pos() const;

		void setX(const int x);
		void setY(const int y);
		void setPos(const int x, const int y);
		void setPos(const QPoint &pos);

		void setXLimits(const int min, const int max, const int step);
		void setYLimits(const int min, const int max, const int step);

	signals:
		void xChanged(int value);
		void yChanged(int value);

	private:
		Ui::Coord2DInput *ui;
};

#endif // COORD2DINPUT_H
