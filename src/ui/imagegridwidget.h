#ifndef IMAGEGRIDWIDGET_H
#define IMAGEGRIDWIDGET_H

#include <QtWidgets/QWidget>
class QImage;

class ImageGridWidget : public QWidget
{
	Q_OBJECT

	public:
		explicit ImageGridWidget(QWidget *parent = 0);
		~ImageGridWidget();

		QSize imageSize() const;

		QImage *image() const;

		QPoint offset() const;
		QSize grid() const;
		QSize spacing() const;

	public slots:
		void setOffset(const QPoint &offset);
		void setOffset(const int x, const int y);

		void setGrid(const QSize &grid);
		void setGrid(const int w, const int h);

		void setSpacing(const QSize &spacing);
		void setSpacing(const int w, const int h);

		void save(const QString &filename);
		void save(QImage &image, const QPoint &destPos);
		void load(const QString &filename);

	protected:
		void paintEvent(QPaintEvent * event);

	private:
		void drawGrid(QPainter &painter);

		QPoint _offset;
		QSize _grid;
		QSize _spacing;

		QImage *_displayImage;
};

#endif // IMAGEGRIDWIDGET_H
