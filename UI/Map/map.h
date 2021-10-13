#pragma once

#include <QPainter>
#include <QGraphicsItem>
#include <string>
class Map: public QGraphicsItem
{
public:
    Map(const std::string& name);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setDotCoord(int x, int y);
    std::string GetLocation() const;
    void setAvailability(bool available);
    void setIsSelected(bool isDotSelected);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool pressed;
    bool isSelected;
    bool isAvailable;
    int x;
    int y;
    std::string location;
    QRectF rec;
    QBrush brush;
};