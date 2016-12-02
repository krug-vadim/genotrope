#include "imagegridwidget.h"
#include <QtGui/QImage>
#include <QtGui/QPainter>

ImageGridWidget::ImageGridWidget(QWidget *parent) : QWidget(parent)
{
	_displayImage = new QImage(150, 150, QImage::Format_ARGB32_Premultiplied);
	_displayImage->fill(Qt::red);
	setMinimumSize(_displayImage->size());

	setOffset(0, 0);
	setGrid(8, 8);
	setSpacing(2, 2);
	setColor(QColor(0,255,0,64));
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

QSize ImageGridWidget::spacing() const
{
	return _spacing;
}

QColor ImageGridWidget::color() const
{
	return _color;
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

void ImageGridWidget::setSpacing(const QSize &spacing)
{
	_spacing = spacing;
	repaint();
}

void ImageGridWidget::setSpacing(const int w, const int h)
{
	setSpacing( QSize(w,h) );
}

void ImageGridWidget::setColor(const QColor &color)
{
	_color = color;
	repaint();
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
	int step;

	painter.setPen(color());

	if ( grid().width() != 0 )
	{
		step = grid().width() + spacing().width();

		for(int x = offset().x(); x < image()->width(); x += step)
			painter.drawLine(x, offset().y(), x, image()->height());

		for(int x = offset().x() + grid().width(); x < image()->width(); x += step)
			painter.drawLine(x, offset().y(), x, image()->height());
	}

	if ( grid().height() != 0 )
	{
		step = grid().height() + spacing().height();
		for(int y = offset().y(); y < image()->height(); y += step)
			painter.drawLine(offset().x(), y, image()->width(), y);
		for(int y = offset().y() + grid().height(); y < image()->height(); y += step)
			painter.drawLine(offset().x(), y, image()->width(), y);
	}
}
