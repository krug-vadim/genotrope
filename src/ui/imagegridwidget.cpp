#include "imagegridwidget.h"
#include <QtGui/QImage>
#include <QtGui/QPainter>

ImageGridWidget::ImageGridWidget(QWidget *parent) : QWidget(parent)
{
	_displayImage = new QImage(50, 50, QImage::Format_ARGB32_Premultiplied);
	_displayImage->fill(Qt::red);
	setMinimumSize(_displayImage->size());
}

ImageGridWidget::~ImageGridWidget()
{
	delete _displayImage;
}

QSize ImageGridWidget::imageSize() const
{
	return _displayImage->size();
}

void ImageGridWidget::drawData(const quint16 data[576])
{
	int x;

	x = 0;
	for(int i = 0; i < 576; i++)
	{
		int y;
		int val = (int)data[i] * _displayImage->height() / 65535;

		for(y = 0; y < val; y++)
			_displayImage->setPixel(x, _displayImage->height() - y - 1, qRgb(0,255,0));

		for(;y < _displayImage->height(); y++)
			_displayImage->setPixel(x, _displayImage->height() - y - 1, qRgb(0,0,0));

		x++;
	}
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
	QPainter painter(this);
	//painter.scale((qreal)width() / _displayImage->width(), (qreal)height()/_displayImage->height());
	painter.drawImage(0, 0, *_displayImage);
}
