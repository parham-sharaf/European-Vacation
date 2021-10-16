#pragma once

#include <QPainter>
#include <QGraphicsItem>
#include <string>
#include <iostream>
#include <vector>

class Map: public QGraphicsItem
{
public:
    Map(const std::string& name, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    std::string GetLocation() const;
    void setPressed(bool isPressed);
    void setAvailability(bool available);
    void setIsSelected(bool isDotSelected);
    void setStartingCity(const std::string& name);
    bool getPressed();
    static std::string getStartingCity();
    static std::vector<Map*> euroMap;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool pressed;
    bool isSelected;
    bool isAvailable;
    int x;
    int y;
    std::string location;
    static std::string startingPoint;
    QRectF rec;
    QBrush brush;
};