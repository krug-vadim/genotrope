#include "imagegridwidget.h"
#include <QtGui/QImage>
#include <QtGui/QPainter>

ImageGridWidget::ImageGridWidget(QWidget *parent) : QWidget(parent)
{
	_displayImage = new QImage(50, 50, QImage::Format_ARGB32_Premultiplied);
	_displayImage->fill(Qt::red);
	setMinimumSize(_displayImage->size());

	setOffset(0, 0);
	setGrid(8, 8);
}

ImageGridWidget::~ImageGridWidget()
{
	delete _displayImage;
}

QSize ImageGridWidget::imageSize() const
{
	return _displayImage->size();
}

QImage* ImageGridWidget::image() const
{
	return _displayImage;
}

QPoint ImageGridWidget::offset() const
{
	return _offset;
}

void ImageGridWidget::setOffset(const QPoint &offset)
{
	_offset = offset;
	repaint();
}

void ImageGridWidget::setOffset(const int x, const int y)
{
	setOffset( QPoint(x,y) );
}

QSize ImageGridWidget::grid() const
{
	return _grid;
}

void ImageGridWidget::setGrid(const QSize &grid)
{
	_grid = grid;
	repaint();
}

void ImageGridWidget::setGrid(const int w, const int h)
{
	setGrid( QSize(w,h) );
}

void ImageGridWidget::save(const QString &filename)
{
	_displayImage->save(filename, "PNG");
}

void ImageGridWidget::save(QImage &image, const QPoint &destPos)
{
	QPainter painter(&image);
	painter.drawImage(destPos, *_displayImage);
	painter.end();
}

void ImageGridWidget::load(const QString& filename)
{
	_displayImage->load(filename);
	setMinimumSize(_displayImage->size());
}

void ImageGridWidget::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
	QPainter painter(this);

	painter.drawImage(0, 0, *_displayImage);
	drawGrid(painter);
}

void ImageGridWidget::drawGrid(QPainter &painter)
{
	if ( grid().width() != 0 )
	{
		for(int x = offset().x(); x < image()->width(); x += grid().width())
			painter.drawLine(x, offset().y(), x, image()->height());
	}

	if ( grid().height() != 0 )
	{
		for(int y = offset().y(); y < image()->height(); y += grid().height())
			painter.drawLine(offset().x(), y, image()->width(), y);
	}
}
