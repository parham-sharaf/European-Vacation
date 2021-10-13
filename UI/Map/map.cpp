#include "map.h"

Map::Map(const std::string& name) {
    location = name;
    isSelected = false;
    pressed = false;
    x = y = 0;
    brush = (Qt::blue);
}

std::string Map::GetLocation() const { return location; };

QRectF Map::boundingRect() const { return QRectF(x, y, 10, 10); }

void Map::setDotCoord(int x, int y) { this->x = x; this->y = y; }

void Map::setIsSelected(bool isDotSelected) {
    isSelected = isDotSelected;
    QGraphicsItem::update();
}


void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
    rec = boundingRect();

    if (isSelected) brush.setColor(Qt::blue);
    if (pressed) brush.setColor(Qt::red);
    else if (!isSelected && !pressed) brush.setColor(Qt::green);

    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}

void Map::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    pressed = !pressed;
    QGraphicsItem::mousePressEvent(event);
    QGraphicsItem::update();
}

