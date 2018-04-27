//
//  SoundNodeObjectGraphicsItem.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef SoundNodeObjectGraphicsItem_hpp
#define SoundNodeObjectGraphicsItem_hpp

#include <QGraphicsItem>
#include <QRectF>
#include <QPainterPath>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QKeyEvent>

#include "SoundFile.hpp"
#include "soundFilePlayer.h" // THIS IS DEPENDANT ON PORTAUDIO - I KNOW IT IS BAD DESIGN TO HAVE IT IN THE GRAPHIC OBJECTS BUT FOR NOW WILL DO



class SoundNodeObjectGraphicsItem : public QGraphicsItem
{
public:
    SoundNodeObjectGraphicsItem(int x, int y, SoundFile *file);
    ~SoundNodeObjectGraphicsItem();
    
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    
    void keyPressEvent(QKeyEvent * event) override;
    
    PaStream *playBackStream;
    
    void updatePlaybackPosition(long position);
    long playBackPosition;
    
private:
    // int indexC;
    
    bool isPlaying;
    
    int dimX;
    int dimY;
    
    double zoomFactor;
    int translateFactor;
    
    QColor waveformColor;
    
    SoundFile *soundFile;
};





#endif /* SoundNodeObjectGraphicsItem_hpp */
