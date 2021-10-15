#include "Map.h"


std::string Map::startingPoint;
std::vector<Map*> euroMap;

Map::Map(const std::string& name, int x, int y) {
    location = name;
    isSelected = false;
    isAvailable = false;
    pressed = false;
    this->x = x;
    this->y = y;
    brush = (Qt::blue);
}

std::string Map::GetLocation() const { return location; };

QRectF Map::boundingRect() const { return QRectF(x, y, 10, 10); }

void Map::setPressed(bool isPressed) {
    pressed = isPressed;
    if (pressed) isSelected = true;
    QGraphicsItem::update();
}

void Map::setIsSelected(bool isDotSelected) {
    isSelected = isDotSelected;
    pressed = false;
    QGraphicsItem::update();
}

void Map::setAvailability(bool available) {
    isAvailable = available;
    QGraphicsItem::update();
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
    rec = boundingRect();
    std::cout << "here" << std::endl;

    if (isAvailable) {
        painter->setPen(Qt::black);
        brush.setColor(Qt::green);
        if (isSelected) {
            brush.setColor(Qt::blue);
            if (pressed) {
                startingPoint = location;
                brush.setColor(Qt::red);
            }
        }
    }
    else {
        painter->setPen(Qt::transparent);
        brush.setColor(Qt::transparent);
    }
    painter->fillRect(rec, brush);
    painter->drawRect(rec);
}

void Map::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    pressed = !pressed;
    QGraphicsItem::mousePressEvent(event);
    QGraphicsItem::update();
}

bool Map::getPressed() {
    return pressed;
}

std::string Map::getStartingCity() {
    return startingPoint;
}

void Map::setStartingCity(const std::string& name) {
    startingPoint = name;
}
