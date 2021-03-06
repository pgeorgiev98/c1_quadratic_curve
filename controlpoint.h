#ifndef CONTROLPOINT_H
#define CONTROLPOINT_H

#include <QPointF>
#include <QLineF>
#include <QSizeF>
#include <QColor>
#include <optional>

class QPainter;

class ControlPoint
{
public:
	ControlPoint() : ControlPoint(QPointF(0, 0), 1) {}
	ControlPoint(QPointF p, double size) : m_p(p), m_isDragged(false), m_size(size) {}

	void constrain(QLineF line);
	void fix();
	void unconstrain();

	bool isHoveredBy(QPointF point, QSizeF scale) const;
	bool press(QPointF pos, QSizeF scale);
	bool release(QPointF pos);
	bool move(QPointF pos);
	void draw(QPainter *painter, QSizeF scale, QColor borderColor, QColor fillColor) const;

	QPointF position() const
	{
		return m_p;
	}

	void setPosition(QPointF position)
	{
		m_p = position;
	}

	bool isDragged() const
	{
		return m_isDragged;
	}

	void setSize(double size)
	{
		m_size = size;
	}

private:
	QPointF m_p;
	QPointF m_offset;
	bool m_isDragged;
	double m_size;
	std::optional<QLineF> m_constrainLine;
};

#endif // CONTROLPOINT_H
