//
//  SoundNodeObjectGraphicsItem.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#include "SoundNodeObjectGraphicsItem.hpp"
#include <iostream>

#include "GraphicsView.hpp"
#include "GraphicsScene.hpp"
#include "CentralWidget.hpp"




SoundNodeObjectGraphicsItem::SoundNodeObjectGraphicsItem(int x, int y, SoundFile *file)
: QGraphicsItem()
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
    
    dimX = 600;
    dimY = 100;
    
    setPos(x, y);
    
    waveformColor = Qt::darkYellow;
    
    zoomFactor = 1.0;
    translateFactor = 0;
    
    soundFile = file;
    
    zoomFactor = static_cast<double>(soundFile->numSamples) / dimX; // full zoom out for now
    
    isPlaying = false;
    
    playBackPosition = -1;
}


SoundNodeObjectGraphicsItem::~SoundNodeObjectGraphicsItem()
{
    
}


void SoundNodeObjectGraphicsItem::updatePlaybackPosition(long position)
{
    playBackPosition = position;
    update();
}


void SoundNodeObjectGraphicsItem::keyPressEvent(QKeyEvent *event)
{
    // std::cout << "key event happened, man..." << event->key() << std::endl;
    if (event->key() == 32)
    {
        std::cout << "Pressed the space bar on my focused object" << std::endl;
        if (isPlaying)
        {
            // stop playback
            std::cout << "Stopping playback" << std::endl;
            
            // OK - SOME PORTAUDIO HEAVY LEAFTING TO DO HERE.
            stopSoundFileStream(playBackStream);
            
            isPlaying = false;
        }
        else
        {
            // start playback
            std::cout << "Starting playback" << std::endl;
            
            // OK - SOME PORTAUDIO HEAVY LIFTING TO DO HERE.
            
            streamSoundFile(soundFile, playBackStream, this);
            
            isPlaying = true;
        }
    }
    
}


void SoundNodeObjectGraphicsItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *)
{
    GraphicsView *view = static_cast<GraphicsView *>(scene()->views()[0]);
    view->parentCentralWidget->editorWindow->show();
}


void SoundNodeObjectGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    waveformColor = Qt::blue;
    update();
    QGraphicsItem::mousePressEvent(event);
}


void SoundNodeObjectGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier)
    {
        translateFactor += event->scenePos().x() - event->lastScenePos().x();
        update();
    }
    else if (event->modifiers() & Qt::ControlModifier)
    {
        
        zoomFactor += (event->scenePos().x() - event->lastScenePos().x()) * 2.0;
        update();
    }
    else
    {
        moveBy(event->scenePos().x() - event->lastScenePos().x(), event->scenePos().y() - event->lastScenePos().y());
    }
    
    
}

void SoundNodeObjectGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    waveformColor = Qt::darkYellow;
    // paint();
    update();
    // QGraphicsItem::mouseReleaseEvent(event);
}


QRectF SoundNodeObjectGraphicsItem::boundingRect() const
{
    return QRectF(-1, -1, dimX + 1, dimY + 1);
}

QPainterPath SoundNodeObjectGraphicsItem::shape() const
{
    QPainterPath path;
    path.addRect(-1, -1, dimX + 1, dimY + 1);
    return path;
}


void SoundNodeObjectGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    long numChannels = soundFile->numChannels;
    
    QPen pen(isSelected() ? waveformColor : Qt::darkCyan);
    painter->setPen(pen);
    
    long numSamplesPerPixel = static_cast<long>(zoomFactor);
    if (numSamplesPerPixel < 1)
        numSamplesPerPixel = 1;
    
    for (long i = 0; i < dimX; i++)
    {
        for (long j = 0; j < numChannels; j++)
        {
            // double yPos = dimY * 0.5;
            // double yScaler = dimY * 0.5;
            
            double yScaler = dimY / static_cast<double>(numChannels) * 0.5; // height of each channel divided by two
            double yPos = j * (2 * yScaler) + yScaler;
            
            long firstIndex = (i - translateFactor) * numSamplesPerPixel;
            bool wasSomething = false;
            double min = 0.0;
            double max = 0.0;
            for (long k = firstIndex; k < firstIndex + numSamplesPerPixel; k++)
            {
                if ((numChannels * k + j) >= 0 && (numChannels * k + j) < soundFile->numSamples * numChannels)
                {
                    wasSomething = true;
                    if (soundFile->samples[numChannels * k + j] < min)
                        min = soundFile->samples[numChannels * k + j];
                    if (soundFile->samples[numChannels * k + j] > max)
                        max = soundFile->samples[numChannels * k + j];
                }
            }
            if (wasSomething)
                painter->drawLine(i, yPos + min * yScaler, i, yPos + max * yScaler);
        }
    }
    
    pen.setColor(Qt::black);
    painter->setPen(pen);
    
    // DRAW CHANNEL SEPARATORS
    
    if (soundFile->numChannels > 1)
    {
        for (long i = 1; i < numChannels; i++)
        {
            double yPos = (static_cast<double>(i) / numChannels) * dimY;
            painter->drawLine(0, yPos, dimX, yPos);
        }
    }
    
    if (isPlaying)
    {
        pen.setColor(Qt::red);
        painter->setPen(pen);
        double cursorPosition = static_cast<double>(playBackPosition) / soundFile->numSamples * dimX;
        painter->drawLine(cursorPosition, 0, cursorPosition, dimY);
    }
    
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->drawRect(0, 0, dimX, dimY);
}

