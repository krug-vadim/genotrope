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

	public slots:
		void drawData(const quint16 data[]);
		void save(const QString &filename);
		void save(QImage &image, const QPoint &destPos);
		void load(const QString &filename);

	protected:
		void paintEvent(QPaintEvent * event);

	private:
		QImage *_displayImage;
};

#endif // IMAGEGRIDWIDGET_H
